/***************************************************************************
*
* Copyright(c) 2015 Baidu.com, Inc. All Rights Reserved
*
**************************************************************************/

/**
* @file caffe_interface.cpp
* @author liuguoyi01(com@baidu.com)
* @date 2015 / 08/23 15:00:37
* @brief
*
**/

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <glog/logging.h>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include "opencv/highgui.h"
#include <boost/thread/thread.hpp> 
#include <boost/thread/tss.hpp>  
#include <boost/thread/mutex.hpp>
//#include "boost/algorithm/string.hpp"
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"

#include "caffe/common.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/data_transformer.hpp"
#include "caffe/util/upgrade_proto.hpp"
#include "caffe_interface.h"
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <glog/logging.h>
#include <glog/raw_logging.h>

#define CFATAL_LOG RAW_LOG_ERROR
#define CWARNING_LOG RAW_LOG_WARNING
#define CNOTICE_LOG RAW_LOG_INFO

#define CDEBUG_LOG RAW_LOG_INFO
#define CTRACE_LOG RAW_LOG_INFO

//#define CWARNING_LOG RAW_LOG_ERROR
//#define CDEBUG_LOG RAW_LOG_ERROR
using std::vector;
using std::string;
using std::stringstream;
using std::cerr;
using std::endl;

using caffe::Blob;
using caffe::Caffe;
using caffe::Net;
using caffe::Layer;

using caffe::Timer;
using caffe::vector;
using caffe::TransformationParameter;
using caffe::DataTransformer;

namespace vis
{

    boost::thread_specific_ptr<int> caffedeviceid; 
    boost::mutex caffeinitmutex; 
    int globaldeviceid = -1;
    //initalized only once for one thread
    void initcaffesetdeviceid(){
        if (caffedeviceid.get() == 0){
            boost::mutex::scoped_lock(caffeinitmutex);
            int deviceid = globaldeviceid;
            if (deviceid >= 0)
            {
                caffedeviceid.reset(new int(deviceid));
                Caffe::SetDevice(deviceid);
                CDEBUG_LOG("#############   Caffe::SetDevice(%d)", deviceid);
#ifdef CPU_ONLY
                Caffe::set_mode(Caffe::CPU);
                CWARNING_LOG("code is compiled CPU_ONLY, Use:CPU instead of GPU");
#else
                Caffe::set_mode(Caffe::GPU);
                CDEBUG_LOG("Use:GPU: deviceid:%d", globaldeviceid);
#endif
            }
            else
            {
                Caffe::set_mode(Caffe::CPU);
                CDEBUG_LOG("Use:CPU");
            }
        }
    }
    static bool exists(const std::string &pathname)
    {
#ifdef _WIN32
        struct _stat file_stat ;
        return _stat(pathname.c_str(), &file_stat) == 0;
#else
        struct stat file_stat ;
        return stat(pathname.c_str(), &file_stat) == 0;
#endif 
    }

    /************************************************************
    Predict the class and attributes of an cloth image as input;
    *************************************************************/

    static bool saveblob(const string & filename, const Blob < float>& blob){
        const float * data = blob.cpu_data();
        if (data == NULL)
        {
            return false;
        }
        const vector < int>& shape = blob.shape();
        int shapesize = shape.size(); 
        std::ofstream ofs(filename.c_str(), std::ios::binary); 
        if (!ofs){
            return false;
        }
        ofs.write((const char*) &shapesize, 4); 
        ofs.write((const char*) &shape[0], shapesize * sizeof(int)); 
        ofs.write((const char*) data, sizeof(float)*blob.count()); 
        return true;
    }

    class CaffeBlobImp : public ICaffeBlob {
    public:
        CaffeBlobImp(const vector < int>& shape){
            initcaffesetdeviceid();
            _blob = boost::shared_ptr < Blob<float> >(new Blob < float>(shape));
        }
        CaffeBlobImp(const boost::shared_ptr < Blob<float> > & blob){
            _blob = blob;
        }
        virtual ~CaffeBlobImp() {}
        virtual const vector < int>& shape() {
            return _blob->shape();
        };
        void reshape(const vector < int>& shape){
            _blob->Reshape(shape);
        }
        virtual const float * cpu_data() const{
            return _blob->cpu_data();
        };
        virtual void set_cpu_data(float * data) {
            _blob->set_cpu_data(data);
        };
        virtual float * mutable_cpu_data(){
            return _blob->mutable_cpu_data();
        };
        virtual void savetofile(const string & filename){
            saveblob(filename, *_blob); 
        }

