#ifndef _ROS_autonomos_rviz_carstate_msgs_TrafficLightWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_TrafficLightWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"

namespace autonomos_rviz_carstate_msgs
{

  class TrafficLightWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      typedef bool _red_light_type;
      _red_light_type red_light;
      typedef bool _yellow_light_type;
      _yellow_light_type yellow_light;
      typedef bool _green_light_type;
      _green_light_type green_light;
      typedef autonomos_rviz_carstate_msgs::Text _text_type;
      _text_type text;

    TrafficLightWidget():
      id(0),
      caption(),
      red_light(0),
      yellow_light(0),
      green_light(0),
      text()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->caption.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_red_light;
      u_red_light.real = this->red_light;
      *(outbuffer + offset + 0) = (u_red_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->red_light);
      union {
        bool real;
        uint8_t base;
      } u_yellow_light;
      u_yellow_light.real = this->yellow_light;
      *(outbuffer + offset + 0) = (u_yellow_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yellow_light);
      union {
        bool real;
        uint8_t base;
      } u_green_light;
      u_green_light.real = this->green_light;
      *(outbuffer + offset + 0) = (u_green_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->green_light);
      offset += this->text.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      offset += this->caption.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_red_light;
      u_red_light.base = 0;
      u_red_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->red_light = u_red_light.real;
      offset += sizeof(this->red_light);
      union {
        bool real;
        uint8_t base;
      } u_yellow_light;
      u_yellow_light.base = 0;
      u_yellow_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yellow_light = u_yellow_light.real;
      offset += sizeof(this->yellow_light);
      union {
        bool real;
        uint8_t base;
      } u_green_light;
      u_green_light.base = 0;
      u_green_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->green_light = u_green_light.real;
      offset += sizeof(this->green_light);
      offset += this->text.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/TrafficLightWidget"; };
    const char * getMD5(){ return "a35407f740d1b740afccb2259d609aa8"; };

  };

}
#endif