#ifndef _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionBorderInfo_h
#define _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionBorderInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_volkswagen_lane_assist_msgs
{

  class LaneDetectionBorderInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _dirt_detected_type;
      _dirt_detected_type dirt_detected;
      typedef bool _is_solid_left_type;
      _is_solid_left_type is_solid_left;
      typedef bool _is_solid_right_type;
      _is_solid_right_type is_solid_right;
      typedef float _lane_curvature_type;
      _lane_curvature_type lane_curvature;
      typedef int16_t _lane_curvature_raw_type;
      _lane_curvature_raw_type lane_curvature_raw;
      typedef float _marking_width_left_type;
      _marking_width_left_type marking_width_left;
      typedef uint8_t _marking_width_left_raw_type;
      _marking_width_left_raw_type marking_width_left_raw;
      typedef float _marking_width_right_type;
      _marking_width_right_type marking_width_right;
      typedef uint8_t _marking_width_right_raw_type;
      _marking_width_right_raw_type marking_width_right_raw;
      enum { can_id =  1666 };
      enum { can_dlc =     8 };

    LaneDetectionBorderInfo():
      header(),
      dirt_detected(0),
      is_solid_left(0),
      is_solid_right(0),
      lane_curvature(0),
      lane_curvature_raw(0),
      marking_width_left(0),
      marking_width_left_raw(0),
      marking_width_right(0),
      marking_width_right_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_dirt_detected;
      u_dirt_detected.real = this->dirt_detected;
      *(outbuffer + offset + 0) = (u_dirt_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dirt_detected);
      union {
        bool real;
        uint8_t base;
      } u_is_solid_left;
      u_is_solid_left.real = this->is_solid_left;
      *(outbuffer + offset + 0) = (u_is_solid_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_solid_left);
      union {
        bool real;
        uint8_t base;
      } u_is_solid_right;
      u_is_solid_right.real = this->is_solid_right;
      *(outbuffer + offset + 0) = (u_is_solid_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_solid_right);
      union {
        float real;
        uint32_t base;
      } u_lane_curvature;
      u_lane_curvature.real = this->lane_curvature;
      *(outbuffer + offset + 0) = (u_lane_curvature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_curvature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_curvature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_curvature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_curvature);
      union {
        int16_t real;
        uint16_t base;
      } u_lane_curvature_raw;
      u_lane_curvature_raw.real = this->lane_curvature_raw;
      *(outbuffer + offset + 0) = (u_lane_curvature_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_curvature_raw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->lane_curvature_raw);
      union {
        float real;
        uint32_t base;
      } u_marking_width_left;
      u_marking_width_left.real = this->marking_width_left;
      *(outbuffer + offset + 0) = (u_marking_width_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_marking_width_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_marking_width_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_marking_width_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->marking_width_left);
      *(outbuffer + offset + 0) = (this->marking_width_left_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->marking_width_left_raw);
      union {
        float real;
        uint32_t base;
      } u_marking_width_right;
      u_marking_width_right.real = this->marking_width_right;
      *(outbuffer + offset + 0) = (u_marking_width_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_marking_width_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_marking_width_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_marking_width_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->marking_width_right);
      *(outbuffer + offset + 0) = (this->marking_width_right_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->marking_width_right_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_dirt_detected;
      u_dirt_detected.base = 0;
      u_dirt_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dirt_detected = u_dirt_detected.real;
      offset += sizeof(this->dirt_detected);
      union {
        bool real;
        uint8_t base;
      } u_is_solid_left;
      u_is_solid_left.base = 0;
      u_is_solid_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_solid_left = u_is_solid_left.real;
      offset += sizeof(this->is_solid_left);
      union {
        bool real;
        uint8_t base;
      } u_is_solid_right;
      u_is_solid_right.base = 0;
      u_is_solid_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_solid_right = u_is_solid_right.real;
      offset += sizeof(this->is_solid_right);
      union {
        float real;
        uint32_t base;
      } u_lane_curvature;
      u_lane_curvature.base = 0;
      u_lane_curvature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_curvature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_curvature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_curvature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_curvature = u_lane_curvature.real;
      offset += sizeof(this->lane_curvature);
      union {
        int16_t real;
        uint16_t base;
      } u_lane_curvature_raw;
      u_lane_curvature_raw.base = 0;
      u_lane_curvature_raw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_curvature_raw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lane_curvature_raw = u_lane_curvature_raw.real;
      offset += sizeof(this->lane_curvature_raw);
      union {
        float real;
        uint32_t base;
      } u_marking_width_left;
      u_marking_width_left.base = 0;
      u_marking_width_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_marking_width_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_marking_width_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_marking_width_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->marking_width_left = u_marking_width_left.real;
      offset += sizeof(this->marking_width_left);
      this->marking_width_left_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->marking_width_left_raw);
      union {
        float real;
        uint32_t base;
      } u_marking_width_right;
      u_marking_width_right.base = 0;
      u_marking_width_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_marking_width_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_marking_width_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_marking_width_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->marking_width_right = u_marking_width_right.real;
      offset += sizeof(this->marking_width_right);
      this->marking_width_right_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->marking_width_right_raw);
     return offset;
    }

    const char * getType(){ return "autonomos_volkswagen_lane_assist_msgs/LaneDetectionBorderInfo"; };
    const char * getMD5(){ return "8b68b6ebe873b73e39eb0f02047defc3"; };

  };

}
#endif