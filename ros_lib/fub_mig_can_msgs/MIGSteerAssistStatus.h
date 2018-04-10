#ifndef _ROS_fub_mig_can_msgs_MIGSteerAssistStatus_h
#define _ROS_fub_mig_can_msgs_MIGSteerAssistStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGSteerAssistStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef float _steer_momentum_type;
      _steer_momentum_type steer_momentum;
      typedef uint16_t _steer_momentum_raw_type;
      _steer_momentum_raw_type steer_momentum_raw;
      typedef bool _steer_momentum_negative_type;
      _steer_momentum_negative_type steer_momentum_negative;
      typedef bool _steer_momentum_valid_type;
      _steer_momentum_valid_type steer_momentum_valid;
      typedef float _steer_angle_type;
      _steer_angle_type steer_angle;
      typedef uint16_t _steer_angle_raw_type;
      _steer_angle_raw_type steer_angle_raw;
      typedef bool _steer_angle_negative_type;
      _steer_angle_negative_type steer_angle_negative;
      typedef bool _steer_angle_valid_type;
      _steer_angle_valid_type steer_angle_valid;
      enum { can_id =  208  };
      enum { can_dlc =    6 };
      enum { can_cycle =   10  };

    MIGSteerAssistStatus():
      header(),
      message_counter(0),
      steer_momentum(0),
      steer_momentum_raw(0),
      steer_momentum_negative(0),
      steer_momentum_valid(0),
      steer_angle(0),
      steer_angle_raw(0),
      steer_angle_negative(0),
      steer_angle_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      union {
        float real;
        uint32_t base;
      } u_steer_momentum;
      u_steer_momentum.real = this->steer_momentum;
      *(outbuffer + offset + 0) = (u_steer_momentum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_momentum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_momentum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_momentum.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_momentum);
      *(outbuffer + offset + 0) = (this->steer_momentum_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steer_momentum_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steer_momentum_raw);
      union {
        bool real;
        uint8_t base;
      } u_steer_momentum_negative;
      u_steer_momentum_negative.real = this->steer_momentum_negative;
      *(outbuffer + offset + 0) = (u_steer_momentum_negative.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steer_momentum_negative);
      union {
        bool real;
        uint8_t base;
      } u_steer_momentum_valid;
      u_steer_momentum_valid.real = this->steer_momentum_valid;
      *(outbuffer + offset + 0) = (u_steer_momentum_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steer_momentum_valid);
      union {
        float real;
        uint32_t base;
      } u_steer_angle;
      u_steer_angle.real = this->steer_angle;
      *(outbuffer + offset + 0) = (u_steer_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_angle);
      *(outbuffer + offset + 0) = (this->steer_angle_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steer_angle_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steer_angle_raw);
      union {
        bool real;
        uint8_t base;
      } u_steer_angle_negative;
      u_steer_angle_negative.real = this->steer_angle_negative;
      *(outbuffer + offset + 0) = (u_steer_angle_negative.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steer_angle_negative);
      union {
        bool real;
        uint8_t base;
      } u_steer_angle_valid;
      u_steer_angle_valid.real = this->steer_angle_valid;
      *(outbuffer + offset + 0) = (u_steer_angle_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steer_angle_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      union {
        float real;
        uint32_t base;
      } u_steer_momentum;
      u_steer_momentum.base = 0;
      u_steer_momentum.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_momentum.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_momentum.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_momentum.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_momentum = u_steer_momentum.real;
      offset += sizeof(this->steer_momentum);
      this->steer_momentum_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steer_momentum_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steer_momentum_raw);
      union {
        bool real;
        uint8_t base;
      } u_steer_momentum_negative;
      u_steer_momentum_negative.base = 0;
      u_steer_momentum_negative.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steer_momentum_negative = u_steer_momentum_negative.real;
      offset += sizeof(this->steer_momentum_negative);
      union {
        bool real;
        uint8_t base;
      } u_steer_momentum_valid;
      u_steer_momentum_valid.base = 0;
      u_steer_momentum_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steer_momentum_valid = u_steer_momentum_valid.real;
      offset += sizeof(this->steer_momentum_valid);
      union {
        float real;
        uint32_t base;
      } u_steer_angle;
      u_steer_angle.base = 0;
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_angle = u_steer_angle.real;
      offset += sizeof(this->steer_angle);
      this->steer_angle_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steer_angle_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steer_angle_raw);
      union {
        bool real;
        uint8_t base;
      } u_steer_angle_negative;
      u_steer_angle_negative.base = 0;
      u_steer_angle_negative.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steer_angle_negative = u_steer_angle_negative.real;
      offset += sizeof(this->steer_angle_negative);
      union {
        bool real;
        uint8_t base;
      } u_steer_angle_valid;
      u_steer_angle_valid.base = 0;
      u_steer_angle_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steer_angle_valid = u_steer_angle_valid.real;
      offset += sizeof(this->steer_angle_valid);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGSteerAssistStatus"; };
    const char * getMD5(){ return "41b268d597b0a51f166696f49d10ee93"; };

  };

}
#endif