        boost::shared_ptr < Blob<float> > & blob(){return _blob;}
        virtual bool getdata(std::vector < float>  & outputdata, std::vector < int> & outputshape){
            const float * data = _blob->cpu_data(); 
            if (_blob.get() == NULL || data == NULL)
            {
                return false;
            }
            int blobsize = _blob->count();
            outputdata.resize(blobsize);
            memcpy(&outputdata[0], data, sizeof(float)*blobsize); 
            outputshape = _blob->shape();
            return true;
        }
        virtual int count() {
            return _blob->count();
        }
    protected:
        boost::shared_ptr < Blob<float> > _blob;
    };

    ICaffeBlob * createcaffeblob(const std::vector < int>& shape)
    {
        return new CaffeBlobImp(shape);
    }

    class CaffeLayerDatasImp : public ICaffeLayerDatas {
    public:
        CaffeLayerDatasImp(){}
        virtual ~CaffeLayerDatasImp(){}
        virtual void push_back(boost::shared_ptr < ICaffeBlob> & blob) {
            _blobs.push_back(blob);
        }
        virtual int getsize()const {return _blobs.size();}
        virtual boost::shared_ptr < ICaffeBlob>& getdata(int i) {return _blobs[i];}
        virtual void clear(){ _blobs.clear();}
    protected:
        std::vector < boost::shared_ptr < ICaffeBlob> > _blobs; 
    };
    
    ICaffeLayerDatas* createcaffelayerdatas(){
        return new CaffeLayerDatasImp();
    }
    
    class CaffePreProcessImp :public ICaffePreProcess {
    protected:
        vector < int> _input_dim; //has size 4
        boost::shared_ptr < caffe::TransformationParameter > _transform_param;
        boost::shared_ptr < caffe::DataTransformer < float> > _data_transformer_;
        int _resizewidth ;
        int _resizeheight;

    public:
        CaffePreProcessImp() : _resizewidth(0), _resizeheight(0){
            initcaffesetdeviceid();
        }
        bool init(const CaffePreProcessParam & param){
            _input_dim = param._input_dim;

            //image preprocess
            bool has_meanfile = !param._mean_file.empty();
            bool has_meanvalue = param._mean_value.size()>0;
            if (_input_dim.size() != 4)
            {
                CFATAL_LOG("wrong input_dim");
                return false;
            }
            if (!has_meanfile && !has_meanvalue)
            {
                CFATAL_LOG("both mean_file and mean_value is empty");
                return false;
            }
            _resizewidth = param._resizewidth;
            _resizeheight = param._resizeheight;
            if (_resizewidth <= 0 || _resizeheight <= 0) {
                CFATAL_LOG("resizewidth %d or resizeheight %d is not valid.",
                    _resizewidth, _resizeheight);
                return false;
            }

            if (_resizewidth < _input_dim[3] || _resizeheight < _input_dim[2]) {
                CFATAL_LOG("invalid resizewidth %d or resizeheight %d,input_dim:(%d,%d,%d,%d)",
                    _resizewidth, _resizeheight, 
                    _input_dim[0], _input_dim[1], _input_dim[2], _input_dim[3]);
                return false;
            }
            //init transform_param
            _transform_param = boost::shared_ptr < TransformationParameter>(
                new TransformationParameter);

            _transform_param->set_scale(param._scale);

            _transform_param->set_crop_size(_input_dim[2]);
            if (has_meanfile){
                if (!exists(param._mean_file)){
                    CFATAL_LOG("mean_file does not exist:%s", param._mean_file.c_str());
                    return false;
                }
                _transform_param->set_mean_file(param._mean_file);
            }
            else
            {
                if (_input_dim[1] != param._mean_value.size())
                {
                    CFATAL_LOG("mean_value size:%d don't match input_dim[1]:%d", 
                        param._mean_value.size(), _input_dim[1]);
                    return false;
                }

                for (int i = 0; i < param._mean_value.size(); i++)
                {
                    _transform_param->add_mean_value(param._mean_value[i]);
                }
            }
            const int crop_size = _transform_param->crop_size();
            if (_input_dim[2] !=crop_size && _input_dim[3] != crop_size)
            {
                CFATAL_LOG("input_dim:(%d,%d,%d,%d) dont match crop_size:%d", 
                    _input_dim[0], _input_dim[1], _input_dim[2], _input_dim[3], crop_size); 
                return false;
            }



            //get input channel from mean and check dim;
            //mean should has same size with resizewidth, resizeheight 

            _data_transformer_ = boost::shared_ptr < caffe::DataTransformer < float> >(
                new caffe::DataTransformer<float>(*_transform_param, caffe::TEST));

            CDEBUG_LOG("CaffePreProcessImp::init quit");
            return true;
        }
        virtual boost::shared_ptr < ICaffeBlob> process(const cv::Mat & image) {
            initcaffesetdeviceid();
            cv::Mat cv_img;
            if (image.empty() || image.rows <= 0 || image.cols <= 0 || 
                    image.channels() != _input_dim[1]){
                return boost::shared_ptr < ICaffeBlob>((ICaffeBlob*)NULL);
            } 

            if (_resizewidth > 0 && _resizeheight > 0 && 
                (image.cols != _resizewidth || image.rows != _resizeheight))
            {    
                cv::resize(image, cv_img, cv::Size(_resizewidth, _resizeheight));
            }
            else{
                cv_img = image;
                //CDEBUG_LOG("use original image:%d,%d", cv_img.cols, cv_img.rows); 
            }

            CaffeBlobImp * pblob = new CaffeBlobImp(_input_dim);
            _data_transformer_->Transform(cv_img, pblob->blob().get());
            return boost::shared_ptr < ICaffeBlob>(pblob);
        }
        bool _init_shared(CaffePreProcessImp * cls){
            this->_transform_param = cls->_transform_param ; 
            if (this->_transform_param.get() != NULL)
            {
                //CDEBUG_LOG("_init_shared before  DataTransformer");
                _data_transformer_ = boost::shared_ptr< DataTransformer<float> >(
                    new DataTransformer < float>(*_transform_param, caffe::TEST));
                //CDEBUG_LOG("_init_shared after  _data_transformer_");
            }
            else{
                return false;
            }
            this->_resizewidth = cls->_resizewidth;
            this->_resizeheight = cls->_resizeheight;
            this->_input_dim = cls->_input_dim;
            return true;
        }

