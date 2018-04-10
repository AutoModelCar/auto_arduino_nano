#ifndef _ROS_autonomos_lane_msgs_Lane_h
#define _ROS_autonomos_lane_msgs_Lane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_lane_msgs/Boundary.h"

namespace autonomos_lane_msgs
{

  class Lane : public ros::Msg
  {
    public:
      typedef autonomos_lane_msgs::Boundary _left_boundary_type;
      _left_boundary_type left_boundary;
      typedef autonomos_lane_msgs::Boundary _right_boundary_type;
      _right_boundary_type right_boundary;
      typedef uint8_t _lane_position_type;
      _lane_position_type lane_position;
      enum { Lane_Ego =  0 };
      enum { Lane_Left =  1 };
      enum { Lane_Right =  2 };

    Lane():
      left_boundary(),
      right_boundary(),
      lane_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->left_boundary.serialize(outbuffer + offset);
      offset += this->right_boundary.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lane_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lane_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->left_boundary.deserialize(inbuffer + offset);
      offset += this->right_boundary.deserialize(inbuffer + offset);
      this->lane_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lane_position);
     return offset;
    }

    const char * getType(){ return "autonomos_lane_msgs/Lane"; };
    const char * getMD5(){ return "10b221078c1d808932ba00498eb15c02"; };

  };

}
#endif