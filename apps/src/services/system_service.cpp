/*
 * system_service.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: jiajiachen
 */

#include "system_service.h"
namespace dg {
SystemAppsService::SystemAppsService(const Config *config, string name, int baseId) {
    config_ = config;
    name_ = name;
    initNetworkThread();
    modelversion_ = (string) config_->Value(VERSION_MODEL);
    serviceversion_ = (string) config_->Value(SERVICE_MODEL);
}
SystemAppsService::~SystemAppsService() {

}
MatrixError SystemAppsService::Ping(const PingRequest *request,
                                    PingResponse *response) {
    MatrixError err;
    response->set_message("Normal");
    return err;
}

//MatrixError SystemAppsService::Version(const VersionRequest *request, VersionResponse *reponse) {
//	MatrixError err;
//	stringstream ss;
//#ifdef CODEVERSION
//    ss << CODEVERSION;
//    reponse->set_codeversion(ss.str());
//#else
//	reponse->set_codeversion("");
//#endif
//
//#ifdef MODELVERSION
//    ss.str("");
//	ss << MODELVERSION;
//    reponse->set_modelversion(ss.str());
//#else
//	reponse->set_modelversion("");
//#endif
//    return err;
//}

void SystemAppsService::initNetworkThread() {
    //   std::thread network_th_(networkInfo, &rx_, &tx_);
    //  network_th_.detach();
}

MatrixError SystemAppsService::SystemStatus(const SystemStatusRequest *request,
        SystemStatusResponse *response) {
    MatrixError err;
    std::string msgCpuUsage;
    std::string msgMemTotal;
    std::string msgMemAvailable;
    std::string msgDiskAvailable;
    std::string msgDiskUsed;
    std::string msgDiskTotal;
    std::string msgGpuMemUsage;
    std::string msgGpuMemTotal;
    std::string msgNetworkRecv;
    std::string msgNetworkSend;

    response->set_modelver(modelversion_);
    response->set_servicever(serviceversion_);
    if (getCpuUsage(msgCpuUsage)) {
        response->set_cpuusage(msgCpuUsage);
    } else {
        err.set_code(-1);
        err.set_message("Can't get cpu usage");
        return err;
    }
    if (getMemInfo(msgMemTotal, "MemTotal")) {
        response->set_totalmem(msgMemTotal);
    } else {
        err.set_code(-1);
        err.set_message("Can't get total memory");
        return err;
    }
    if (getMemInfo(msgMemAvailable, "MemAvailable:")) {
        response->set_availmem(msgMemAvailable);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getDiskInfo(msgDiskAvailable, "Available")) {
        response->set_availdisk(msgDiskAvailable);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getDiskInfo(msgDiskUsed, "Used")) {
        int total = atoi(msgDiskUsed.c_str()) + atoi(msgDiskAvailable.c_str());
        response->set_totaldisk(to_string(total));
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getGPUMemory(msgGpuMemUsage, "Used")) {
        response->set_gpuusage(msgGpuMemUsage);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getGPUMemory(msgGpuMemTotal, "Total")) {
        response->set_gputotalmem(msgGpuMemTotal);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getNetworkInfo(msgNetworkRecv, "RX")) {
        response->set_netiorecv(msgNetworkRecv);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    if (getNetworkInfo(msgNetworkSend, "TX")) {
        response->set_netiosend(msgNetworkSend);
    } else {
        err.set_code(-1);
        err.set_message("Can't get avaliable memory");
        return err;
    }
    return err;

}


MatrixError SystemAppsService::GetInstances(
    const GetInstancesRequest *request,
    InstanceConfigureResponse *response) {
    MatrixError err;
    return err;
}

MatrixError SystemAppsService::ConfigEngine(
    const InstanceConfigureRequest *request,
    InstanceConfigureResponse *response) {
    MatrixError err;
    return err;
}

}
