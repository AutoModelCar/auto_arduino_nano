#ifndef _ROS_fub_mig_can_msgs_MIGSteeringWheelSpeed_h
#define _ROS_fub_mig_can_msgs_MIGSteeringWheelSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGSteeringWheelSpeed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _steering_wheel_angle_type;
      _steering_wheel_angle_type steering_wheel_angle;
      typedef uint16_t _steering_wheel_angle_raw_type;
      _steering_wheel_angle_raw_type steering_wheel_angle_raw;
      typedef bool _steering_wheel_angle_sign_type;
      _steering_wheel_angle_sign_type steering_wheel_angle_sign;
      typedef float _steering_wheel_speed_type;
      _steering_wheel_speed_type steering_wheel_speed;
      typedef uint16_t _steering_wheel_speed_raw_type;
      _steering_wheel_speed_raw_type steering_wheel_speed_raw;
      typedef bool _steering_wheel_speed_sign_type;
      _steering_wheel_speed_sign_type steering_wheel_speed_sign;
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  194 };
      enum { can_dlc =    8 };

    MIGSteeringWheelSpeed():
      header(),
      steering_wheel_angle(0),
      steering_wheel_angle_raw(0),
      steering_wheel_angle_sign(0),
      steering_wheel_speed(0),
      steering_wheel_speed_raw(0),
      steering_wheel_speed_sign(0),
      id(0),
      message_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->steering_wheel_angle_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steering_wheel_angle_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steering_wheel_angle_raw);
      union {
        bool real;
        uint8_t base;
      } u_steering_wheel_angle_sign;
      u_steering_wheel_angle_sign.real = this->steering_wheel_angle_sign;
      *(outbuffer + offset + 0) = (u_steering_wheel_angle_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_wheel_angle_sign);
      union {
        float real;
        uint32_t base;
      } u_steering_wheel_speed;
      u_steering_wheel_speed.real = this->steering_wheel_speed;
      *(outbuffer + offset + 0) = (u_steering_wheel_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_wheel_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_wheel_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_wheel_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_wheel_speed);
      *(outbuffer + offset + 0) = (this->steering_wheel_speed_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steering_wheel_speed_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steering_wheel_speed_raw);
      union {
        bool real;
        uint8_t base;
      } u_steering_wheel_speed_sign;
      u_steering_wheel_speed_sign.real = this->steering_wheel_speed_sign;
      *(outbuffer + offset + 0) = (u_steering_wheel_speed_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_wheel_speed_sign);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      this->steering_wheel_angle_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steering_wheel_angle_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steering_wheel_angle_raw);
      union {
        bool real;
        uint8_t base;
      } u_steering_wheel_angle_sign;
      u_steering_wheel_angle_sign.base = 0;
      u_steering_wheel_angle_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steering_wheel_angle_sign = u_steering_wheel_angle_sign.real;
      offset += sizeof(this->steering_wheel_angle_sign);
      union {
        float real;
        uint32_t base;
      } u_steering_wheel_speed;
      u_steering_wheel_speed.base = 0;
      u_steering_wheel_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_wheel_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_wheel_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_wheel_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_wheel_speed = u_steering_wheel_speed.real;
      offset += sizeof(this->steering_wheel_speed);
      this->steering_wheel_speed_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->steering_wheel_speed_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->steering_wheel_speed_raw);
      union {
        bool real;
        uint8_t base;
      } u_steering_wheel_speed_sign;
      u_steering_wheel_speed_sign.base = 0;
      u_steering_wheel_speed_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steering_wheel_speed_sign = u_steering_wheel_speed_sign.real;
      offset += sizeof(this->steering_wheel_speed_sign);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGSteeringWheelSpeed"; };
    const char * getMD5(){ return "cda366a5175af033b9e88e962b27486a"; };

  };

}
#endif