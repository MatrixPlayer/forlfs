//
// Created by chenzhen on 7/18/16.
//

#ifndef PROJECT_REPO_SERVICE_H
#define PROJECT_REPO_SERVICE_H

#include <string>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include "config.h"
#include "string_util.h"
#include "../config/config_val.h"
#include "witness.grpc.pb.h"
#include "matrix_engine/model/model.h"

#define DEFAULT_INT_VALUE -1

using namespace std;
using namespace ::dg::model;

namespace dg {

class RepoService {
 public:
    static RepoService &GetInstance() {
        static RepoService instance;
        return instance;
    }

    void Init(const Config &config);


    MatrixError Index(const IndexRequest *request,
                      IndexResponse *response);
    MatrixError IndexTxt(const IndexTxtRequest *request,
                         IndexTxtResponse *response);

    MatrixError FillModel(const Vehicle &vobj, RecVehicle *vrec);
    MatrixError FillModel(NonMotorVehicle &vobj,
                          RecNonMotorVehicle *vrec);
    MatrixError FillColor(const Vehicle::Color &color, Color *rcolor);
    MatrixError FillPlates(const vector<Vehicle::Plate> &plate, RecVehicle *vrec);
    MatrixError FillPassengers(const vector<Object *> &plate, RecVehicle *vrec);

    MatrixError FillSymbols(const vector<Object *> &objects,
                            RecVehicle *vrec);
    string FindVehicleTypeName(ObjectType type) {
        return lookup_string(vehicle_type_repo_, type);
    }
    string FindPedestrianAttrName(int attrId) {
        return lookup_string(pedestrian_attr_type_repo_, attrId);
    }

    const vector<unsigned int> &GetVehicleIsHeadRepo() const {
        return vehicle_is_head_repo;
    }


    float FindBodyRelativeFace(string dir) {
        if (dir == "left") return pBodyRelativeFaceLeft;
        if (dir == "right") return pBodyRelativeFaceRight;
        if (dir == "top") return pBodyRelativeFaceTop;
        if (dir == "bottom") return pBodyRelativeFaceBottom;
        return 0.0;
    }

    string FindPedestrianAttrCatagory(int attrId) {
        return lookup_string(pedestrian_attr_catagory_repo_, attrId);
    }

    string FindNonMotorAttrName(int attrId) {
        return lookup_string(nonMotor_attr_mapping_repo_, attrId);
    }

    string FindNonMotorAttrCategory(int attrId) {
        return lookup_string(nonMotor_attr_category_repo_, attrId);
    }

    static void CopyCutboard(const Detection &b, Cutboard *cb) {
        cb->set_x(b.box().x);
        cb->set_y(b.box().y);
        cb->set_width(b.box().width);
        cb->set_height(b.box().height);
        cb->set_confidence(b.confidence);
    }

 private:
    RepoService();


    static bool is_init_;

    //repo list
    string unknown_string_;
    VehicleModelType unknown_vehicle_;
    vector<VehicleModelType> vehicle_repo_;
    vector<unsigned int> vehicle_is_head_repo;
    vector<string> car_type_repo_;
    vector<string> vehicle_type_repo_;
    vector<string> color_repo_;
    vector<string> plate_color_repo_;
    vector<string> plate_type_repo_;
    vector<string> plate_color_gpu_repo_;
    string model_mapping_data_;
    string color_mapping_data_;
    string symbol_mapping_data_;
    string plate_color_mapping_data_;
    string plate_type_mapping_data_;
    string vehicle_type_mapping_data_;
    //string plate_color_gpu_mapping_data_;
    vector<string> pedestrian_attr_type_repo_;
    vector<string> pedestrian_attr_catagory_repo_;
    vector<string> nonMotor_attr_mapping_repo_;
    vector<string> nonMotor_attr_category_repo_;
    vector<pair<int, string> > symbol_repo_;
    string pedestrian_attr_mapping_data_;
    string pedestrian_attr_catagory_data_;
    string nonMotor_attr_mapping_data_;
    string nonMotor_attr_category_data_;
    float pBodyRelativeFaceLeft;
    float pBodyRelativeFaceRight;
    float pBodyRelativeFaceTop;
    float pBodyRelativeFaceBottom;
    bool is_gpu_plate_;

    const string &lookup_string(const vector<string> &array, int index);
    const pair<int, string> &lookup_int_string(const vector<pair<int, string> > &array, int index);

    const VehicleModelType &lookup_vehicle(const vector<VehicleModelType> &array,
                                           int index);
    void init_string_map(string filename, string sep, vector<string> &array);
    void init_int_string_map(string filename, vector<pair<int, string> > &array);

    void init_vehicle_map(string filename, string sep,
                          vector<VehicleModelType> &array);

//    int parseInt(string str) {
//        return std::stoi(trimString(str), nullptr, 10);
//    }
//
//    float parseFloat(string str) {
//        return std::stof(trimString(str), nullptr);
//    }
//
//    string trimString(string str) {
//        str.erase(0, str.find_first_not_of(" \n\r\t"));  //prefixing spaces
//        str.erase(str.find_last_not_of(" \n\r\t") + 1);   //surfixing spaces
//        return str;
//    }

    void filterPlateType(string color, string plateNum, int &type);
    static void resetModel(RecVehicle *vrec) {
        VehicleModelType *mType = vrec->mutable_modeltype();
        mType->set_id(DEFAULT_INT_VALUE);
        mType->set_brandid(DEFAULT_INT_VALUE);
        mType->set_subbrandid(DEFAULT_INT_VALUE);
        mType->set_modelyearid(DEFAULT_INT_VALUE);
        mType->set_typeid_(DEFAULT_INT_VALUE);
        mType->set_ishead(DEFAULT_INT_VALUE);
        Color *color = vrec->mutable_color();
        color->set_colorid(DEFAULT_INT_VALUE);
        vrec->mutable_plate()->set_typeid_(DEFAULT_INT_VALUE);
        vrec->mutable_plate()->mutable_color()->set_colorid(DEFAULT_INT_VALUE);
        vrec->set_vehicletype(OBJ_TYPE_UNKNOWN);
    }

};

}
#endif //PROJECT_REPO_SERVICE_H
