#ifndef _ROS_autonomos_rviz_carstate_msgs_TextBoxWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_TextBoxWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"

namespace autonomos_rviz_carstate_msgs
{

  class TextBoxWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      typedef autonomos_rviz_carstate_msgs::Text _text_type;
      _text_type text;

    TextBoxWidget():
      id(0),
      caption(),
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
      offset += this->text.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/TextBoxWidget"; };
    const char * getMD5(){ return "61777300e36b3d095635feebccc7efec"; };

  };

}
#endif