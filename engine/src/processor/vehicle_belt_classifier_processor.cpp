/*
 * vehicle_marker_classifier_processor.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: jiajaichen
 */

#include <model/alg_config.h>
#include "vehicle_belt_classifier_processor.h"
#include "processor_helper.h"

using namespace dgvehicle;
namespace dg {

VehicleBeltClassifierProcessor::VehicleBeltClassifierProcessor(
    float threshold, bool drive)
    : Processor() {

    belt_classifier_ = AlgorithmFactory::GetInstance()->CreateBeltClassifier(drive);
    threshold_ = threshold;

}
VehicleBeltClassifierProcessor::~VehicleBeltClassifierProcessor() {

    if (belt_classifier_) {
        delete belt_classifier_;
    }
    images_.clear();
}

bool VehicleBeltClassifierProcessor::process(FrameBatch *frameBatch) {

    VLOG(VLOG_RUNTIME_DEBUG) << "Start belt processor " << frameBatch->id() << endl;
    VLOG(VLOG_SERVICE) << "Start belt processor" << frameBatch->id() << endl;
    vector<vector<Prediction> > preds;
    belt_classifier_->BatchProcess(images_, preds);

    for (int i = 0; i < objs_.size(); i++) {
        float value;
        Vehicle *v = (Vehicle *) objs_[i];

        if (preds[i][0].second < threshold_) {
            VLOG(VLOG_RUNTIME_DEBUG)
            << "Belt detection confidence is lower than threshold " << preds[i][0].second << ":" << threshold_ << endl;
            continue;
        }

        switch (preds[i][0].first) {
            case 0: {
                ObjectType driverType = OBJECT_DRIVER;
                if (!is_driver) {
                    driverType = OBJECT_CODRIVER;
                }
                Vehicler *vr = (Vehicler *) v->child(driverType);
                if (!vr) {
                    vr = new Vehicler(driverType);
                    v->set_vehicler(vr);
                }
                value = preds[i][0].second;
                vr->set_vehicler_attr(Vehicler::NoBelt, value);
                break;
            }
            default:
                break;
        }

    }
    objs_.clear();

    VLOG(VLOG_RUNTIME_DEBUG) << "Finish Start belt processor " << frameBatch->id() << endl;
    return true;
}

bool VehicleBeltClassifierProcessor::beforeUpdate(FrameBatch *frameBatch) {

#if DEBUG
#else
    if (performance_ > RECORD_UNIT) {
        if (!RecordFeaturePerformance()) {
            return false;
        }
    }
#endif
    objs_.clear();
    images_.clear();
    vector<Object *> objs;
    if (is_driver) {
        objs = frameBatch->CollectObjects(OPERATION_DRIVER_BELT);
    } else {
        objs = frameBatch->CollectObjects(OPERATION_CODRIVER_BELT);
    }
    vector<Object *>::iterator itr = objs.begin();
    while (itr != objs.end()) {
        Object *obj = *itr;
        if (obj->type() == OBJECT_CAR) {
            for (int i = 0; i < obj->children().size(); i++) {
                Object *obj_child = obj->children()[i];
                if (obj_child->type() == OBJECT_WINDOW) {
                    Window *w = (Window *) obj->children()[i];
                    images_.push_back(w->resized_image());
                    performance_++;
                    objs_.push_back(obj);

                }
            }

        } else {
        }
        ++itr;

    }

    return true;

}

bool VehicleBeltClassifierProcessor::RecordFeaturePerformance() {

    return RecordPerformance(FEATURE_CAR_MARK, performance_);

}
}
