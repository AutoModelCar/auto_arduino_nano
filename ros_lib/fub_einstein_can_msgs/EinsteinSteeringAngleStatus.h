#ifndef _ROS_fub_einstein_can_msgs_EinsteinSteeringAngleStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinSteeringAngleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinSteeringAngleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef uint16_t _steering_angle_raw_type;
      _steering_angle_raw_type steering_angle_raw;
      typedef float _steering_angle_type;
      _steering_angle_type steering_angle;
      typedef uint16_t _steering_momentum_raw_type;
      _steering_momentum_raw_type steering_momentum_raw;
      typedef float _steering_momentum_type;
      _steering_momentum_type steering_momentum;
      enum { can_id =  566  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinSteeringAngleStatus():
      header(),
      message_counter(0),
      steering_angle_raw(0),
      steering_angle(0),
      steering_momentum_raw(0),
      steering_momentum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      *(outbuffer + offset + 0) = (this->steering_angle_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steering_angle_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steering_angle_raw);
      union {
        float real;
        uint32_t base;
      } u_steering_angle;
      u_steering_angle.real = this->steering_angle;
      *(outbuffer + offset + 0) = (u_steering_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_angle);
      *(outbuffer + offset + 0) = (this->steering_momentum_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steering_momentum_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steering_momentum_raw);
      union {
        float real;
        uint32_t base;
      } u_steering_momentum;
      u_steering_momentum.real = this->steering_momentum;
      *(outbuffer + offset + 0) = (u_steering_momentum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_momentum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_momentum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_momentum.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_momentum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      this->steering_angle_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steering_angle_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steering_angle_raw);
      union {
        float real;
        uint32_t base;
      } u_steering_angle;
      u_steering_angle.base = 0;
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_angle = u_steering_angle.real;
      offset += sizeof(this->steering_angle);
      this->steering_momentum_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steering_momentum_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steering_momentum_raw);
      union {
        float real;
        uint32_t base;
      } u_steering_momentum;
      u_steering_momentum.base = 0;
      u_steering_momentum.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_momentum.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_momentum.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_momentum.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_momentum = u_steering_momentum.real;
      offset += sizeof(this->steering_momentum);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinSteeringAngleStatus"; };
    const char * getMD5(){ return "62aa1b94c09b0763cbd848c193262109"; };

  };

}
#endif