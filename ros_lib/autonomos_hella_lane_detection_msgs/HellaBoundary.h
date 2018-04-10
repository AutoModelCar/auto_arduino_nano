#ifndef _ROS_autonomos_hella_lane_detection_msgs_HellaBoundary_h
#define _ROS_autonomos_hella_lane_detection_msgs_HellaBoundary_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_hella_lane_detection_msgs
{

  class HellaBoundary : public ros::Msg
  {
    public:
      float clothoid[4];
      typedef float _quality_type;
      _quality_type quality;
      typedef uint32_t _quality_raw_type;
      _quality_raw_type quality_raw;
      typedef float _range_of_sight_type;
      _range_of_sight_type range_of_sight;
      typedef uint32_t _range_of_sight_raw_type;
      _range_of_sight_raw_type range_of_sight_raw;
      typedef float _mark_width_type;
      _mark_width_type mark_width;
      typedef uint16_t _mark_width_raw_type;
      _mark_width_raw_type mark_width_raw;
      typedef uint8_t _boundary_type_type;
      _boundary_type_type boundary_type;
      typedef uint8_t _position_type;
      _position_type position;
      enum { BoundaryType_Solid =  0 };
      enum { BoundaryType_Dashed =  1 };
      enum { BoundaryType_BitumenGap =  6 };
      enum { BoundaryType_BottsDots =  7 };
      enum { BoundaryType_Other =  8 };
      enum { BoundaryType_Unknown =  15 };
      enum { BoundaryType_Invalid =  255 };
      enum { Position_Ego_Left =  0 };
      enum { Position_Ego_Right =  1 };
      enum { Position_Left_Left =  2 };
      enum { Position_Left_Right =  3 };
      enum { Position_Right_Left =  4 };
      enum { Position_Right_Right =  5 };
      enum { Position_Unknown =  6 };
      enum { Position_Invalid =  255 };

    HellaBoundary():
      clothoid(),
      quality(0),
      quality_raw(0),
      range_of_sight(0),
      range_of_sight_raw(0),
      mark_width(0),
      mark_width_raw(0),
      boundary_type(0),
      position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->clothoid[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_quality;
      u_quality.real = this->quality;
      *(outbuffer + offset + 0) = (u_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quality);
      *(outbuffer + offset + 0) = (this->quality_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->quality_raw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->quality_raw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->quality_raw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quality_raw);
      union {
        float real;
        uint32_t base;
      } u_range_of_sight;
      u_range_of_sight.real = this->range_of_sight;
      *(outbuffer + offset + 0) = (u_range_of_sight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_of_sight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_of_sight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_of_sight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_of_sight);
      *(outbuffer + offset + 0) = (this->range_of_sight_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->range_of_sight_raw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->range_of_sight_raw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->range_of_sight_raw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_of_sight_raw);
      union {
        float real;
        uint32_t base;
      } u_mark_width;
      u_mark_width.real = this->mark_width;
      *(outbuffer + offset + 0) = (u_mark_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mark_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mark_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mark_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mark_width);
      *(outbuffer + offset + 0) = (this->mark_width_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mark_width_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->mark_width_raw);
      *(outbuffer + offset + 0) = (this->boundary_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->boundary_type);
      *(outbuffer + offset + 0) = (this->position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->clothoid[i]));
      }
      union {
        float real;
        uint32_t base;
      } u_quality;
      u_quality.base = 0;
      u_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->quality = u_quality.real;
      offset += sizeof(this->quality);
      this->quality_raw =  ((uint32_t) (*(inbuffer + offset)));
      this->quality_raw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->quality_raw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->quality_raw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->quality_raw);
      union {
        float real;
        uint32_t base;
      } u_range_of_sight;
      u_range_of_sight.base = 0;
      u_range_of_sight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_of_sight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_of_sight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_of_sight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_of_sight = u_range_of_sight.real;
      offset += sizeof(this->range_of_sight);
      this->range_of_sight_raw =  ((uint32_t) (*(inbuffer + offset)));
      this->range_of_sight_raw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->range_of_sight_raw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->range_of_sight_raw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->range_of_sight_raw);
      union {
        float real;
        uint32_t base;
      } u_mark_width;
      u_mark_width.base = 0;
      u_mark_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mark_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mark_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mark_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mark_width = u_mark_width.real;
      offset += sizeof(this->mark_width);
      this->mark_width_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->mark_width_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->mark_width_raw);
      this->boundary_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->boundary_type);
      this->position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->position);
     return offset;
    }

    const char * getType(){ return "autonomos_hella_lane_detection_msgs/HellaBoundary"; };
    const char * getMD5(){ return "073313d475cee7892aa09d50cd645a37"; };

  };

}
#endif