#ifndef _ROS_fub_mig_can_msgs_MIGMotorStatus_h
#define _ROS_fub_mig_can_msgs_MIGMotorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGMotorStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _pedal_status_type;
      _pedal_status_type pedal_status;
      typedef bool _kick_down_type;
      _kick_down_type kick_down;
      typedef float _pedal_value_type;
      _pedal_value_type pedal_value;
      typedef uint8_t _pedal_value_raw_type;
      _pedal_value_raw_type pedal_value_raw;
      typedef float _revolution_speed_type;
      _revolution_speed_type revolution_speed;
      typedef uint16_t _revolution_speed_raw_type;
      _revolution_speed_raw_type revolution_speed_raw;
      enum { can_id =  640  };
      enum { can_dlc =    8 };

    MIGMotorStatus():
      header(),
      pedal_status(0),
      kick_down(0),
      pedal_value(0),
      pedal_value_raw(0),
      revolution_speed(0),
      revolution_speed_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pedal_status;
      u_pedal_status.real = this->pedal_status;
      *(outbuffer + offset + 0) = (u_pedal_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pedal_status);
      union {
        bool real;
        uint8_t base;
      } u_kick_down;
      u_kick_down.real = this->kick_down;
      *(outbuffer + offset + 0) = (u_kick_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kick_down);
      union {
        float real;
        uint32_t base;
      } u_pedal_value;
      u_pedal_value.real = this->pedal_value;
      *(outbuffer + offset + 0) = (u_pedal_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pedal_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pedal_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pedal_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pedal_value);
      *(outbuffer + offset + 0) = (this->pedal_value_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pedal_value_raw);
      union {
        float real;
        uint32_t base;
      } u_revolution_speed;
      u_revolution_speed.real = this->revolution_speed;
      *(outbuffer + offset + 0) = (u_revolution_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_revolution_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_revolution_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_revolution_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->revolution_speed);
      *(outbuffer + offset + 0) = (this->revolution_speed_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->revolution_speed_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->revolution_speed_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pedal_status;
      u_pedal_status.base = 0;
      u_pedal_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pedal_status = u_pedal_status.real;
      offset += sizeof(this->pedal_status);
      union {
        bool real;
        uint8_t base;
      } u_kick_down;
      u_kick_down.base = 0;
      u_kick_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->kick_down = u_kick_down.real;
      offset += sizeof(this->kick_down);
      union {
        float real;
        uint32_t base;
      } u_pedal_value;
      u_pedal_value.base = 0;
      u_pedal_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pedal_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pedal_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pedal_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pedal_value = u_pedal_value.real;
      offset += sizeof(this->pedal_value);
      this->pedal_value_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pedal_value_raw);
      union {
        float real;
        uint32_t base;
      } u_revolution_speed;
      u_revolution_speed.base = 0;
      u_revolution_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_revolution_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_revolution_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_revolution_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->revolution_speed = u_revolution_speed.real;
      offset += sizeof(this->revolution_speed);
      this->revolution_speed_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->revolution_speed_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->revolution_speed_raw);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGMotorStatus"; };
    const char * getMD5(){ return "75db6882364f0c6728f77d000e8fd9a3"; };

  };

}
#endif