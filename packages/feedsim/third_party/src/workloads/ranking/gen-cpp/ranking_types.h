/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ranking_TYPES_H
#define ranking_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>

#include "folly/small_vector.h"
#include "folly/container/F14Map.h"

namespace ranking {

struct RankingStoryType {
  enum type {
    STORY_TYPE_A = 0,
    STORY_TYPE_B = 1,
    STORY_TYPE_C = 2,
    STORY_TYPE_D = 3,
    STORY_TYPE_E = 4,
    STORY_TYPE_F = 5,
    STORY_TYPE_G = 6,
    STORY_TYPE_H = 7,
    STORY_TYPE_I = 8,
    STORY_TYPE_J = 9,
    STORY_TYPE_K = 10,
    STORY_TYPE_L = 11,
    STORY_TYPE_M = 12,
    STORY_TYPE_N = 13,
    STORY_TYPE_O = 14,
    STORY_TYPE_P = 15,
    STORY_TYPE_Q = 16,
    STORY_TYPE_R = 17,
    STORY_TYPE_S = 18,
    STORY_TYPE_T = 19,
    STORY_TYPE_U = 20,
    STORY_TYPE_V = 21,
    STORY_TYPE_W = 22,
    STORY_TYPE_X = 23,
    STORY_TYPE_Y = 24,
    STORY_TYPE_Z = 25
  };
};

extern const std::map<int, const char*> _RankingStoryType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const RankingStoryType::type& val);

std::string to_string(const RankingStoryType::type& val);

struct RankingObjectType {
  enum type {
    OBJ_TYPE_A = 0,
    OBJ_TYPE_B = 1,
    OBJ_TYPE_C = 2,
    OBJ_TYPE_D = 3,
    OBJ_TYPE_E = 4,
    OBJ_TYPE_F = 5,
    OBJ_TYPE_G = 6,
    OBJ_TYPE_H = 7,
    OBJ_TYPE_I = 8,
    OBJ_TYPE_J = 9,
    OBJ_TYPE_K = 10,
    OBJ_TYPE_L = 11,
    OBJ_TYPE_M = 12,
    OBJ_TYPE_N = 13,
    OBJ_TYPE_O = 14,
    OBJ_TYPE_P = 15,
    OBJ_TYPE_Q = 16,
    OBJ_TYPE_R = 17,
    OBJ_TYPE_S = 18,
    OBJ_TYPE_T = 19,
    OBJ_TYPE_U = 20,
    OBJ_TYPE_V = 21,
    OBJ_TYPE_W = 22,
    OBJ_TYPE_X = 23,
    OBJ_TYPE_Y = 24,
    OBJ_TYPE_Z = 25
  };
};

extern const std::map<int, const char*> _RankingObjectType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const RankingObjectType::type& val);

std::string to_string(const RankingObjectType::type& val);

typedef std::vector<int64_t>  SmallListI64;

typedef std::map<int16_t, int64_t>  RankingPayloadIntMap;

typedef std::map<int16_t, std::string>  RankingPayloadStringMap;

typedef std::map<int16_t, SmallListI64>  RankingPayloadVecMap;

class Payload;

class Action;

class RankingObject;

class RankingStory;

class RankingResponse;

typedef struct _Payload__isset {
  _Payload__isset() : message(false) {}
  bool message :1;
} _Payload__isset;

class Payload : public virtual ::apache::thrift::TBase {
 public:

  Payload(const Payload&);
  Payload(Payload&&);
  Payload& operator=(const Payload&);
  Payload& operator=(Payload&&);
  Payload() : message() {
  }

  virtual ~Payload() noexcept;
  std::string message;

  _Payload__isset __isset;

  void __set_message(const std::string& val);

  bool operator == (const Payload & rhs) const
  {
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const Payload &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Payload & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Payload &a, Payload &b);

std::ostream& operator<<(std::ostream& out, const Payload& obj);

typedef struct _Action__isset {
  _Action__isset() : type(false), timeUsec(false), timeMsec(false), actorID(false) {}
  bool type :1;
  bool timeUsec :1;
  bool timeMsec :1;
  bool actorID :1;
} _Action__isset;

class Action : public virtual ::apache::thrift::TBase {
 public:

  Action(const Action&);
  Action(Action&&);
  Action& operator=(const Action&);
  Action& operator=(Action&&);
  Action() : type(0), timeUsec(0), timeMsec(0), actorID(0) {
  }

  virtual ~Action() noexcept;
  int16_t type;
  int64_t timeUsec;
  int32_t timeMsec;
  int64_t actorID;

  _Action__isset __isset;

  void __set_type(const int16_t val);

  void __set_timeUsec(const int64_t val);

  void __set_timeMsec(const int32_t val);

  void __set_actorID(const int64_t val);

  bool operator == (const Action & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(timeUsec == rhs.timeUsec))
      return false;
    if (!(timeMsec == rhs.timeMsec))
      return false;
    if (!(actorID == rhs.actorID))
      return false;
    return true;
  }
  bool operator != (const Action &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Action & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Action &a, Action &b);

std::ostream& operator<<(std::ostream& out, const Action& obj);

typedef struct _RankingObject__isset {
  _RankingObject__isset() : objectID(false), objectType(false), actorID(false), createTime(false), payloadIntMap(false), payloadStrMap(false), payloadVecMap(false), actions(false), weight(false) {}
  bool objectID :1;
  bool objectType :1;
  bool actorID :1;
  bool createTime :1;
  bool payloadIntMap :1;
  bool payloadStrMap :1;
  bool payloadVecMap :1;
  bool actions :1;
  bool weight :1;
} _RankingObject__isset;

class RankingObject : public virtual ::apache::thrift::TBase {
 public:

  RankingObject(const RankingObject&);
  RankingObject(RankingObject&&);
  RankingObject& operator=(const RankingObject&);
  RankingObject& operator=(RankingObject&&);
  RankingObject() : objectID(0), objectType((RankingObjectType::type)0), actorID(0), createTime(0), weight(0) {
  }

  virtual ~RankingObject() noexcept;
  int64_t objectID;
  RankingObjectType::type objectType;
  int64_t actorID;
  int64_t createTime;
  RankingPayloadIntMap payloadIntMap;
  RankingPayloadStringMap payloadStrMap;
  RankingPayloadVecMap payloadVecMap;
  std::vector<Action>  actions;
  double weight;

  _RankingObject__isset __isset;

  void __set_objectID(const int64_t val);

  void __set_objectType(const RankingObjectType::type val);

  void __set_actorID(const int64_t val);

  void __set_createTime(const int64_t val);

  void __set_payloadIntMap(const RankingPayloadIntMap& val);

  void __set_payloadStrMap(const RankingPayloadStringMap& val);

  void __set_payloadVecMap(const RankingPayloadVecMap& val);

  void __set_actions(const std::vector<Action> & val);

  void __set_weight(const double val);

  bool operator == (const RankingObject & rhs) const
  {
    if (!(objectID == rhs.objectID))
      return false;
    if (!(objectType == rhs.objectType))
      return false;
    if (!(actorID == rhs.actorID))
      return false;
    if (!(createTime == rhs.createTime))
      return false;
    if (!(payloadIntMap == rhs.payloadIntMap))
      return false;
    if (!(payloadStrMap == rhs.payloadStrMap))
      return false;
    if (!(payloadVecMap == rhs.payloadVecMap))
      return false;
    if (!(actions == rhs.actions))
      return false;
    if (!(weight == rhs.weight))
      return false;
    return true;
  }
  bool operator != (const RankingObject &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RankingObject & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(RankingObject &a, RankingObject &b);

std::ostream& operator<<(std::ostream& out, const RankingObject& obj);

typedef struct _RankingStory__isset {
  _RankingStory__isset() : storyID(false), objects(false), weight(false), storyType(false) {}
  bool storyID :1;
  bool objects :1;
  bool weight :1;
  bool storyType :1;
} _RankingStory__isset;

class RankingStory : public virtual ::apache::thrift::TBase {
 public:

  RankingStory(const RankingStory&);
  RankingStory(RankingStory&&);
  RankingStory& operator=(const RankingStory&);
  RankingStory& operator=(RankingStory&&);
  RankingStory() : storyID(0), weight(0), storyType((RankingStoryType::type)0) {
  }

  virtual ~RankingStory() noexcept;
  int64_t storyID;
  std::vector<RankingObject>  objects;
  double weight;
  RankingStoryType::type storyType;

  _RankingStory__isset __isset;

  void __set_storyID(const int64_t val);

  void __set_objects(const std::vector<RankingObject> & val);

  void __set_weight(const double val);

  void __set_storyType(const RankingStoryType::type val);

  bool operator == (const RankingStory & rhs) const
  {
    if (!(storyID == rhs.storyID))
      return false;
    if (!(objects == rhs.objects))
      return false;
    if (!(weight == rhs.weight))
      return false;
    if (!(storyType == rhs.storyType))
      return false;
    return true;
  }
  bool operator != (const RankingStory &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RankingStory & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(RankingStory &a, RankingStory &b);

std::ostream& operator<<(std::ostream& out, const RankingStory& obj);

typedef struct _RankingResponse__isset {
  _RankingResponse__isset() : queryID(false), rankingStories(false), objectCounts(false), metadata(false) {}
  bool queryID :1;
  bool rankingStories :1;
  bool objectCounts :1;
  bool metadata :1;
} _RankingResponse__isset;

class RankingResponse : public virtual ::apache::thrift::TBase {
 public:

  RankingResponse(const RankingResponse&);
  RankingResponse(RankingResponse&&);
  RankingResponse& operator=(const RankingResponse&);
  RankingResponse& operator=(RankingResponse&&);
  RankingResponse() : queryID(0), metadata() {
  }

  virtual ~RankingResponse() noexcept;
  int64_t queryID;
  std::vector<RankingStory>  rankingStories;
  std::vector<int32_t>  objectCounts;
  std::string metadata;

  _RankingResponse__isset __isset;

  void __set_queryID(const int64_t val);

  void __set_rankingStories(const std::vector<RankingStory> & val);

  void __set_objectCounts(const std::vector<int32_t> & val);

  void __set_metadata(const std::string& val);

  bool operator == (const RankingResponse & rhs) const
  {
    if (!(queryID == rhs.queryID))
      return false;
    if (!(rankingStories == rhs.rankingStories))
      return false;
    if (!(objectCounts == rhs.objectCounts))
      return false;
    if (!(metadata == rhs.metadata))
      return false;
    return true;
  }
  bool operator != (const RankingResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RankingResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(RankingResponse &a, RankingResponse &b);

std::ostream& operator<<(std::ostream& out, const RankingResponse& obj);

} // namespace

#endif