#ifndef _ROS_autonomos_rviz_carstate_msgs_TwoLineTextBoxWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_TwoLineTextBoxWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"

namespace autonomos_rviz_carstate_msgs
{

  class TwoLineTextBoxWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      typedef autonomos_rviz_carstate_msgs::Text _line1_type;
      _line1_type line1;
      typedef autonomos_rviz_carstate_msgs::Text _line2_type;
      _line2_type line2;

    TwoLineTextBoxWidget():
      id(0),
      caption(),
      line1(),
      line2()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->caption.serialize(outbuffer + offset);
      offset += this->line1.serialize(outbuffer + offset);
      offset += this->line2.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      offset += this->caption.deserialize(inbuffer + offset);
      offset += this->line1.deserialize(inbuffer + offset);
      offset += this->line2.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/TwoLineTextBoxWidget"; };
    const char * getMD5(){ return "4f36addc390d99580a4b7dac242493a4"; };

  };

}
#endif