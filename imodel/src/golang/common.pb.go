// Code generated by protoc-gen-go.
// source: common.proto
// DO NOT EDIT!

/*
Package dg_model is a generated protocol buffer package.

It is generated from these files:
	common.proto

It has these top-level messages:
	SrcMetadata
	Cutboard
	CutboardImage
	Color
	FeatureVector
	NullMessage
	Image
	RecFace
	NameAndConfidence
	CategoryAndFeature
	PeopleAttr
	RecVehicle
	Passenger
	RecPedestrian
	VehicleModelType
	LicensePlate
	VehicleSymbol
	Symbol
	StorageConfig
	VehicleObj
	PedestrianObj
*/
package dg_model

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

type ObjType int32

const (
	ObjType_OBJ_TYPE_UNKNOWN             ObjType = 0
	ObjType_OBJ_TYPE_CAR                 ObjType = 1
	ObjType_OBJ_TYPE_BICYCLE             ObjType = 2
	ObjType_OBJ_TYPE_TRICYCLE            ObjType = 3
	ObjType_OBJ_TYPE_PEDESTRIAN          ObjType = 4
	ObjType_OBJ_TYPE_FACE                ObjType = 1024
	ObjType_OBJ_TYPE_VEHICLE_VECTOR      ObjType = 2048
	ObjType_OBJ_TYPE_BICYCLE_VECTOR      ObjType = 2049
	ObjType_OBJ_TYPE_TRICYCLE_VECTOR     ObjType = 2050
	ObjType_OBJ_TYPE_PEDESTRIAN_VECTOR   ObjType = 2051
	ObjType_OBJ_TYPE_FACE_VECTOR         ObjType = 3072
	ObjType_OBJ_TYPE_VEHICLE_CUTBOARD    ObjType = 4096
	ObjType_OBJ_TYPE_BICYCLE_CUTBOARD    ObjType = 4097
	ObjType_OBJ_TYPE_TRICYCLE_CUTBOARD   ObjType = 4098
	ObjType_OBJ_TYPE_PEDESTRIAN_CUTBOARD ObjType = 4099
	ObjType_OBJ_TYPE_FACE_CUTBOARD       ObjType = 5120
)

var ObjType_name = map[int32]string{
	0:    "OBJ_TYPE_UNKNOWN",
	1:    "OBJ_TYPE_CAR",
	2:    "OBJ_TYPE_BICYCLE",
	3:    "OBJ_TYPE_TRICYCLE",
	4:    "OBJ_TYPE_PEDESTRIAN",
	1024: "OBJ_TYPE_FACE",
	2048: "OBJ_TYPE_VEHICLE_VECTOR",
	2049: "OBJ_TYPE_BICYCLE_VECTOR",
	2050: "OBJ_TYPE_TRICYCLE_VECTOR",
	2051: "OBJ_TYPE_PEDESTRIAN_VECTOR",
	3072: "OBJ_TYPE_FACE_VECTOR",
	4096: "OBJ_TYPE_VEHICLE_CUTBOARD",
	4097: "OBJ_TYPE_BICYCLE_CUTBOARD",
	4098: "OBJ_TYPE_TRICYCLE_CUTBOARD",
	4099: "OBJ_TYPE_PEDESTRIAN_CUTBOARD",
	5120: "OBJ_TYPE_FACE_CUTBOARD",
}
var ObjType_value = map[string]int32{
	"OBJ_TYPE_UNKNOWN":             0,
	"OBJ_TYPE_CAR":                 1,
	"OBJ_TYPE_BICYCLE":             2,
	"OBJ_TYPE_TRICYCLE":            3,
	"OBJ_TYPE_PEDESTRIAN":          4,
	"OBJ_TYPE_FACE":                1024,
	"OBJ_TYPE_VEHICLE_VECTOR":      2048,
	"OBJ_TYPE_BICYCLE_VECTOR":      2049,
	"OBJ_TYPE_TRICYCLE_VECTOR":     2050,
	"OBJ_TYPE_PEDESTRIAN_VECTOR":   2051,
	"OBJ_TYPE_FACE_VECTOR":         3072,
	"OBJ_TYPE_VEHICLE_CUTBOARD":    4096,
	"OBJ_TYPE_BICYCLE_CUTBOARD":    4097,
	"OBJ_TYPE_TRICYCLE_CUTBOARD":   4098,
	"OBJ_TYPE_PEDESTRIAN_CUTBOARD": 4099,
	"OBJ_TYPE_FACE_CUTBOARD":       5120,
}

