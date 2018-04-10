#ifndef _ROS_fub_einstein_can_msgs_EinsteinBrakeVelocityStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinBrakeVelocityStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinBrakeVelocityStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _actual_pressure_type;
      _actual_pressure_type actual_pressure;
      typedef uint16_t _actual_pressure_raw_type;
      _actual_pressure_raw_type actual_pressure_raw;
      typedef float _actual_velocity_type;
      _actual_velocity_type actual_velocity;
      typedef uint16_t _actual_velocity_raw_type;
      _actual_velocity_raw_type actual_velocity_raw;
      enum { can_id =  520  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinBrakeVelocityStatus():
      header(),
      actual_pressure(0),
      actual_pressure_raw(0),
      actual_velocity(0),
      actual_velocity_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_actual_pressure;
      u_actual_pressure.real = this->actual_pressure;
      *(outbuffer + offset + 0) = (u_actual_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actual_pressure);
      *(outbuffer + offset + 0) = (this->actual_pressure_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actual_pressure_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_actual_velocity;
      u_actual_velocity.real = this->actual_velocity;
      *(outbuffer + offset + 0) = (u_actual_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actual_velocity);
      *(outbuffer + offset + 0) = (this->actual_velocity_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actual_velocity_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->actual_velocity_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_actual_pressure;
      u_actual_pressure.base = 0;
      u_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->actual_pressure = u_actual_pressure.real;
      offset += sizeof(this->actual_pressure);
      this->actual_pressure_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->actual_pressure_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_actual_velocity;
      u_actual_velocity.base = 0;
      u_actual_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_actual_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_actual_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_actual_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->actual_velocity = u_actual_velocity.real;
      offset += sizeof(this->actual_velocity);
      this->actual_velocity_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->actual_velocity_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->actual_velocity_raw);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinBrakeVelocityStatus"; };
    const char * getMD5(){ return "ef7c6531dece51217fbbf27f62f61b54"; };

  };

}
#endif