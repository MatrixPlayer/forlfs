// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: matrix.proto
#ifndef GRPC_matrix_2eproto__INCLUDED
#define GRPC_matrix_2eproto__INCLUDED

#include "matrix.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace dg {
namespace model {

class MatrixService GRPC_FINAL {
public:
    class StubInterface {
    public:
        virtual ~StubInterface() { }
        virtual ::grpc::Status Ping(::grpc::ClientContext *context,
                                    const ::dg::model::PingRequest &request,
                                    ::dg::model::PingResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::PingResponse>> AsyncPing(::grpc::ClientContext *context,
                                                                                                         const ::dg::model::PingRequest &request,
                                                                                                         ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::PingResponse>>(AsyncPingRaw(
                context,
                request,
                cq));
        }
        virtual ::grpc::Status SystemStatus(::grpc::ClientContext *context,
                                            const ::dg::model::SystemStatusRequest &request,
                                            ::dg::model::SystemStatusResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SystemStatusResponse>> AsyncSystemStatus(
            ::grpc::ClientContext *context,
            const ::dg::model::SystemStatusRequest &request,
            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SystemStatusResponse>>(
                AsyncSystemStatusRaw(context, request, cq));
        }
        virtual ::grpc::Status GetInstances(::grpc::ClientContext *context,
                                            const ::dg::model::GetInstancesRequest &request,
                                            ::dg::model::InstanceConfigureResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse>> AsyncGetInstances(
            ::grpc::ClientContext *context,
            const ::dg::model::GetInstancesRequest &request,
            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse>>(
                AsyncGetInstancesRaw(context, request, cq));
        }
        virtual ::grpc::Status ConfigEngine(::grpc::ClientContext *context,
                                            const ::dg::model::InstanceConfigureRequest &request,
                                            ::dg::model::InstanceConfigureResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse>> AsyncConfigEngine(
            ::grpc::ClientContext *context,
            const ::dg::model::InstanceConfigureRequest &request,
            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse>>(
                AsyncConfigEngineRaw(context, request, cq));
        }
        virtual ::grpc::Status Recognize(::grpc::ClientContext *context,
                                         const ::dg::model::WitnessRequest &request,
                                         ::dg::model::WitnessResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessResponse>> AsyncRecognize(::grpc::ClientContext *context,
                                                                                                                 const ::dg::model::WitnessRequest &request,
                                                                                                                 ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessResponse>>(
                AsyncRecognizeRaw(context, request, cq));
        }
        virtual ::grpc::Status BatchRecognize(::grpc::ClientContext *context,
                                              const ::dg::model::WitnessBatchRequest &request,
                                              ::dg::model::WitnessBatchResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessBatchResponse>> AsyncBatchRecognize(
            ::grpc::ClientContext *context,
            const ::dg::model::WitnessBatchRequest &request,
            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessBatchResponse>>(
                AsyncBatchRecognizeRaw(context, request, cq));
        }
        virtual ::grpc::Status VideoRecognize(::grpc::ClientContext *context,
                                              const ::dg::model::SkynetRequest &request,
                                              ::dg::model::SkynetResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse>> AsyncVideoRecognize(::grpc::ClientContext *context,
                                                                                                                     const ::dg::model::SkynetRequest &request,
                                                                                                                     ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse>>(
                AsyncVideoRecognizeRaw(context, request, cq));
        }
        virtual ::grpc::Status GetRankedVector(::grpc::ClientContext *context,
                                               const ::dg::model::FeatureRankingRequest &request,
                                               ::dg::model::FeatureRankingResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::FeatureRankingResponse>> AsyncGetRankedVector(
            ::grpc::ClientContext *context,
            const ::dg::model::FeatureRankingRequest &request,
            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::FeatureRankingResponse>>(
                AsyncGetRankedVectorRaw(context, request, cq));
        }
    private:
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::PingResponse> *AsyncPingRaw
            (::grpc::ClientContext *context, const ::dg::model::PingRequest &request, ::grpc::CompletionQueue *cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::SystemStatusResponse> *AsyncSystemStatusRaw
            (::grpc::ClientContext *context,
             const ::dg::model::SystemStatusRequest &request,
             ::grpc::CompletionQueue *cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse> *AsyncGetInstancesRaw
            (::grpc::ClientContext *context,
             const ::dg::model::GetInstancesRequest &request,
             ::grpc::CompletionQueue *cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::InstanceConfigureResponse> *AsyncConfigEngineRaw
            (::grpc::ClientContext *context,
             const ::dg::model::InstanceConfigureRequest &request,
             ::grpc::CompletionQueue *cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessResponse> *AsyncRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::WitnessRequest &request, ::grpc::CompletionQueue *cq) =
            0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::WitnessBatchResponse> *AsyncBatchRecognizeRaw
            (::grpc::ClientContext *context,
             const ::dg::model::WitnessBatchRequest &request,
             ::grpc::CompletionQueue *cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse> *AsyncVideoRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::SkynetRequest &request, ::grpc::CompletionQueue *cq) =
            0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::FeatureRankingResponse> *AsyncGetRankedVectorRaw
            (::grpc::ClientContext *context,
             const ::dg::model::FeatureRankingRequest &request,
             ::grpc::CompletionQueue *cq) = 0;
    };
    class Stub GRPC_FINAL: public StubInterface {
    public:
        Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel);
        ::grpc::Status Ping(::grpc::ClientContext *context,
                            const ::dg::model::PingRequest &request,
                            ::dg::model::PingResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::PingResponse>> AsyncPing(::grpc::ClientContext *context,
                                                                                                const ::dg::model::PingRequest &request,
                                                                                                ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::PingResponse>>(AsyncPingRaw(context,
                                                                                                              request,
                                                                                                              cq));
        }
        ::grpc::Status SystemStatus(::grpc::ClientContext *context,
                                    const ::dg::model::SystemStatusRequest &request,
                                    ::dg::model::SystemStatusResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SystemStatusResponse>> AsyncSystemStatus(::grpc::ClientContext *context,
                                                                                                                const ::dg::model::SystemStatusRequest &request,
                                                                                                                ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SystemStatusResponse>>(
                AsyncSystemStatusRaw(context, request, cq));
        }
        ::grpc::Status GetInstances(::grpc::ClientContext *context,
                                    const ::dg::model::GetInstancesRequest &request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse>> AsyncGetInstances(::grpc::ClientContext *context,
                                                                                                                     const ::dg::model::GetInstancesRequest &request,
                                                                                                                     ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse>>(
                AsyncGetInstancesRaw(context, request, cq));
        }
        ::grpc::Status ConfigEngine(::grpc::ClientContext *context,
                                    const ::dg::model::InstanceConfigureRequest &request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse>> AsyncConfigEngine(::grpc::ClientContext *context,
                                                                                                                     const ::dg::model::InstanceConfigureRequest &request,
                                                                                                                     ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse>>(
                AsyncConfigEngineRaw(context, request, cq));
        }
        ::grpc::Status Recognize(::grpc::ClientContext *context,
                                 const ::dg::model::WitnessRequest &request,
                                 ::dg::model::WitnessResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::WitnessResponse>> AsyncRecognize(::grpc::ClientContext *context,
                                                                                                        const ::dg::model::WitnessRequest &request,
                                                                                                        ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::WitnessResponse>>(AsyncRecognizeRaw(
                context,
                request,
                cq));
        }
        ::grpc::Status BatchRecognize(::grpc::ClientContext *context,
                                      const ::dg::model::WitnessBatchRequest &request,
                                      ::dg::model::WitnessBatchResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::WitnessBatchResponse>> AsyncBatchRecognize(::grpc::ClientContext *context,
                                                                                                                  const ::dg::model::WitnessBatchRequest &request,
                                                                                                                  ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::WitnessBatchResponse>>(
                AsyncBatchRecognizeRaw(context, request, cq));
        }
        ::grpc::Status VideoRecognize(::grpc::ClientContext *context,
                                      const ::dg::model::SkynetRequest &request,
                                      ::dg::model::SkynetResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse>> AsyncVideoRecognize(::grpc::ClientContext *context,
                                                                                                            const ::dg::model::SkynetRequest &request,
                                                                                                            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse>>(
                AsyncVideoRecognizeRaw(context, request, cq));
        }
        ::grpc::Status GetRankedVector(::grpc::ClientContext *context,
                                       const ::dg::model::FeatureRankingRequest &request,
                                       ::dg::model::FeatureRankingResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::FeatureRankingResponse>> AsyncGetRankedVector(::grpc::ClientContext *context,
                                                                                                                     const ::dg::model::FeatureRankingRequest &request,
                                                                                                                     ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::FeatureRankingResponse>>(
                AsyncGetRankedVectorRaw(context, request, cq));
        }

    private:
        std::shared_ptr<::grpc::ChannelInterface> channel_;
        ::grpc::ClientAsyncResponseReader<::dg::model::PingResponse> *AsyncPingRaw
            (::grpc::ClientContext *context, const ::dg::model::PingRequest &request, ::grpc::CompletionQueue *cq)
            GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::SystemStatusResponse> *AsyncSystemStatusRaw
            (::grpc::ClientContext *context,
             const ::dg::model::SystemStatusRequest &request,
             ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse> *AsyncGetInstancesRaw
            (::grpc::ClientContext *context,
             const ::dg::model::GetInstancesRequest &request,
             ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::InstanceConfigureResponse> *AsyncConfigEngineRaw
            (::grpc::ClientContext *context,
             const ::dg::model::InstanceConfigureRequest &request,
             ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::WitnessResponse> *AsyncRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::WitnessRequest &request, ::grpc::CompletionQueue *cq)
            GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::WitnessBatchResponse> *AsyncBatchRecognizeRaw
            (::grpc::ClientContext *context,
             const ::dg::model::WitnessBatchRequest &request,
             ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse> *AsyncVideoRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::SkynetRequest &request, ::grpc::CompletionQueue *cq)
            GRPC_OVERRIDE;
        ::grpc::ClientAsyncResponseReader<::dg::model::FeatureRankingResponse> *AsyncGetRankedVectorRaw
            (::grpc::ClientContext *context,
             const ::dg::model::FeatureRankingRequest &request,
             ::grpc::CompletionQueue *cq) GRPC_OVERRIDE;
        const ::grpc::RpcMethod rpcmethod_Ping_;
        const ::grpc::RpcMethod rpcmethod_SystemStatus_;
        const ::grpc::RpcMethod rpcmethod_GetInstances_;
        const ::grpc::RpcMethod rpcmethod_ConfigEngine_;
        const ::grpc::RpcMethod rpcmethod_Recognize_;
        const ::grpc::RpcMethod rpcmethod_BatchRecognize_;
        const ::grpc::RpcMethod rpcmethod_VideoRecognize_;
        const ::grpc::RpcMethod rpcmethod_GetRankedVector_;
    };
    static std::unique_ptr<Stub> NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                                         const ::grpc::StubOptions &options = ::grpc::StubOptions());

    class Service: public ::grpc::Service {
    public:
        Service();
        virtual ~Service();
        virtual ::grpc::Status Ping(::grpc::ServerContext *context,
                                    const ::dg::model::PingRequest *request,
                                    ::dg::model::PingResponse *response);
        virtual ::grpc::Status SystemStatus(::grpc::ServerContext *context,
                                            const ::dg::model::SystemStatusRequest *request,
                                            ::dg::model::SystemStatusResponse *response);
        virtual ::grpc::Status GetInstances(::grpc::ServerContext *context,
                                            const ::dg::model::GetInstancesRequest *request,
                                            ::dg::model::InstanceConfigureResponse *response);
        virtual ::grpc::Status ConfigEngine(::grpc::ServerContext *context,
                                            const ::dg::model::InstanceConfigureRequest *request,
                                            ::dg::model::InstanceConfigureResponse *response);
        virtual ::grpc::Status Recognize(::grpc::ServerContext *context,
                                         const ::dg::model::WitnessRequest *request,
                                         ::dg::model::WitnessResponse *response);
        virtual ::grpc::Status BatchRecognize(::grpc::ServerContext *context,
                                              const ::dg::model::WitnessBatchRequest *request,
                                              ::dg::model::WitnessBatchResponse *response);
        virtual ::grpc::Status VideoRecognize(::grpc::ServerContext *context,
                                              const ::dg::model::SkynetRequest *request,
                                              ::dg::model::SkynetResponse *response);
        virtual ::grpc::Status GetRankedVector(::grpc::ServerContext *context,
                                               const ::dg::model::FeatureRankingRequest *request,
                                               ::dg::model::FeatureRankingResponse *response);
    };
    template<class BaseClass>
    class WithAsyncMethod_Ping: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_Ping() {
            ::grpc::Service::MarkMethodAsync(0);
        }
        ~WithAsyncMethod_Ping() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Ping(::grpc::ServerContext *context,
                            const ::dg::model::PingRequest *request,
                            ::dg::model::PingResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestPing(::grpc::ServerContext *context,
                         ::dg::model::PingRequest *request,
                         ::grpc::ServerAsyncResponseWriter<::dg::model::PingResponse> *response,
                         ::grpc::CompletionQueue *new_call_cq,
                         ::grpc::ServerCompletionQueue *notification_cq,
                         void *tag) {
            ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_SystemStatus: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_SystemStatus() {
            ::grpc::Service::MarkMethodAsync(1);
        }
        ~WithAsyncMethod_SystemStatus() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status SystemStatus(::grpc::ServerContext *context,
                                    const ::dg::model::SystemStatusRequest *request,
                                    ::dg::model::SystemStatusResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestSystemStatus(::grpc::ServerContext *context,
                                 ::dg::model::SystemStatusRequest *request,
                                 ::grpc::ServerAsyncResponseWriter<::dg::model::SystemStatusResponse> *response,
                                 ::grpc::CompletionQueue *new_call_cq,
                                 ::grpc::ServerCompletionQueue *notification_cq,
                                 void *tag) {
            ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_GetInstances: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_GetInstances() {
            ::grpc::Service::MarkMethodAsync(2);
        }
        ~WithAsyncMethod_GetInstances() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status GetInstances(::grpc::ServerContext *context,
                                    const ::dg::model::GetInstancesRequest *request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestGetInstances(::grpc::ServerContext *context,
                                 ::dg::model::GetInstancesRequest *request,
                                 ::grpc::ServerAsyncResponseWriter<::dg::model::InstanceConfigureResponse> *response,
                                 ::grpc::CompletionQueue *new_call_cq,
                                 ::grpc::ServerCompletionQueue *notification_cq,
                                 void *tag) {
            ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_ConfigEngine: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_ConfigEngine() {
            ::grpc::Service::MarkMethodAsync(3);
        }
        ~WithAsyncMethod_ConfigEngine() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status ConfigEngine(::grpc::ServerContext *context,
                                    const ::dg::model::InstanceConfigureRequest *request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestConfigEngine(::grpc::ServerContext *context,
                                 ::dg::model::InstanceConfigureRequest *request,
                                 ::grpc::ServerAsyncResponseWriter<::dg::model::InstanceConfigureResponse> *response,
                                 ::grpc::CompletionQueue *new_call_cq,
                                 ::grpc::ServerCompletionQueue *notification_cq,
                                 void *tag) {
            ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_Recognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_Recognize() {
            ::grpc::Service::MarkMethodAsync(4);
        }
        ~WithAsyncMethod_Recognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Recognize(::grpc::ServerContext *context,
                                 const ::dg::model::WitnessRequest *request,
                                 ::dg::model::WitnessResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestRecognize(::grpc::ServerContext *context,
                              ::dg::model::WitnessRequest *request,
                              ::grpc::ServerAsyncResponseWriter<::dg::model::WitnessResponse> *response,
                              ::grpc::CompletionQueue *new_call_cq,
                              ::grpc::ServerCompletionQueue *notification_cq,
                              void *tag) {
            ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_BatchRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_BatchRecognize() {
            ::grpc::Service::MarkMethodAsync(5);
        }
        ~WithAsyncMethod_BatchRecognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status BatchRecognize(::grpc::ServerContext *context,
                                      const ::dg::model::WitnessBatchRequest *request,
                                      ::dg::model::WitnessBatchResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestBatchRecognize(::grpc::ServerContext *context,
                                   ::dg::model::WitnessBatchRequest *request,
                                   ::grpc::ServerAsyncResponseWriter<::dg::model::WitnessBatchResponse> *response,
                                   ::grpc::CompletionQueue *new_call_cq,
                                   ::grpc::ServerCompletionQueue *notification_cq,
                                   void *tag) {
            ::grpc::Service::RequestAsyncUnary(5, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_VideoRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_VideoRecognize() {
            ::grpc::Service::MarkMethodAsync(6);
        }
        ~WithAsyncMethod_VideoRecognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status VideoRecognize(::grpc::ServerContext *context,
                                      const ::dg::model::SkynetRequest *request,
                                      ::dg::model::SkynetResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestVideoRecognize(::grpc::ServerContext *context,
                                   ::dg::model::SkynetRequest *request,
                                   ::grpc::ServerAsyncResponseWriter<::dg::model::SkynetResponse> *response,
                                   ::grpc::CompletionQueue *new_call_cq,
                                   ::grpc::ServerCompletionQueue *notification_cq,
                                   void *tag) {
            ::grpc::Service::RequestAsyncUnary(6, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass>
    class WithAsyncMethod_GetRankedVector: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_GetRankedVector() {
            ::grpc::Service::MarkMethodAsync(7);
        }
        ~WithAsyncMethod_GetRankedVector() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status GetRankedVector(::grpc::ServerContext *context,
                                       const ::dg::model::FeatureRankingRequest *request,
                                       ::dg::model::FeatureRankingResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestGetRankedVector(::grpc::ServerContext *context,
                                    ::dg::model::FeatureRankingRequest *request,
                                    ::grpc::ServerAsyncResponseWriter<::dg::model::FeatureRankingResponse> *response,
                                    ::grpc::CompletionQueue *new_call_cq,
                                    ::grpc::ServerCompletionQueue *notification_cq,
                                    void *tag) {
            ::grpc::Service::RequestAsyncUnary(7, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    typedef WithAsyncMethod_Ping<WithAsyncMethod_SystemStatus<WithAsyncMethod_GetInstances<WithAsyncMethod_ConfigEngine<
        WithAsyncMethod_Recognize<WithAsyncMethod_BatchRecognize<WithAsyncMethod_VideoRecognize<
            WithAsyncMethod_GetRankedVector<Service> > > > > > > > AsyncService;
    template<class BaseClass>
    class WithGenericMethod_Ping: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_Ping() {
            ::grpc::Service::MarkMethodGeneric(0);
        }
        ~WithGenericMethod_Ping() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Ping(::grpc::ServerContext *context,
                            const ::dg::model::PingRequest *request,
                            ::dg::model::PingResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_SystemStatus: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_SystemStatus() {
            ::grpc::Service::MarkMethodGeneric(1);
        }
        ~WithGenericMethod_SystemStatus() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status SystemStatus(::grpc::ServerContext *context,
                                    const ::dg::model::SystemStatusRequest *request,
                                    ::dg::model::SystemStatusResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_GetInstances: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_GetInstances() {
            ::grpc::Service::MarkMethodGeneric(2);
        }
        ~WithGenericMethod_GetInstances() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status GetInstances(::grpc::ServerContext *context,
                                    const ::dg::model::GetInstancesRequest *request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_ConfigEngine: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_ConfigEngine() {
            ::grpc::Service::MarkMethodGeneric(3);
        }
        ~WithGenericMethod_ConfigEngine() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status ConfigEngine(::grpc::ServerContext *context,
                                    const ::dg::model::InstanceConfigureRequest *request,
                                    ::dg::model::InstanceConfigureResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_Recognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_Recognize() {
            ::grpc::Service::MarkMethodGeneric(4);
        }
        ~WithGenericMethod_Recognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Recognize(::grpc::ServerContext *context,
                                 const ::dg::model::WitnessRequest *request,
                                 ::dg::model::WitnessResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_BatchRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_BatchRecognize() {
            ::grpc::Service::MarkMethodGeneric(5);
        }
        ~WithGenericMethod_BatchRecognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status BatchRecognize(::grpc::ServerContext *context,
                                      const ::dg::model::WitnessBatchRequest *request,
                                      ::dg::model::WitnessBatchResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_VideoRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_VideoRecognize() {
            ::grpc::Service::MarkMethodGeneric(6);
        }
        ~WithGenericMethod_VideoRecognize() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status VideoRecognize(::grpc::ServerContext *context,
                                      const ::dg::model::SkynetRequest *request,
                                      ::dg::model::SkynetResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass>
    class WithGenericMethod_GetRankedVector: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_GetRankedVector() {
            ::grpc::Service::MarkMethodGeneric(7);
        }
        ~WithGenericMethod_GetRankedVector() GRPC_OVERRIDE {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status GetRankedVector(::grpc::ServerContext *context,
                                       const ::dg::model::FeatureRankingRequest *request,
                                       ::dg::model::FeatureRankingResponse *response) GRPC_FINAL GRPC_OVERRIDE {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
};

}  // namespace model
}  // namespace dg


#endif  // GRPC_matrix_2eproto__INCLUDED
