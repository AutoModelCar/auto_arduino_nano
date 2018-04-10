#ifndef _ROS_autonomos_rviz_carstate_msgs_SpeedLimitWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_SpeedLimitWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"

namespace autonomos_rviz_carstate_msgs
{

  class SpeedLimitWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      typedef bool _valid_type;
      _valid_type valid;
      typedef int32_t _speed_type;
      _speed_type speed;
      typedef autonomos_rviz_carstate_msgs::Text _text_type;
      _text_type text;

    SpeedLimitWidget():
      id(0),
      caption(),
      valid(0),
      speed(0),
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
      } u_valid;
      u_valid.real = this->valid;
      *(outbuffer + offset + 0) = (u_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid);
      union {
        int32_t real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
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
      } u_valid;
      u_valid.base = 0;
      u_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid = u_valid.real;
      offset += sizeof(this->valid);
      union {
        int32_t real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      offset += this->text.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/SpeedLimitWidget"; };
    const char * getMD5(){ return "a86eacb946ae08badb80655ffc97de5d"; };

  };

}
#endif