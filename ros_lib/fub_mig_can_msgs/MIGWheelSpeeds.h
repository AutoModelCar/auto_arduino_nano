#ifndef _ROS_fub_mig_can_msgs_MIGWheelSpeeds_h
#define _ROS_fub_mig_can_msgs_MIGWheelSpeeds_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGWheelSpeeds : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _speed_front_left_type;
      _speed_front_left_type speed_front_left;
      typedef uint16_t _speed_front_left_raw_type;
      _speed_front_left_raw_type speed_front_left_raw;
      typedef bool _speed_front_left_signed_type;
      _speed_front_left_signed_type speed_front_left_signed;
      typedef float _speed_front_right_type;
      _speed_front_right_type speed_front_right;
      typedef uint16_t _speed_front_right_raw_type;
      _speed_front_right_raw_type speed_front_right_raw;
      typedef bool _speed_front_right_signed_type;
      _speed_front_right_signed_type speed_front_right_signed;
      typedef float _speed_back_left_type;
      _speed_back_left_type speed_back_left;
      typedef uint16_t _speed_back_left_raw_type;
      _speed_back_left_raw_type speed_back_left_raw;
      typedef bool _speed_back_left_signed_type;
      _speed_back_left_signed_type speed_back_left_signed;
      typedef float _speed_back_right_type;
      _speed_back_right_type speed_back_right;
      typedef uint16_t _speed_back_right_raw_type;
      _speed_back_right_raw_type speed_back_right_raw;
      typedef bool _speed_back_right_signed_type;
      _speed_back_right_signed_type speed_back_right_signed;
      enum { can_id =  1184 };
      enum { can_dlc =     8 };

    MIGWheelSpeeds():
      header(),
      speed_front_left(0),
      speed_front_left_raw(0),
      speed_front_left_signed(0),
      speed_front_right(0),
      speed_front_right_raw(0),
      speed_front_right_signed(0),
      speed_back_left(0),
      speed_back_left_raw(0),
      speed_back_left_signed(0),
      speed_back_right(0),
      speed_back_right_raw(0),
      speed_back_right_signed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed_front_left;
      u_speed_front_left.real = this->speed_front_left;
      *(outbuffer + offset + 0) = (u_speed_front_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_front_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_front_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_front_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_front_left);
      *(outbuffer + offset + 0) = (this->speed_front_left_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_front_left_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_front_left_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_front_left_signed;
      u_speed_front_left_signed.real = this->speed_front_left_signed;
      *(outbuffer + offset + 0) = (u_speed_front_left_signed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_front_left_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_front_right;
      u_speed_front_right.real = this->speed_front_right;
      *(outbuffer + offset + 0) = (u_speed_front_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_front_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_front_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_front_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_front_right);
      *(outbuffer + offset + 0) = (this->speed_front_right_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_front_right_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_front_right_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_front_right_signed;
      u_speed_front_right_signed.real = this->speed_front_right_signed;
      *(outbuffer + offset + 0) = (u_speed_front_right_signed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_front_right_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_back_left;
      u_speed_back_left.real = this->speed_back_left;
      *(outbuffer + offset + 0) = (u_speed_back_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_back_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_back_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_back_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_back_left);
      *(outbuffer + offset + 0) = (this->speed_back_left_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_back_left_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_back_left_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_back_left_signed;
      u_speed_back_left_signed.real = this->speed_back_left_signed;
      *(outbuffer + offset + 0) = (u_speed_back_left_signed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_back_left_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_back_right;
      u_speed_back_right.real = this->speed_back_right;
      *(outbuffer + offset + 0) = (u_speed_back_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_back_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_back_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_back_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_back_right);
      *(outbuffer + offset + 0) = (this->speed_back_right_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_back_right_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_back_right_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_back_right_signed;
      u_speed_back_right_signed.real = this->speed_back_right_signed;
      *(outbuffer + offset + 0) = (u_speed_back_right_signed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_back_right_signed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed_front_left;
      u_speed_front_left.base = 0;
      u_speed_front_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_front_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_front_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_front_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_front_left = u_speed_front_left.real;
      offset += sizeof(this->speed_front_left);
      this->speed_front_left_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_front_left_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_front_left_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_front_left_signed;
      u_speed_front_left_signed.base = 0;
      u_speed_front_left_signed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_front_left_signed = u_speed_front_left_signed.real;
      offset += sizeof(this->speed_front_left_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_front_right;
      u_speed_front_right.base = 0;
      u_speed_front_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_front_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_front_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_front_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_front_right = u_speed_front_right.real;
      offset += sizeof(this->speed_front_right);
      this->speed_front_right_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_front_right_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_front_right_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_front_right_signed;
      u_speed_front_right_signed.base = 0;
      u_speed_front_right_signed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_front_right_signed = u_speed_front_right_signed.real;
      offset += sizeof(this->speed_front_right_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_back_left;
      u_speed_back_left.base = 0;
      u_speed_back_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_back_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_back_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_back_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_back_left = u_speed_back_left.real;
      offset += sizeof(this->speed_back_left);
      this->speed_back_left_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_back_left_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_back_left_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_back_left_signed;
      u_speed_back_left_signed.base = 0;
      u_speed_back_left_signed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_back_left_signed = u_speed_back_left_signed.real;
      offset += sizeof(this->speed_back_left_signed);
      union {
        float real;
        uint32_t base;
      } u_speed_back_right;
      u_speed_back_right.base = 0;
      u_speed_back_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_back_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_back_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_back_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_back_right = u_speed_back_right.real;
      offset += sizeof(this->speed_back_right);
      this->speed_back_right_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_back_right_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_back_right_raw);
      union {
        bool real;
        uint8_t base;
      } u_speed_back_right_signed;
      u_speed_back_right_signed.base = 0;
      u_speed_back_right_signed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed_back_right_signed = u_speed_back_right_signed.real;
      offset += sizeof(this->speed_back_right_signed);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGWheelSpeeds"; };
    const char * getMD5(){ return "847f0568667ca1df95ef79456d24ebb5"; };

  };

}
#endif