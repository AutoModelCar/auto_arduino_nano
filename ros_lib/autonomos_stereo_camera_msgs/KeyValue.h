#ifndef _ROS_autonomos_stereo_camera_msgs_KeyValue_h
#define _ROS_autonomos_stereo_camera_msgs_KeyValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace autonomos_stereo_camera_msgs
{

  class KeyValue : public ros::Msg
  {
    public:
      typedef const char* _key_type;
      _key_type key;
      typedef uint8_t _value_type_type;
      _value_type_type value_type;
      typedef uint64_t _value_uint64_type;
      _value_uint64_type value_uint64;
      typedef int64_t _value_int64_type;
      _value_int64_type value_int64;
      typedef float _value_float64_type;
      _value_float64_type value_float64;
      typedef const char* _value_string_type;
      _value_string_type value_string;
      typedef bool _value_bool_type;
      _value_bool_type value_bool;
      typedef ros::Time _value_time_type;
      _value_time_type value_time;
      typedef ros::Duration _value_duration_type;
      _value_duration_type value_duration;
      enum { VALUE_TYPE_UNDEFINED =  0 };
      enum { VALUE_TYPE_UINT64 =  1 };
      enum { VALUE_TYPE_INT64 =  2 };
      enum { VALUE_TYPE_FLOAT64 =  3 };
      enum { VALUE_TYPE_STRING =  4 };
      enum { VALUE_TYPE_BOOL =  5 };
      enum { VALUE_TYPE_TIME =  6 };
      enum { VALUE_TYPE_DURATION =  7 };

    KeyValue():
      key(""),
      value_type(0),
      value_uint64(0),
      value_int64(0),
      value_float64(0),
      value_string(""),
      value_bool(0),
      value_time(),
      value_duration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_key = strlen(this->key);
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      *(outbuffer + offset + 0) = (this->value_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value_type);
      union {
        uint64_t real;
        uint32_t base;
      } u_value_uint64;
      u_value_uint64.real = this->value_uint64;
      *(outbuffer + offset + 0) = (u_value_uint64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value_uint64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value_uint64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value_uint64.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_uint64);
      union {
        int64_t real;
        uint64_t base;
      } u_value_int64;
      u_value_int64.real = this->value_int64;
      *(outbuffer + offset + 0) = (u_value_int64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value_int64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value_int64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value_int64.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_value_int64.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_value_int64.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_value_int64.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_value_int64.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->value_int64);
      offset += serializeAvrFloat64(outbuffer + offset, this->value_float64);
      uint32_t length_value_string = strlen(this->value_string);
      varToArr(outbuffer + offset, length_value_string);
      offset += 4;
      memcpy(outbuffer + offset, this->value_string, length_value_string);
      offset += length_value_string;
      union {
        bool real;
        uint8_t base;
      } u_value_bool;
      u_value_bool.real = this->value_bool;
      *(outbuffer + offset + 0) = (u_value_bool.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value_bool);
      *(outbuffer + offset + 0) = (this->value_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_time.sec);
      *(outbuffer + offset + 0) = (this->value_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_time.nsec);
      *(outbuffer + offset + 0) = (this->value_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_duration.sec);
      *(outbuffer + offset + 0) = (this->value_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_duration.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      this->value_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value_type);
      union {
        uint64_t real;
        uint32_t base;
      } u_value_uint64;
      u_value_uint64.base = 0;
      u_value_uint64.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value_uint64.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value_uint64.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value_uint64.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value_uint64 = u_value_uint64.real;
      offset += sizeof(this->value_uint64);
      union {
        int64_t real;
        uint64_t base;
      } u_value_int64;
      u_value_int64.base = 0;
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_value_int64.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->value_int64 = u_value_int64.real;
      offset += sizeof(this->value_int64);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value_float64));
      uint32_t length_value_string;
      arrToVar(length_value_string, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value_string-1]=0;
      this->value_string = (char *)(inbuffer + offset-1);
      offset += length_value_string;
      union {
        bool real;
        uint8_t base;
      } u_value_bool;
      u_value_bool.base = 0;
      u_value_bool.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value_bool = u_value_bool.real;
      offset += sizeof(this->value_bool);
      this->value_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->value_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->value_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->value_time.sec);
      this->value_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->value_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->value_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->value_time.nsec);
      this->value_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->value_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->value_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->value_duration.sec);
      this->value_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->value_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->value_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->value_duration.nsec);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/KeyValue"; };
    const char * getMD5(){ return "80e9fb7be13eccc78379dba0654bd6dc"; };

  };

}
#endif