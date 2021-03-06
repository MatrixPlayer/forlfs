/*
 * config_val.h
 *
 *  Created on: Apr 25, 2016
 *      Author: chenzhen
 */

#ifndef CONFIG_VAL_H_
#define CONFIG_VAL_H_

#include <string>

using namespace std;

namespace dg {

static const string VEHICLE_MODEL_MAPPING_FILE = "Render/Vehicle/Model";
static const string VEHICLE_COLOR_MAPPING_FILE = "Render/Vehicle/Color";
static const string VEHICLE_SYMBOL_MAPPING_FILE = "Render/Vehicle/Symbol";
static const string VEHICLE_PLATE_COLOR_MAPPING_FILE =
    "Render/Vehicle/Plate/Color";
static const string VEHICLE_PLATE_TYPE_MAPPING_FILE =
    "Render/Vehicle/Plate/Type";
static const string VEHICLE_TYPE_MAPPING_FILE = "Render/Vehicle/Type";
static const string PEDESTRIAN_ATTR_TYPE = "Render/Pedestrian/PedestrianAttr";
static const string PEDESTRIAN_ATTR_CATAGORY = "Render/Pedestrian/PedestrianCategory";
static const string NONMOTORVEHICLE_ATTR_TYPE = "Render/NonMotorVehicle/NonMotorAttr";
static const string NONMOTORVEHICLE_ATTR_CATEGORY = "Render/NonMotorVehicle/NonMotorCategory";
static const string BODY_RELATIVE_FACE_LEFT = "Advanced/FaceDetect/BodyRelativeFaceLeft";
static const string BODY_RELATIVE_FACE_RIGHT = "Advanced/FaceDetect/BodyRelativeFaceRight";
static const string BODY_RELATIVE_FACE_TOP = "Advanced/FaceDetect/BodyRelativeFaceTop";
static const string BODY_RELATIVE_FACE_BOTTOM = "Advanced/FaceDetect/BodyRelativeFaceBottom";

//static const string SYSTEM_GPU_NUM = "System/GpuNum";
//static const string SYSTEM_THREADS_PER_GPU = "System/ThreadsPerGpu";

static const string SYSTEM_THREADS = "System/Threads";

static const string VERSION_MODEL = "Version/Model";
static const string SERVICE_MODEL = "Version/Code";

static const string RENDER_VEHICLE_TYPE = "Render/Vehicle/Type";
static const string RENDER_VEHICLE_MODEL = "Render/Vehicle/Model";
static const string RENDER_VEHICLE_COLOR = "Render/Vehicle/Color";
static const string RENDER_VEHICLE_SYMBOL = "Render/Vehicle/Symbol";
static const string RENDER_VEHICLE_PLATE_COLOR = "Render/Vehicle/Plate/Color";
static const string RENDER_VEHICLE_PLATE_GPU_COLOR = "Render/Vehicle/Plate/ColorGpu";
static const string RENDER_VEHICLE_PLATE_TYPE = "Render/Vehicle/Plate/Type";
static const string STORAGE_ADDRESS = "Storage/Address";
static const string STORAGE_ENABLED = "Storage/Enabled";
static const string STORAGE_DB_TYPE = "Storage/DBType";
static const string IS_GPU_PLATE = "Feature/Vehicle/EnableGpuPlate";
static const string ENABLE_CUTBOARD = "Debug/EnableCutboard";
static const string PARSE_IMAGE_TIMEOUT = "Advanced/ParseImageTimeout";
static const string NO_BELT = "NoBelt";
static const string PHONE = "Phone";

static const string PACK_BATCHSIZE = "Pack/BatchSize";
static const string PACK_TIMEOUT = "Pack/TimeOut";
static const string PACK_ENABLE = "Pack/Enable";
static const int BEHAVIOR = 11;
}

#endif /* CONFIG_VAL_H_ */