        ICaffePreProcess * clone() {  
            CaffePreProcessImp * cls = new CaffePreProcessImp(); 
            if (!cls->_init_shared(this))
            {
                CFATAL_LOG("fail to call cls->_init_shared");
                delete cls;
                return NULL; 
            }
            return cls;
        }
    };

    ICaffePreProcess * createcaffepreprocess(const CaffePreProcessParam & param)
    {
        CaffePreProcessImp * instance = new CaffePreProcessImp();
        if (!instance->init(param)){
            CWARNING_LOG("fail to call CaffePreProcessImp::init");
            delete instance;
            return NULL;
        }
        return instance;
    }

    class CaffePredictImp : public ICaffePredict {
    public:
        CaffePredictImp(){};
        ~CaffePredictImp(){};
        bool init(const CaffeParam &param)
        {
            initcaffesetdeviceid();
            if (!exists(param._models_file)){
                CFATAL_LOG("models_file does not exist:%s", param._models_file.c_str());
                return false;
            }
            if (!exists(param._weights_file)){
                CFATAL_LOG("weights_file does not exist:%s", param._weights_file.c_str());
                return false;
            }
            _netparam = boost::shared_ptr < caffe::NetParameter>(new caffe::NetParameter()); 
            caffe::ReadNetParamsFromTextFileOrDie(param._models_file, _netparam.get());
            _netparam->mutable_state()->set_phase(caffe::TEST);

            _caffe_net_ = boost::shared_ptr<caffe::Net<float> >(new Net<float>(*_netparam));
            CDEBUG_LOG("load weights_file :%s", param._weights_file.c_str());
            _caffe_net_->CopyTrainedLayersFrom(param._weights_file);
            CDEBUG_LOG("predict model::init quit");
            return true;
        }

