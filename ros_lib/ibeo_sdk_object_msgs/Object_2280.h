#ifndef _ROS_ibeo_sdk_object_msgs_Object_2280_h
#define _ROS_ibeo_sdk_object_msgs_Object_2280_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_time_msgs/NTP64_2280.h"
#include "ibeo_sdk_object_msgs/ObjectClass.h"
#include "ibeo_sdk_point_msgs/Point.h"
#include "ibeo_sdk_object_msgs/RefPointBoxLocation.h"

namespace ibeo_sdk_object_msgs
{

  class Object_2280 : public ros::Msg
  {
    public:
      typedef uint16_t _object_id_type;
      _object_id_type object_id;
      typedef uint16_t _flags_type;
      _flags_type flags;
      typedef uint32_t _object_age_type;
      _object_age_type object_age;
      typedef ibeo_sdk_time_msgs::NTP64_2280 _timestamp_type;
      _timestamp_type timestamp;
      typedef uint16_t _hidden_status_age_type;
      _hidden_status_age_type hidden_status_age;
      typedef ibeo_sdk_object_msgs::ObjectClass _classification_type;
      _classification_type classification;
      typedef uint8_t _classification_quality_type;
      _classification_quality_type classification_quality;
      typedef uint32_t _classification_age_type;
      _classification_age_type classification_age;
      typedef ibeo_sdk_point_msgs::Point _reserved_0_type;
      _reserved_0_type reserved_0;
      typedef ibeo_sdk_point_msgs::Point _reserved_1_type;
      _reserved_1_type reserved_1;
      typedef ibeo_sdk_point_msgs::Point _object_box_center_type;
      _object_box_center_type object_box_center;
      typedef ibeo_sdk_point_msgs::Point _object_box_center_sigma_type;
      _object_box_center_sigma_type object_box_center_sigma;
      typedef ibeo_sdk_point_msgs::Point _object_box_size_type;
      _object_box_size_type object_box_size;
      typedef ibeo_sdk_point_msgs::Point _reserved_2_type;
      _reserved_2_type reserved_2;
      typedef float _object_box_orientation_type;
      _object_box_orientation_type object_box_orientation;
      typedef float _object_box_orientation_sigma_type;
      _object_box_orientation_sigma_type object_box_orientation_sigma;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_type;
      _relative_velocity_type relative_velocity;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_sigma_type;
      _relative_velocity_sigma_type relative_velocity_sigma;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_type;
      _absolute_velocity_type absolute_velocity;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_sigma_type;
      _absolute_velocity_sigma_type absolute_velocity_sigma;
      typedef uint64_t _reserved_4_type;
      _reserved_4_type reserved_4;
      typedef float _reserved_5_type;
      _reserved_5_type reserved_5;
      typedef float _reserved_6_type;
      _reserved_6_type reserved_6;
      typedef uint16_t _reserved_7_type;
      _reserved_7_type reserved_7;
      typedef uint8_t _index_closest_point_type;
      _index_closest_point_type index_closest_point;
      typedef ibeo_sdk_object_msgs::RefPointBoxLocation _reference_point_location_type;
      _reference_point_location_type reference_point_location;
      typedef ibeo_sdk_point_msgs::Point _reference_point_coordinates_type;
      _reference_point_coordinates_type reference_point_coordinates;
      typedef ibeo_sdk_point_msgs::Point _reference_point_coordinates_sigma_type;
      _reference_point_coordinates_sigma_type reference_point_coordinates_sigma;
      typedef float _reference_point_position_correction_coefficient_type;
      _reference_point_position_correction_coefficient_type reference_point_position_correction_coefficient;
      typedef float _reserved_8_type;
      _reserved_8_type reserved_8;
      typedef float _reserved_9_type;
      _reserved_9_type reserved_9;
      typedef uint16_t _object_priority_type;
      _object_priority_type object_priority;
      typedef float _object_existence_meas_type;
      _object_existence_meas_type object_existence_meas;
      uint32_t contour_points_length;
      typedef ibeo_sdk_point_msgs::Point _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;

