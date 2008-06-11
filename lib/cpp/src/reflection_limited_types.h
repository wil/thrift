/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef reflection_limited_TYPES_H
#define reflection_limited_TYPES_H

#include <Thrift.h>
#include <reflection_limited_types.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace facebook { namespace thrift { namespace reflection { namespace limited {

enum TTypeTag {
  T_VOID = 1,
  T_BOOL = 2,
  T_BYTE = 3,
  T_I16 = 6,
  T_I32 = 8,
  T_I64 = 10,
  T_DOUBLE = 4,
  T_STRING = 11,
  T_STRUCT = 12,
  T_MAP = 13,
  T_SET = 14,
  T_LIST = 15,
  T_ENUM = 101,
  T_NOT_REFLECTED = 102
};

class SimpleType {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  SimpleType() : name("") {
  }

  virtual ~SimpleType() throw() {}

  TTypeTag ttype;
  std::string name;

  struct __isset {
    __isset() : ttype(false), name(false) {}
    bool ttype;
    bool name;
  } __isset;

  bool operator == (const SimpleType & rhs) const
  {
    if (!(ttype == rhs.ttype))
      return false;
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const SimpleType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SimpleType & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

class ContainerType {
 public:

  static const char* ascii_fingerprint; // = "654FA6EFFF8242F4C2A604B970686634";
  static const uint8_t binary_fingerprint[16]; // = {0x65,0x4F,0xA6,0xEF,0xFF,0x82,0x42,0xF4,0xC2,0xA6,0x04,0xB9,0x70,0x68,0x66,0x34};

  ContainerType() {
  }

  virtual ~ContainerType() throw() {}

  TTypeTag ttype;
  SimpleType subtype1;
  SimpleType subtype2;

  struct __isset {
    __isset() : ttype(false), subtype1(false), subtype2(false) {}
    bool ttype;
    bool subtype1;
    bool subtype2;
  } __isset;

  bool operator == (const ContainerType & rhs) const
  {
    if (!(ttype == rhs.ttype))
      return false;
    if (!(subtype1 == rhs.subtype1))
      return false;
    if (__isset.subtype2 != rhs.__isset.subtype2)
      return false;
    else if (__isset.subtype2 && !(subtype2 == rhs.subtype2))
      return false;
    return true;
  }
  bool operator != (const ContainerType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ContainerType & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

class ThriftType {
 public:

  static const char* ascii_fingerprint; // = "76BC1CC759001D7D85FEE75C4F183062";
  static const uint8_t binary_fingerprint[16]; // = {0x76,0xBC,0x1C,0xC7,0x59,0x00,0x1D,0x7D,0x85,0xFE,0xE7,0x5C,0x4F,0x18,0x30,0x62};

  ThriftType() : is_container(0) {
  }

  virtual ~ThriftType() throw() {}

  bool is_container;
  SimpleType simple_type;
  ContainerType container_type;

  struct __isset {
    __isset() : is_container(false), simple_type(false), container_type(false) {}
    bool is_container;
    bool simple_type;
    bool container_type;
  } __isset;

  bool operator == (const ThriftType & rhs) const
  {
    if (!(is_container == rhs.is_container))
      return false;
    if (__isset.simple_type != rhs.__isset.simple_type)
      return false;
    else if (__isset.simple_type && !(simple_type == rhs.simple_type))
      return false;
    if (__isset.container_type != rhs.__isset.container_type)
      return false;
    else if (__isset.container_type && !(container_type == rhs.container_type))
      return false;
    return true;
  }
  bool operator != (const ThriftType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftType & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

class Argument {
 public:

  static const char* ascii_fingerprint; // = "8C45506BE0EFBB22FB19FA40DDCECB3F";
  static const uint8_t binary_fingerprint[16]; // = {0x8C,0x45,0x50,0x6B,0xE0,0xEF,0xBB,0x22,0xFB,0x19,0xFA,0x40,0xDD,0xCE,0xCB,0x3F};

  Argument() : key(0), name("") {
  }

  virtual ~Argument() throw() {}

  int16_t key;
  std::string name;
  ThriftType type;

  struct __isset {
    __isset() : key(false), name(false), type(false) {}
    bool key;
    bool name;
    bool type;
  } __isset;

  bool operator == (const Argument & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(type == rhs.type))
      return false;
    return true;
  }
  bool operator != (const Argument &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Argument & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

class Method {
 public:

  static const char* ascii_fingerprint; // = "E6573428C492D24C84A19432D39A17B0";
  static const uint8_t binary_fingerprint[16]; // = {0xE6,0x57,0x34,0x28,0xC4,0x92,0xD2,0x4C,0x84,0xA1,0x94,0x32,0xD3,0x9A,0x17,0xB0};

  Method() : name("") {
  }

  virtual ~Method() throw() {}

  std::string name;
  ThriftType return_type;
  std::vector<Argument>  arguments;

  struct __isset {
    __isset() : name(false), return_type(false), arguments(false) {}
    bool name;
    bool return_type;
    bool arguments;
  } __isset;

  bool operator == (const Method & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(return_type == rhs.return_type))
      return false;
    if (!(arguments == rhs.arguments))
      return false;
    return true;
  }
  bool operator != (const Method &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Method & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

class Service {
 public:

  static const char* ascii_fingerprint; // = "4673B0777B701D9B02A7A74CEC7908A7";
  static const uint8_t binary_fingerprint[16]; // = {0x46,0x73,0xB0,0x77,0x7B,0x70,0x1D,0x9B,0x02,0xA7,0xA7,0x4C,0xEC,0x79,0x08,0xA7};

  Service() : name(""), fully_reflected(0) {
  }

  virtual ~Service() throw() {}

  std::string name;
  std::vector<Method>  methods;
  bool fully_reflected;

  struct __isset {
    __isset() : name(false), methods(false), fully_reflected(false) {}
    bool name;
    bool methods;
    bool fully_reflected;
  } __isset;

  bool operator == (const Service & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(methods == rhs.methods))
      return false;
    if (!(fully_reflected == rhs.fully_reflected))
      return false;
    return true;
  }
  bool operator != (const Service &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Service & ) const;

  uint32_t read(facebook::thrift::protocol::TProtocol* iprot);
  uint32_t write(facebook::thrift::protocol::TProtocol* oprot) const;

};

}}}} // namespace

#endif
