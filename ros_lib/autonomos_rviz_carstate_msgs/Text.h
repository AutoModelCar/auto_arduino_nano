#ifndef _ROS_autonomos_rviz_carstate_msgs_Text_h
#define _ROS_autonomos_rviz_carstate_msgs_Text_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Color.h"
#include "std_msgs/String.h"

namespace autonomos_rviz_carstate_msgs
{

  class Text : public ros::Msg
  {
    public:
      typedef autonomos_rviz_carstate_msgs::Color _color_type;
      _color_type color;
      typedef std_msgs::String _text_type;
      _text_type text;
      typedef uint8_t _fontSize_type;
      _fontSize_type fontSize;

    Text():
      color(),
      text(),
      fontSize(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      offset += this->text.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->fontSize >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fontSize);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
      offset += this->text.deserialize(inbuffer + offset);
      this->fontSize =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->fontSize);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/Text"; };
    const char * getMD5(){ return "50b71c36bdb52d2dfbab6328a56988d3"; };

  };

}
#endif