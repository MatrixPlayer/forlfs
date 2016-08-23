// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: dataservice.proto

#include "dataservice.pb.h"
#include "dataservice.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace model {

static const char* DataService_method_names[] = {
  "/model.DataService/SendData",
  "/model.DataService/SendBatchData",
  "/model.DataService/Search",
};

std::unique_ptr< DataService::Stub> DataService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< DataService::Stub> stub(new DataService::Stub(channel));
  return stub;
}

DataService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SendData_(DataService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SendBatchData_(DataService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Search_(DataService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status DataService::Stub::SendData(::grpc::ClientContext* context, const ::model::DataRequest& request, ::model::DataResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_SendData_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::model::DataResponse>* DataService::Stub::AsyncSendDataRaw(::grpc::ClientContext* context, const ::model::DataRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::model::DataResponse>(channel_.get(), cq, rpcmethod_SendData_, context, request);
}

::grpc::Status DataService::Stub::SendBatchData(::grpc::ClientContext* context, const ::model::BatchDataRequest& request, ::model::DataResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_SendBatchData_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::model::DataResponse>* DataService::Stub::AsyncSendBatchDataRaw(::grpc::ClientContext* context, const ::model::BatchDataRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::model::DataResponse>(channel_.get(), cq, rpcmethod_SendBatchData_, context, request);
}

::grpc::Status DataService::Stub::Search(::grpc::ClientContext* context, const ::model::SearchRequest& request, ::model::DataResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Search_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::model::DataResponse>* DataService::Stub::AsyncSearchRaw(::grpc::ClientContext* context, const ::model::SearchRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::model::DataResponse>(channel_.get(), cq, rpcmethod_Search_, context, request);
}

DataService::Service::Service() {
  (void)DataService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      DataService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< DataService::Service, ::model::DataRequest, ::model::DataResponse>(
          std::mem_fn(&DataService::Service::SendData), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      DataService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< DataService::Service, ::model::BatchDataRequest, ::model::DataResponse>(
          std::mem_fn(&DataService::Service::SendBatchData), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      DataService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< DataService::Service, ::model::SearchRequest, ::model::DataResponse>(
          std::mem_fn(&DataService::Service::Search), this)));
}

DataService::Service::~Service() {
}

::grpc::Status DataService::Service::SendData(::grpc::ServerContext* context, const ::model::DataRequest* request, ::model::DataResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DataService::Service::SendBatchData(::grpc::ServerContext* context, const ::model::BatchDataRequest* request, ::model::DataResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DataService::Service::Search(::grpc::ServerContext* context, const ::model::SearchRequest* request, ::model::DataResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace model
