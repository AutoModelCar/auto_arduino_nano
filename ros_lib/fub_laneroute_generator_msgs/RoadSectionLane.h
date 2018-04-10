#ifndef _ROS_fub_laneroute_generator_msgs_RoadSectionLane_h
#define _ROS_fub_laneroute_generator_msgs_RoadSectionLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fub_laneroute_generator_msgs
{

  class RoadSectionLane : public ros::Msg
  {
    public:
      typedef uint64_t _road_section_id_type;
      _road_section_id_type road_section_id;
      typedef uint64_t _lane_id_type;
      _lane_id_type lane_id;
      typedef uint64_t _weight_type;
      _weight_type weight;
      typedef bool _lane_change_left_to_right_type;
      _lane_change_left_to_right_type lane_change_left_to_right;
      typedef bool _lane_change_right_to_left_type;
      _lane_change_right_to_left_type lane_change_right_to_left;

    RoadSectionLane():
      road_section_id(0),
      lane_id(0),
      weight(0),
      lane_change_left_to_right(0),
      lane_change_right_to_left(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_road_section_id;
      u_road_section_id.real = this->road_section_id;
      *(outbuffer + offset + 0) = (u_road_section_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_road_section_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_road_section_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_road_section_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->road_section_id);
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
        uint64_t real;
        uint32_t base;
      } u_weight;
      u_weight.real = this->weight;
      *(outbuffer + offset + 0) = (u_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weight);
      union {
        bool real;
        uint8_t base;
      } u_lane_change_left_to_right;
      u_lane_change_left_to_right.real = this->lane_change_left_to_right;
      *(outbuffer + offset + 0) = (u_lane_change_left_to_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lane_change_left_to_right);
      union {
        bool real;
        uint8_t base;
      } u_lane_change_right_to_left;
      u_lane_change_right_to_left.real = this->lane_change_right_to_left;
      *(outbuffer + offset + 0) = (u_lane_change_right_to_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lane_change_right_to_left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_road_section_id;
      u_road_section_id.base = 0;
      u_road_section_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_road_section_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_road_section_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_road_section_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->road_section_id = u_road_section_id.real;
      offset += sizeof(this->road_section_id);
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
        uint64_t real;
        uint32_t base;
      } u_weight;
      u_weight.base = 0;
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weight = u_weight.real;
      offset += sizeof(this->weight);
      union {
        bool real;
        uint8_t base;
      } u_lane_change_left_to_right;
      u_lane_change_left_to_right.base = 0;
      u_lane_change_left_to_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lane_change_left_to_right = u_lane_change_left_to_right.real;
      offset += sizeof(this->lane_change_left_to_right);
      union {
        bool real;
        uint8_t base;
      } u_lane_change_right_to_left;
      u_lane_change_right_to_left.base = 0;
      u_lane_change_right_to_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lane_change_right_to_left = u_lane_change_right_to_left.real;
      offset += sizeof(this->lane_change_right_to_left);
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/RoadSectionLane"; };
    const char * getMD5(){ return "3c129a56f0cc02691f4ae7afc792e4c9"; };

  };

}
#endif