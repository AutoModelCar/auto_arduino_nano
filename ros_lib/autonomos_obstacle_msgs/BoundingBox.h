#ifndef _ROS_autonomos_obstacle_msgs_BoundingBox_h
#define _ROS_autonomos_obstacle_msgs_BoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"

namespace autonomos_obstacle_msgs
{

  class BoundingBox : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _center_pose_type;
      _center_pose_type center_pose;
      typedef geometry_msgs::Vector3 _size_type;
      _size_type size;
      float covariances[9];

    BoundingBox():
      header(),
      center_pose(),
      size(),
      covariances()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->center_pose.serialize(outbuffer + offset);
      offset += this->size.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->center_pose.deserialize(inbuffer + offset);
      offset += this->size.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariances[i]));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_obstacle_msgs/BoundingBox"; };
    const char * getMD5(){ return "e090cb067881bef73a89620ad169580d"; };

  };

}
#endif