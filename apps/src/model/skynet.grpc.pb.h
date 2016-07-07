// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: skynet.proto
#ifndef GRPC_skynet_2eproto__INCLUDED
#define GRPC_skynet_2eproto__INCLUDED

#include "skynet.pb.h"

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

class SkynetService GRPC_FINAL {
public:
    class StubInterface {
    public:
        virtual ~StubInterface() { }
        virtual ::grpc::Status VideoRecognize(::grpc::ClientContext *context,
                                              const ::dg::model::SkynetRequest &request,
                                              ::dg::model::SkynetResponse *response) = 0;
        std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse>> AsyncVideoRecognize(::grpc::ClientContext *context,
                                                                                                                     const ::dg::model::SkynetRequest &request,
                                                                                                                     ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse>>(
                AsyncVideoRecognizeRaw(context, request, cq));
        }
    private:
        virtual ::grpc::ClientAsyncResponseReaderInterface<::dg::model::SkynetResponse> *AsyncVideoRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::SkynetRequest &request, ::grpc::CompletionQueue *cq) =
            0;
    };
    class Stub GRPC_FINAL: public StubInterface {
    public:
        Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel);
        ::grpc::Status VideoRecognize(::grpc::ClientContext *context,
                                      const ::dg::model::SkynetRequest &request,
                                      ::dg::model::SkynetResponse *response) GRPC_OVERRIDE;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse>> AsyncVideoRecognize(::grpc::ClientContext *context,
                                                                                                            const ::dg::model::SkynetRequest &request,
                                                                                                            ::grpc::CompletionQueue *cq) {
            return std::unique_ptr<::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse>>(
                AsyncVideoRecognizeRaw(context, request, cq));
        }

    private:
        std::shared_ptr<::grpc::ChannelInterface> channel_;
        ::grpc::ClientAsyncResponseReader<::dg::model::SkynetResponse> *AsyncVideoRecognizeRaw
            (::grpc::ClientContext *context, const ::dg::model::SkynetRequest &request, ::grpc::CompletionQueue *cq)
            GRPC_OVERRIDE;
        const ::grpc::RpcMethod rpcmethod_VideoRecognize_;
    };
    static std::unique_ptr<Stub> NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                                         const ::grpc::StubOptions &options = ::grpc::StubOptions());

    class Service: public ::grpc::Service {
    public:
        Service();
        virtual ~Service();
        virtual ::grpc::Status VideoRecognize(::grpc::ServerContext *context,
                                              const ::dg::model::SkynetRequest *request,
                                              ::dg::model::SkynetResponse *response);
    };
    template<class BaseClass>
    class WithAsyncMethod_VideoRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithAsyncMethod_VideoRecognize() {
            ::grpc::Service::MarkMethodAsync(0);
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
            ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    typedef WithAsyncMethod_VideoRecognize<Service> AsyncService;
    template<class BaseClass>
    class WithGenericMethod_VideoRecognize: public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service *service) { }
    public:
        WithGenericMethod_VideoRecognize() {
            ::grpc::Service::MarkMethodGeneric(0);
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
};

}  // namespace model
}  // namespace dg


#endif  // GRPC_skynet_2eproto__INCLUDED
