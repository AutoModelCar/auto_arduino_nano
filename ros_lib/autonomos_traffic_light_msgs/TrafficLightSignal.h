#ifndef _ROS_autonomos_traffic_light_msgs_TrafficLightSignal_h
#define _ROS_autonomos_traffic_light_msgs_TrafficLightSignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_traffic_light_msgs
{

  class TrafficLightSignal : public ros::Msg
  {
    public:
      typedef uint8_t _color_type;
      _color_type color;
      typedef uint8_t _shape_type;
      _shape_type shape;
      typedef bool _blinking_type;
      _blinking_type blinking;
      enum { COLOR_UNKNOWN =  0 };
      enum { COLOR_RED =  1 };
      enum { COLOR_GREEN =  2 };
      enum { COLOR_YELLOW =  3 };
      enum { SHAPE_UNKNOWN =  0 };
      enum { SHAPE_ROUND =  1 };
      enum { SHAPE_ARROW_R =  2 };
      enum { SHAPE_ARROW_L =  3 };
      enum { SHAPE_ARROW_F =  4 };

    TrafficLightSignal():
      color(0),
      shape(0),
      blinking(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      *(outbuffer + offset + 0) = (this->shape >> (8 * 0)) & 0xFF;
      offset += sizeof(this->shape);
      union {
        bool real;
        uint8_t base;
      } u_blinking;
      u_blinking.real = this->blinking;
      *(outbuffer + offset + 0) = (u_blinking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blinking);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
      this->shape =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->shape);
      union {
        bool real;
        uint8_t base;
      } u_blinking;
      u_blinking.base = 0;
      u_blinking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blinking = u_blinking.real;
      offset += sizeof(this->blinking);
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/TrafficLightSignal"; };
    const char * getMD5(){ return "cb641ee252573ffdac5192c188f2c558"; };

  };

}
#endif