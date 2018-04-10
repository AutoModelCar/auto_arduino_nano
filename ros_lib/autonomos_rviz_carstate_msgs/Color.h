#ifndef _ROS_autonomos_rviz_carstate_msgs_Color_h
#define _ROS_autonomos_rviz_carstate_msgs_Color_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_rviz_carstate_msgs
{

  class Color : public ros::Msg
  {
    public:
      typedef uint8_t _color_type;
      _color_type color;
      enum { RED =  0 };
      enum { ORANGE =  1 };
      enum { BLUE =  2 };
      enum { GREEN =  3 };
      enum { WHITE =  4 };

    Color():
      color(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/Color"; };
    const char * getMD5(){ return "20adc5fd3ea6a65f37a8758025b525fe"; };

  };

}
#endif