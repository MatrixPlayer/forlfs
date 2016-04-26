/*============================================================================
 * File Name   : face_detect_processor.cpp
 * Author      : tongliu@deepglint.com
 * Version     : 1.0.0.0
 * Copyright   : Copyright 2016 DeepGlint Inc.
 * Created on  : 2016年3月2日 下午1:53:19
 * Description : 
 * ==========================================================================*/

#include "processor/face_detect_processor.h"

namespace dg {

FaceDetectProcessor::FaceDetectProcessor(string model_file, string trained_file,
                                         const bool use_gpu,
                                         const int batch_size, float threshold,
                                         int width, int height) {
    //Initialize face detection caffe model and arguments
    std::cout << "Strart loading fece detector model" << std::endl;
    model_file_ = model_file;
    trained_file_ = trained_file;
    det_thresh_ = threshold;
    resolution_.width = width;
    resolution_.height = height;

    //Initialize face detector
    detector_ = new FaceDetector(model_file_, trained_file_, use_gpu,
                                 batch_size, resolution_, det_thresh_);
    std::cout << "Fece detector has been initialized" << std::endl;
}

FaceDetectProcessor::~FaceDetectProcessor() {
    delete detector_;
}

void FaceDetectProcessor::Update(Frame *frame) {
    vector<Mat> imgs;
    imgs.push_back(frame->payload()->data());
    vector<vector<Detection>> boxes_in = detector_->Detect(imgs);

    for (size_t bbox_id = 0; bbox_id < boxes_in[0].size(); bbox_id++) {
        Detection detection = boxes_in[0][bbox_id];
        Face *face = new Face(bbox_id, detection, detection.confidence);
        frame->put_object(face);
    }
}

} /* namespace dg */
