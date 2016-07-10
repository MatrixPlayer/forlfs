/*
 * vehicle_confirm_caffe_detector.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: jiajaichen
 */

#include "car_only_confirm_caffe_detector.h"
#include "../caffe_helper.h"

namespace dg {

CarOnlyConfirmCaffeDetector::CarOnlyConfirmCaffeDetector(const VehicleCaffeDetectorConfig &config)
    : device_setted_(false),
      caffe_config_(config),
      rescale_(100) {

//    device_setted_ = false;
//    if (caffe_config_.use_gpu) {
//        Caffe::SetDevice(caffe_config_.gpu_id);
//        Caffe::set_mode(Caffe::GPU);
//        LOG(INFO) << "Use device " << caffe_config_.gpu_id << endl;
//    } else {
//        LOG(WARNING) << "Use CPU only" << endl;
//        Caffe::set_mode(Caffe::CPU);
//    }
//
//    /* Load the network. */
//    caffe_config_.deploy_file =
//        "/home/chenzhen/Workspace/cpp/Matrix/apps/bin/Debug/unencrypted_models/detection_secondary/deploy.prototxt";
//    caffe_config_.model_file =
//        "/home/chenzhen/Workspace/cpp/Matrix/apps/bin/Debug/unencrypted_models/detection_secondary/car_not_car_train_iter_30000.caffemodel";
//    net_.reset(new Net<float>(caffe_config_.deploy_file, TEST));
//    net_->CopyTrainedLayersFrom(caffe_config_.model_file);
//
////    CHECK_EQ(net_->num_inputs(), 1) << "Network should have exactly one input.";
//    //   CHECK_EQ(net_->num_outputs(), 1)<< "Network should have exactly one output.";
//
//    Blob<float> *input_layer = net_->input_blobs()[0];
//    num_channels_ = input_layer->channels();
////    CHECK(num_channels_ == 3 || num_channels_ == 1)
////    << "Input layer should have 1 or 3 channels.";
//    input_geometry_ = cv::Size(input_layer->width(), input_layer->height());
//    means_ = Mat(input_geometry_, CV_32FC3, Scalar(128, 128, 128));
//    caffe_config_.target_min_size = 400.0;
//    caffe_config_.target_max_size = 600.0;

}

CarOnlyConfirmCaffeDetector::~CarOnlyConfirmCaffeDetector() {
    // TODO Auto-generated destructor stub
}

vector<vector<Detection> > CarOnlyConfirmCaffeDetector::Confirm(
    vector<Mat> imgs, vector<vector<Detection> > &vvbbox) {

    vector<Mat> images;
    int batch_size = imgs.size();

    vector<vector<Detection> > pre_result(batch_size);

    for (int j = 0; j < batch_size; j++) {
        Mat image = imgs[j];
        Mat tmp_img = image;

        detectionNMS(vvbbox[j], 0.2);
//        sort(vvbbox[j].begin(), vvbbox[j].end(), mycmp);
//
//        nms(vvbbox[j], 0.2);

        int tot_left = 0;

        vector<Detection> vbbox = vvbbox[j];
        for (int i = 0; i < vbbox.size(); i++) {
            if ((vbbox[i].box.width * 5 < vbbox[i].box.height)
                || (vbbox[i].box.height * 5 < vbbox[i].box.width)) {
                continue;
            }
            if (!vbbox[i].deleted && vbbox[i].confidence > 0.8) {

                Rect bbox = vbbox[i].box;
                float x = bbox.x;    // / enlarge_ratio;
                float y = bbox.y;    // / enlarge_ratio;
                float w = bbox.width;    // / enlarge_ratio;
                float h = bbox.height;    // / enlarge_ratio;

                x -= w * 0.1;
                y -= h * 0.1;
                w *= 1.2;
                h *= 1.2;

                Rect newbox(x, y, w, h);
                Mat img_rect = image(
                    newbox & Rect(0, 0, image.cols, image.rows));

                resize(img_rect, img_rect, Size(128, 128));
                img_rect = img_rect(Rect(5, 5, 118, 118));
                //vector<Mat> images;
                images.push_back(img_rect);

                x = bbox.x;    // / enlarge_ratio;
                y = bbox.y;    /// enlarge_ratio;
                w = bbox.width;    // / enlarge_ratio;
                h = bbox.height;    /// enlarge_ratio;

                Detection box;

                x = x > 0 ? x : 0;
                y = y > 0 ? y : 0;
                w = (w + x) > image.cols ? (image.cols - x) : w;
                h = (h + y) > image.rows ? (image.rows - y) : h;

                box.box = Rect(x, y, w, h);
                box.confidence = vbbox[i].confidence;
                pre_result[j].push_back(box);
            }
        }
    }
    vector<vector<Detection> > result(batch_size);
    vector<vector<Prediction> > pred;
    pred = ClassifyAutoBatch(images);
    int idx = 0;

    for (int j = 0; j < batch_size; j++) {
        string name;

        for (int i = 0; i < pre_result[j].size(); i++) {
            int cls = pred[idx][0].first == 0 ? 0 : 1;
            float pred_confidence = pred[idx][cls].second;
            float vbbox_confidence = pre_result[j][i].confidence;
            if ((vbbox_confidence > 0.995 && pred_confidence > 0.9)
                || vbbox_confidence > 0.999) {
                Detection car = pre_result[j][i];
                car.id = DETECTION_CAR;
                result[j].push_back(car);
            }
            idx++;

        }

    }
    return result;

}

vector<vector<Prediction> > CarOnlyConfirmCaffeDetector::ClassifyAutoBatch(
    const vector<Mat> &imgs) {
    vector<vector<Prediction> > prediction;
    vector<Mat> images = imgs;
    for (auto batch_images : PrepareBatch(images, caffe_config_.batch_size)) {
        vector<vector<Prediction> > pred = ClassifyBatch(batch_images);
        prediction.insert(prediction.end(), pred.begin(), pred.end());
    }
    int padding_size = (caffe_config_.batch_size
        - imgs.size() % caffe_config_.batch_size)
        % caffe_config_.batch_size;
    prediction.erase(prediction.end() - padding_size, prediction.end());
    return prediction;
}

vector<vector<Prediction> > CarOnlyConfirmCaffeDetector::ClassifyBatch(
    const vector<Mat> &imgs) {
    //return ClassifyBatchDifferentSIze(imgs);
    vector<Blob<float> *> output_layer = PredictBatch(imgs);
    int class_num_ = output_layer[0]->channels();
    const float *begin = output_layer[0]->cpu_data();
    const float *end = begin + output_layer[0]->channels() * imgs.size();
    vector<float> output_batch = std::vector<float>(begin, end);
    std::vector<std::vector<Prediction> > predictions;
    for (int j = 0; j < imgs.size(); j++) {
        std::vector<float> output(
            output_batch.begin() + j * class_num_,
            output_batch.begin() + (j + 1) * class_num_);
        //   std::vector<int> maxN = Argmax(output, class_num_);
        std::vector<Prediction> prediction_single;
        for (int i = 0; i < class_num_; ++i) {
            //     int idx = maxN[i];
            prediction_single.push_back(std::make_pair(i, output[i]));
        }
        predictions.push_back(std::vector<Prediction>(prediction_single));
    }
    return predictions;
}

vector<Blob<float> *> CarOnlyConfirmCaffeDetector::PredictBatch(
    const vector<Mat> imgs) {
    if (!device_setted_) {
        Caffe::SetDevice(caffe_config_.gpu_id);
        device_setted_ = true;
        if (caffe_config_.use_gpu) {
            Caffe::SetDevice(caffe_config_.gpu_id);
            Caffe::set_mode(Caffe::GPU);
            LOG(INFO) << "Use device " << caffe_config_.gpu_id << endl;
        } else {
            LOG(WARNING) << "Use CPU only" << endl;
            Caffe::set_mode(Caffe::CPU);
        }

        /* Load the network. */
        caffe_config_.deploy_file =
            "./unencrypted_models/detection_secondary/deploy.prototxt";
        caffe_config_.model_file =
            "./unencrypted_models/detection_secondary/car_not_car_train_iter_30000.caffemodel";
        net_.reset(new Net<float>(caffe_config_.deploy_file, TEST));
        net_->CopyTrainedLayersFrom(caffe_config_.model_file);

//    CHECK_EQ(net_->num_inputs(), 1) << "Network should have exactly one input.";
        //   CHECK_EQ(net_->num_outputs(), 1)<< "Network should have exactly one output.";

        Blob<float> *input_layer = net_->input_blobs()[0];
        num_channels_ = input_layer->channels();
//    CHECK(num_channels_ == 3 || num_channels_ == 1)
//    << "Input layer should have 1 or 3 channels.";
        input_geometry_ = cv::Size(input_layer->width(), input_layer->height());
        means_ = Mat(input_geometry_, CV_32FC3, Scalar(128, 128, 128));
        caffe_config_.target_min_size = 400.0;
        caffe_config_.target_max_size = 600.0;
    }

    Blob<float> *input_layer = net_->input_blobs()[0];

    input_layer->Reshape(caffe_config_.batch_size, num_channels_, input_geometry_.height,
                         input_geometry_.width);
    /* Forward dimension change to all layers. */
    net_->Reshape();
    std::vector<std::vector<cv::Mat> > input_batch;
    WrapBatchInputLayer(&input_batch);
    PreprocessBatch(imgs, &input_batch);

    net_->ForwardPrefilled();

    if (caffe_config_.use_gpu) {
        cudaDeviceSynchronize();
    }

    /* Copy the output layer to a std::vector */
    vector<Blob<float> *> outputs;
    for (int i = 0; i < net_->num_outputs(); i++) {
        Blob<float> *output_layer = net_->output_blobs()[i];
        outputs.push_back(output_layer);
    }

    return outputs;

}

void CarOnlyConfirmCaffeDetector::WrapBatchInputLayer(
    std::vector<std::vector<cv::Mat> > *input_batch) {
    Blob<float> *input_layer = net_->input_blobs()[0];

    int width = input_layer->width();
    int height = input_layer->height();
    int num = input_layer->num();
    float *input_data = input_layer->mutable_cpu_data();
    for (int j = 0; j < num; j++) {
        vector<cv::Mat> input_channels;
        for (int i = 0; i < input_layer->channels(); ++i) {
            cv::Mat channel(height, width, CV_32FC1, input_data);
            input_channels.push_back(channel);
            input_data += width * height;
        }
        input_batch->push_back(vector<cv::Mat>(input_channels));
    }
    //cv::imshow("bla", input_batch->at(1).at(0));
    //cv::waitKey(1);
}

void CarOnlyConfirmCaffeDetector::PreprocessBatch(
    const vector<cv::Mat> imgs,
    std::vector<std::vector<cv::Mat> > *input_batch) {
    for (int i = 0; i < imgs.size(); i++) {
        cv::Mat img = imgs[i];
        std::vector<cv::Mat> *input_channels = &(input_batch->at(i));

        cv::Mat sample;
        GenerateSample(num_channels_, img, sample);

        /* Convert the input image to the input image format of the network. */
//        cv::Mat sample;
//        if (img.channels() == 3 && num_channels_ == 1)
//            cv::cvtColor(img, sample, CV_BGR2GRAY);
//        else if (img.channels() == 4 && num_channels_ == 1)
//            cv::cvtColor(img, sample, CV_BGRA2GRAY);
//        else if (img.channels() == 4 && num_channels_ == 3)
//            cv::cvtColor(img, sample, CV_BGRA2BGR);
//        else if (img.channels() == 1 && num_channels_ == 3)
//            cv::cvtColor(img, sample, CV_GRAY2BGR);
//        else
//            sample = img;

        cv::Mat sample_resized;
        if (sample.size() != input_geometry_)
            cv::resize(sample, sample_resized, input_geometry_);
        else
            sample_resized = sample;

        cv::Mat sample_float;
        if (num_channels_ == 3)
            sample_resized.convertTo(sample_float, CV_32FC3);
        else
            sample_resized.convertTo(sample_float, CV_32FC1);

        cv::Mat sample_normalized;

        cv::subtract(sample_float, means_, sample_normalized);

        /* This operation will write the separate BGR planes directly to the
         * input layer of the network because it is wrapped by the cv::Mat
         * objects in input_channels. */
        if (rescale_ == 100) {
            cv::addWeighted(sample_normalized, 0.01, sample_normalized, 0, 0,
                            sample_normalized);
        }

        cv::split(sample_normalized, *input_channels);
//        CHECK(reinterpret_ckast<float*>(input_channels->at(0).data)
//              == net_->input_blobs()[0]->cpu_data())
//          << "Input channels are not wrapping the input layer of the network.";
    }
}

}
