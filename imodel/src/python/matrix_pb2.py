# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: matrix.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import system_pb2 as system__pb2
import witness_pb2 as witness__pb2
import skynet_pb2 as skynet__pb2
import ranker_pb2 as ranker__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='matrix.proto',
  package='dg.model',
  syntax='proto3',
  serialized_pb=_b('\n\x0cmatrix.proto\x12\x08\x64g.model\x1a\x0csystem.proto\x1a\rwitness.proto\x1a\x0cskynet.proto\x1a\x0cranker.proto2\x80\x05\n\rMatrixService\x12\x37\n\x04Ping\x12\x15.dg.model.PingRequest\x1a\x16.dg.model.PingResponse\"\x00\x12O\n\x0cSystemStatus\x12\x1d.dg.model.SystemStatusRequest\x1a\x1e.dg.model.SystemStatusResponse\"\x00\x12T\n\x0cGetInstances\x12\x1d.dg.model.GetInstancesRequest\x1a#.dg.model.InstanceConfigureResponse\"\x00\x12Y\n\x0c\x43onfigEngine\x12\".dg.model.InstanceConfigureRequest\x1a#.dg.model.InstanceConfigureResponse\"\x00\x12\x42\n\tRecognize\x12\x18.dg.model.WitnessRequest\x1a\x19.dg.model.WitnessResponse\"\x00\x12Q\n\x0e\x42\x61tchRecognize\x12\x1d.dg.model.WitnessBatchRequest\x1a\x1e.dg.model.WitnessBatchResponse\"\x00\x12\x45\n\x0eVideoRecognize\x12\x17.dg.model.SkynetRequest\x1a\x18.dg.model.SkynetResponse\"\x00\x12V\n\x0fGetRankedVector\x12\x1f.dg.model.FeatureRankingRequest\x1a .dg.model.FeatureRankingResponse\"\x00\x62\x06proto3')
  ,
  dependencies=[system__pb2.DESCRIPTOR,witness__pb2.DESCRIPTOR,skynet__pb2.DESCRIPTOR,ranker__pb2.DESCRIPTOR,])
_sym_db.RegisterFileDescriptor(DESCRIPTOR)





import grpc
from grpc.beta import implementations as beta_implementations
from grpc.beta import interfaces as beta_interfaces
from grpc.framework.common import cardinality
from grpc.framework.interfaces.face import utilities as face_utilities


class MatrixServiceStub(object):

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.Ping = channel.unary_unary(
        '/dg.model.MatrixService/Ping',
        request_serializer=system__pb2.PingRequest.SerializeToString,
        response_deserializer=system__pb2.PingResponse.FromString,
        )
    self.SystemStatus = channel.unary_unary(
        '/dg.model.MatrixService/SystemStatus',
        request_serializer=system__pb2.SystemStatusRequest.SerializeToString,
        response_deserializer=system__pb2.SystemStatusResponse.FromString,
        )
    self.GetInstances = channel.unary_unary(
        '/dg.model.MatrixService/GetInstances',
        request_serializer=system__pb2.GetInstancesRequest.SerializeToString,
        response_deserializer=system__pb2.InstanceConfigureResponse.FromString,
        )
    self.ConfigEngine = channel.unary_unary(
        '/dg.model.MatrixService/ConfigEngine',
        request_serializer=system__pb2.InstanceConfigureRequest.SerializeToString,
        response_deserializer=system__pb2.InstanceConfigureResponse.FromString,
        )
    self.Recognize = channel.unary_unary(
        '/dg.model.MatrixService/Recognize',
        request_serializer=witness__pb2.WitnessRequest.SerializeToString,
        response_deserializer=witness__pb2.WitnessResponse.FromString,
        )
    self.BatchRecognize = channel.unary_unary(
        '/dg.model.MatrixService/BatchRecognize',
        request_serializer=witness__pb2.WitnessBatchRequest.SerializeToString,
        response_deserializer=witness__pb2.WitnessBatchResponse.FromString,
        )
    self.VideoRecognize = channel.unary_unary(
        '/dg.model.MatrixService/VideoRecognize',
        request_serializer=skynet__pb2.SkynetRequest.SerializeToString,
        response_deserializer=skynet__pb2.SkynetResponse.FromString,
        )
    self.GetRankedVector = channel.unary_unary(
        '/dg.model.MatrixService/GetRankedVector',
        request_serializer=ranker__pb2.FeatureRankingRequest.SerializeToString,
        response_deserializer=ranker__pb2.FeatureRankingResponse.FromString,
        )