func (x ObjType) String() string {
	return proto.EnumName(ObjType_name, int32(x))
}
func (ObjType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

type DataFmtType int32

const (
	DataFmtType_UNKNOWNFMT DataFmtType = 0
	DataFmtType_JSON       DataFmtType = 1
	DataFmtType_PROTOBUF   DataFmtType = 2
	DataFmtType_CSV        DataFmtType = 3
	DataFmtType_PDF        DataFmtType = 4
)

var DataFmtType_name = map[int32]string{
	0: "UNKNOWNFMT",
	1: "JSON",
	2: "PROTOBUF",
	3: "CSV",
	4: "PDF",
}
var DataFmtType_value = map[string]int32{
	"UNKNOWNFMT": 0,
	"JSON":       1,
	"PROTOBUF":   2,
	"CSV":        3,
	"PDF":        4,
}

func (x DataFmtType) String() string {
	return proto.EnumName(DataFmtType_name, int32(x))
}
func (DataFmtType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

type SexType int32

const (
	SexType_SEX_TYPE_UNKNOWN SexType = 0
	SexType_SEX_TYPE_MALE    SexType = 1
	SexType_SEX_TYPE_FEMALE  SexType = 2
)

var SexType_name = map[int32]string{
	0: "SEX_TYPE_UNKNOWN",
	1: "SEX_TYPE_MALE",
	2: "SEX_TYPE_FEMALE",
}
var SexType_value = map[string]int32{
	"SEX_TYPE_UNKNOWN": 0,
	"SEX_TYPE_MALE":    1,
	"SEX_TYPE_FEMALE":  2,
}

func (x SexType) String() string {
	return proto.EnumName(SexType_name, int32(x))
}
func (SexType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{2} }

type NationalType int32

const (
	NationalType_NATIONAL_TYPE_UNKNOWN  NationalType = 0
	NationalType_NATIONAL_TYPE_HAN      NationalType = 1
	NationalType_NATIONAL_TYPE_MINORITY NationalType = 2
)

var NationalType_name = map[int32]string{
	0: "NATIONAL_TYPE_UNKNOWN",
	1: "NATIONAL_TYPE_HAN",
	2: "NATIONAL_TYPE_MINORITY",
}
var NationalType_value = map[string]int32{
	"NATIONAL_TYPE_UNKNOWN":  0,
	"NATIONAL_TYPE_HAN":      1,
	"NATIONAL_TYPE_MINORITY": 2,
}

func (x NationalType) String() string {
	return proto.EnumName(NationalType_name, int32(x))
}
func (NationalType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{3} }

type AgeType int32

const (
	AgeType_AGE_TYPE_UNKNOWN AgeType = 0
	AgeType_AGE_TYPE_LT15    AgeType = 1
	AgeType_AGE_TYPE_1530    AgeType = 2
	AgeType_AGE_TYPE_3050    AgeType = 3
	AgeType_AGE_TYPE_50UP    AgeType = 4
)

var AgeType_name = map[int32]string{
	0: "AGE_TYPE_UNKNOWN",
	1: "AGE_TYPE_LT15",
	2: "AGE_TYPE_1530",
	3: "AGE_TYPE_3050",
	4: "AGE_TYPE_50UP",
}
var AgeType_value = map[string]int32{
	"AGE_TYPE_UNKNOWN": 0,
	"AGE_TYPE_LT15":    1,
	"AGE_TYPE_1530":    2,
	"AGE_TYPE_3050":    3,
	"AGE_TYPE_50UP":    4,
}

func (x AgeType) String() string {
	return proto.EnumName(AgeType_name, int32(x))
}
func (AgeType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{4} }

type DBType int32

const (
	DBType_KAFKA     DBType = 0
	DBType_POSTGRES  DBType = 1
	DBType_FILEIMAGE DBType = 2
)

var DBType_name = map[int32]string{
	0: "KAFKA",
	1: "POSTGRES",
	2: "FILEIMAGE",
}
var DBType_value = map[string]int32{
	"KAFKA":     0,
	"POSTGRES":  1,
	"FILEIMAGE": 2,
}

func (x DBType) String() string {
	return proto.EnumName(DBType_name, int32(x))
}
func (DBType) EnumDescriptor() ([]byte, []int) { return fileDescriptor0, []int{5} }

type SrcMetadata struct {
	Timestamp  int64  `protobuf:"varint,1,opt,name=Timestamp,json=timestamp" json:"Timestamp,omitempty"`
	Duration   int32  `protobuf:"varint,2,opt,name=Duration,json=duration" json:"Duration,omitempty"`
	SensorId   int32  `protobuf:"varint,3,opt,name=SensorId,json=sensorId" json:"SensorId,omitempty"`
	SensorName string `protobuf:"bytes,4,opt,name=SensorName,json=sensorName" json:"SensorName,omitempty"`
	SensorUrl  string `protobuf:"bytes,5,opt,name=SensorUrl,json=sensorUrl" json:"SensorUrl,omitempty"`
	RepoId     int32  `protobuf:"varint,6,opt,name=RepoId,json=repoId" json:"RepoId,omitempty"`
	RepoInfo   string `protobuf:"bytes,7,opt,name=RepoInfo,json=repoInfo" json:"RepoInfo,omitempty"`
}

func (m *SrcMetadata) Reset()                    { *m = SrcMetadata{} }
func (m *SrcMetadata) String() string            { return proto.CompactTextString(m) }
func (*SrcMetadata) ProtoMessage()               {}
func (*SrcMetadata) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{0} }

type Cutboard struct {
	X          uint32  `protobuf:"varint,1,opt,name=X,json=x" json:"X,omitempty"`
	Y          uint32  `protobuf:"varint,2,opt,name=Y,json=y" json:"Y,omitempty"`
	Width      uint32  `protobuf:"varint,3,opt,name=Width,json=width" json:"Width,omitempty"`
	Height     uint32  `protobuf:"varint,4,opt,name=Height,json=height" json:"Height,omitempty"`
	ResWidth   uint32  `protobuf:"varint,5,opt,name=ResWidth,json=resWidth" json:"ResWidth,omitempty"`
	ResHeight  uint32  `protobuf:"varint,6,opt,name=ResHeight,json=resHeight" json:"ResHeight,omitempty"`
	Confidence float32 `protobuf:"fixed32,7,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
}

func (m *Cutboard) Reset()                    { *m = Cutboard{} }
func (m *Cutboard) String() string            { return proto.CompactTextString(m) }
func (*Cutboard) ProtoMessage()               {}
func (*Cutboard) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{1} }

type CutboardImage struct {
	Cutboard *Cutboard `protobuf:"bytes,1,opt,name=Cutboard,json=cutboard" json:"Cutboard,omitempty"`
	Img      *Image    `protobuf:"bytes,2,opt,name=Img,json=img" json:"Img,omitempty"`
}

func (m *CutboardImage) Reset()                    { *m = CutboardImage{} }
func (m *CutboardImage) String() string            { return proto.CompactTextString(m) }
func (*CutboardImage) ProtoMessage()               {}
func (*CutboardImage) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{2} }

func (m *CutboardImage) GetCutboard() *Cutboard {
	if m != nil {
		return m.Cutboard
	}
	return nil
}

func (m *CutboardImage) GetImg() *Image {
	if m != nil {
		return m.Img
	}
	return nil
}

type Color struct {
	ColorId    int32   `protobuf:"varint,1,opt,name=ColorId,json=colorId" json:"ColorId,omitempty"`
	Confidence float32 `protobuf:"fixed32,2,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
	ColorName  string  `protobuf:"bytes,3,opt,name=ColorName,json=colorName" json:"ColorName,omitempty"`
}

func (m *Color) Reset()                    { *m = Color{} }
func (m *Color) String() string            { return proto.CompactTextString(m) }
func (*Color) ProtoMessage()               {}
func (*Color) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{3} }

type FeatureVector struct {
	Id      int64  `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	Feature string `protobuf:"bytes,2,opt,name=Feature,json=feature" json:"Feature,omitempty"`
}

func (m *FeatureVector) Reset()                    { *m = FeatureVector{} }
func (m *FeatureVector) String() string            { return proto.CompactTextString(m) }
func (*FeatureVector) ProtoMessage()               {}
func (*FeatureVector) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{4} }

type NullMessage struct {
}

func (m *NullMessage) Reset()                    { *m = NullMessage{} }
func (m *NullMessage) String() string            { return proto.CompactTextString(m) }
func (*NullMessage) ProtoMessage()               {}
func (*NullMessage) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{5} }

type Image struct {
	Id      string `protobuf:"bytes,1,opt,name=Id,json=id" json:"Id,omitempty"`
	Width   int32  `protobuf:"varint,2,opt,name=Width,json=width" json:"Width,omitempty"`
	Height  int32  `protobuf:"varint,3,opt,name=Height,json=height" json:"Height,omitempty"`
	URI     string `protobuf:"bytes,4,opt,name=URI,json=uRI" json:"URI,omitempty"`
	BinData string `protobuf:"bytes,5,opt,name=BinData,json=binData" json:"BinData,omitempty"`
}

func (m *Image) Reset()                    { *m = Image{} }
func (m *Image) String() string            { return proto.CompactTextString(m) }
func (*Image) ProtoMessage()               {}
func (*Image) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{6} }

type RecFace struct {
	Id         int64          `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	Img        *CutboardImage `protobuf:"bytes,2,opt,name=Img,json=img" json:"Img,omitempty"`
	Features   string         `protobuf:"bytes,3,opt,name=Features,json=features" json:"Features,omitempty"`
	Confidence float32        `protobuf:"fixed32,4,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
}

func (m *RecFace) Reset()                    { *m = RecFace{} }
func (m *RecFace) String() string            { return proto.CompactTextString(m) }
func (*RecFace) ProtoMessage()               {}
func (*RecFace) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{7} }

func (m *RecFace) GetImg() *CutboardImage {
	if m != nil {
		return m.Img
	}
	return nil
}

type NameAndConfidence struct {
	Id         int32   `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	Name       string  `protobuf:"bytes,2,opt,name=Name,json=name" json:"Name,omitempty"`
	Confidence float32 `protobuf:"fixed32,3,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
}

func (m *NameAndConfidence) Reset()                    { *m = NameAndConfidence{} }
func (m *NameAndConfidence) String() string            { return proto.CompactTextString(m) }
func (*NameAndConfidence) ProtoMessage()               {}
func (*NameAndConfidence) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{8} }

type CategoryAndFeature struct {
	Id           int32                `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	CategoryName string               `protobuf:"bytes,2,opt,name=CategoryName,json=categoryName" json:"CategoryName,omitempty"`
	Items        []*NameAndConfidence `protobuf:"bytes,3,rep,name=Items,json=items" json:"Items,omitempty"`
}

