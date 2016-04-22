/*============================================================================
 * File Name   : face_extractor.h
 * Author      : yanlongtan@deepglint.com
 * Version     : 1.0.0.0
 * Copyright   : Copyright 2016 DeepGlint Inc.
 * Created on  : 04/19/2016
 * Description : 
 * ==========================================================================*/

#ifndef MATRIX_RANKER_ALG_FACE_EXTRACTOR_H_
#define MATRIX_RANKER_ALG_FACE_EXTRACTOR_H_

#include <glog/logging.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <caffe/caffe.hpp>

#include "model/rank_feature.h"

using namespace std;
using namespace cv;
using namespace caffe;

namespace dg 
{
class FaceExtractor
{
public:
    FaceExtractor(string deploy, string model,int batchSize = 8, int gpuId=0);
    virtual ~FaceExtractor();

    void Classify(const vector<Mat>& images, const vector<FaceFeature>& features, vector<vector<Score>>& predicts);

private:
    int batch_size_;
    Size input_geometry_;
    int num_channels_;
    caffe::shared_ptr<Net<float> > net_;
};

}

#endif //MATRIX_RANKER_ALG_FACE_EXTRACTOR_H_