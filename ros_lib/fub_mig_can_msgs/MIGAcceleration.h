#ifndef _ROS_fub_mig_can_msgs_MIGAcceleration_h
#define _ROS_fub_mig_can_msgs_MIGAcceleration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGAcceleration : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _current_acceleration_type;
      _current_acceleration_type current_acceleration;
      typedef uint16_t _current_acceleration_raw_type;
      _current_acceleration_raw_type current_acceleration_raw;
      typedef float _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;
      typedef uint16_t _longitudinal_acceleration_raw_type;
      _longitudinal_acceleration_raw_type longitudinal_acceleration_raw;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _acceleration_sign_type;
      _acceleration_sign_type acceleration_sign;
      enum { can_id =  428  };
      enum { can_dlc =    8  };

    MIGAcceleration():
      header(),
      current_acceleration(0),
      current_acceleration_raw(0),
      longitudinal_acceleration(0),
      longitudinal_acceleration_raw(0),
      message_counter(0),
      acceleration_sign(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_current_acceleration;
      u_current_acceleration.real = this->current_acceleration;
      *(outbuffer + offset + 0) = (u_current_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_acceleration);
      *(outbuffer + offset + 0) = (this->current_acceleration_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_acceleration_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_acceleration_raw);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.real = this->longitudinal_acceleration;
      *(outbuffer + offset + 0) = (u_longitudinal_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudinal_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudinal_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudinal_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitudinal_acceleration);
      *(outbuffer + offset + 0) = (this->longitudinal_acceleration_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->longitudinal_acceleration_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->longitudinal_acceleration_raw);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_sign;
      u_acceleration_sign.real = this->acceleration_sign;
      *(outbuffer + offset + 0) = (u_acceleration_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->acceleration_sign);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_current_acceleration;
      u_current_acceleration.base = 0;
      u_current_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_acceleration = u_current_acceleration.real;
      offset += sizeof(this->current_acceleration);
      this->current_acceleration_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->current_acceleration_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_acceleration_raw);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.base = 0;
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitudinal_acceleration = u_longitudinal_acceleration.real;
      offset += sizeof(this->longitudinal_acceleration);
      this->longitudinal_acceleration_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->longitudinal_acceleration_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->longitudinal_acceleration_raw);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      union {
        bool real;
        uint8_t base;
      } u_acceleration_sign;
      u_acceleration_sign.base = 0;
      u_acceleration_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->acceleration_sign = u_acceleration_sign.real;
      offset += sizeof(this->acceleration_sign);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGAcceleration"; };
    const char * getMD5(){ return "380ef41a1022b783da9d379e2cd3b235"; };

  };

}
#endif