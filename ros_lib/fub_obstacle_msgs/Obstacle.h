#ifndef _ROS_fub_obstacle_msgs_Obstacle_h
#define _ROS_fub_obstacle_msgs_Obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

namespace fub_obstacle_msgs
{

  class Obstacle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _object_frame_id_type;
      _object_frame_id_type object_frame_id;
      typedef uint16_t _object_id_type;
      _object_id_type object_id;
      typedef ros::Duration _age_type;
      _age_type age;
      typedef ros::Duration _prediction_age_type;
      _prediction_age_type prediction_age;
      typedef nav_msgs::Odometry _odom_type;
      _odom_type odom;
      typedef geometry_msgs::Vector3 _size_type;
      _size_type size;
      uint32_t contour_points_length;
      typedef geometry_msgs::Point _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;
      typedef uint16_t _classification_type;
      _classification_type classification;
      typedef ros::Duration _classification_age_type;
      _classification_age_type classification_age;
      typedef float _classification_certainty_type;
      _classification_certainty_type classification_certainty;
      enum { UNCLASSIFIED =  0 };
      enum { UNKNOWN_SMALL =  1 };
      enum { UNKNOWN_BIG =  2 };
      enum { PEDESTRIAN =  3 };
      enum { BIKE =  4 };
      enum { CAR =  5 };
      enum { TRUCK =  6 };

    Obstacle():
      header(),
      object_frame_id(""),
      object_id(0),
      age(),
      prediction_age(),
      odom(),
      size(),
      contour_points_length(0), contour_points(NULL),
      classification(0),
      classification_age(),
      classification_certainty(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_object_frame_id = strlen(this->object_frame_id);
      varToArr(outbuffer + offset, length_object_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->object_frame_id, length_object_frame_id);
      offset += length_object_frame_id;
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_id);
      *(outbuffer + offset + 0) = (this->age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.sec);
      *(outbuffer + offset + 0) = (this->age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.nsec);
      *(outbuffer + offset + 0) = (this->prediction_age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prediction_age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->prediction_age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->prediction_age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prediction_age.sec);
      *(outbuffer + offset + 0) = (this->prediction_age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prediction_age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->prediction_age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->prediction_age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prediction_age.nsec);
      offset += this->odom.serialize(outbuffer + offset);
      offset += this->size.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contour_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contour_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contour_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contour_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contour_points_length);
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->contour_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->classification >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification >> (8 * 1)) & 0xFF;
      offset += sizeof(this->classification);
      *(outbuffer + offset + 0) = (this->classification_age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classification_age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classification_age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_age.sec);
      *(outbuffer + offset + 0) = (this->classification_age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classification_age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classification_age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_age.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->classification_certainty);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_object_frame_id;
      arrToVar(length_object_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_frame_id-1]=0;
      this->object_frame_id = (char *)(inbuffer + offset-1);
      offset += length_object_frame_id;
      this->object_id =  ((uint16_t) (*(inbuffer + offset)));
      this->object_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->object_id);
      this->age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.sec);
      this->age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.nsec);
      this->prediction_age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->prediction_age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->prediction_age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->prediction_age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->prediction_age.sec);
      this->prediction_age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->prediction_age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->prediction_age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->prediction_age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->prediction_age.nsec);
      offset += this->odom.deserialize(inbuffer + offset);
      offset += this->size.deserialize(inbuffer + offset);
      uint32_t contour_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contour_points_length);
      if(contour_points_lengthT > contour_points_length)
        this->contour_points = (geometry_msgs::Point*)realloc(this->contour_points, contour_points_lengthT * sizeof(geometry_msgs::Point));
      contour_points_length = contour_points_lengthT;
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->st_contour_points.deserialize(inbuffer + offset);
        memcpy( &(this->contour_points[i]), &(this->st_contour_points), sizeof(geometry_msgs::Point));
      }
      this->classification =  ((uint16_t) (*(inbuffer + offset)));
      this->classification |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->classification);
      this->classification_age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->classification_age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->classification_age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->classification_age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->classification_age.sec);
      this->classification_age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->classification_age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->classification_age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->classification_age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->classification_age.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->classification_certainty));
     return offset;
    }

    const char * getType(){ return "fub_obstacle_msgs/Obstacle"; };
    const char * getMD5(){ return "56ed5dd3c8412ae50b6a996467672cf4"; };

  };

}
#endif