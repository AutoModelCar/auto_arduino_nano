#ifndef _ROS_autonomos_stereo_camera_msgs_PackedPointCloud_h
#define _ROS_autonomos_stereo_camera_msgs_PackedPointCloud_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_stereo_camera_msgs/PackedPoint.h"
#include "geometry_msgs/Point.h"

namespace autonomos_stereo_camera_msgs
{

  class PackedPointCloud : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _precision_type;
      _precision_type precision;
      uint32_t points_length;
      typedef autonomos_stereo_camera_msgs::PackedPoint _points_type;
      _points_type st_points;
      _points_type * points;
      typedef geometry_msgs::Point _worldOffset_type;
      _worldOffset_type worldOffset;

    PackedPointCloud():
      header(),
      precision(0),
      points_length(0), points(NULL),
      worldOffset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->precision >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->precision >> (8 * 1)) & 0xFF;
      offset += sizeof(this->precision);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      offset += this->worldOffset.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->precision =  ((uint16_t) (*(inbuffer + offset)));
      this->precision |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->precision);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (autonomos_stereo_camera_msgs::PackedPoint*)realloc(this->points, points_lengthT * sizeof(autonomos_stereo_camera_msgs::PackedPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(autonomos_stereo_camera_msgs::PackedPoint));
      }
      offset += this->worldOffset.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/PackedPointCloud"; };
    const char * getMD5(){ return "8f45b31318869cbc632d94d97c0b37e5"; };

  };

}
#endif