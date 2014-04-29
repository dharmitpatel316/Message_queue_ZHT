// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meta.proto

#ifndef PROTOBUF_meta_2eproto__INCLUDED
#define PROTOBUF_meta_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_meta_2eproto();
void protobuf_AssignDesc_meta_2eproto();
void protobuf_ShutdownFile_meta_2eproto();

class Package;

// ===================================================================

class Package : public ::google::protobuf::Message {
 public:
  Package();
  virtual ~Package();
  
  Package(const Package& from);
  
  inline Package& operator=(const Package& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Package& default_instance();
  
  void Swap(Package* other);
  
  // implements Message ----------------------------------------------
  
  Package* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Package& from);
  void MergeFrom(const Package& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional string virtualPath = 1;
  inline bool has_virtualpath() const;
  inline void clear_virtualpath();
  static const int kVirtualPathFieldNumber = 1;
  inline const ::std::string& virtualpath() const;
  inline void set_virtualpath(const ::std::string& value);
  inline void set_virtualpath(const char* value);
  inline void set_virtualpath(const char* value, size_t size);
  inline ::std::string* mutable_virtualpath();
  inline ::std::string* release_virtualpath();
  
  // optional string realFullPath = 2;
  inline bool has_realfullpath() const;
  inline void clear_realfullpath();
  static const int kRealFullPathFieldNumber = 2;
  inline const ::std::string& realfullpath() const;
  inline void set_realfullpath(const ::std::string& value);
  inline void set_realfullpath(const char* value);
  inline void set_realfullpath(const char* value, size_t size);
  inline ::std::string* mutable_realfullpath();
  inline ::std::string* release_realfullpath();
  
  // optional bool isDir = 3;
  inline bool has_isdir() const;
  inline void clear_isdir();
  static const int kIsDirFieldNumber = 3;
  inline bool isdir() const;
  inline void set_isdir(bool value);
  
  // optional int32 replicanum = 4;
  inline bool has_replicanum() const;
  inline void clear_replicanum();
  static const int kReplicanumFieldNumber = 4;
  inline ::google::protobuf::int32 replicanum() const;
  inline void set_replicanum(::google::protobuf::int32 value);
  
  // repeated string listItem = 5;
  inline int listitem_size() const;
  inline void clear_listitem();
  static const int kListItemFieldNumber = 5;
  inline const ::std::string& listitem(int index) const;
  inline ::std::string* mutable_listitem(int index);
  inline void set_listitem(int index, const ::std::string& value);
  inline void set_listitem(int index, const char* value);
  inline void set_listitem(int index, const char* value, size_t size);
  inline ::std::string* add_listitem();
  inline void add_listitem(const ::std::string& value);
  inline void add_listitem(const char* value);
  inline void add_listitem(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& listitem() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_listitem();
  
  // @@protoc_insertion_point(class_scope:Package)
 private:
  inline void set_has_virtualpath();
  inline void clear_has_virtualpath();
  inline void set_has_realfullpath();
  inline void clear_has_realfullpath();
  inline void set_has_isdir();
  inline void clear_has_isdir();
  inline void set_has_replicanum();
  inline void clear_has_replicanum();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* virtualpath_;
  ::std::string* realfullpath_;
  bool isdir_;
  ::google::protobuf::int32 replicanum_;
  ::google::protobuf::RepeatedPtrField< ::std::string> listitem_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];
  
  friend void  protobuf_AddDesc_meta_2eproto();
  friend void protobuf_AssignDesc_meta_2eproto();
  friend void protobuf_ShutdownFile_meta_2eproto();
  
  void InitAsDefaultInstance();
  static Package* default_instance_;
};
// ===================================================================


// ===================================================================

// Package

// optional string virtualPath = 1;
inline bool Package::has_virtualpath() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Package::set_has_virtualpath() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Package::clear_has_virtualpath() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Package::clear_virtualpath() {
  if (virtualpath_ != &::google::protobuf::internal::kEmptyString) {
    virtualpath_->clear();
  }
  clear_has_virtualpath();
}
inline const ::std::string& Package::virtualpath() const {
  return *virtualpath_;
}
inline void Package::set_virtualpath(const ::std::string& value) {
  set_has_virtualpath();
  if (virtualpath_ == &::google::protobuf::internal::kEmptyString) {
    virtualpath_ = new ::std::string;
  }
  virtualpath_->assign(value);
}
inline void Package::set_virtualpath(const char* value) {
  set_has_virtualpath();
  if (virtualpath_ == &::google::protobuf::internal::kEmptyString) {
    virtualpath_ = new ::std::string;
  }
  virtualpath_->assign(value);
}
inline void Package::set_virtualpath(const char* value, size_t size) {
  set_has_virtualpath();
  if (virtualpath_ == &::google::protobuf::internal::kEmptyString) {
    virtualpath_ = new ::std::string;
  }
  virtualpath_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Package::mutable_virtualpath() {
  set_has_virtualpath();
  if (virtualpath_ == &::google::protobuf::internal::kEmptyString) {
    virtualpath_ = new ::std::string;
  }
  return virtualpath_;
}
inline ::std::string* Package::release_virtualpath() {
  clear_has_virtualpath();
  if (virtualpath_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = virtualpath_;
    virtualpath_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string realFullPath = 2;
inline bool Package::has_realfullpath() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Package::set_has_realfullpath() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Package::clear_has_realfullpath() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Package::clear_realfullpath() {
  if (realfullpath_ != &::google::protobuf::internal::kEmptyString) {
    realfullpath_->clear();
  }
  clear_has_realfullpath();
}
inline const ::std::string& Package::realfullpath() const {
  return *realfullpath_;
}
inline void Package::set_realfullpath(const ::std::string& value) {
  set_has_realfullpath();
  if (realfullpath_ == &::google::protobuf::internal::kEmptyString) {
    realfullpath_ = new ::std::string;
  }
  realfullpath_->assign(value);
}
inline void Package::set_realfullpath(const char* value) {
  set_has_realfullpath();
  if (realfullpath_ == &::google::protobuf::internal::kEmptyString) {
    realfullpath_ = new ::std::string;
  }
  realfullpath_->assign(value);
}
inline void Package::set_realfullpath(const char* value, size_t size) {
  set_has_realfullpath();
  if (realfullpath_ == &::google::protobuf::internal::kEmptyString) {
    realfullpath_ = new ::std::string;
  }
  realfullpath_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Package::mutable_realfullpath() {
  set_has_realfullpath();
  if (realfullpath_ == &::google::protobuf::internal::kEmptyString) {
    realfullpath_ = new ::std::string;
  }
  return realfullpath_;
}
inline ::std::string* Package::release_realfullpath() {
  clear_has_realfullpath();
  if (realfullpath_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = realfullpath_;
    realfullpath_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional bool isDir = 3;
inline bool Package::has_isdir() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Package::set_has_isdir() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Package::clear_has_isdir() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Package::clear_isdir() {
  isdir_ = false;
  clear_has_isdir();
}
inline bool Package::isdir() const {
  return isdir_;
}
inline void Package::set_isdir(bool value) {
  set_has_isdir();
  isdir_ = value;
}

// optional int32 replicanum = 4;
inline bool Package::has_replicanum() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Package::set_has_replicanum() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Package::clear_has_replicanum() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Package::clear_replicanum() {
  replicanum_ = 0;
  clear_has_replicanum();
}
inline ::google::protobuf::int32 Package::replicanum() const {
  return replicanum_;
}
inline void Package::set_replicanum(::google::protobuf::int32 value) {
  set_has_replicanum();
  replicanum_ = value;
}

// repeated string listItem = 5;
inline int Package::listitem_size() const {
  return listitem_.size();
}
inline void Package::clear_listitem() {
  listitem_.Clear();
}
inline const ::std::string& Package::listitem(int index) const {
  return listitem_.Get(index);
}
inline ::std::string* Package::mutable_listitem(int index) {
  return listitem_.Mutable(index);
}
inline void Package::set_listitem(int index, const ::std::string& value) {
  listitem_.Mutable(index)->assign(value);
}
inline void Package::set_listitem(int index, const char* value) {
  listitem_.Mutable(index)->assign(value);
}
inline void Package::set_listitem(int index, const char* value, size_t size) {
  listitem_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Package::add_listitem() {
  return listitem_.Add();
}
inline void Package::add_listitem(const ::std::string& value) {
  listitem_.Add()->assign(value);
}
inline void Package::add_listitem(const char* value) {
  listitem_.Add()->assign(value);
}
inline void Package::add_listitem(const char* value, size_t size) {
  listitem_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Package::listitem() const {
  return listitem_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Package::mutable_listitem() {
  return &listitem_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_meta_2eproto__INCLUDED
