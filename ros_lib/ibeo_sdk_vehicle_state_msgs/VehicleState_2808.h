#ifndef _ROS_ibeo_sdk_vehicle_state_msgs_VehicleState_2808_h
#define _ROS_ibeo_sdk_vehicle_state_msgs_VehicleState_2808_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2281.h"

namespace ibeo_sdk_vehicle_state_msgs
{

  class VehicleState_2808 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _microseconds_type;
      _microseconds_type microseconds;
      typedef ibeo_sdk_time_msgs::NTP64_2281 _time_type;
      _time_type time;
      typedef uint16_t _sources_type;
      _sources_type sources;
      typedef uint16_t _blind_prediction_age_type;
      _blind_prediction_age_type blind_prediction_age;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _latitude_sigma_type;
      _latitude_sigma_type latitude_sigma;
      typedef float _longtitude_type;
      _longtitude_type longtitude;
      typedef float _longtitude_sigma_type;
      _longtitude_sigma_type longtitude_sigma;
      typedef float _altitude_type;
      _altitude_type altitude;
      typedef float _altitude_sigma_type;
      _altitude_sigma_type altitude_sigma;
      typedef float _x_type;
      _x_type x;
      typedef float _x_sigma_type;
      _x_sigma_type x_sigma;
      typedef float _y_type;
      _y_type y;
      typedef float _y_sigma_type;
      _y_sigma_type y_sigma;
      typedef float _z_type;
      _z_type z;
      typedef float _z_sigma_type;
      _z_sigma_type z_sigma;
      typedef float _xy_corr_type;
      _xy_corr_type xy_corr;
      typedef float _xz_corr_type;
      _xz_corr_type xz_corr;
      typedef float _yz_corr_type;
      _yz_corr_type yz_corr;
      typedef float _course_angle_type;
      _course_angle_type course_angle;
      typedef float _course_angle_sigma_type;
      _course_angle_sigma_type course_angle_sigma;
      typedef float _heading_angle_type;
      _heading_angle_type heading_angle;
      typedef float _heading_angle_sigma_type;
      _heading_angle_sigma_type heading_angle_sigma;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _pitch_sigma_type;
      _pitch_sigma_type pitch_sigma;
      typedef float _roll_type;
      _roll_type roll;
      typedef float _roll_sigma_type;
      _roll_sigma_type roll_sigma;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _velocity_sigma_type;
      _velocity_sigma_type velocity_sigma;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef float _yaw_rate_sigma_type;
      _yaw_rate_sigma_type yaw_rate_sigma;
      typedef float _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;
      typedef float _longitudinal_acceleration_sigma_type;
      _longitudinal_acceleration_sigma_type longitudinal_acceleration_sigma;
      typedef float _cross_acceleration_type;
      _cross_acceleration_type cross_acceleration;
      typedef float _cross_acceleration_sigma_type;
      _cross_acceleration_sigma_type cross_acceleration_sigma;
      typedef float _steer_angle_type;
      _steer_angle_type steer_angle;
      typedef float _steering_wheel_angle_type;
      _steering_wheel_angle_type steering_wheel_angle;
      typedef float _vehicle_width_type;
      _vehicle_width_type vehicle_width;
      typedef float _min_turning_cycle_type;
      _min_turning_cycle_type min_turning_cycle;
      typedef float _vehicle_front_to_front_axle_type;
      _vehicle_front_to_front_axle_type vehicle_front_to_front_axle;
      typedef float _front_axle_to_rear_axle_type;
      _front_axle_to_rear_axle_type front_axle_to_rear_axle;
      typedef float _rear_axle_to_vehicle_rear_type;
      _rear_axle_to_vehicle_rear_type rear_axle_to_vehicle_rear;
      typedef float _rear_axle_to_origin_type;
      _rear_axle_to_origin_type rear_axle_to_origin;
      typedef float _steer_ratio_coeff0_type;
      _steer_ratio_coeff0_type steer_ratio_coeff0;
      typedef float _steer_ratio_coeff1_type;
      _steer_ratio_coeff1_type steer_ratio_coeff1;
      typedef float _steer_ratio_coeff2_type;
      _steer_ratio_coeff2_type steer_ratio_coeff2;
      typedef float _steer_ratio_coeff3_type;
      _steer_ratio_coeff3_type steer_ratio_coeff3;

