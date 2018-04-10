#ifndef _ROS_autonomos_vehicle_msgs_Gear_h
#define _ROS_autonomos_vehicle_msgs_Gear_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class Gear : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _position_type;
      _position_type position;
      enum { POSITION_ERROR =  -9999 };
      enum { POSITION_REVERSE =  -1 };
      enum { POSITION_NEUTRAL =  0 };
      enum { POSITION_PARK =  1 };
      enum { POSITION_DRIVE =  2 };

    Gear():
      header(),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->position = u_position.real;
      offset += sizeof(this->position);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/Gear"; };
    const char * getMD5(){ return "39e2f2bb0a80e8ca5f6ea1a8c6a807b1"; };

  };

}
#endif