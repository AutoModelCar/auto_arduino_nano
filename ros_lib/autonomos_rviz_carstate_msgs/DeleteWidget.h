#ifndef _ROS_autonomos_rviz_carstate_msgs_DeleteWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_DeleteWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_rviz_carstate_msgs
{

  class DeleteWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;

    DeleteWidget():
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/DeleteWidget"; };
    const char * getMD5(){ return "77962e6c8dbdcc134ef99d44edc6bf05"; };

  };

}
#endif