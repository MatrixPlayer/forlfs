/*
 * plate_recognize_mxnet_processor.cpp
 *
 *  Created on: May 18, 2016
 *      Author: jiajaichen
 */

//#include <matrix_engine/model/model.h>
#include "plate_recognize_mxnet_processor.h"
#include "debug_util.h"
#include <opencv2/highgui/highgui.hpp>

namespace dg {
/*const char *paInv_chardict[LPDR_CLASS_NUM] = { "_", "0", "1", "2", "3", "4",
        "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "J",
        "K", "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
        "Z", "I", "\u4eac", "\u6d25", "\u6caa", "\u6e1d", "\u5180", "\u8c6b", "\u4e91", "\u8fdb", "\u9ed1", "\u6e58", "皖", "闽",
        "鲁", "新", "苏", "浙", "赣", "鄂", "桂", "甘", "晋", "蒙", "\u9655", "吉", "贵", "粤",
        "青", "藏", "川", "宁", "琼", "使", "领", "试", "学", "临", "时", "警", "港", "O",
        "挂", "澳", "#" };*/
const char *paInv_chardict[79] = {"_", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", \
                                  "A", "B", "C", "D", "E", "F", "G", "H", "J", \
                                  "K", "L", "M", "N", "P", "Q", "R", "S", "T", \
                                  "U", "V", "W", "X", "Y", "Z", "I", "京", "津", \
                                  "沪", "渝", "冀", "豫", "云", "辽", "黑", "湘", \
                                  "皖", "闽", "鲁", "新", "苏", "浙", "赣", "鄂", \
                                  "桂", "甘", "晋", "蒙", "陕", "吉", "贵", "粤", \
                                  "青", "藏", "川", "宁", "琼", "使", "领", "试", \
                                  "学", "临", "时", "警", "港", "O", "挂", "澳", "#"
};

PlateRecognizeMxnetProcessor::PlateRecognizeMxnetProcessor(const PlateRecognizeMxnetConfig& config) {
    batch_size_ = config.batchsize;
    enable_local_province_ = config.enableLocalProvince;
    local_province_ = config.localProvinceText;
    local_province_confidence_ = config.localProvinceConfidence;
    pclsLPDR = new dgLP::LPDR(config.modelPath, config.gpuId, config.is_model_encrypt);
}

PlateRecognizeMxnetProcessor::~PlateRecognizeMxnetProcessor() {
    // TODO Auto-generated destructor stub
    delete pclsLPDR;
}
bool PlateRecognizeMxnetProcessor::process(Frame *frame) {
    return false;
}
bool PlateRecognizeMxnetProcessor::process(FrameBatch *frameBatch) {

    VLOG(VLOG_RUNTIME_DEBUG) << "Start Plate Recognize Mxnet Processor : " << frameBatch->id() << endl;

    float costtime, diff;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    int batchsize = batch_size_;
    int imagesize = images_.size();
    VLOG(VLOG_RUNTIME_DEBUG) << "LPDR loop: " << (ceil((float) imagesize / (float) batchsize) * batchsize) << endl;
    for (int i = 0; i < (ceil((float) imagesize / (float) batchsize) * batchsize); i +=
                                                                                       batchsize) {
        stImgSet_.dwImageNum = 0;
        for (int j = 0; j < batchsize; j++) {
            if (i + j < imagesize) {
                Mat pubyData = images_[i + j];
                stImgSet_.astSet[j].pubyData = pubyData.data;
                stImgSet_.astSet[j].dwImgH = pubyData.rows;
                stImgSet_.astSet[j].dwImgW = pubyData.cols;
                stImgSet_.dwImageNum++;

            }
        }
        LPDR_OutputSet_S stOutput;

        VLOG(VLOG_RUNTIME_DEBUG) << "Start LPDR: " << frameBatch->id() << endl;
        pclsLPDR->Process(&stImgSet_, &stOutput);
        VLOG(VLOG_RUNTIME_DEBUG) << "Finish LPDR: " << frameBatch->id() << endl;


        VLOG(VLOG_RUNTIME_DEBUG) << "Start Post process: " << frameBatch->id() << endl;

        for (int j = 0; j < batchsize; j++) {
            LPDR_Output_S *pstOut = stOutput.astLPSet + j;
            vector<Vehicle::Plate> plates;
            for (int dwJ = 0; dwJ < pstOut->dwLPNum; dwJ++) {
                LPDRInfo_S *pstLP = pstOut->astLPs + dwJ;
                int *pdwLPRect = pstLP->adwLPRect;
                Vehicle::Plate plate;
                plate.box.x = pdwLPRect[0];
                plate.box.y = pdwLPRect[1];
                plate.box.width = pdwLPRect[2] - pdwLPRect[0];
                plate.box.height = pdwLPRect[3] - pdwLPRect[1];

                string platenum;
                float score = 0;
                if (pstLP->afScores[0] < local_province_confidence_ && enable_local_province_) {
                    platenum = local_province_;
                } else {
                    platenum = paInv_chardict[pstLP->adwLPNumber[0]];
                }
                score += pstLP->afScores[0];
                for (int dwK = 1; dwK < pstLP->dwLPLen; dwK++) {
                    platenum += paInv_chardict[pstLP->adwLPNumber[dwK]];
                    score += pstLP->afScores[dwK];
                }


                score /= pstLP->dwLPLen;
                plate.color_id = pstLP->dwColor;
                plate.plate_type = pstLP->dwType;
                plate.confidence = score;
                plate.plate_num = platenum;
                plate.local_province_confidence = pstLP->afScores[0];
                plates.push_back(plate);
            }
            if (objs_.size() > (i + j)) {
                Vehicle *v = (Vehicle *) objs_[i + j];
                v->set_plates(plates);
            }

        }

    }
    gettimeofday(&end, NULL);
    VLOG(VLOG_PROCESS_COST) << "Plate mxnet cost: " << TimeCostInMs(start, end) << endl;
    VLOG(VLOG_RUNTIME_DEBUG) << "Finish Plate Recognize Mxnet Processor : " << frameBatch->id() << endl;
    return true;
}

bool PlateRecognizeMxnetProcessor::RecordFeaturePerformance() {

    return RecordPerformance(FEATURE_CAR_PLATE, performance_);
}

bool PlateRecognizeMxnetProcessor::beforeUpdate(FrameBatch *frameBatch) {
#if DEBUG
#else
    if (performance_ > RECORD_UNIT) {
        if (!RecordFeaturePerformance()) {
            return false;
        }
    }
#endif
    this->vehiclesFilter(frameBatch);
    return true;
}

void PlateRecognizeMxnetProcessor::vehiclesFilter(FrameBatch *frameBatch) {
    /*   images_.clear();
     images_.push_back(frameBatch->frames()[0]->payload()->data());
     return;*/
    images_.clear();
    objs_.clear();
    objs_ = frameBatch->CollectObjects(OPERATION_VEHICLE_PLATE);
    vector<Object *>::iterator itr = objs_.begin();
    while (itr != objs_.end()) {

        Object *obj = *itr;

        if (obj->type() == OBJECT_CAR) {
            Vehicle *v = (Vehicle *) obj;
            VLOG(VLOG_RUNTIME_DEBUG) << "Put vehicle images to be color classified: " << obj->id() << endl;
            images_.push_back(v->image());
            ++itr;
            performance_++;

        } else {
            itr = objs_.erase(itr);
            VLOG(VLOG_RUNTIME_DEBUG) << "This is not a type of vehicle: " << obj->id() << endl;
        }
    }
}
}
/* namespace dg */
