#ifndef _ROS_autonomos_rviz_carstate_msgs_TwoValueGaugeWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_TwoValueGaugeWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"
#include "autonomos_rviz_carstate_msgs/Value.h"

namespace autonomos_rviz_carstate_msgs
{

  class TwoValueGaugeWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      typedef autonomos_rviz_carstate_msgs::Value _gauge1_type;
      _gauge1_type gauge1;
      typedef autonomos_rviz_carstate_msgs::Value _gauge2_type;
      _gauge2_type gauge2;
      typedef autonomos_rviz_carstate_msgs::Value _leftValue_type;
      _leftValue_type leftValue;
      typedef autonomos_rviz_carstate_msgs::Value _rightValue_type;
      _rightValue_type rightValue;

    TwoValueGaugeWidget():
      id(0),
      caption(),
      gauge1(),
      gauge2(),
      leftValue(),
      rightValue()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->caption.serialize(outbuffer + offset);
      offset += this->gauge1.serialize(outbuffer + offset);
      offset += this->gauge2.serialize(outbuffer + offset);
      offset += this->leftValue.serialize(outbuffer + offset);
      offset += this->rightValue.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      offset += this->caption.deserialize(inbuffer + offset);
      offset += this->gauge1.deserialize(inbuffer + offset);
      offset += this->gauge2.deserialize(inbuffer + offset);
      offset += this->leftValue.deserialize(inbuffer + offset);
      offset += this->rightValue.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/TwoValueGaugeWidget"; };
    const char * getMD5(){ return "38ccfcfd576ff255ca9efc30570d80c7"; };

  };

}
#endif