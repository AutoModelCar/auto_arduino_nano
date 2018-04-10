#ifndef _ROS_autonomos_lane_msgs_Boundary_h
#define _ROS_autonomos_lane_msgs_Boundary_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace autonomos_lane_msgs
{

  class Boundary : public ros::Msg
  {
    public:
      geometry_msgs::Vector3 polynomial[4];
      typedef float _quality_type;
      _quality_type quality;
      typedef float _range_type;
      _range_type range;
      typedef float _mark_width_type;
      _mark_width_type mark_width;
      typedef uint8_t _boundary_type_type;
      _boundary_type_type boundary_type;
      enum { BoundaryType_None =  0 };
      enum { BoundaryType_Solid =  1 };
      enum { BoundaryType_Dashed =  2 };
      enum { BoundaryType_BitumenGap =  3 };
      enum { BoundaryType_BottsDots =  4 };
      enum { BoundaryType_Other =  5 };

    Boundary():
      polynomial(),
      quality(0),
      range(0),
      mark_width(0),
      boundary_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += this->polynomial[i].serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->boundary_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->boundary_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
      offset += this->polynomial[i].deserialize(inbuffer + offset);
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
      this->boundary_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->boundary_type);
     return offset;
    }

    const char * getType(){ return "autonomos_lane_msgs/Boundary"; };
    const char * getMD5(){ return "334243a46afbe827f3328b2c54df8e58"; };

  };

}
#endif