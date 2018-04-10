#ifndef _ROS_autonomos_navigation_msgs_WeightedLane_h
#define _ROS_autonomos_navigation_msgs_WeightedLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_navigation_msgs
{

  class WeightedLane : public ros::Msg
  {
    public:
      typedef uint64_t _roadsection_id_type;
      _roadsection_id_type roadsection_id;
      typedef uint64_t _lane_id_type;
      _lane_id_type lane_id;
      typedef float _start_weight_type;
      _start_weight_type start_weight;
      typedef float _end_weight_type;
      _end_weight_type end_weight;

    WeightedLane():
      roadsection_id(0),
      lane_id(0),
      start_weight(0),
      end_weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.real = this->roadsection_id;
      *(outbuffer + offset + 0) = (u_roadsection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roadsection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roadsection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roadsection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roadsection_id);
      union {
        uint64_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.real = this->lane_id;
      *(outbuffer + offset + 0) = (u_lane_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_id);
      union {
        float real;
        uint32_t base;
      } u_start_weight;
      u_start_weight.real = this->start_weight;
      *(outbuffer + offset + 0) = (u_start_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_weight);
      union {
        float real;
        uint32_t base;
      } u_end_weight;
      u_end_weight.real = this->end_weight;
      *(outbuffer + offset + 0) = (u_end_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_end_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_end_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_end_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.base = 0;
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roadsection_id = u_roadsection_id.real;
      offset += sizeof(this->roadsection_id);
      union {
        uint64_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.base = 0;
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_id = u_lane_id.real;
      offset += sizeof(this->lane_id);
      union {
        float real;
        uint32_t base;
      } u_start_weight;
      u_start_weight.base = 0;
      u_start_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_weight = u_start_weight.real;
      offset += sizeof(this->start_weight);
      union {
        float real;
        uint32_t base;
      } u_end_weight;
      u_end_weight.base = 0;
      u_end_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_end_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_end_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_end_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->end_weight = u_end_weight.real;
      offset += sizeof(this->end_weight);
     return offset;
    }

    const char * getType(){ return "autonomos_navigation_msgs/WeightedLane"; };
    const char * getMD5(){ return "d20201ae838ae2b36eee663bec0b4a3a"; };

  };

}
#endif