func (m *CategoryAndFeature) Reset()                    { *m = CategoryAndFeature{} }
func (m *CategoryAndFeature) String() string            { return proto.CompactTextString(m) }
func (*CategoryAndFeature) ProtoMessage()               {}
func (*CategoryAndFeature) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{9} }

func (m *CategoryAndFeature) GetItems() []*NameAndConfidence {
	if m != nil {
		return m.Items
	}
	return nil
}

type PeopleAttr struct {
	Sex      *NameAndConfidence    `protobuf:"bytes,1,opt,name=Sex,json=sex" json:"Sex,omitempty"`
	Age      *NameAndConfidence    `protobuf:"bytes,2,opt,name=Age,json=age" json:"Age,omitempty"`
	National *NameAndConfidence    `protobuf:"bytes,3,opt,name=National,json=national" json:"National,omitempty"`
	Category []*CategoryAndFeature `protobuf:"bytes,4,rep,name=Category,json=category" json:"Category,omitempty"`
}

func (m *PeopleAttr) Reset()                    { *m = PeopleAttr{} }
func (m *PeopleAttr) String() string            { return proto.CompactTextString(m) }
func (*PeopleAttr) ProtoMessage()               {}
func (*PeopleAttr) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{10} }

func (m *PeopleAttr) GetSex() *NameAndConfidence {
	if m != nil {
		return m.Sex
	}
	return nil
}

func (m *PeopleAttr) GetAge() *NameAndConfidence {
	if m != nil {
		return m.Age
	}
	return nil
}

func (m *PeopleAttr) GetNational() *NameAndConfidence {
	if m != nil {
		return m.National
	}
	return nil
}

func (m *PeopleAttr) GetCategory() []*CategoryAndFeature {
	if m != nil {
		return m.Category
	}
	return nil
}

type RecVehicle struct {
	Id              int64             `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	ModelType       *VehicleModelType `protobuf:"bytes,2,opt,name=ModelType,json=modelType" json:"ModelType,omitempty"`
	Color           *Color            `protobuf:"bytes,3,opt,name=Color,json=color" json:"Color,omitempty"`
	Plate           *LicensePlate     `protobuf:"bytes,4,opt,name=Plate,json=plate" json:"Plate,omitempty"`
	Img             *CutboardImage    `protobuf:"bytes,5,opt,name=Img,json=img" json:"Img,omitempty"`
	Symbols         []*VehicleSymbol  `protobuf:"bytes,6,rep,name=Symbols,json=symbols" json:"Symbols,omitempty"`
	Features        string            `protobuf:"bytes,7,opt,name=Features,json=features" json:"Features,omitempty"`
	VehicleType     ObjType           `protobuf:"varint,8,opt,name=VehicleType,json=vehicleType,enum=dg.model.ObjType" json:"VehicleType,omitempty"`
	VehicleTypeName string            `protobuf:"bytes,9,opt,name=VehicleTypeName,json=vehicleTypeName" json:"VehicleTypeName,omitempty"`
	Plates          []*LicensePlate   `protobuf:"bytes,10,rep,name=Plates,json=plates" json:"Plates,omitempty"`
	Passengers      []*Passenger      `protobuf:"bytes,11,rep,name=Passengers,json=passengers" json:"Passengers,omitempty"`
}

func (m *RecVehicle) Reset()                    { *m = RecVehicle{} }
func (m *RecVehicle) String() string            { return proto.CompactTextString(m) }
func (*RecVehicle) ProtoMessage()               {}
func (*RecVehicle) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{11} }

func (m *RecVehicle) GetModelType() *VehicleModelType {
	if m != nil {
		return m.ModelType
	}
	return nil
}

func (m *RecVehicle) GetColor() *Color {
	if m != nil {
		return m.Color
	}
	return nil
}

func (m *RecVehicle) GetPlate() *LicensePlate {
	if m != nil {
		return m.Plate
	}
	return nil
}

func (m *RecVehicle) GetImg() *CutboardImage {
	if m != nil {
		return m.Img
	}
	return nil
}

func (m *RecVehicle) GetSymbols() []*VehicleSymbol {
	if m != nil {
		return m.Symbols
	}
	return nil
}

func (m *RecVehicle) GetPlates() []*LicensePlate {
	if m != nil {
		return m.Plates
	}
	return nil
}

func (m *RecVehicle) GetPassengers() []*Passenger {
	if m != nil {
		return m.Passengers
	}
	return nil
}

type Passenger struct {
	Id            int64       `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	PassengerAttr *PeopleAttr `protobuf:"bytes,2,opt,name=PassengerAttr,json=passengerAttr" json:"PassengerAttr,omitempty"`
	Face          *RecFace    `protobuf:"bytes,3,opt,name=Face,json=face" json:"Face,omitempty"`
	Driver        bool        `protobuf:"varint,4,opt,name=Driver,json=driver" json:"Driver,omitempty"`
}

func (m *Passenger) Reset()                    { *m = Passenger{} }
func (m *Passenger) String() string            { return proto.CompactTextString(m) }
func (*Passenger) ProtoMessage()               {}
func (*Passenger) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{12} }

func (m *Passenger) GetPassengerAttr() *PeopleAttr {
	if m != nil {
		return m.PassengerAttr
	}
	return nil
}

func (m *Passenger) GetFace() *RecFace {
	if m != nil {
		return m.Face
	}
	return nil
}

