#ifndef _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionLaneInfo_h
#define _ROS_autonomos_volkswagen_lane_assist_msgs_LaneDetectionLaneInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_volkswagen_lane_assist_msgs
{

  class LaneDetectionLaneInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _lane_width_type;
      _lane_width_type lane_width;
      typedef uint16_t _lane_width_raw_type;
      _lane_width_raw_type lane_width_raw;
      typedef float _lane_offset_type;
      _lane_offset_type lane_offset;
      typedef int16_t _lane_offset_raw_type;
      _lane_offset_raw_type lane_offset_raw;
      typedef float _detection_quality_type;
      _detection_quality_type detection_quality;
      typedef uint8_t _detection_quality_raw_type;
      _detection_quality_raw_type detection_quality_raw;
      typedef float _yaw_angle_error_type;
      _yaw_angle_error_type yaw_angle_error;
      typedef int16_t _yaw_angle_error_raw_type;
      _yaw_angle_error_raw_type yaw_angle_error_raw;
      enum { can_id =  1664  };
      enum { can_dlc =     8 };

    LaneDetectionLaneInfo():
      header(),
      lane_width(0),
      lane_width_raw(0),
      lane_offset(0),
      lane_offset_raw(0),
      detection_quality(0),
      detection_quality_raw(0),
      yaw_angle_error(0),
      yaw_angle_error_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_lane_width;
      u_lane_width.real = this->lane_width;
      *(outbuffer + offset + 0) = (u_lane_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_width);
      *(outbuffer + offset + 0) = (this->lane_width_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_width_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->lane_width_raw);
      union {
        float real;
        uint32_t base;
      } u_lane_offset;
      u_lane_offset.real = this->lane_offset;
      *(outbuffer + offset + 0) = (u_lane_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_offset);
      union {
        int16_t real;
        uint16_t base;
      } u_lane_offset_raw;
      u_lane_offset_raw.real = this->lane_offset_raw;
      *(outbuffer + offset + 0) = (u_lane_offset_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_offset_raw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->lane_offset_raw);
      union {
        float real;
        uint32_t base;
      } u_detection_quality;
      u_detection_quality.real = this->detection_quality;
      *(outbuffer + offset + 0) = (u_detection_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_quality);
      *(outbuffer + offset + 0) = (this->detection_quality_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detection_quality_raw);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle_error;
      u_yaw_angle_error.real = this->yaw_angle_error;
      *(outbuffer + offset + 0) = (u_yaw_angle_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_angle_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_angle_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_angle_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_angle_error);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_angle_error_raw;
      u_yaw_angle_error_raw.real = this->yaw_angle_error_raw;
      *(outbuffer + offset + 0) = (u_yaw_angle_error_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_angle_error_raw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_angle_error_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_lane_width;
      u_lane_width.base = 0;
      u_lane_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_width = u_lane_width.real;
      offset += sizeof(this->lane_width);
      this->lane_width_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->lane_width_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->lane_width_raw);
      union {
        float real;
        uint32_t base;
      } u_lane_offset;
      u_lane_offset.base = 0;
      u_lane_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_offset = u_lane_offset.real;
      offset += sizeof(this->lane_offset);
      union {
        int16_t real;
        uint16_t base;
      } u_lane_offset_raw;
      u_lane_offset_raw.base = 0;
      u_lane_offset_raw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_offset_raw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lane_offset_raw = u_lane_offset_raw.real;
      offset += sizeof(this->lane_offset_raw);
      union {
        float real;
        uint32_t base;
      } u_detection_quality;
      u_detection_quality.base = 0;
      u_detection_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_quality = u_detection_quality.real;
      offset += sizeof(this->detection_quality);
      this->detection_quality_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->detection_quality_raw);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle_error;
      u_yaw_angle_error.base = 0;
      u_yaw_angle_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_angle_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_angle_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_angle_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_angle_error = u_yaw_angle_error.real;
      offset += sizeof(this->yaw_angle_error);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_angle_error_raw;
      u_yaw_angle_error_raw.base = 0;
      u_yaw_angle_error_raw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_angle_error_raw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_angle_error_raw = u_yaw_angle_error_raw.real;
      offset += sizeof(this->yaw_angle_error_raw);
     return offset;
    }

    const char * getType(){ return "autonomos_volkswagen_lane_assist_msgs/LaneDetectionLaneInfo"; };
    const char * getMD5(){ return "533221d9edb1fcca90bde12a7a11c7fd"; };

  };

}
#endif