    Object_2280():
      object_id(0),
      flags(0),
      object_age(0),
      timestamp(),
      hidden_status_age(0),
      classification(),
      classification_quality(0),
      classification_age(0),
      reserved_0(),
      reserved_1(),
      object_box_center(),
      object_box_center_sigma(),
      object_box_size(),
      reserved_2(),
      object_box_orientation(0),
      object_box_orientation_sigma(0),
      relative_velocity(),
      relative_velocity_sigma(),
      absolute_velocity(),
      absolute_velocity_sigma(),
      reserved_4(0),
      reserved_5(0),
      reserved_6(0),
      reserved_7(0),
      index_closest_point(0),
      reference_point_location(),
      reference_point_coordinates(),
      reference_point_coordinates_sigma(),
      reference_point_position_correction_coefficient(0),
      reserved_8(0),
      reserved_9(0),
      object_priority(0),
      object_existence_meas(0),
      contour_points_length(0), contour_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_id);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flags);
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
      offset += this->reserved_0.serialize(outbuffer + offset);
      offset += this->reserved_1.serialize(outbuffer + offset);
      offset += this->object_box_center.serialize(outbuffer + offset);
      offset += this->object_box_center_sigma.serialize(outbuffer + offset);
      offset += this->object_box_size.serialize(outbuffer + offset);
      offset += this->reserved_2.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_box_orientation;
      u_object_box_orientation.real = this->object_box_orientation;
      *(outbuffer + offset + 0) = (u_object_box_orientation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_box_orientation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_box_orientation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_box_orientation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_box_orientation);
      union {
        float real;
        uint32_t base;
      } u_object_box_orientation_sigma;
      u_object_box_orientation_sigma.real = this->object_box_orientation_sigma;
      *(outbuffer + offset + 0) = (u_object_box_orientation_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_box_orientation_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_box_orientation_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_box_orientation_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_box_orientation_sigma);
      offset += this->relative_velocity.serialize(outbuffer + offset);
      offset += this->relative_velocity_sigma.serialize(outbuffer + offset);
      offset += this->absolute_velocity.serialize(outbuffer + offset);
      offset += this->absolute_velocity_sigma.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_reserved_4;
      u_reserved_4.real = this->reserved_4;
      *(outbuffer + offset + 0) = (u_reserved_4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved_4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved_4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved_4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved_4);
      union {
        float real;
        uint32_t base;
      } u_reserved_5;
      u_reserved_5.real = this->reserved_5;
      *(outbuffer + offset + 0) = (u_reserved_5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved_5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved_5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved_5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved_5);
      union {
        float real;
        uint32_t base;
      } u_reserved_6;
      u_reserved_6.real = this->reserved_6;
      *(outbuffer + offset + 0) = (u_reserved_6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved_6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved_6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved_6.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved_6);
      *(outbuffer + offset + 0) = (this->reserved_7 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved_7 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved_7);
      *(outbuffer + offset + 0) = (this->index_closest_point >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index_closest_point);
      offset += this->reference_point_location.serialize(outbuffer + offset);
      offset += this->reference_point_coordinates.serialize(outbuffer + offset);
      offset += this->reference_point_coordinates_sigma.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_reference_point_position_correction_coefficient;
      u_reference_point_position_correction_coefficient.real = this->reference_point_position_correction_coefficient;
      *(outbuffer + offset + 0) = (u_reference_point_position_correction_coefficient.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_point_position_correction_coefficient.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_point_position_correction_coefficient.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_point_position_correction_coefficient.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_point_position_correction_coefficient);
      union {
        float real;
        uint32_t base;
      } u_reserved_8;
      u_reserved_8.real = this->reserved_8;
      *(outbuffer + offset + 0) = (u_reserved_8.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved_8.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved_8.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved_8.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved_8);
      union {
        float real;
        uint32_t base;
      } u_reserved_9;
      u_reserved_9.real = this->reserved_9;
      *(outbuffer + offset + 0) = (u_reserved_9.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved_9.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved_9.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved_9.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved_9);
      *(outbuffer + offset + 0) = (this->object_priority >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_priority >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_priority);
      union {
        float real;
        uint32_t base;
      } u_object_existence_meas;
      u_object_existence_meas.real = this->object_existence_meas;
      *(outbuffer + offset + 0) = (u_object_existence_meas.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_existence_meas.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_existence_meas.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_existence_meas.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_existence_meas);
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
      this->flags =  ((uint16_t) (*(inbuffer + offset)));
      this->flags |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->flags);
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
      offset += this->reserved_0.deserialize(inbuffer + offset);
      offset += this->reserved_1.deserialize(inbuffer + offset);
      offset += this->object_box_center.deserialize(inbuffer + offset);
      offset += this->object_box_center_sigma.deserialize(inbuffer + offset);
      offset += this->object_box_size.deserialize(inbuffer + offset);
      offset += this->reserved_2.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_box_orientation;
      u_object_box_orientation.base = 0;
      u_object_box_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_box_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_box_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_box_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_box_orientation = u_object_box_orientation.real;
      offset += sizeof(this->object_box_orientation);
      union {
        float real;
        uint32_t base;
      } u_object_box_orientation_sigma;
      u_object_box_orientation_sigma.base = 0;
      u_object_box_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_box_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_box_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_box_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_box_orientation_sigma = u_object_box_orientation_sigma.real;
      offset += sizeof(this->object_box_orientation_sigma);
      offset += this->relative_velocity.deserialize(inbuffer + offset);
      offset += this->relative_velocity_sigma.deserialize(inbuffer + offset);
      offset += this->absolute_velocity.deserialize(inbuffer + offset);
      offset += this->absolute_velocity_sigma.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_reserved_4;
      u_reserved_4.base = 0;
      u_reserved_4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved_4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved_4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved_4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved_4 = u_reserved_4.real;
      offset += sizeof(this->reserved_4);
      union {
        float real;
        uint32_t base;
      } u_reserved_5;
      u_reserved_5.base = 0;
      u_reserved_5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved_5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved_5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved_5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved_5 = u_reserved_5.real;
      offset += sizeof(this->reserved_5);
      union {
        float real;
        uint32_t base;
      } u_reserved_6;
      u_reserved_6.base = 0;
      u_reserved_6.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved_6.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved_6.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved_6.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved_6 = u_reserved_6.real;
      offset += sizeof(this->reserved_6);
      this->reserved_7 =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved_7 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved_7);
      this->index_closest_point =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->index_closest_point);
      offset += this->reference_point_location.deserialize(inbuffer + offset);
      offset += this->reference_point_coordinates.deserialize(inbuffer + offset);
      offset += this->reference_point_coordinates_sigma.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_reference_point_position_correction_coefficient;
      u_reference_point_position_correction_coefficient.base = 0;
      u_reference_point_position_correction_coefficient.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_point_position_correction_coefficient.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_point_position_correction_coefficient.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_point_position_correction_coefficient.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_point_position_correction_coefficient = u_reference_point_position_correction_coefficient.real;
      offset += sizeof(this->reference_point_position_correction_coefficient);
      union {
        float real;
        uint32_t base;
      } u_reserved_8;
      u_reserved_8.base = 0;
      u_reserved_8.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved_8.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved_8.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved_8.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved_8 = u_reserved_8.real;
      offset += sizeof(this->reserved_8);
      union {
        float real;
        uint32_t base;
      } u_reserved_9;
      u_reserved_9.base = 0;
      u_reserved_9.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved_9.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved_9.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved_9.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved_9 = u_reserved_9.real;
      offset += sizeof(this->reserved_9);
      this->object_priority =  ((uint16_t) (*(inbuffer + offset)));
      this->object_priority |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->object_priority);
      union {
        float real;
        uint32_t base;
      } u_object_existence_meas;
      u_object_existence_meas.base = 0;
      u_object_existence_meas.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_existence_meas.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_existence_meas.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_existence_meas.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_existence_meas = u_object_existence_meas.real;
      offset += sizeof(this->object_existence_meas);
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

    const char * getType(){ return "ibeo_sdk_object_msgs/Object_2280"; };
    const char * getMD5(){ return "0a794e7d40c6774bb6d660d78b375c20"; };

  };

}
#endif