class MatrixServiceServicer(object):

  def Ping(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def SystemStatus(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def GetInstances(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def ConfigEngine(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def Recognize(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def BatchRecognize(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def VideoRecognize(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def GetRankedVector(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_MatrixServiceServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'Ping': grpc.unary_unary_rpc_method_handler(
          servicer.Ping,
          request_deserializer=system__pb2.PingRequest.FromString,
          response_serializer=system__pb2.PingResponse.SerializeToString,
      ),
      'SystemStatus': grpc.unary_unary_rpc_method_handler(
          servicer.SystemStatus,
          request_deserializer=system__pb2.SystemStatusRequest.FromString,
          response_serializer=system__pb2.SystemStatusResponse.SerializeToString,
      ),
      'GetInstances': grpc.unary_unary_rpc_method_handler(
          servicer.GetInstances,
          request_deserializer=system__pb2.GetInstancesRequest.FromString,
          response_serializer=system__pb2.InstanceConfigureResponse.SerializeToString,
      ),
      'ConfigEngine': grpc.unary_unary_rpc_method_handler(
          servicer.ConfigEngine,
          request_deserializer=system__pb2.InstanceConfigureRequest.FromString,
          response_serializer=system__pb2.InstanceConfigureResponse.SerializeToString,
      ),
      'Recognize': grpc.unary_unary_rpc_method_handler(
          servicer.Recognize,
          request_deserializer=witness__pb2.WitnessRequest.FromString,
          response_serializer=witness__pb2.WitnessResponse.SerializeToString,
      ),
      'BatchRecognize': grpc.unary_unary_rpc_method_handler(
          servicer.BatchRecognize,
          request_deserializer=witness__pb2.WitnessBatchRequest.FromString,
          response_serializer=witness__pb2.WitnessBatchResponse.SerializeToString,
      ),
      'VideoRecognize': grpc.unary_unary_rpc_method_handler(
          servicer.VideoRecognize,
          request_deserializer=skynet__pb2.SkynetRequest.FromString,
          response_serializer=skynet__pb2.SkynetResponse.SerializeToString,
      ),
      'GetRankedVector': grpc.unary_unary_rpc_method_handler(
          servicer.GetRankedVector,
          request_deserializer=ranker__pb2.FeatureRankingRequest.FromString,
          response_serializer=ranker__pb2.FeatureRankingResponse.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'dg.model.MatrixService', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))


class BetaMatrixServiceServicer(object):
  def Ping(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def SystemStatus(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def GetInstances(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def ConfigEngine(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def Recognize(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def BatchRecognize(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def VideoRecognize(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)
  def GetRankedVector(self, request, context):
    context.code(beta_interfaces.StatusCode.UNIMPLEMENTED)


class BetaMatrixServiceStub(object):
  def Ping(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  Ping.future = None
  def SystemStatus(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  SystemStatus.future = None
  def GetInstances(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  GetInstances.future = None
  def ConfigEngine(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  ConfigEngine.future = None
  def Recognize(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  Recognize.future = None
  def BatchRecognize(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  BatchRecognize.future = None
  def VideoRecognize(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  VideoRecognize.future = None
  def GetRankedVector(self, request, timeout, metadata=None, with_call=False, protocol_options=None):
    raise NotImplementedError()
  GetRankedVector.future = None


def beta_create_MatrixService_server(servicer, pool=None, pool_size=None, default_timeout=None, maximum_timeout=None):
  request_deserializers = {
    ('dg.model.MatrixService', 'BatchRecognize'): witness__pb2.WitnessBatchRequest.FromString,
    ('dg.model.MatrixService', 'ConfigEngine'): system__pb2.InstanceConfigureRequest.FromString,
    ('dg.model.MatrixService', 'GetInstances'): system__pb2.GetInstancesRequest.FromString,
    ('dg.model.MatrixService', 'GetRankedVector'): ranker__pb2.FeatureRankingRequest.FromString,
    ('dg.model.MatrixService', 'Ping'): system__pb2.PingRequest.FromString,
    ('dg.model.MatrixService', 'Recognize'): witness__pb2.WitnessRequest.FromString,
    ('dg.model.MatrixService', 'SystemStatus'): system__pb2.SystemStatusRequest.FromString,
    ('dg.model.MatrixService', 'VideoRecognize'): skynet__pb2.SkynetRequest.FromString,
  }
  response_serializers = {
    ('dg.model.MatrixService', 'BatchRecognize'): witness__pb2.WitnessBatchResponse.SerializeToString,
    ('dg.model.MatrixService', 'ConfigEngine'): system__pb2.InstanceConfigureResponse.SerializeToString,
    ('dg.model.MatrixService', 'GetInstances'): system__pb2.InstanceConfigureResponse.SerializeToString,
    ('dg.model.MatrixService', 'GetRankedVector'): ranker__pb2.FeatureRankingResponse.SerializeToString,
    ('dg.model.MatrixService', 'Ping'): system__pb2.PingResponse.SerializeToString,
    ('dg.model.MatrixService', 'Recognize'): witness__pb2.WitnessResponse.SerializeToString,
    ('dg.model.MatrixService', 'SystemStatus'): system__pb2.SystemStatusResponse.SerializeToString,
    ('dg.model.MatrixService', 'VideoRecognize'): skynet__pb2.SkynetResponse.SerializeToString,
  }
  method_implementations = {
    ('dg.model.MatrixService', 'BatchRecognize'): face_utilities.unary_unary_inline(servicer.BatchRecognize),
    ('dg.model.MatrixService', 'ConfigEngine'): face_utilities.unary_unary_inline(servicer.ConfigEngine),
    ('dg.model.MatrixService', 'GetInstances'): face_utilities.unary_unary_inline(servicer.GetInstances),
    ('dg.model.MatrixService', 'GetRankedVector'): face_utilities.unary_unary_inline(servicer.GetRankedVector),
    ('dg.model.MatrixService', 'Ping'): face_utilities.unary_unary_inline(servicer.Ping),
    ('dg.model.MatrixService', 'Recognize'): face_utilities.unary_unary_inline(servicer.Recognize),
    ('dg.model.MatrixService', 'SystemStatus'): face_utilities.unary_unary_inline(servicer.SystemStatus),
    ('dg.model.MatrixService', 'VideoRecognize'): face_utilities.unary_unary_inline(servicer.VideoRecognize),
  }
  server_options = beta_implementations.server_options(request_deserializers=request_deserializers, response_serializers=response_serializers, thread_pool=pool, thread_pool_size=pool_size, default_timeout=default_timeout, maximum_timeout=maximum_timeout)
  return beta_implementations.server(method_implementations, options=server_options)


def beta_create_MatrixService_stub(channel, host=None, metadata_transformer=None, pool=None, pool_size=None):
  request_serializers = {
    ('dg.model.MatrixService', 'BatchRecognize'): witness__pb2.WitnessBatchRequest.SerializeToString,
    ('dg.model.MatrixService', 'ConfigEngine'): system__pb2.InstanceConfigureRequest.SerializeToString,
    ('dg.model.MatrixService', 'GetInstances'): system__pb2.GetInstancesRequest.SerializeToString,
    ('dg.model.MatrixService', 'GetRankedVector'): ranker__pb2.FeatureRankingRequest.SerializeToString,
    ('dg.model.MatrixService', 'Ping'): system__pb2.PingRequest.SerializeToString,
    ('dg.model.MatrixService', 'Recognize'): witness__pb2.WitnessRequest.SerializeToString,
    ('dg.model.MatrixService', 'SystemStatus'): system__pb2.SystemStatusRequest.SerializeToString,
    ('dg.model.MatrixService', 'VideoRecognize'): skynet__pb2.SkynetRequest.SerializeToString,
  }
  response_deserializers = {
    ('dg.model.MatrixService', 'BatchRecognize'): witness__pb2.WitnessBatchResponse.FromString,
    ('dg.model.MatrixService', 'ConfigEngine'): system__pb2.InstanceConfigureResponse.FromString,
    ('dg.model.MatrixService', 'GetInstances'): system__pb2.InstanceConfigureResponse.FromString,
    ('dg.model.MatrixService', 'GetRankedVector'): ranker__pb2.FeatureRankingResponse.FromString,
    ('dg.model.MatrixService', 'Ping'): system__pb2.PingResponse.FromString,
    ('dg.model.MatrixService', 'Recognize'): witness__pb2.WitnessResponse.FromString,
    ('dg.model.MatrixService', 'SystemStatus'): system__pb2.SystemStatusResponse.FromString,
    ('dg.model.MatrixService', 'VideoRecognize'): skynet__pb2.SkynetResponse.FromString,
  }
  cardinalities = {
    'BatchRecognize': cardinality.Cardinality.UNARY_UNARY,
    'ConfigEngine': cardinality.Cardinality.UNARY_UNARY,
    'GetInstances': cardinality.Cardinality.UNARY_UNARY,
    'GetRankedVector': cardinality.Cardinality.UNARY_UNARY,
    'Ping': cardinality.Cardinality.UNARY_UNARY,
    'Recognize': cardinality.Cardinality.UNARY_UNARY,
    'SystemStatus': cardinality.Cardinality.UNARY_UNARY,
    'VideoRecognize': cardinality.Cardinality.UNARY_UNARY,
  }
  stub_options = beta_implementations.stub_options(host=host, metadata_transformer=metadata_transformer, request_serializers=request_serializers, response_deserializers=response_deserializers, thread_pool=pool, thread_pool_size=pool_size)
  return beta_implementations.dynamic_stub(channel, 'dg.model.MatrixService', cardinalities, options=stub_options)
# @@protoc_insertion_point(module_scope)