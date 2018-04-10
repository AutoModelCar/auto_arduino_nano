#ifndef _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionCurvatureInfo_h
#define _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionCurvatureInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_volkswagen_lane_assist_msgs
{

  class LaneDetectionCurvatureInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _curvature_change_type;
      _curvature_change_type curvature_change;
      typedef int16_t _curvature_change_raw_type;
      _curvature_change_raw_type curvature_change_raw;
      enum { can_id =  1665  };
      enum { can_dlc =     8  };

    LaneDetectionCurvatureInfo():
      header(),
      curvature_change(0),
      curvature_change_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_curvature_change;
      u_curvature_change.real = this->curvature_change;
      *(outbuffer + offset + 0) = (u_curvature_change.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curvature_change.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curvature_change.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curvature_change.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curvature_change);
      union {
        int16_t real;
        uint16_t base;
      } u_curvature_change_raw;
      u_curvature_change_raw.real = this->curvature_change_raw;
      *(outbuffer + offset + 0) = (u_curvature_change_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curvature_change_raw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->curvature_change_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_curvature_change;
      u_curvature_change.base = 0;
      u_curvature_change.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curvature_change.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curvature_change.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curvature_change.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curvature_change = u_curvature_change.real;
      offset += sizeof(this->curvature_change);
      union {
        int16_t real;
        uint16_t base;
      } u_curvature_change_raw;
      u_curvature_change_raw.base = 0;
      u_curvature_change_raw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curvature_change_raw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->curvature_change_raw = u_curvature_change_raw.real;
      offset += sizeof(this->curvature_change_raw);
     return offset;
    }

    const char * getType(){ return "autonomos_volkswagen_lane_assist_msgs/LaneDetectionCurvatureInfo"; };
    const char * getMD5(){ return "7e1c20edc9bd71cc6ff3c271df815633"; };

  };

}
#endif