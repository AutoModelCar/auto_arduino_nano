#ifndef _ROS_autonomos_transform_handler_msgs_Transform_h
#define _ROS_autonomos_transform_handler_msgs_Transform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace autonomos_transform_handler_msgs
{

  class Transform : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _transform_type;
      _transform_type transform;
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;

    Transform():
      transform(),
      frame_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->transform.serialize(outbuffer + offset);
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->transform.deserialize(inbuffer + offset);
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
     return offset;
    }

    const char * getType(){ return "autonomos_transform_handler_msgs/Transform"; };
    const char * getMD5(){ return "a60d90120c5004fc9a40619c1e0b2da3"; };

  };

}
#endif