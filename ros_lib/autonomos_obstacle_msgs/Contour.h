#ifndef _ROS_autonomos_obstacle_msgs_Contour_h
#define _ROS_autonomos_obstacle_msgs_Contour_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"

namespace autonomos_obstacle_msgs
{

  class Contour : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t contour_points_length;
      typedef geometry_msgs::Point32 _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;

    Contour():
      header(),
      contour_points_length(0), contour_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contour_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contour_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contour_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contour_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contour_points_length);
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->contour_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t contour_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contour_points_length);
      if(contour_points_lengthT > contour_points_length)
        this->contour_points = (geometry_msgs::Point32*)realloc(this->contour_points, contour_points_lengthT * sizeof(geometry_msgs::Point32));
      contour_points_length = contour_points_lengthT;
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->st_contour_points.deserialize(inbuffer + offset);
        memcpy( &(this->contour_points[i]), &(this->st_contour_points), sizeof(geometry_msgs::Point32));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_obstacle_msgs/Contour"; };
    const char * getMD5(){ return "19df7d20c99b3e75f70f53fe6d997f44"; };

  };

}
#endif