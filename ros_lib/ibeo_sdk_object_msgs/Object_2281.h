#ifndef _ROS_ibeo_sdk_object_msgs_Object_2281_h
#define _ROS_ibeo_sdk_object_msgs_Object_2281_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_time_msgs/NTP64_2281.h"
#include "ibeo_sdk_object_msgs/ObjectClass.h"
#include "ibeo_sdk_point_msgs/Point.h"
#include "ibeo_sdk_object_msgs/RefPointBoxLocation.h"
#include "ibeo_sdk_measurement_list_msgs/MeasurementList_2281.h"

namespace ibeo_sdk_object_msgs
{

  class Object_2281 : public ros::Msg
  {
    public:
      typedef uint32_t _object_id_type;
      _object_id_type object_id;
      typedef uint16_t _flags_type;
      _flags_type flags;
      typedef uint32_t _object_age_type;
      _object_age_type object_age;
      typedef ibeo_sdk_time_msgs::NTP64_2281 _timestamp_type;
      _timestamp_type timestamp;
      typedef uint16_t _hidden_status_age_type;
      _hidden_status_age_type hidden_status_age;
      typedef ibeo_sdk_object_msgs::ObjectClass _classification_type;
      _classification_type classification;
      typedef uint8_t _classification_quality_type;
      _classification_quality_type classification_quality;
      typedef uint32_t _classification_age_type;
      _classification_age_type classification_age;
      typedef ibeo_sdk_point_msgs::Point _object_box_size_type;
      _object_box_size_type object_box_size;
      typedef ibeo_sdk_point_msgs::Point _object_box_size_sigma_type;
      _object_box_size_sigma_type object_box_size_sigma;
      typedef float _course_angle_type;
      _course_angle_type course_angle;
      typedef float _course_angle_sigma_type;
      _course_angle_sigma_type course_angle_sigma;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_type;
      _relative_velocity_type relative_velocity;
      typedef ibeo_sdk_point_msgs::Point _relative_velocity_sigma_type;
      _relative_velocity_sigma_type relative_velocity_sigma;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_type;
      _absolute_velocity_type absolute_velocity;
      typedef ibeo_sdk_point_msgs::Point _absolute_velocity_sigma_type;
      _absolute_velocity_sigma_type absolute_velocity_sigma;
      typedef float _object_height_type;
      _object_height_type object_height;
      typedef float _object_height_sigma_type;
      _object_height_sigma_type object_height_sigma;
      typedef ibeo_sdk_point_msgs::Point _motion_reference_point_type;
      _motion_reference_point_type motion_reference_point;
      typedef ibeo_sdk_point_msgs::Point _motion_reference_point_sigma_type;
      _motion_reference_point_sigma_type motion_reference_point_sigma;
      typedef float _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;
      typedef float _longitudinal_acceleration_sigma_type;
      _longitudinal_acceleration_sigma_type longitudinal_acceleration_sigma;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef float _yaw_rate_sigma_type;
      _yaw_rate_sigma_type yaw_rate_sigma;
      typedef uint8_t _num_contour_points_type;
      _num_contour_points_type num_contour_points;
      typedef uint8_t _closest_contour_point_index_type;
      _closest_contour_point_index_type closest_contour_point_index;
      typedef ibeo_sdk_object_msgs::RefPointBoxLocation _reference_point_location_type;
      _reference_point_location_type reference_point_location;
      typedef ibeo_sdk_point_msgs::Point _reference_point_coordinates_type;
      _reference_point_coordinates_type reference_point_coordinates;
      typedef ibeo_sdk_point_msgs::Point _reference_point_coordinates_sigma_type;
      _reference_point_coordinates_sigma_type reference_point_coordinates_sigma;
      typedef float _reference_point_position_correction_coefficient_type;
      _reference_point_position_correction_coefficient_type reference_point_position_correction_coefficient;
      typedef ibeo_sdk_point_msgs::Point _center_of_gravity_type;
      _center_of_gravity_type center_of_gravity;
      typedef uint16_t _object_priority_type;
      _object_priority_type object_priority;
      typedef float _object_existence_meas_type;
      _object_existence_meas_type object_existence_meas;
      typedef int8_t _object_box_height_offset_type;
      _object_box_height_offset_type object_box_height_offset;
      typedef uint8_t _object_box_height_offset_sigma_type;
      _object_box_height_offset_sigma_type object_box_height_offset_sigma;
      typedef uint8_t _reserved3_type;
      _reserved3_type reserved3;
      typedef uint8_t _reserved4_type;
      _reserved4_type reserved4;
      uint32_t contour_points_length;
      typedef ibeo_sdk_point_msgs::Point _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;
      typedef ibeo_sdk_measurement_list_msgs::MeasurementList_2281 _dynamic_measurement_type;
      _dynamic_measurement_type dynamic_measurement;

