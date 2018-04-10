#ifndef _ROS_ibeo_sdk_vehicle_state_msgs_VehicleState_2807_h
#define _ROS_ibeo_sdk_vehicle_state_msgs_VehicleState_2807_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2281.h"

namespace ibeo_sdk_vehicle_state_msgs
{

  class VehicleState_2807 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _microseconds_type;
      _microseconds_type microseconds;
      typedef ibeo_sdk_time_msgs::NTP64_2281 _time_type;
      _time_type time;
      typedef int32_t _x_type;
      _x_type x;
      typedef int32_t _y_type;
      _y_type y;
      typedef float _course_angle_type;
      _course_angle_type course_angle;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef float _steering_wheel_angle_type;
      _steering_wheel_angle_type steering_wheel_angle;
      typedef float _reserved0_type;
      _reserved0_type reserved0;
      typedef float _steer_angle_type;
      _steer_angle_type steer_angle;
      typedef uint16_t _reserved1_type;
      _reserved1_type reserved1;
      typedef float _vehicle_width_type;
      _vehicle_width_type vehicle_width;
      typedef float _reserved2_type;
      _reserved2_type reserved2;
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
      typedef float _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;

    VehicleState_2807():
      header(),
      microseconds(0),
      time(),
      x(0),
      y(0),
      course_angle(0),
      velocity(0),
      yaw_rate(0),
      steering_wheel_angle(0),
      reserved0(0),
      steer_angle(0),
      reserved1(0),
      vehicle_width(0),
      reserved2(0),
      vehicle_front_to_front_axle(0),
      front_axle_to_rear_axle(0),
      rear_axle_to_vehicle_rear(0),
      rear_axle_to_origin(0),
      steer_ratio_coeff0(0),
      steer_ratio_coeff1(0),
      steer_ratio_coeff2(0),
      steer_ratio_coeff3(0),
      longitudinal_acceleration(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
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
      } u_reserved0;
      u_reserved0.real = this->reserved0;
      *(outbuffer + offset + 0) = (u_reserved0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved0);
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
      *(outbuffer + offset + 0) = (this->reserved1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved1);
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
      } u_reserved2;
      u_reserved2.real = this->reserved2;
      *(outbuffer + offset + 0) = (u_reserved2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reserved2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reserved2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reserved2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reserved2);
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
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
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
      } u_reserved0;
      u_reserved0.base = 0;
      u_reserved0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved0 = u_reserved0.real;
      offset += sizeof(this->reserved0);
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
      this->reserved1 =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved1);
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
      } u_reserved2;
      u_reserved2.base = 0;
      u_reserved2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reserved2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reserved2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reserved2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reserved2 = u_reserved2.real;
      offset += sizeof(this->reserved2);
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
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_vehicle_state_msgs/VehicleState_2807"; };
    const char * getMD5(){ return "575a7c73abe8a603729900388e2a7e5b"; };

  };

}
#endif