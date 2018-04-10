#ifndef _ROS_ibeo_sdk_object_msgs_Object_2225_h
#define _ROS_ibeo_sdk_object_msgs_Object_2225_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_time_msgs/NTP64_2225.h"
#include "ibeo_sdk_object_msgs/ObjectClass.h"
#include "ibeo_sdk_point_msgs/Point.h"

namespace ibeo_sdk_object_msgs
{

  class Object_2225 : public ros::Msg
  {
    public:
      typedef uint16_t _object_id_type;
      _object_id_type object_id;
      typedef uint32_t _object_age_type;
      _object_age_type object_age;
      typedef ibeo_sdk_time_msgs::NTP64_2225 _timestamp_type;
      _timestamp_type timestamp;
      typedef uint16_t _hidden_status_age_type;
      _hidden_status_age_type hidden_status_age;
      typedef ibeo_sdk_object_msgs::ObjectClass _classification_type;
      _classification_type classification;
      typedef uint8_t _classification_quality_type;
      _classification_quality_type classification_quality;
      typedef uint32_t _classification_age_type;
      _classification_age_type classification_age;
      typedef ibeo_sdk_point_msgs::Point _bounding_box_center_type;
      _bounding_box_center_type bounding_box_center;
      typedef ibeo_sdk_point_msgs::Point _bounding_box_size_type;
      _bounding_box_size_type bounding_box_size;
      typedef ibeo_sdk_point_msgs::Point _object_box_center_type;
      _object_box_center_type object_box_center;
      typedef ibeo_sdk_point_msgs::Point _object_box_center_sigma_type;
      _object_box_center_sigma_type object_box_center_sigma;
      typedef ibeo_sdk_point_msgs::Point _object_box_size_type;
      _object_box_size_type object_box_size;
      typedef float _yaw_angle_type;
      _yaw_angle_type yaw_angle;
      typedef float _yaw_angle_sigma_type;
      _yaw_angle_sigma_type yaw_angle_sigma;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_type;
      _relative_velocity_type relative_velocity;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_sigma_type;
      _relative_velocity_sigma_type relative_velocity_sigma;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_type;
      _absolute_velocity_type absolute_velocity;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_sigma_type;
      _absolute_velocity_sigma_type absolute_velocity_sigma;
      typedef uint8_t _num_contour_points_type;
      _num_contour_points_type num_contour_points;
      typedef uint8_t _closest_contour_point_index_type;
      _closest_contour_point_index_type closest_contour_point_index;
      uint32_t contour_points_length;
      typedef ibeo_sdk_point_msgs::Point _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;

    Object_2225():
      object_id(0),
      object_age(0),
      timestamp(),
      hidden_status_age(0),
      classification(),
      classification_quality(0),
      classification_age(0),
      bounding_box_center(),
      bounding_box_size(),
      object_box_center(),
      object_box_center_sigma(),
      object_box_size(),
      yaw_angle(0),
      yaw_angle_sigma(0),
      relative_velocity(),
      relative_velocity_sigma(),
      absolute_velocity(),
      absolute_velocity_sigma(),
      num_contour_points(0),
      closest_contour_point_index(0),
      contour_points_length(0), contour_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_id);
      *(outbuffer + offset + 0) = (this->object_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_age >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->object_age >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->object_age >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_age);
      offset += this->timestamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->hidden_status_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hidden_status_age >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hidden_status_age);
      offset += this->classification.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->classification_quality >> (8 * 0)) & 0xFF;
      offset += sizeof(this->classification_quality);
      *(outbuffer + offset + 0) = (this->classification_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_age >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classification_age >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classification_age >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_age);
      offset += this->bounding_box_center.serialize(outbuffer + offset);
      offset += this->bounding_box_size.serialize(outbuffer + offset);
      offset += this->object_box_center.serialize(outbuffer + offset);
      offset += this->object_box_center_sigma.serialize(outbuffer + offset);
      offset += this->object_box_size.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle;
      u_yaw_angle.real = this->yaw_angle;
      *(outbuffer + offset + 0) = (u_yaw_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle_sigma;
      u_yaw_angle_sigma.real = this->yaw_angle_sigma;
      *(outbuffer + offset + 0) = (u_yaw_angle_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_angle_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_angle_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_angle_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_angle_sigma);
      offset += this->relative_velocity.serialize(outbuffer + offset);
      offset += this->relative_velocity_sigma.serialize(outbuffer + offset);
      offset += this->absolute_velocity.serialize(outbuffer + offset);
      offset += this->absolute_velocity_sigma.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_contour_points >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_contour_points);
      *(outbuffer + offset + 0) = (this->closest_contour_point_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->closest_contour_point_index);
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
      this->object_id =  ((uint16_t) (*(inbuffer + offset)));
      this->object_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->object_id);
      this->object_age =  ((uint32_t) (*(inbuffer + offset)));
      this->object_age |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->object_age |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->object_age |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->object_age);
      offset += this->timestamp.deserialize(inbuffer + offset);
      this->hidden_status_age =  ((uint16_t) (*(inbuffer + offset)));
      this->hidden_status_age |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hidden_status_age);
      offset += this->classification.deserialize(inbuffer + offset);
      this->classification_quality =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->classification_quality);
      this->classification_age =  ((uint32_t) (*(inbuffer + offset)));
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->classification_age);
      offset += this->bounding_box_center.deserialize(inbuffer + offset);
      offset += this->bounding_box_size.deserialize(inbuffer + offset);
      offset += this->object_box_center.deserialize(inbuffer + offset);
      offset += this->object_box_center_sigma.deserialize(inbuffer + offset);
      offset += this->object_box_size.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle;
      u_yaw_angle.base = 0;
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_angle = u_yaw_angle.real;
      offset += sizeof(this->yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_yaw_angle_sigma;
      u_yaw_angle_sigma.base = 0;
      u_yaw_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_angle_sigma = u_yaw_angle_sigma.real;
      offset += sizeof(this->yaw_angle_sigma);
      offset += this->relative_velocity.deserialize(inbuffer + offset);
      offset += this->relative_velocity_sigma.deserialize(inbuffer + offset);
      offset += this->absolute_velocity.deserialize(inbuffer + offset);
      offset += this->absolute_velocity_sigma.deserialize(inbuffer + offset);
      this->num_contour_points =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_contour_points);
      this->closest_contour_point_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->closest_contour_point_index);
      uint32_t contour_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contour_points_length);
      if(contour_points_lengthT > contour_points_length)
        this->contour_points = (ibeo_sdk_point_msgs::Point*)realloc(this->contour_points, contour_points_lengthT * sizeof(ibeo_sdk_point_msgs::Point));
      contour_points_length = contour_points_lengthT;
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->st_contour_points.deserialize(inbuffer + offset);
        memcpy( &(this->contour_points[i]), &(this->st_contour_points), sizeof(ibeo_sdk_point_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_msgs/Object_2225"; };
    const char * getMD5(){ return "d3061dbef568c14c3aaf1038a08c2e34"; };

  };

}
#endif