    VehicleState_2808():
      header(),
      microseconds(0),
      time(),
      sources(0),
      blind_prediction_age(0),
      latitude(0),
      latitude_sigma(0),
      longtitude(0),
      longtitude_sigma(0),
      altitude(0),
      altitude_sigma(0),
      x(0),
      x_sigma(0),
      y(0),
      y_sigma(0),
      z(0),
      z_sigma(0),
      xy_corr(0),
      xz_corr(0),
      yz_corr(0),
      course_angle(0),
      course_angle_sigma(0),
      heading_angle(0),
      heading_angle_sigma(0),
      pitch(0),
      pitch_sigma(0),
      roll(0),
      roll_sigma(0),
      velocity(0),
      velocity_sigma(0),
      yaw_rate(0),
      yaw_rate_sigma(0),
      longitudinal_acceleration(0),
      longitudinal_acceleration_sigma(0),
      cross_acceleration(0),
      cross_acceleration_sigma(0),
      steer_angle(0),
      steering_wheel_angle(0),
      vehicle_width(0),
      min_turning_cycle(0),
      vehicle_front_to_front_axle(0),
      front_axle_to_rear_axle(0),
      rear_axle_to_vehicle_rear(0),
      rear_axle_to_origin(0),
      steer_ratio_coeff0(0),
      steer_ratio_coeff1(0),
      steer_ratio_coeff2(0),
      steer_ratio_coeff3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->microseconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->microseconds >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->microseconds >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->microseconds >> (8 * 3)) & 0xFF;
      offset += sizeof(this->microseconds);
      offset += this->time.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sources >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sources >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sources);
      *(outbuffer + offset + 0) = (this->blind_prediction_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blind_prediction_age >> (8 * 1)) & 0xFF;
      offset += sizeof(this->blind_prediction_age);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      union {
        float real;
        uint32_t base;
      } u_latitude_sigma;
      u_latitude_sigma.real = this->latitude_sigma;
      *(outbuffer + offset + 0) = (u_latitude_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude_sigma);
      offset += serializeAvrFloat64(outbuffer + offset, this->longtitude);
      union {
        float real;
        uint32_t base;
      } u_longtitude_sigma;
      u_longtitude_sigma.real = this->longtitude_sigma;
      *(outbuffer + offset + 0) = (u_longtitude_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longtitude_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longtitude_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longtitude_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longtitude_sigma);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_sigma;
      u_altitude_sigma.real = this->altitude_sigma;
      *(outbuffer + offset + 0) = (u_altitude_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_sigma);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      union {
        float real;
        uint32_t base;
      } u_x_sigma;
      u_x_sigma.real = this->x_sigma;
      *(outbuffer + offset + 0) = (u_x_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_sigma);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      union {
        float real;
        uint32_t base;
      } u_y_sigma;
      u_y_sigma.real = this->y_sigma;
      *(outbuffer + offset + 0) = (u_y_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_sigma);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_z_sigma;
      u_z_sigma.real = this->z_sigma;
      *(outbuffer + offset + 0) = (u_z_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_sigma);
      union {
        float real;
        uint32_t base;
      } u_xy_corr;
      u_xy_corr.real = this->xy_corr;
      *(outbuffer + offset + 0) = (u_xy_corr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xy_corr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xy_corr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xy_corr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xy_corr);
      union {
        float real;
        uint32_t base;
      } u_xz_corr;
      u_xz_corr.real = this->xz_corr;
      *(outbuffer + offset + 0) = (u_xz_corr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xz_corr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xz_corr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xz_corr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xz_corr);
      union {
        float real;
        uint32_t base;
      } u_yz_corr;
      u_yz_corr.real = this->yz_corr;
      *(outbuffer + offset + 0) = (u_yz_corr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yz_corr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yz_corr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yz_corr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yz_corr);
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
      union {
        float real;
        uint32_t base;
      } u_heading_angle;
      u_heading_angle.real = this->heading_angle;
      *(outbuffer + offset + 0) = (u_heading_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading_angle);
      union {
        float real;
        uint32_t base;
      } u_heading_angle_sigma;
      u_heading_angle_sigma.real = this->heading_angle_sigma;
      *(outbuffer + offset + 0) = (u_heading_angle_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heading_angle_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heading_angle_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heading_angle_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->heading_angle_sigma);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_pitch_sigma;
      u_pitch_sigma.real = this->pitch_sigma;
      *(outbuffer + offset + 0) = (u_pitch_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_sigma);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_roll_sigma;
      u_roll_sigma.real = this->roll_sigma;
      *(outbuffer + offset + 0) = (u_roll_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_sigma);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_velocity_sigma;
      u_velocity_sigma.real = this->velocity_sigma;
      *(outbuffer + offset + 0) = (u_velocity_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_sigma);
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
      } u_cross_acceleration;
      u_cross_acceleration.real = this->cross_acceleration;
      *(outbuffer + offset + 0) = (u_cross_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cross_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cross_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cross_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cross_acceleration);
      union {
        float real;
        uint32_t base;
      } u_cross_acceleration_sigma;
      u_cross_acceleration_sigma.real = this->cross_acceleration_sigma;
      *(outbuffer + offset + 0) = (u_cross_acceleration_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cross_acceleration_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cross_acceleration_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cross_acceleration_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cross_acceleration_sigma);
      union {
        float real;
        uint32_t base;
      } u_steer_angle;
      u_steer_angle.real = this->steer_angle;
      *(outbuffer + offset + 0) = (u_steer_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_angle);
      union {
        float real;
        uint32_t base;
      } u_steering_wheel_angle;
      u_steering_wheel_angle.real = this->steering_wheel_angle;
      *(outbuffer + offset + 0) = (u_steering_wheel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_wheel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_wheel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_wheel_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_vehicle_width;
      u_vehicle_width.real = this->vehicle_width;
      *(outbuffer + offset + 0) = (u_vehicle_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vehicle_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vehicle_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vehicle_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vehicle_width);
      union {
        float real;
        uint32_t base;
      } u_min_turning_cycle;
      u_min_turning_cycle.real = this->min_turning_cycle;
      *(outbuffer + offset + 0) = (u_min_turning_cycle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_turning_cycle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_turning_cycle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_turning_cycle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_turning_cycle);
      union {
        float real;
        uint32_t base;
      } u_vehicle_front_to_front_axle;
      u_vehicle_front_to_front_axle.real = this->vehicle_front_to_front_axle;
      *(outbuffer + offset + 0) = (u_vehicle_front_to_front_axle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vehicle_front_to_front_axle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vehicle_front_to_front_axle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vehicle_front_to_front_axle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vehicle_front_to_front_axle);
      union {
        float real;
        uint32_t base;
      } u_front_axle_to_rear_axle;
      u_front_axle_to_rear_axle.real = this->front_axle_to_rear_axle;
      *(outbuffer + offset + 0) = (u_front_axle_to_rear_axle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_axle_to_rear_axle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_axle_to_rear_axle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_axle_to_rear_axle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_axle_to_rear_axle);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_vehicle_rear;
      u_rear_axle_to_vehicle_rear.real = this->rear_axle_to_vehicle_rear;
      *(outbuffer + offset + 0) = (u_rear_axle_to_vehicle_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_axle_to_vehicle_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_axle_to_vehicle_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_axle_to_vehicle_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rear_axle_to_vehicle_rear);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_origin;
      u_rear_axle_to_origin.real = this->rear_axle_to_origin;
      *(outbuffer + offset + 0) = (u_rear_axle_to_origin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_axle_to_origin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_axle_to_origin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_axle_to_origin.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rear_axle_to_origin);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff0;
      u_steer_ratio_coeff0.real = this->steer_ratio_coeff0;
      *(outbuffer + offset + 0) = (u_steer_ratio_coeff0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_ratio_coeff0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_ratio_coeff0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_ratio_coeff0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_ratio_coeff0);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff1;
      u_steer_ratio_coeff1.real = this->steer_ratio_coeff1;
      *(outbuffer + offset + 0) = (u_steer_ratio_coeff1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_ratio_coeff1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_ratio_coeff1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_ratio_coeff1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_ratio_coeff1);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff2;
      u_steer_ratio_coeff2.real = this->steer_ratio_coeff2;
      *(outbuffer + offset + 0) = (u_steer_ratio_coeff2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_ratio_coeff2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_ratio_coeff2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_ratio_coeff2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_ratio_coeff2);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff3;
      u_steer_ratio_coeff3.real = this->steer_ratio_coeff3;
      *(outbuffer + offset + 0) = (u_steer_ratio_coeff3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steer_ratio_coeff3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steer_ratio_coeff3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steer_ratio_coeff3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_ratio_coeff3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->microseconds =  ((uint32_t) (*(inbuffer + offset)));
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->microseconds);
      offset += this->time.deserialize(inbuffer + offset);
      this->sources =  ((uint16_t) (*(inbuffer + offset)));
      this->sources |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sources);
      this->blind_prediction_age =  ((uint16_t) (*(inbuffer + offset)));
      this->blind_prediction_age |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->blind_prediction_age);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      union {
        float real;
        uint32_t base;
      } u_latitude_sigma;
      u_latitude_sigma.base = 0;
      u_latitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude_sigma = u_latitude_sigma.real;
      offset += sizeof(this->latitude_sigma);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longtitude));
      union {
        float real;
        uint32_t base;
      } u_longtitude_sigma;
      u_longtitude_sigma.base = 0;
      u_longtitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longtitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longtitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longtitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longtitude_sigma = u_longtitude_sigma.real;
      offset += sizeof(this->longtitude_sigma);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_sigma;
      u_altitude_sigma.base = 0;
      u_altitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_sigma = u_altitude_sigma.real;
      offset += sizeof(this->altitude_sigma);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      union {
        float real;
        uint32_t base;
      } u_x_sigma;
      u_x_sigma.base = 0;
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_sigma = u_x_sigma.real;
      offset += sizeof(this->x_sigma);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      union {
        float real;
        uint32_t base;
      } u_y_sigma;
      u_y_sigma.base = 0;
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_sigma = u_y_sigma.real;
      offset += sizeof(this->y_sigma);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_z_sigma;
      u_z_sigma.base = 0;
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_sigma = u_z_sigma.real;
      offset += sizeof(this->z_sigma);
      union {
        float real;
        uint32_t base;
      } u_xy_corr;
      u_xy_corr.base = 0;
      u_xy_corr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xy_corr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xy_corr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xy_corr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xy_corr = u_xy_corr.real;
      offset += sizeof(this->xy_corr);
      union {
        float real;
        uint32_t base;
      } u_xz_corr;
      u_xz_corr.base = 0;
      u_xz_corr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_xz_corr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_xz_corr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_xz_corr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->xz_corr = u_xz_corr.real;
      offset += sizeof(this->xz_corr);
      union {
        float real;
        uint32_t base;
      } u_yz_corr;
      u_yz_corr.base = 0;
      u_yz_corr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yz_corr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yz_corr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yz_corr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yz_corr = u_yz_corr.real;
      offset += sizeof(this->yz_corr);
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
      union {
        float real;
        uint32_t base;
      } u_heading_angle;
      u_heading_angle.base = 0;
      u_heading_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading_angle = u_heading_angle.real;
      offset += sizeof(this->heading_angle);
      union {
        float real;
        uint32_t base;
      } u_heading_angle_sigma;
      u_heading_angle_sigma.base = 0;
      u_heading_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heading_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heading_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heading_angle_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->heading_angle_sigma = u_heading_angle_sigma.real;
      offset += sizeof(this->heading_angle_sigma);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_pitch_sigma;
      u_pitch_sigma.base = 0;
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_sigma = u_pitch_sigma.real;
      offset += sizeof(this->pitch_sigma);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_roll_sigma;
      u_roll_sigma.base = 0;
      u_roll_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll_sigma = u_roll_sigma.real;
      offset += sizeof(this->roll_sigma);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_velocity_sigma;
      u_velocity_sigma.base = 0;
      u_velocity_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_sigma = u_velocity_sigma.real;
      offset += sizeof(this->velocity_sigma);
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
      } u_cross_acceleration;
      u_cross_acceleration.base = 0;
      u_cross_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cross_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cross_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cross_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cross_acceleration = u_cross_acceleration.real;
      offset += sizeof(this->cross_acceleration);
      union {
        float real;
        uint32_t base;
      } u_cross_acceleration_sigma;
      u_cross_acceleration_sigma.base = 0;
      u_cross_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cross_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cross_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cross_acceleration_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cross_acceleration_sigma = u_cross_acceleration_sigma.real;
      offset += sizeof(this->cross_acceleration_sigma);
      union {
        float real;
        uint32_t base;
      } u_steer_angle;
      u_steer_angle.base = 0;
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_angle = u_steer_angle.real;
      offset += sizeof(this->steer_angle);
      union {
        float real;
        uint32_t base;
      } u_steering_wheel_angle;
      u_steering_wheel_angle.base = 0;
      u_steering_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_wheel_angle = u_steering_wheel_angle.real;
      offset += sizeof(this->steering_wheel_angle);
      union {
        float real;
        uint32_t base;
      } u_vehicle_width;
      u_vehicle_width.base = 0;
      u_vehicle_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vehicle_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vehicle_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vehicle_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vehicle_width = u_vehicle_width.real;
      offset += sizeof(this->vehicle_width);
      union {
        float real;
        uint32_t base;
      } u_min_turning_cycle;
      u_min_turning_cycle.base = 0;
      u_min_turning_cycle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_turning_cycle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_turning_cycle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_turning_cycle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_turning_cycle = u_min_turning_cycle.real;
      offset += sizeof(this->min_turning_cycle);
      union {
        float real;
        uint32_t base;
      } u_vehicle_front_to_front_axle;
      u_vehicle_front_to_front_axle.base = 0;
      u_vehicle_front_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vehicle_front_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vehicle_front_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vehicle_front_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vehicle_front_to_front_axle = u_vehicle_front_to_front_axle.real;
      offset += sizeof(this->vehicle_front_to_front_axle);
      union {
        float real;
        uint32_t base;
      } u_front_axle_to_rear_axle;
      u_front_axle_to_rear_axle.base = 0;
      u_front_axle_to_rear_axle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_axle_to_rear_axle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_axle_to_rear_axle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_axle_to_rear_axle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_axle_to_rear_axle = u_front_axle_to_rear_axle.real;
      offset += sizeof(this->front_axle_to_rear_axle);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_vehicle_rear;
      u_rear_axle_to_vehicle_rear.base = 0;
      u_rear_axle_to_vehicle_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_axle_to_vehicle_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_axle_to_vehicle_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_axle_to_vehicle_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rear_axle_to_vehicle_rear = u_rear_axle_to_vehicle_rear.real;
      offset += sizeof(this->rear_axle_to_vehicle_rear);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_origin;
      u_rear_axle_to_origin.base = 0;
      u_rear_axle_to_origin.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_axle_to_origin.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_axle_to_origin.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_axle_to_origin.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rear_axle_to_origin = u_rear_axle_to_origin.real;
      offset += sizeof(this->rear_axle_to_origin);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff0;
      u_steer_ratio_coeff0.base = 0;
      u_steer_ratio_coeff0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_ratio_coeff0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_ratio_coeff0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_ratio_coeff0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_ratio_coeff0 = u_steer_ratio_coeff0.real;
      offset += sizeof(this->steer_ratio_coeff0);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff1;
      u_steer_ratio_coeff1.base = 0;
      u_steer_ratio_coeff1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_ratio_coeff1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_ratio_coeff1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_ratio_coeff1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_ratio_coeff1 = u_steer_ratio_coeff1.real;
      offset += sizeof(this->steer_ratio_coeff1);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff2;
      u_steer_ratio_coeff2.base = 0;
      u_steer_ratio_coeff2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_ratio_coeff2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_ratio_coeff2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_ratio_coeff2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_ratio_coeff2 = u_steer_ratio_coeff2.real;
      offset += sizeof(this->steer_ratio_coeff2);
      union {
        float real;
        uint32_t base;
      } u_steer_ratio_coeff3;
      u_steer_ratio_coeff3.base = 0;
      u_steer_ratio_coeff3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steer_ratio_coeff3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steer_ratio_coeff3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steer_ratio_coeff3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steer_ratio_coeff3 = u_steer_ratio_coeff3.real;
      offset += sizeof(this->steer_ratio_coeff3);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_vehicle_state_msgs/VehicleState_2808"; };
    const char * getMD5(){ return "b1370243998bb542583a4925db826eee"; };

  };

}
#endif