#ifndef _ROS_autonomos_vehicle_msgs_Paddles_h
#define _ROS_autonomos_vehicle_msgs_Paddles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class Paddles : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _shifter_paddle_left_type;
      _shifter_paddle_left_type shifter_paddle_left;
      typedef bool _shifter_paddle_right_type;
      _shifter_paddle_right_type shifter_paddle_right;

    Paddles():
      header(),
      shifter_paddle_left(0),
      shifter_paddle_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_shifter_paddle_left;
      u_shifter_paddle_left.real = this->shifter_paddle_left;
      *(outbuffer + offset + 0) = (u_shifter_paddle_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shifter_paddle_left);
      union {
        bool real;
        uint8_t base;
      } u_shifter_paddle_right;
      u_shifter_paddle_right.real = this->shifter_paddle_right;
      *(outbuffer + offset + 0) = (u_shifter_paddle_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shifter_paddle_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_shifter_paddle_left;
      u_shifter_paddle_left.base = 0;
      u_shifter_paddle_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->shifter_paddle_left = u_shifter_paddle_left.real;
      offset += sizeof(this->shifter_paddle_left);
      union {
        bool real;
        uint8_t base;
      } u_shifter_paddle_right;
      u_shifter_paddle_right.base = 0;
      u_shifter_paddle_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->shifter_paddle_right = u_shifter_paddle_right.real;
      offset += sizeof(this->shifter_paddle_right);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/Paddles"; };
    const char * getMD5(){ return "bd37a31400341b4df0dccc3451f1a12f"; };

  };

}
#endif