type RecPedestrian struct {
	Id         int64          `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	Img        *CutboardImage `protobuf:"bytes,2,opt,name=Img,json=img" json:"Img,omitempty"`
	Confidence float32        `protobuf:"fixed32,3,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
	PedesAttr  *PeopleAttr    `protobuf:"bytes,4,opt,name=PedesAttr,json=pedesAttr" json:"PedesAttr,omitempty"`
	Face       *RecFace       `protobuf:"bytes,5,opt,name=Face,json=face" json:"Face,omitempty"`
}

func (m *RecPedestrian) Reset()                    { *m = RecPedestrian{} }
func (m *RecPedestrian) String() string            { return proto.CompactTextString(m) }
func (*RecPedestrian) ProtoMessage()               {}
func (*RecPedestrian) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{13} }

func (m *RecPedestrian) GetImg() *CutboardImage {
	if m != nil {
		return m.Img
	}
	return nil
}

func (m *RecPedestrian) GetPedesAttr() *PeopleAttr {
	if m != nil {
		return m.PedesAttr
	}
	return nil
}

func (m *RecPedestrian) GetFace() *RecFace {
	if m != nil {
		return m.Face
	}
	return nil
}

type VehicleModelType struct {
	Id          int64   `protobuf:"varint,1,opt,name=Id,json=id" json:"Id,omitempty"`
	BrandId     int32   `protobuf:"varint,2,opt,name=BrandId,json=brandId" json:"BrandId,omitempty"`
	SubBrandId  int32   `protobuf:"varint,3,opt,name=SubBrandId,json=subBrandId" json:"SubBrandId,omitempty"`
	ModelYearId int32   `protobuf:"varint,4,opt,name=ModelYearId,json=modelYearId" json:"ModelYearId,omitempty"`
	Confidence  float32 `protobuf:"fixed32,5,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
	Type        string  `protobuf:"bytes,6,opt,name=Type,json=type" json:"Type,omitempty"`
	Brand       string  `protobuf:"bytes,7,opt,name=Brand,json=brand" json:"Brand,omitempty"`
	SubBrand    string  `protobuf:"bytes,8,opt,name=SubBrand,json=subBrand" json:"SubBrand,omitempty"`
	ModelYear   string  `protobuf:"bytes,9,opt,name=ModelYear,json=modelYear" json:"ModelYear,omitempty"`
	TypeId      int32   `protobuf:"varint,10,opt,name=TypeId,json=typeId" json:"TypeId,omitempty"`
	Model       string  `protobuf:"bytes,11,opt,name=Model,json=model" json:"Model,omitempty"`
	IsHead      int32   `protobuf:"varint,12,opt,name=IsHead,json=isHead" json:"IsHead,omitempty"`
}

func (m *VehicleModelType) Reset()                    { *m = VehicleModelType{} }
func (m *VehicleModelType) String() string            { return proto.CompactTextString(m) }
func (*VehicleModelType) ProtoMessage()               {}
func (*VehicleModelType) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{14} }

type LicensePlate struct {
	PlateText               string    `protobuf:"bytes,1,opt,name=PlateText,json=plateText" json:"PlateText,omitempty"`
	Color                   *Color    `protobuf:"bytes,2,opt,name=Color,json=color" json:"Color,omitempty"`
	TypeId                  int32     `protobuf:"varint,3,opt,name=TypeId,json=typeId" json:"TypeId,omitempty"`
	TypeName                string    `protobuf:"bytes,4,opt,name=TypeName,json=typeName" json:"TypeName,omitempty"`
	Confidence              float32   `protobuf:"fixed32,5,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
	Cutboard                *Cutboard `protobuf:"bytes,6,opt,name=Cutboard,json=cutboard" json:"Cutboard,omitempty"`
	LocalProvinceConfidence float32   `protobuf:"fixed32,7,opt,name=LocalProvinceConfidence,json=localProvinceConfidence" json:"LocalProvinceConfidence,omitempty"`
}

func (m *LicensePlate) Reset()                    { *m = LicensePlate{} }
func (m *LicensePlate) String() string            { return proto.CompactTextString(m) }
func (*LicensePlate) ProtoMessage()               {}
func (*LicensePlate) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{15} }

func (m *LicensePlate) GetColor() *Color {
	if m != nil {
		return m.Color
	}
	return nil
}

func (m *LicensePlate) GetCutboard() *Cutboard {
	if m != nil {
		return m.Cutboard
	}
	return nil
}

type VehicleSymbol struct {
	SymbolId   int32     `protobuf:"varint,1,opt,name=SymbolId,json=symbolId" json:"SymbolId,omitempty"`
	SymbolName string    `protobuf:"bytes,2,opt,name=SymbolName,json=symbolName" json:"SymbolName,omitempty"`
	Symbols    []*Symbol `protobuf:"bytes,3,rep,name=Symbols,json=symbols" json:"Symbols,omitempty"`
}

func (m *VehicleSymbol) Reset()                    { *m = VehicleSymbol{} }
func (m *VehicleSymbol) String() string            { return proto.CompactTextString(m) }
func (*VehicleSymbol) ProtoMessage()               {}
func (*VehicleSymbol) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{16} }

func (m *VehicleSymbol) GetSymbols() []*Symbol {
	if m != nil {
		return m.Symbols
	}
	return nil
}

type Symbol struct {
	Cutboard   *Cutboard `protobuf:"bytes,1,opt,name=Cutboard,json=cutboard" json:"Cutboard,omitempty"`
	Confidence float32   `protobuf:"fixed32,2,opt,name=Confidence,json=confidence" json:"Confidence,omitempty"`
}

func (m *Symbol) Reset()                    { *m = Symbol{} }
func (m *Symbol) String() string            { return proto.CompactTextString(m) }
func (*Symbol) ProtoMessage()               {}
func (*Symbol) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{17} }

func (m *Symbol) GetCutboard() *Cutboard {
	if m != nil {
		return m.Cutboard
	}
	return nil
}

type StorageConfig struct {
	Address string   `protobuf:"bytes,1,opt,name=Address,json=address" json:"Address,omitempty"`
	Type    DBType   `protobuf:"varint,2,opt,name=Type,json=type,enum=dg.model.DBType" json:"Type,omitempty"`
	Tags    []string `protobuf:"bytes,3,rep,name=Tags,json=tags" json:"Tags,omitempty"`
}

func (m *StorageConfig) Reset()                    { *m = StorageConfig{} }
func (m *StorageConfig) String() string            { return proto.CompactTextString(m) }
func (*StorageConfig) ProtoMessage()               {}
func (*StorageConfig) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{18} }

type VehicleObj struct {
	Metadata *SrcMetadata  `protobuf:"bytes,1,opt,name=Metadata,json=metadata" json:"Metadata,omitempty"`
	Img      *Image        `protobuf:"bytes,2,opt,name=Img,json=img" json:"Img,omitempty"`
	Vehicle  []*RecVehicle `protobuf:"bytes,3,rep,name=Vehicle,json=vehicle" json:"Vehicle,omitempty"`
}

func (m *VehicleObj) Reset()                    { *m = VehicleObj{} }
func (m *VehicleObj) String() string            { return proto.CompactTextString(m) }
func (*VehicleObj) ProtoMessage()               {}
func (*VehicleObj) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{19} }