    Object_2281():
      object_id(0),
      flags(0),
      object_age(0),
      timestamp(),
      hidden_status_age(0),
      classification(),
      classification_quality(0),
      classification_age(0),
      object_box_size(),
      object_box_size_sigma(),
      course_angle(0),
      course_angle_sigma(0),
      relative_velocity(),
      relative_velocity_sigma(),
      absolute_velocity(),
      absolute_velocity_sigma(),
      object_height(0),
      object_height_sigma(0),
      motion_reference_point(),
      motion_reference_point_sigma(),
      longitudinal_acceleration(0),
      longitudinal_acceleration_sigma(0),
      yaw_rate(0),
      yaw_rate_sigma(0),
      num_contour_points(0),
      closest_contour_point_index(0),
      reference_point_location(),
      reference_point_coordinates(),
      reference_point_coordinates_sigma(),
      reference_point_position_correction_coefficient(0),
      center_of_gravity(),
      object_priority(0),
      object_existence_meas(0),
      object_box_height_offset(0),
      object_box_height_offset_sigma(0),
      reserved3(0),
      reserved4(0),
      contour_points_length(0), contour_points(NULL),
      dynamic_measurement()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->object_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->object_id >> (8 * 3)) & 0xFF;
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
      offset += this->object_box_size.serialize(outbuffer + offset);
      offset += this->object_box_size_sigma.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_course_angle;
      u_course_angle.real = this->course_angle;
      *(outbuffer + offset + 0) = (u_course_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_course_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_course_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_course_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->course_angle);
      union {
        float real;
        uint32_t base;
      } u_course_angle_sigma;
      u_course_angle_sigma.real = this->course_angle_sigma;
      *(outbuffer + offset + 0) = (u_course_angle_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_course_angle_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_course_angle_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_course_angle_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->course_angle_sigma);
      offset += this->relative_velocity.serialize(outbuffer + offset);
      offset += this->relative_velocity_sigma.serialize(outbuffer + offset);
      offset += this->absolute_velocity.serialize(outbuffer + offset);
      offset += this->absolute_velocity_sigma.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_height;
      u_object_height.real = this->object_height;
      *(outbuffer + offset + 0) = (u_object_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_height);
      union {
        float real;
        uint32_t base;
      } u_object_height_sigma;
      u_object_height_sigma.real = this->object_height_sigma;
      *(outbuffer + offset + 0) = (u_object_height_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_height_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_height_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_height_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_height_sigma);
      offset += this->motion_reference_point.serialize(outbuffer + offset);
      offset += this->motion_reference_point_sigma.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.real = this->longitudinal_acceleration;
      *(outbuffer + offset + 0) = (u_longitudinal_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudinal_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudinal_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudinal_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitudinal_acceleration);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration_sigma;
      u_longitudinal_acceleration_sigma.real = this->longitudinal_acceleration_sigma;
      *(outbuffer + offset + 0) = (u_longitudinal_acceleration_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudinal_acceleration_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudinal_acceleration_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudinal_acceleration_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitudinal_acceleration_sigma);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate;
      u_yaw_rate.real = this->yaw_rate;
      *(outbuffer + offset + 0) = (u_yaw_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_rate);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate_sigma;
      u_yaw_rate_sigma.real = this->yaw_rate_sigma;
      *(outbuffer + offset + 0) = (u_yaw_rate_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_rate_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_rate_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_rate_sigma);
      *(outbuffer + offset + 0) = (this->num_contour_points >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_contour_points);
      *(outbuffer + offset + 0) = (this->closest_contour_point_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->closest_contour_point_index);
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
      offset += this->center_of_gravity.serialize(outbuffer + offset);
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
      union {
        int8_t real;
        uint8_t base;
      } u_object_box_height_offset;
      u_object_box_height_offset.real = this->object_box_height_offset;
      *(outbuffer + offset + 0) = (u_object_box_height_offset.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_box_height_offset);
      *(outbuffer + offset + 0) = (this->object_box_height_offset_sigma >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_box_height_offset_sigma);
      *(outbuffer + offset + 0) = (this->reserved3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved3);
      *(outbuffer + offset + 0) = (this->reserved4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved4);
      *(outbuffer + offset + 0) = (this->contour_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contour_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contour_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contour_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contour_points_length);
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->contour_points[i].serialize(outbuffer + offset);
      }
      offset += this->dynamic_measurement.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->object_id =  ((uint32_t) (*(inbuffer + offset)));
      this->object_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->object_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->object_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
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
      offset += this->object_box_size.deserialize(inbuffer + offset);
      offset += this->object_box_size_sigma.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_course_angle;
      u_course_angle.base = 0;
      u_course_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_course_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_course_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_course_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->course_angle = u_course_angle.real;
      offset += sizeof(this->course_angle);
      union {
        float real;
        uint32_t base;
      } u_course_angle_sigma;
      u_course_angle_sigma.base = 0;
      u_course_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_course_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_course_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_course_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->course_angle_sigma = u_course_angle_sigma.real;
      offset += sizeof(this->course_angle_sigma);
      offset += this->relative_velocity.deserialize(inbuffer + offset);
      offset += this->relative_velocity_sigma.deserialize(inbuffer + offset);
      offset += this->absolute_velocity.deserialize(inbuffer + offset);
      offset += this->absolute_velocity_sigma.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_height;
      u_object_height.base = 0;
      u_object_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_height = u_object_height.real;
      offset += sizeof(this->object_height);
      union {
        float real;
        uint32_t base;
      } u_object_height_sigma;
      u_object_height_sigma.base = 0;
      u_object_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_height_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_height_sigma = u_object_height_sigma.real;
      offset += sizeof(this->object_height_sigma);
      offset += this->motion_reference_point.deserialize(inbuffer + offset);
      offset += this->motion_reference_point_sigma.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration;
      u_longitudinal_acceleration.base = 0;
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudinal_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitudinal_acceleration = u_longitudinal_acceleration.real;
      offset += sizeof(this->longitudinal_acceleration);
      union {
        float real;
        uint32_t base;
      } u_longitudinal_acceleration_sigma;
      u_longitudinal_acceleration_sigma.base = 0;
      u_longitudinal_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudinal_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudinal_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudinal_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitudinal_acceleration_sigma = u_longitudinal_acceleration_sigma.real;
      offset += sizeof(this->longitudinal_acceleration_sigma);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate;
      u_yaw_rate.base = 0;
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_rate = u_yaw_rate.real;
      offset += sizeof(this->yaw_rate);
      union {
        float real;
        uint32_t base;
      } u_yaw_rate_sigma;
      u_yaw_rate_sigma.base = 0;
      u_yaw_rate_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_rate_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_rate_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_rate_sigma = u_yaw_rate_sigma.real;
      offset += sizeof(this->yaw_rate_sigma);
      this->num_contour_points =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_contour_points);
      this->closest_contour_point_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->closest_contour_point_index);
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
      offset += this->center_of_gravity.deserialize(inbuffer + offset);
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
      union {
        int8_t real;
        uint8_t base;
      } u_object_box_height_offset;
      u_object_box_height_offset.base = 0;
      u_object_box_height_offset.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->object_box_height_offset = u_object_box_height_offset.real;
      offset += sizeof(this->object_box_height_offset);
      this->object_box_height_offset_sigma =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_box_height_offset_sigma);
      this->reserved3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved3);
      this->reserved4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved4);
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
      offset += this->dynamic_measurement.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_msgs/Object_2281"; };
    const char * getMD5(){ return "15549fe6eb372540b1e1cad666acd5df"; };

  };

}
#endif