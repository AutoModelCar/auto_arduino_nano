#ifndef _ROS_autonomos_ibeo_msgs_IbeoVehicleState_h
#define _ROS_autonomos_ibeo_msgs_IbeoVehicleState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_ibeo_msgs
{

  class IbeoVehicleState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _source_type;
      _source_type source;
      typedef float _front_wheel_angle_type;
      _front_wheel_angle_type front_wheel_angle;
      typedef float _course_angle_type;
      _course_angle_type course_angle;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef float _longitudinal_velocity_type;
      _longitudinal_velocity_type longitudinal_velocity;
      typedef float _longitudinal_acceleration_type;
      _longitudinal_acceleration_type longitudinal_acceleration;
      typedef float _vehicle_width_type;
      _vehicle_width_type vehicle_width;
      typedef float _front_axle_to_front_type;
      _front_axle_to_front_type front_axle_to_front;
      typedef float _rear_axle_to_front_axle_type;
      _rear_axle_to_front_axle_type rear_axle_to_front_axle;
      typedef float _rear_axle_to_rear_type;
      _rear_axle_to_rear_type rear_axle_to_rear;
      enum { SOURCE_CAN =  1 };
      enum { SOURCE_GPS =  2 };
      enum { SOURCE_IMU =  4 };

    IbeoVehicleState():
      header(),
      source(0),
      front_wheel_angle(0),
      course_angle(0),
      yaw_rate(0),
      longitudinal_velocity(0),
      longitudinal_acceleration(0),
      vehicle_width(0),
      front_axle_to_front(0),
      rear_axle_to_front_axle(0),
      rear_axle_to_rear(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->source >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->source >> (8 * 1)) & 0xFF;
      offset += sizeof(this->source);
      union {
        float real;
        uint32_t base;
      } u_front_wheel_angle;
      u_front_wheel_angle.real = this->front_wheel_angle;
      *(outbuffer + offset + 0) = (u_front_wheel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_wheel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_wheel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_wheel_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_wheel_angle);
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
      } u_longitudinal_velocity;
      u_longitudinal_velocity.real = this->longitudinal_velocity;
      *(outbuffer + offset + 0) = (u_longitudinal_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitudinal_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitudinal_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitudinal_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitudinal_velocity);
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
      } u_front_axle_to_front;
      u_front_axle_to_front.real = this->front_axle_to_front;
      *(outbuffer + offset + 0) = (u_front_axle_to_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_axle_to_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_axle_to_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_axle_to_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_axle_to_front);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_front_axle;
      u_rear_axle_to_front_axle.real = this->rear_axle_to_front_axle;
      *(outbuffer + offset + 0) = (u_rear_axle_to_front_axle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_axle_to_front_axle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_axle_to_front_axle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_axle_to_front_axle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rear_axle_to_front_axle);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_rear;
      u_rear_axle_to_rear.real = this->rear_axle_to_rear;
      *(outbuffer + offset + 0) = (u_rear_axle_to_rear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rear_axle_to_rear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rear_axle_to_rear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rear_axle_to_rear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rear_axle_to_rear);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->source =  ((uint16_t) (*(inbuffer + offset)));
      this->source |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->source);
      union {
        float real;
        uint32_t base;
      } u_front_wheel_angle;
      u_front_wheel_angle.base = 0;
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_wheel_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_wheel_angle = u_front_wheel_angle.real;
      offset += sizeof(this->front_wheel_angle);
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
      } u_longitudinal_velocity;
      u_longitudinal_velocity.base = 0;
      u_longitudinal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitudinal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitudinal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitudinal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitudinal_velocity = u_longitudinal_velocity.real;
      offset += sizeof(this->longitudinal_velocity);
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
      } u_front_axle_to_front;
      u_front_axle_to_front.base = 0;
      u_front_axle_to_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_axle_to_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_axle_to_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_axle_to_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_axle_to_front = u_front_axle_to_front.real;
      offset += sizeof(this->front_axle_to_front);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_front_axle;
      u_rear_axle_to_front_axle.base = 0;
      u_rear_axle_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_axle_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_axle_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_axle_to_front_axle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rear_axle_to_front_axle = u_rear_axle_to_front_axle.real;
      offset += sizeof(this->rear_axle_to_front_axle);
      union {
        float real;
        uint32_t base;
      } u_rear_axle_to_rear;
      u_rear_axle_to_rear.base = 0;
      u_rear_axle_to_rear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rear_axle_to_rear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rear_axle_to_rear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rear_axle_to_rear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rear_axle_to_rear = u_rear_axle_to_rear.real;
      offset += sizeof(this->rear_axle_to_rear);
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoVehicleState"; };
    const char * getMD5(){ return "2b27795bc12af8a6d9c91842a4a58e6d"; };

  };

}
#endif