func (m *VehicleObj) GetMetadata() *SrcMetadata {
	if m != nil {
		return m.Metadata
	}
	return nil
}

func (m *VehicleObj) GetImg() *Image {
	if m != nil {
		return m.Img
	}
	return nil
}

func (m *VehicleObj) GetVehicle() []*RecVehicle {
	if m != nil {
		return m.Vehicle
	}
	return nil
}

type PedestrianObj struct {
	Metadata   *SrcMetadata     `protobuf:"bytes,1,opt,name=Metadata,json=metadata" json:"Metadata,omitempty"`
	Img        *Image           `protobuf:"bytes,2,opt,name=Img,json=img" json:"Img,omitempty"`
	Pedestrian []*RecPedestrian `protobuf:"bytes,3,rep,name=Pedestrian,json=pedestrian" json:"Pedestrian,omitempty"`
}

func (m *PedestrianObj) Reset()                    { *m = PedestrianObj{} }
func (m *PedestrianObj) String() string            { return proto.CompactTextString(m) }
func (*PedestrianObj) ProtoMessage()               {}
func (*PedestrianObj) Descriptor() ([]byte, []int) { return fileDescriptor0, []int{20} }

func (m *PedestrianObj) GetMetadata() *SrcMetadata {
	if m != nil {
		return m.Metadata
	}
	return nil
}

func (m *PedestrianObj) GetImg() *Image {
	if m != nil {
		return m.Img
	}
	return nil
}

func (m *PedestrianObj) GetPedestrian() []*RecPedestrian {
	if m != nil {
		return m.Pedestrian
	}
	return nil
}

func init() {
	proto.RegisterType((*SrcMetadata)(nil), "dg.model.SrcMetadata")
	proto.RegisterType((*Cutboard)(nil), "dg.model.Cutboard")
	proto.RegisterType((*CutboardImage)(nil), "dg.model.CutboardImage")
	proto.RegisterType((*Color)(nil), "dg.model.Color")
	proto.RegisterType((*FeatureVector)(nil), "dg.model.FeatureVector")
	proto.RegisterType((*NullMessage)(nil), "dg.model.NullMessage")
	proto.RegisterType((*Image)(nil), "dg.model.Image")
	proto.RegisterType((*RecFace)(nil), "dg.model.RecFace")
	proto.RegisterType((*NameAndConfidence)(nil), "dg.model.NameAndConfidence")
	proto.RegisterType((*CategoryAndFeature)(nil), "dg.model.CategoryAndFeature")
	proto.RegisterType((*PeopleAttr)(nil), "dg.model.PeopleAttr")
	proto.RegisterType((*RecVehicle)(nil), "dg.model.RecVehicle")
	proto.RegisterType((*Passenger)(nil), "dg.model.Passenger")
	proto.RegisterType((*RecPedestrian)(nil), "dg.model.RecPedestrian")
	proto.RegisterType((*VehicleModelType)(nil), "dg.model.VehicleModelType")
	proto.RegisterType((*LicensePlate)(nil), "dg.model.LicensePlate")
	proto.RegisterType((*VehicleSymbol)(nil), "dg.model.VehicleSymbol")
	proto.RegisterType((*Symbol)(nil), "dg.model.Symbol")
	proto.RegisterType((*StorageConfig)(nil), "dg.model.StorageConfig")
	proto.RegisterType((*VehicleObj)(nil), "dg.model.VehicleObj")
	proto.RegisterType((*PedestrianObj)(nil), "dg.model.PedestrianObj")
	proto.RegisterEnum("dg.model.ObjType", ObjType_name, ObjType_value)
	proto.RegisterEnum("dg.model.DataFmtType", DataFmtType_name, DataFmtType_value)
	proto.RegisterEnum("dg.model.SexType", SexType_name, SexType_value)
	proto.RegisterEnum("dg.model.NationalType", NationalType_name, NationalType_value)
	proto.RegisterEnum("dg.model.AgeType", AgeType_name, AgeType_value)
	proto.RegisterEnum("dg.model.DBType", DBType_name, DBType_value)
}

func init() { proto.RegisterFile("common.proto", fileDescriptor0) }