        ICaffePredict * clone() {  
            if (this->_caffe_net_ == NULL){
                CFATAL_LOG("current net is not inited for a clone"); 
                return NULL;
            }
            CaffePredictImp * cls = new CaffePredictImp(); 
            if (!cls->_init_shared(this))
            {
                CFATAL_LOG("fail to call cls->_init_shared");
                delete cls;
                return NULL; 
            }
            return cls;
        } 
        virtual bool predict(const ICaffeLayerDatas* inputdatas, 
            const std::vector < std::string> & layernames,
            ICaffeLayerDatas * outputdatas) {
            initcaffesetdeviceid();
            if (!_checkoutputnames(layernames))
            {
                //CWARNING_LOG("fail to call _checkoutputnames");
                for (int i = 0; i < layernames.size(); i++)
                {
                    CFATAL_LOG("fail to call _checkoutputnames:%s", &layernames[i][0]);
                }
                return false;
            }
            vector < Blob<float> * > bottom_vec;
            for (int i = 0; i < inputdatas->getsize(); i++)
            {
                CaffeBlobImp * pblob = dynamic_cast < CaffeBlobImp*>(
                    (const_cast<ICaffeLayerDatas*>(inputdatas))->getdata(i).get());
                if (pblob == NULL)
                {
                    return false;
                }
                bottom_vec.push_back(pblob->blob().get());
            }
            //std::cout << "bottom_vec.shape" << bottom_vec[0]->shape()[0] << " " << bottom_vec[0]->shape()[1] << " " << bottom_vec[0]->shape()[2] << " " << bottom_vec[0]->shape()[3] << std::endl;

            Blob<float>* input_layer = _caffe_net_->input_blobs()[0];
            input_layer->Reshape(bottom_vec[0]->shape()[0], bottom_vec[0]->shape()[1], bottom_vec[0]->shape()[2],bottom_vec[0]->shape()[3]);
            _caffe_net_->Reshape();

            float loss = 0.0f;
            _caffe_net_->Forward(bottom_vec, &loss);
            CDEBUG_LOG("_caffe_net_->Forward called");
            outputdatas->clear();
            const vector < boost::shared_ptr < Blob<float> > > & result = _caffe_net_->blobs();

            //debug
            {
                const vector<string> blob_names = _caffe_net_->blob_names();
                if(blob_names.size()!=result.size())
                {
                    std::cerr<<"the num of blob name not match the num of blobs!"<<std::endl;
                }
                else
                {
                    //for(int j=0;j<result.size();++j)
                    //{
                    //    std::cerr<<"blob name:"<<blob_names[j]<<" sum="<<result[j]->asum_data()<<std::endl;
                    //}
                }
            }





            for (int j = 0; j < layernames.size(); ++j) {
                boost::shared_ptr < ICaffeBlob> outblob = boost::shared_ptr < ICaffeBlob>(
                    new CaffeBlobImp(_caffe_net_->blob_by_name(layernames[j])));
                outputdatas->push_back(outblob);
            }
            return true;
        }
       
    private:
        bool _init_shared(CaffePredictImp * cls)
        {
            //CDEBUG_LOG("_init_shared enter");
            if (cls->_netparam.get() == NULL || cls->_caffe_net_.get() == NULL){
                CFATAL_LOG("_init_shared with empty cls"); 
                return false;
            }
            this->_netparam = cls->_netparam ; 
            //CDEBUG_LOG("_init_shared before create net");
            _caffe_net_ = boost::shared_ptr<Net<float> >(new Net<float>(*_netparam));
            //CDEBUG_LOG("_init_shared after create net");
            this->_caffe_net_->ShareTrainedLayersWith(cls->_caffe_net_.get()); 
            //CDEBUG_LOG("_init_shared after shared net");
            this->_input_dim = cls->_input_dim;
            return true;
        }

        bool _checkoutputnames(const std::vector < std::string> & layernames){
            //first check layernames
            for (int i = 0; i < layernames.size(); i++)
            {
                if (!_caffe_net_->has_blob(layernames[i]))
                {  
                    CWARNING_LOG("net does not contain outputname as \"%s\"",
                        layernames[i].c_str());
                    return false;
                }
            }
            return true;
        }
        boost::shared_ptr < Net<float> > _caffe_net_;
        vector < int> _input_dim  ;
        boost::shared_ptr < caffe::NetParameter > _netparam;

    };

    ICaffePredict * createcaffepredict(const  CaffeParam &param)
    {
        CaffePredictImp * cls = new CaffePredictImp();
        if (!cls->init(param))
        {
            CFATAL_LOG("fail to call cls->init"); 
            delete cls;
            return NULL;
        }
        return cls;
    }

    void initcaffeglobal(int argc, char** argv, int deviceid){
        globaldeviceid = deviceid;
#ifdef CPU_ONLY
        if (globaldeviceid >= 0)
        {
            CWARNING_LOG("deviceid=%d cant be used in CPU_ONLY code", globaldeviceid);
            globaldeviceid = -1;
        }
#endif
        caffe::GlobalInit(&argc, &argv);
    }
    static double clock_microsec()
    {
        static double freq = cvGetTickFrequency(); 
        static int64 base = cvGetTickCount(); 
        int64 t = cvGetTickCount(); 
        return ((double)(t - base) / freq);
    }
}
