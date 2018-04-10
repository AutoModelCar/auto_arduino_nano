#ifndef _ROS_fub_mig_can_msgs_MIGYawAndBrakePressure_h
#define _ROS_fub_mig_can_msgs_MIGYawAndBrakePressure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGYawAndBrakePressure : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _yaw_rate_valid_type;
      _yaw_rate_valid_type yaw_rate_valid;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      typedef uint16_t _yaw_rate_raw_type;
      _yaw_rate_raw_type yaw_rate_raw;
      typedef bool _yaw_rate_sign_type;
      _yaw_rate_sign_type yaw_rate_sign;
      typedef bool _brake_pressure_valid_type;
      _brake_pressure_valid_type brake_pressure_valid;
      typedef float _brake_pressure_type;
      _brake_pressure_type brake_pressure;
      typedef uint16_t _brake_pressure_raw_type;
      _brake_pressure_raw_type brake_pressure_raw;
      typedef bool _brake_pressure_sign_type;
      _brake_pressure_sign_type brake_pressure_sign;
      enum { can_id =  1192 };
      enum { can_dlc =     8 };

    MIGYawAndBrakePressure():
      header(),
      message_counter(0),
      yaw_rate_valid(0),
      yaw_rate(0),
      yaw_rate_raw(0),
      yaw_rate_sign(0),
      brake_pressure_valid(0),
      brake_pressure(0),
      brake_pressure_raw(0),
      brake_pressure_sign(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      union {
        bool real;
        uint8_t base;
      } u_yaw_rate_valid;
      u_yaw_rate_valid.real = this->yaw_rate_valid;
      *(outbuffer + offset + 0) = (u_yaw_rate_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_rate_valid);
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
      *(outbuffer + offset + 0) = (this->yaw_rate_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->yaw_rate_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_rate_raw);
      union {
        bool real;
        uint8_t base;
      } u_yaw_rate_sign;
      u_yaw_rate_sign.real = this->yaw_rate_sign;
      *(outbuffer + offset + 0) = (u_yaw_rate_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_rate_sign);
      union {
        bool real;
        uint8_t base;
      } u_brake_pressure_valid;
      u_brake_pressure_valid.real = this->brake_pressure_valid;
      *(outbuffer + offset + 0) = (u_brake_pressure_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_pressure_valid);
      union {
        float real;
        uint32_t base;
      } u_brake_pressure;
      u_brake_pressure.real = this->brake_pressure;
      *(outbuffer + offset + 0) = (u_brake_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake_pressure);
      *(outbuffer + offset + 0) = (this->brake_pressure_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->brake_pressure_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->brake_pressure_raw);
      union {
        bool real;
        uint8_t base;
      } u_brake_pressure_sign;
      u_brake_pressure_sign.real = this->brake_pressure_sign;
      *(outbuffer + offset + 0) = (u_brake_pressure_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_pressure_sign);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      union {
        bool real;
        uint8_t base;
      } u_yaw_rate_valid;
      u_yaw_rate_valid.base = 0;
      u_yaw_rate_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yaw_rate_valid = u_yaw_rate_valid.real;
      offset += sizeof(this->yaw_rate_valid);
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
      this->yaw_rate_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->yaw_rate_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->yaw_rate_raw);
      union {
        bool real;
        uint8_t base;
      } u_yaw_rate_sign;
      u_yaw_rate_sign.base = 0;
      u_yaw_rate_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yaw_rate_sign = u_yaw_rate_sign.real;
      offset += sizeof(this->yaw_rate_sign);
      union {
        bool real;
        uint8_t base;
      } u_brake_pressure_valid;
      u_brake_pressure_valid.base = 0;
      u_brake_pressure_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_pressure_valid = u_brake_pressure_valid.real;
      offset += sizeof(this->brake_pressure_valid);
      union {
        float real;
        uint32_t base;
      } u_brake_pressure;
      u_brake_pressure.base = 0;
      u_brake_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake_pressure = u_brake_pressure.real;
      offset += sizeof(this->brake_pressure);
      this->brake_pressure_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->brake_pressure_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->brake_pressure_raw);
      union {
        bool real;
        uint8_t base;
      } u_brake_pressure_sign;
      u_brake_pressure_sign.base = 0;
      u_brake_pressure_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_pressure_sign = u_brake_pressure_sign.real;
      offset += sizeof(this->brake_pressure_sign);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGYawAndBrakePressure"; };
    const char * getMD5(){ return "006ab80f2b93a0e2174a9d64a29ff2d9"; };

  };

}
#endif