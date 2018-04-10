#ifndef _ROS_autonomos_rviz_carstate_msgs_Value_h
#define _ROS_autonomos_rviz_carstate_msgs_Value_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Color.h"

namespace autonomos_rviz_carstate_msgs
{

  class Value : public ros::Msg
  {
    public:
      typedef float _value_type;
      _value_type value;
      typedef autonomos_rviz_carstate_msgs::Color _color_type;
      _color_type color;

    Value():
      value(0),
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/Value"; };
    const char * getMD5(){ return "bd728ebb16e4b250dd8d3859d02c496a"; };

  };

}
#endif