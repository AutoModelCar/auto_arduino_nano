#ifndef _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionLaneRangeInfo_h
#define _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionLaneRangeInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_volkswagen_lane_assist_msgs
{

  class LaneDetectionLaneRangeInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _range_type;
      _range_type range;
      typedef uint16_t _range_raw_type;
      _range_raw_type range_raw;
      enum { can_id =  1668  };
      enum { can_dlc =     8  };

    LaneDetectionLaneRangeInfo():
      header(),
      range(0),
      range_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      *(outbuffer + offset + 0) = (this->range_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->range_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->range_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
      this->range_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->range_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->range_raw);
     return offset;
    }

    const char * getType(){ return "autonomos_volkswagen_lane_assist_msgs/LaneDetectionLaneRangeInfo"; };
    const char * getMD5(){ return "7bb2419bee6ad83afce8548e287428ed"; };

  };

}
#endif