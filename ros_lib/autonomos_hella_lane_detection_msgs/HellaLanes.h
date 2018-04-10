#ifndef _ROS_autonomos_hella_lane_detection_msgs_HellaLanes_h
#define _ROS_autonomos_hella_lane_detection_msgs_HellaLanes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_hella_lane_detection_msgs/HellaBoundary.h"

namespace autonomos_hella_lane_detection_msgs
{

  class HellaLanes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _version_type;
      _version_type version;
      autonomos_hella_lane_detection_msgs::HellaBoundary boundaries[8];

    HellaLanes():
      header(),
      version(0),
      boundaries()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_version;
      u_version.real = this->version;
      *(outbuffer + offset + 0) = (u_version.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_version.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_version.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_version.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->version);
      for( uint32_t i = 0; i < 8; i++){
      offset += this->boundaries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_version;
      u_version.base = 0;
      u_version.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_version.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_version.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_version.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->version = u_version.real;
      offset += sizeof(this->version);
      for( uint32_t i = 0; i < 8; i++){
      offset += this->boundaries[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "autonomos_hella_lane_detection_msgs/HellaLanes"; };
    const char * getMD5(){ return "6f077f4a1e52ea1f82f5304c547b4f56"; };

  };

}
#endif