var fileDescriptor0 = []byte{
	// 1695 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x09, 0x6e, 0x88, 0x02, 0xff, 0xb4, 0x58, 0xdd, 0x6e, 0xe3, 0x5a,
	0x15, 0x26, 0x71, 0x1c, 0xdb, 0x2b, 0xc9, 0xa9, 0xeb, 0xe9, 0xb4, 0x99, 0x9e, 0x01, 0x8a, 0x05,
	0xd2, 0x50, 0x41, 0xd5, 0x1f, 0x55, 0x67, 0xe0, 0x2e, 0x4d, 0x93, 0x99, 0x9c, 0x69, 0x93, 0x68,
	0x27, 0xed, 0x4c, 0x25, 0xa4, 0x91, 0x13, 0xbb, 0x69, 0x20, 0x89, 0x83, 0xed, 0xf6, 0xb4, 0xe2,
	0xa6, 0xe7, 0xcc, 0x13, 0xc0, 0x05, 0x97, 0x3c, 0x02, 0x2f, 0x81, 0x90, 0x78, 0x01, 0x2e, 0x79,
	0x00, 0xde, 0x82, 0xb5, 0x97, 0xb7, 0xff, 0x92, 0xd2, 0x0e, 0x42, 0xe7, 0xaa, 0x5e, 0x3f, 0x7b,
	0xad, 0x6f, 0xfd, 0xec, 0xb5, 0x76, 0x0a, 0xe5, 0xa1, 0x3b, 0x9d, 0xba, 0xb3, 0x9d, 0xb9, 0xe7,
	0x06, 0xae, 0xa1, 0xda, 0xa3, 0x9d, 0xa9, 0x6b, 0x3b, 0x13, 0xf3, 0x9f, 0x39, 0x28, 0xf5, 0xbc,
	0xe1, 0xa9, 0x13, 0x58, 0xb6, 0x15, 0x58, 0xc6, 0x4b, 0xd0, 0xfa, 0xe3, 0xa9, 0xe3, 0x07, 0xd6,
	0x74, 0x5e, 0xcd, 0x6d, 0xe5, 0x5e, 0x49, 0x4c, 0x0b, 0x22, 0x86, 0xb1, 0x09, 0xea, 0xf1, 0xb5,
	0x67, 0x05, 0x63, 0x77, 0x56, 0xcd, 0xa3, 0x50, 0x66, 0xaa, 0x2d, 0x68, 0x2e, 0xeb, 0x39, 0x33,
	0xdf, 0xf5, 0x5a, 0x76, 0x55, 0x0a, 0x65, 0xbe, 0xa0, 0x8d, 0x1f, 0x01, 0x84, 0xb2, 0xb6, 0x35,
	0x75, 0xaa, 0x05, 0x94, 0x6a, 0x0c, 0xfc, 0x98, 0xc3, 0xbd, 0x86, 0xf2, 0x33, 0x6f, 0x52, 0x95,
	0x49, 0xac, 0xf9, 0x11, 0xc3, 0x58, 0x87, 0x22, 0x73, 0xe6, 0x2e, 0xda, 0x2d, 0x92, 0xdd, 0xa2,
	0x47, 0x14, 0xf7, 0x48, 0xfc, 0xd9, 0xa5, 0x5b, 0x55, 0xe8, 0x90, 0xea, 0x09, 0xda, 0xfc, 0x6b,
	0x0e, 0xd4, 0xfa, 0x75, 0x30, 0x70, 0x2d, 0xcf, 0x36, 0xca, 0x90, 0xfb, 0x40, 0xc1, 0x54, 0x58,
	0xee, 0x96, 0x53, 0x17, 0x84, 0x1e, 0xa9, 0x3b, 0x63, 0x0d, 0xe4, 0xf7, 0x63, 0x3b, 0xb8, 0x22,
	0xcc, 0x15, 0x26, 0x7f, 0xc3, 0x09, 0xee, 0xf2, 0xad, 0x33, 0x1e, 0x5d, 0x05, 0x04, 0xb6, 0xc2,
	0x8a, 0x57, 0x44, 0x85, 0x2e, 0xfd, 0xf0, 0x80, 0x4c, 0x12, 0x74, 0x19, 0xd2, 0x3c, 0x08, 0x94,
	0x89, 0x63, 0x45, 0x12, 0x6a, 0x5e, 0xc4, 0xe0, 0x29, 0xa8, 0xbb, 0xb3, 0xcb, 0xb1, 0xed, 0xcc,
	0x86, 0x0e, 0xc1, 0xcd, 0x33, 0x18, 0xc6, 0x1c, 0x73, 0x00, 0x95, 0x08, 0x6f, 0x6b, 0x6a, 0x8d,
	0x1c, 0x63, 0x27, 0x09, 0x80, 0xb0, 0x97, 0xf6, 0x8d, 0x9d, 0xa8, 0x6c, 0x3b, 0x91, 0x84, 0xa9,
	0xc3, 0x28, 0xc8, 0x9f, 0x80, 0xd4, 0x9a, 0x8e, 0x28, 0xb0, 0xd2, 0xfe, 0x4a, 0xa2, 0x4a, 0xd6,
	0x98, 0x34, 0x9e, 0x8e, 0xcc, 0x8f, 0x20, 0xd7, 0xdd, 0x89, 0xeb, 0x19, 0x55, 0x50, 0xe8, 0xa3,
	0x15, 0x9a, 0x96, 0x99, 0x32, 0x0c, 0xc9, 0x05, 0x98, 0xf9, 0x45, 0x98, 0x3c, 0x48, 0x3a, 0x49,
	0x85, 0x94, 0xc2, 0x4a, 0x0d, 0x23, 0x86, 0xf9, 0x2b, 0xa8, 0x34, 0x1d, 0x2b, 0xb8, 0xf6, 0x9c,
	0x73, 0x67, 0x18, 0xa0, 0xa3, 0x2f, 0x20, 0x2f, 0x7c, 0x48, 0x2c, 0x3f, 0xb6, 0xb9, 0x63, 0xa1,
	0x40, 0xb6, 0x35, 0xa6, 0x5c, 0x86, 0xa4, 0x59, 0x81, 0x52, 0xfb, 0x7a, 0x32, 0x39, 0x75, 0x7c,
	0x1f, 0xf1, 0x9a, 0xbf, 0x07, 0x39, 0x4c, 0x43, 0x62, 0x41, 0x23, 0x0b, 0x71, 0xbd, 0xc2, 0xfe,
	0x5b, 0xaa, 0x57, 0xd8, 0x7a, 0x51, 0xbd, 0x74, 0x90, 0xce, 0x58, 0x4b, 0x74, 0x9c, 0x74, 0xcd,
	0x5a, 0x1c, 0xc1, 0xd1, 0x78, 0x76, 0x8c, 0xbd, 0x2e, 0x1a, 0x4d, 0x19, 0x84, 0xa4, 0x79, 0x9f,
	0x03, 0x85, 0x39, 0xc3, 0xa6, 0x35, 0x74, 0x96, 0x70, 0xff, 0x3c, 0x9d, 0xdc, 0x8d, 0xe5, 0x3a,
	0x24, 0x49, 0xe6, 0x2d, 0x22, 0x42, 0xf4, 0x45, 0x82, 0x54, 0x11, 0xa3, 0xbf, 0x90, 0xdd, 0xc2,
	0x52, 0x13, 0xbc, 0x87, 0x55, 0x9e, 0xc7, 0xda, 0xcc, 0x4e, 0xd4, 0x52, 0x58, 0x64, 0xc2, 0x62,
	0x40, 0x81, 0xb2, 0x1f, 0x26, 0xb0, 0x30, 0xe3, 0x17, 0x28, 0x6b, 0x58, 0x5a, 0x32, 0xfc, 0x07,
	0x30, 0xea, 0x56, 0xe0, 0x8c, 0x5c, 0xef, 0x0e, 0x8d, 0x0b, 0x7c, 0x4b, 0x96, 0x4d, 0x28, 0x47,
	0x5a, 0x29, 0x0f, 0xe5, 0x61, 0x8a, 0x67, 0xec, 0x61, 0x61, 0x02, 0x67, 0xca, 0x63, 0x93, 0x30,
	0x17, 0x5f, 0x26, 0xb9, 0x58, 0x42, 0xce, 0xe4, 0x31, 0xd7, 0x34, 0xff, 0x95, 0x03, 0xe8, 0x3a,
	0xee, 0x7c, 0xe2, 0xd4, 0x82, 0xc0, 0x33, 0x7e, 0x09, 0x52, 0xcf, 0xb9, 0x15, 0x3d, 0xfd, 0xe8,
	0x79, 0xc9, 0x77, 0x6e, 0xb9, 0x7a, 0x6d, 0xe4, 0x88, 0xd4, 0x3f, 0xae, 0xce, 0xfb, 0xe5, 0x2b,
	0x50, 0xdb, 0x34, 0x90, 0xac, 0x09, 0xe5, 0xe1, 0x89, 0x33, 0xea, 0x4c, 0x28, 0x1b, 0xaf, 0xf1,
	0xbe, 0x89, 0x40, 0xb1, 0x32, 0x3c, 0xb6, 0x97, 0xa9, 0x3a, 0x2f, 0x25, 0x0f, 0x6f, 0x9e, 0xe0,
	0x99, 0xff, 0x96, 0x00, 0xb0, 0x71, 0xce, 0x9d, 0xab, 0xf1, 0x70, 0xb2, 0xdc, 0x3b, 0xaf, 0x41,
	0x3b, 0xe5, 0x46, 0xfa, 0x77, 0xf3, 0x28, 0x8c, 0xcd, 0xc4, 0xb2, 0x38, 0x15, 0x6b, 0x30, 0x6d,
	0x1a, 0x7d, 0x1a, 0x3f, 0x13, 0xf7, 0x55, 0x04, 0x92, 0xba, 0xd4, 0xc4, 0x66, 0x32, 0xdd, 0x3c,
	0xe3, 0x17, 0x20, 0x77, 0x27, 0x08, 0x86, 0x1a, 0xaa, 0xb4, 0xbf, 0x9e, 0xa8, 0x9d, 0x8c, 0x87,
	0x38, 0x45, 0x1d, 0x92, 0x32, 0x79, 0xce, 0xff, 0x44, 0xad, 0x2c, 0x7f, 0x46, 0x2b, 0xef, 0x81,
	0xd2, 0xbb, 0x9b, 0x0e, 0xdc, 0x89, 0x8f, 0xf3, 0x4c, 0xca, 0xaa, 0x0b, 0xdc, 0xa1, 0x9c, 0x29,
	0x7e, 0xa8, 0x97, 0xe9, 0x7e, 0x65, 0xa1, 0xfb, 0x0f, 0xa0, 0x24, 0x4e, 0x51, 0x2a, 0x54, 0x14,
	0x7f, 0xb1, 0xbf, 0x9a, 0x98, 0xec, 0x0c, 0x7e, 0x4b, 0x19, 0x28, 0xdd, 0x24, 0x5a, 0xc6, 0x2b,
	0x58, 0x49, 0x1d, 0xa2, 0xb6, 0xd4, 0xc8, 0xee, 0xca, 0x4d, 0x96, 0x8d, 0x03, 0xb3, 0x48, 0x81,
	0xfa, 0x55, 0x20, 0xb0, 0xff, 0x2d, 0x0f, 0x45, 0xca, 0x03, 0x87, 0x03, 0x5d, 0xcb, 0xc7, 0x35,
	0x33, 0x72, 0x3c, 0xbf, 0x5a, 0xa2, 0x33, 0xcf, 0x92, 0x33, 0xb1, 0x8c, 0xc1, 0x3c, 0x56, 0x33,
	0xff, 0x9c, 0x03, 0x2d, 0x96, 0x2c, 0x95, 0xfa, 0xd7, 0x50, 0x89, 0x85, 0xbc, 0xd7, 0x45, 0xb9,
	0xd7, 0x52, 0x56, 0xe3, 0x7b, 0xc0, 0x2a, 0xf3, 0xb4, 0x2a, 0x16, 0xbb, 0xc0, 0x47, 0x8f, 0xa8,
	0x75, 0x2a, 0x2d, 0x62, 0x26, 0xb1, 0xc2, 0x25, 0x9f, 0x4c, 0x38, 0xe9, 0x8e, 0xbd, 0xf1, 0x8d,
	0xe3, 0x51, 0xb5, 0x55, 0x56, 0xb4, 0x89, 0x32, 0xff, 0x9e, 0x83, 0x0a, 0x6a, 0x76, 0x1d, 0x1b,
	0x77, 0xb5, 0x37, 0xb6, 0x66, 0xff, 0xcf, 0x0c, 0x7b, 0x62, 0x9c, 0x18, 0xfb, 0x98, 0x04, 0xee,
	0x88, 0x62, 0x2c, 0x3c, 0x12, 0xa3, 0x36, 0x8f, 0xd4, 0xe2, 0xf8, 0xe4, 0x47, 0xe3, 0x33, 0xff,
	0x91, 0x07, 0x7d, 0xf1, 0x4e, 0x3c, 0xb4, 0x46, 0x8e, 0x3c, 0x6b, 0x66, 0x23, 0x33, 0x5c, 0x03,
	0xca, 0x20, 0x24, 0xe9, 0xa5, 0x71, 0x3d, 0x88, 0x84, 0xe1, 0x32, 0x00, 0x3f, 0xe6, 0x18, 0x5b,
	0x50, 0x22, 0xb3, 0x17, 0x8e, 0xc5, 0xb7, 0x5f, 0x81, 0x14, 0x4a, 0xd3, 0x84, 0xb5, 0x10, 0xbb,
	0xbc, 0x14, 0x3b, 0x8e, 0x5f, 0x6a, 0xdf, 0x62, 0x38, 0x7e, 0x03, 0x8e, 0x0f, 0x97, 0x12, 0x39,
	0x10, 0x2d, 0x2f, 0x13, 0x1a, 0x7a, 0x11, 0x09, 0xcf, 0xd4, 0xec, 0x78, 0x17, 0x22, 0x24, 0x7c,
	0x8f, 0xc6, 0x38, 0x44, 0x43, 0x6b, 0x31, 0x0a, 0x5e, 0x64, 0xee, 0x03, 0x01, 0x42, 0xb8, 0xce,
	0x02, 0xa2, 0xb8, 0x1f, 0x3a, 0x85, 0xdd, 0x4a, 0x7e, 0xe8, 0x04, 0xd7, 0x6e, 0xe1, 0x33, 0xc3,
	0xb2, 0xab, 0xe5, 0x50, 0x7b, 0x4c, 0x94, 0xf9, 0xc7, 0x3c, 0x94, 0xd3, 0x9d, 0xcf, 0x9d, 0xd2,
	0x47, 0xdf, 0xb9, 0x0d, 0xc4, 0x4a, 0xd5, 0xe6, 0x11, 0x23, 0x99, 0x36, 0xf9, 0x47, 0xa7, 0x4d,
	0x82, 0x4d, 0xca, 0x60, 0xc3, 0x68, 0xe3, 0x1b, 0x1a, 0xee, 0x5b, 0x35, 0x88, 0xae, 0xe6, 0x53,
	0x39, 0x4d, 0xbf, 0x75, 0x8a, 0x9f, 0xf1, 0xd6, 0x79, 0x0d, 0x1b, 0x27, 0xee, 0xd0, 0x9a, 0x74,
	0x3d, 0xf7, 0x66, 0x8c, 0x06, 0x96, 0x5e, 0x56, 0x1b, 0x93, 0x87, 0xc5, 0xe6, 0x37, 0x50, 0xc9,
	0x4c, 0x2e, 0x2a, 0x12, 0x7d, 0xc5, 0x9b, 0x50, 0xf5, 0x05, 0x4d, 0xcd, 0x44, 0xdf, 0xa9, 0x6d,
	0x08, 0x7e, 0xcc, 0x31, 0xb6, 0x93, 0xf9, 0x18, 0x6e, 0x43, 0x3d, 0x41, 0xbd, 0x30, 0x18, 0xcd,
	0x0f, 0x50, 0x14, 0x1e, 0xff, 0xd7, 0x87, 0xdd, 0x13, 0x4f, 0x32, 0x73, 0x08, 0x95, 0x1e, 0xbe,
	0xb5, 0xf0, 0xf2, 0x92, 0xda, 0x88, 0xdf, 0x8e, 0x9a, 0x6d, 0xe3, 0xc4, 0xf5, 0x45, 0x91, 0x15,
	0x2b, 0x24, 0x8d, 0x9f, 0x8a, 0xde, 0xcd, 0xd3, 0xe8, 0x4d, 0xa1, 0x3d, 0x3e, 0xa2, 0xc9, 0x1b,
	0x76, 0x33, 0xef, 0x70, 0x6b, 0x14, 0xc6, 0xc4, 0x3b, 0x1c, 0xbf, 0xcd, 0x3f, 0xe1, 0x0e, 0x17,
	0x89, 0xc3, 0x31, 0x8d, 0x9b, 0x41, 0x8d, 0x7e, 0x32, 0x88, 0x18, 0x9e, 0xa7, 0x42, 0x4f, 0x7e,
	0x4f, 0x30, 0x75, 0x1a, 0xfd, 0xb2, 0x78, 0xfa, 0x7d, 0x8a, 0x99, 0x51, 0x84, 0x0f, 0x91, 0xcf,
	0xb5, 0xcc, 0x94, 0x10, 0x32, 0xa6, 0x88, 0xc9, 0x6f, 0xfe, 0x05, 0x67, 0x5e, 0x32, 0xf0, 0xbe,
	0x3f, 0x5c, 0x5f, 0xf1, 0xf7, 0x4b, 0xe4, 0x46, 0x40, 0xdb, 0xc8, 0x40, 0x4b, 0xc4, 0xb8, 0x2d,
	0xe2, 0xef, 0xed, 0xbf, 0x49, 0xa0, 0x88, 0xad, 0x86, 0x77, 0x57, 0xef, 0x1c, 0x7d, 0xfd, 0xb1,
	0x7f, 0xd1, 0x6d, 0x7c, 0x3c, 0x6b, 0xbf, 0x6b, 0x77, 0xde, 0xb7, 0xf5, 0x1f, 0xe0, 0x03, 0xb5,
	0x1c, 0x73, 0xeb, 0x35, 0xa6, 0xe7, 0x32, 0x7a, 0x47, 0xad, 0xfa, 0x45, 0xfd, 0xa4, 0xa1, 0xe7,
	0x8d, 0xe7, 0xb0, 0x1a, 0x73, 0xfb, 0x4c, 0xb0, 0x25, 0x63, 0x03, 0x9e, 0xc5, 0xec, 0x6e, 0xe3,
	0xb8, 0xd1, 0x43, 0x59, 0xad, 0xad, 0x17, 0xb0, 0x86, 0x95, 0x58, 0xd0, 0xac, 0xd5, 0x1b, 0xfa,
	0xbd, 0x8a, 0xd7, 0x7f, 0x23, 0xe6, 0x9d, 0x37, 0xde, 0xb6, 0xd0, 0x04, 0xfe, 0xad, 0xf7, 0x3b,
	0x4c, 0xbf, 0xd7, 0x33, 0x52, 0xe1, 0x37, 0x92, 0x7e, 0xab, 0x1b, 0x3f, 0x84, 0xea, 0x92, 0xff,
	0x48, 0xfc, 0x9d, 0x6e, 0xfc, 0x18, 0x36, 0x1f, 0xc0, 0x11, 0x29, 0x7c, 0xd2, 0x8d, 0x17, 0xb0,
	0x96, 0xc1, 0x13, 0x3b, 0xae, 0x62, 0x7f, 0xbf, 0x58, 0x82, 0x55, 0x3f, 0xeb, 0x1f, 0x75, 0x6a,
	0xec, 0x58, 0xbf, 0xdf, 0xca, 0xc8, 0x23, 0x60, 0xb1, 0xfc, 0xdb, 0xad, 0x8c, 0xef, 0x18, 0x5a,
	0xac, 0xf0, 0xdd, 0x16, 0x56, 0xf8, 0xe5, 0x43, 0xe0, 0x62, 0x95, 0x4f, 0x5b, 0xc6, 0x97, 0xb0,
	0x9e, 0x85, 0x97, 0x00, 0x78, 0xb5, 0xfd, 0x06, 0x4a, 0xfc, 0x07, 0x42, 0x73, 0x1a, 0x88, 0x65,
	0x04, 0xa2, 0x7e, 0xcd, 0xd3, 0x3e, 0x96, 0x50, 0x85, 0xc2, 0xd7, 0xbd, 0x4e, 0x1b, 0x4b, 0x57,
	0x06, 0xb5, 0xcb, 0x3a, 0xfd, 0xce, 0xd1, 0x59, 0x13, 0x4b, 0xa6, 0x80, 0x54, 0xef, 0x9d, 0x63,
	0x91, 0xf0, 0xa3, 0x7b, 0xdc, 0xd4, 0x0b, 0x68, 0x48, 0xc1, 0x97, 0x6f, 0xd4, 0x0d, 0xbd, 0xc6,
	0x87, 0xc5, 0x6e, 0x58, 0xc5, 0xab, 0x1c, 0x71, 0x4f, 0x6b, 0x58, 0xe1, 0x9c, 0xf1, 0x0c, 0x56,
	0x62, 0x56, 0xb3, 0x41, 0xcc, 0xfc, 0xf6, 0x6f, 0xa0, 0x1c, 0x3d, 0x72, 0xc9, 0xda, 0x0b, 0x78,
	0xde, 0xae, 0xf5, 0x5b, 0x9d, 0x76, 0xed, 0x64, 0xd1, 0x24, 0x36, 0x4e, 0x56, 0xf4, 0xb6, 0xc6,
	0xa1, 0x6e, 0xc2, 0x7a, 0x96, 0x7d, 0xda, 0x6a, 0x77, 0x58, 0xab, 0x7f, 0x81, 0xd6, 0x7f, 0x87,
	0xf3, 0x63, 0xe4, 0x44, 0x30, 0x6b, 0x6f, 0x1a, 0x0f, 0xc0, 0x8c, 0xb9, 0x27, 0xfd, 0xbd, 0x43,
	0xb4, 0x97, 0x66, 0xed, 0x1d, 0x1e, 0xec, 0x62, 0xfc, 0x69, 0xd6, 0xc1, 0xee, 0xe1, 0x2e, 0x66,
	0x22, 0xcd, 0x3a, 0xdc, 0x3d, 0xeb, 0x62, 0x4e, 0x76, 0xf1, 0x3d, 0x43, 0xc3, 0xc7, 0xd0, 0x40,
	0x7e, 0x57, 0x6b, 0xbe, 0xab, 0xa1, 0x03, 0x9e, 0xc8, 0x4e, 0xaf, 0xff, 0x86, 0x35, 0x7a, 0x68,
	0xbb, 0x02, 0x5a, 0xb3, 0x75, 0xd2, 0x68, 0x9d, 0xe2, 0x59, 0x3d, 0x3f, 0x28, 0xd2, 0xff, 0x30,
	0x0e, 0xfe, 0x13, 0x00, 0x00, 0xff, 0xff, 0xce, 0x8f, 0xb4, 0x90, 0xd3, 0x10, 0x00, 0x00,
}
