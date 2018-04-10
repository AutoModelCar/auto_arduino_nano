#ifndef _ROS_fub_einstein_can_msgs_EinsteinVelocityStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinVelocityStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinVelocityStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _velocity_raw_type;
      _velocity_raw_type velocity_raw;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef uint16_t _path_pulse_left_type;
      _path_pulse_left_type path_pulse_left;
      typedef uint16_t _path_pulse_right_type;
      _path_pulse_right_type path_pulse_right;
      enum { can_id =  533  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinVelocityStatus():
      header(),
      velocity_raw(0),
      velocity(0),
      path_pulse_left(0),
      path_pulse_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->velocity_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->velocity_raw);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      *(outbuffer + offset + 0) = (this->path_pulse_left >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_pulse_left >> (8 * 1)) & 0xFF;
      offset += sizeof(this->path_pulse_left);
      *(outbuffer + offset + 0) = (this->path_pulse_right >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_pulse_right >> (8 * 1)) & 0xFF;
      offset += sizeof(this->path_pulse_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->velocity_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->velocity_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->velocity_raw);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      this->path_pulse_left =  ((uint16_t) (*(inbuffer + offset)));
      this->path_pulse_left |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->path_pulse_left);
      this->path_pulse_right =  ((uint16_t) (*(inbuffer + offset)));
      this->path_pulse_right |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->path_pulse_right);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinVelocityStatus"; };
    const char * getMD5(){ return "3b11772b75b5ca10618e3dd141be16a6"; };

  };

}
#endif