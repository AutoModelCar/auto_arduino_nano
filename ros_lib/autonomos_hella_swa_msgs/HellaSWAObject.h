#ifndef _ROS_autonomos_hella_swa_msgs_HellaSWAObject_h
#define _ROS_autonomos_hella_swa_msgs_HellaSWAObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_hella_swa_msgs
{

  class HellaSWAObject : public ros::Msg
  {
    public:
      typedef float _relative_position_x_type;
      _relative_position_x_type relative_position_x;
      typedef uint16_t _relative_position_x_raw_type;
      _relative_position_x_raw_type relative_position_x_raw;
      typedef float _relative_position_y_type;
      _relative_position_y_type relative_position_y;
      typedef uint16_t _relative_position_y_raw_type;
      _relative_position_y_raw_type relative_position_y_raw;
      typedef float _relative_velocity_x_type;
      _relative_velocity_x_type relative_velocity_x;
      typedef uint16_t _relative_velocity_x_raw_type;
      _relative_velocity_x_raw_type relative_velocity_x_raw;
      typedef float _relative_velocity_y_type;
      _relative_velocity_y_type relative_velocity_y;
      typedef uint16_t _relative_velocity_y_raw_type;
      _relative_velocity_y_raw_type relative_velocity_y_raw;
      typedef uint8_t _lane_type;
      _lane_type lane;
      typedef uint8_t _length_type;
      _length_type length;
      typedef uint8_t _size_type;
      _size_type size;
      typedef uint8_t _index_type;
      _index_type index;

    HellaSWAObject():
      relative_position_x(0),
      relative_position_x_raw(0),
      relative_position_y(0),
      relative_position_y_raw(0),
      relative_velocity_x(0),
      relative_velocity_x_raw(0),
      relative_velocity_y(0),
      relative_velocity_y_raw(0),
      lane(0),
      length(0),
      size(0),
      index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_relative_position_x;
      u_relative_position_x.real = this->relative_position_x;
      *(outbuffer + offset + 0) = (u_relative_position_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_position_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_position_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_position_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_position_x);
      *(outbuffer + offset + 0) = (this->relative_position_x_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->relative_position_x_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->relative_position_x_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_position_y;
      u_relative_position_y.real = this->relative_position_y;
      *(outbuffer + offset + 0) = (u_relative_position_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_position_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_position_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_position_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_position_y);
      *(outbuffer + offset + 0) = (this->relative_position_y_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->relative_position_y_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->relative_position_y_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_velocity_x;
      u_relative_velocity_x.real = this->relative_velocity_x;
      *(outbuffer + offset + 0) = (u_relative_velocity_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_velocity_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_velocity_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_velocity_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_velocity_x);
      *(outbuffer + offset + 0) = (this->relative_velocity_x_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->relative_velocity_x_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->relative_velocity_x_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_velocity_y;
      u_relative_velocity_y.real = this->relative_velocity_y;
      *(outbuffer + offset + 0) = (u_relative_velocity_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_velocity_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_velocity_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_velocity_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_velocity_y);
      *(outbuffer + offset + 0) = (this->relative_velocity_y_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->relative_velocity_y_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->relative_velocity_y_raw);
      *(outbuffer + offset + 0) = (this->lane >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lane);
      *(outbuffer + offset + 0) = (this->length >> (8 * 0)) & 0xFF;
      offset += sizeof(this->length);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      offset += sizeof(this->size);
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_relative_position_x;
      u_relative_position_x.base = 0;
      u_relative_position_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_position_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_position_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_position_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_position_x = u_relative_position_x.real;
      offset += sizeof(this->relative_position_x);
      this->relative_position_x_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->relative_position_x_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->relative_position_x_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_position_y;
      u_relative_position_y.base = 0;
      u_relative_position_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_position_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_position_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_position_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_position_y = u_relative_position_y.real;
      offset += sizeof(this->relative_position_y);
      this->relative_position_y_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->relative_position_y_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->relative_position_y_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_velocity_x;
      u_relative_velocity_x.base = 0;
      u_relative_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_velocity_x = u_relative_velocity_x.real;
      offset += sizeof(this->relative_velocity_x);
      this->relative_velocity_x_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->relative_velocity_x_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->relative_velocity_x_raw);
      union {
        float real;
        uint32_t base;
      } u_relative_velocity_y;
      u_relative_velocity_y.base = 0;
      u_relative_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_velocity_y = u_relative_velocity_y.real;
      offset += sizeof(this->relative_velocity_y);
      this->relative_velocity_y_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->relative_velocity_y_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->relative_velocity_y_raw);
      this->lane =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lane);
      this->length =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->length);
      this->size =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->size);
      this->index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->index);
     return offset;
    }

    const char * getType(){ return "autonomos_hella_swa_msgs/HellaSWAObject"; };
    const char * getMD5(){ return "8c55dbbd54c38a95427ec003f679a407"; };

  };

}
#endif