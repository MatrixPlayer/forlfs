#include <string>
#include <memory>
#include <iostream>
#include <glog/logging.h>
#include <grpc++/grpc++.h>
#include <curl/curl.h>
#include "config.h"
#include "grpc/witness_grpc.h"
#include "grpc/ranker_grpc.h"
#include "watchdog/watch_dog.h"
#include "restful/witness_restful.h"
#include "restful/ranker_restful.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


using namespace std;
using namespace dg;
#if DEBUG
extern "C" void __gcov_flush();
static void dump_coverage(int signal) {
   __gcov_flush();
}
#endif
#define BOOST_SPIRIT_THREADSAFE

string getServerAddress(Config *config, int userPort = 0) {
    if (userPort != 0) {
        cout << "Use command line port instead of config file value" << endl;
        config->AddEntry("System/Port", AnyConversion(userPort));
    }

    return (string) config->Value("System/Ip") + ":"
        + (string) config->Value("System/Port");
}

void serveWitness(Config *config, int userPort = 0) {

    MatrixEnginesPool<WitnessEngine> *engine_pool = MatrixEnginesPool<WitnessEngine>::GetInstance();
    engine_pool->Run(config);

    string protocolType = (string) config->Value("ProtocolType");

    cout << "Protocol type: " << protocolType << endl;
    string address = getServerAddress(config, userPort);

    WitnessBucket::Instance().SetMaxSize(100);
    SpringGrpcClientImpl *client = new SpringGrpcClientImpl(*config);
    std::thread springTh(&SpringGrpcClientImpl::Run, client);

    if (protocolType == "restful") {

        RestfulService *service = new RestWitnessServiceImpl(*config, address);
        service->Run();

    } else if (protocolType == "rpc") {

        GrpcWitnessServiceImpl *witness_service = new GrpcWitnessServiceImpl(*config, address);
        std::thread witness_thread(&GrpcWitnessServiceImpl::Run, witness_service);
        witness_thread.join();

    }
    else if (protocolType == "restful|rpc" || protocolType == "rpc|restful") {
        GrpcWitnessServiceImpl *grpc_witness_service = new GrpcWitnessServiceImpl(*config, address);
        std::thread grpc_witness_thread(&GrpcWitnessServiceImpl::Run, grpc_witness_service);

        string restful_addr = getServerAddress(config, (int) config->Value("System/Port") + 1);
        RestWitnessServiceImpl *rest_witness_service = new RestWitnessServiceImpl(*config,restful_addr);
        std::thread rest_witness_thread(&RestWitnessServiceImpl::Run, rest_witness_service);

        grpc_witness_thread.join();
        rest_witness_thread.join();
    }

    else {
        cout << "Invalid protocol, should be rpc, restful or rpc|restful"
            << endl;
        exit(-1);
    }
    springTh.join();
    //  network_th_.join();
}

void serveRanker(Config *config, int userPort = 0) {

    MatrixEnginesPool<RankEngine> *engine_pool = MatrixEnginesPool<RankEngine>::GetInstance();
    engine_pool->Run(config);

    string protocolType = (string) config->Value("ProtocolType");
    cout << "Protocol type: " << protocolType << endl;

    string address = getServerAddress(config, userPort);

    if (protocolType == "restful") {
        RestRankerServiceImpl *service = new RestRankerServiceImpl(*config,
                                                                   address);
        service->Run();
    } else if (protocolType == "rpc") {

        GrpcRankerServiceImpl *grpc_ranker_service = new GrpcRankerServiceImpl(*config,
                                                                               address);
        std::thread grpc_ranker_thread(&GrpcRankerServiceImpl::Run, grpc_ranker_service);
        grpc_ranker_thread.join();

    } else if (protocolType == "restful|rpc" || protocolType == "rpc|restful") {
        GrpcRankerServiceImpl *grpc_ranker_service = new GrpcRankerServiceImpl(*config,
                                                                               address);
        std::thread grpc_ranker_thread(&GrpcRankerServiceImpl::Run, grpc_ranker_service);
        string rest_ranker_addr = getServerAddress(config,
                                                   (int) config->Value("System/Port") + 1);
        RestRankerServiceImpl *rest_ranker_service = new RestRankerServiceImpl(*config,
                                                                               rest_ranker_addr);
        std::thread rest_ranker_thread(&RestRankerServiceImpl::Run, rest_ranker_service);

        grpc_ranker_thread.join();
        rest_ranker_thread.join();
    }

    else {
        cout << "Invalid protocol, should be rpc, restful or rpc|restful"
            << endl;
        exit(-1);
    }
}

DEFINE_int32(port, 0,
             "Service port number, will overwite the value defined in config file");
DEFINE_string(config, "config.json", "Config file path");
DEFINE_bool(showconfig, false, "Show config file content");
DEFINE_bool(encrypt, false, "Use the encrype data, only valid in DEBUG mode");


int main(int argc, char *argv[]) {
#if false
    if (signal(SIGINT, dump_coverage) == SIG_ERR) {
        fputs("An error occurred while setting a signal handler.\n", stderr);
        return EXIT_FAILURE;
    }
#endif
    google::InitGoogleLogging(argv[0]);

    google::SetUsageMessage(
        "Usage: " + string(argv[0])
            + " [--port=6500] [--config=config.json] [--encrypt=false (valid only in DEBUG mode)]");

    google::SetVersionString("0.2.4");
    google::ParseCommandLineFlags(&argc, &argv, false);



    // init curl in the main thread
    // see https://curl.haxx.se/libcurl/c/curl_easy_init.html
    curl_global_init(CURL_GLOBAL_ALL);

    Config *config = new Config();

    config->Load(FLAGS_config);
    config->AddEntry(DEBUG_MODEL_ENCRYPT, AnyConversion(true));

#ifdef DEBUG
    if (FLAGS_encrypt) {
        config->AddEntry(DEBUG_MODEL_ENCRYPT, AnyConversion(true));
#endif
        StartDogMonitor();
        if (CheckHardware())
            return -1;
#ifdef DEBUG
    } else {
        // in DEBUG mode, encrypt is false in default
        config->AddEntry(DEBUG_MODEL_ENCRYPT, AnyConversion(false));
    }
#endif

    if (FLAGS_showconfig) {
        config->DumpValues();
    }

    string instType = (string) config->Value("InstanceType");

    if (instType == "witness") {

        serveWitness(config, FLAGS_port);
    }
    else if (instType == "ranker") {
        serveRanker(config, FLAGS_port);
    }
    else {
        cout << "Invalid instance type , should be either witness or ranker."
            << endl;
        return -1;
    }

    return 0;
}
