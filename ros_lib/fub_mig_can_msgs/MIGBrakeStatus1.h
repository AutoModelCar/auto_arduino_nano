#ifndef _ROS_fub_mig_can_msgs_MIGBrakeStatus1_h
#define _ROS_fub_mig_can_msgs_MIGBrakeStatus1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGBrakeStatus1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _pressure_sensor1_actual_pressure_type;
      _pressure_sensor1_actual_pressure_type pressure_sensor1_actual_pressure;
      typedef uint16_t _pressure_sensor1_actual_pressure_raw_type;
      _pressure_sensor1_actual_pressure_raw_type pressure_sensor1_actual_pressure_raw;
      typedef float _travel_sensor_type;
      _travel_sensor_type travel_sensor;
      typedef uint8_t _travel_sensor_raw_type;
      _travel_sensor_raw_type travel_sensor_raw;
      typedef float _magnet_current_type;
      _magnet_current_type magnet_current;
      typedef uint8_t _magnet_current_raw_type;
      _magnet_current_raw_type magnet_current_raw;
      typedef uint8_t _magnet_pwm_ratio_type;
      _magnet_pwm_ratio_type magnet_pwm_ratio;
      typedef float _magnet_voltage_type;
      _magnet_voltage_type magnet_voltage;
      typedef uint8_t _magnet_voltage_raw_type;
      _magnet_voltage_raw_type magnet_voltage_raw;
      typedef bool _break_assist_firing_type;
      _break_assist_firing_type break_assist_firing;
      enum { can_id =  801  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    MIGBrakeStatus1():
      header(),
      pressure_sensor1_actual_pressure(0),
      pressure_sensor1_actual_pressure_raw(0),
      travel_sensor(0),
      travel_sensor_raw(0),
      magnet_current(0),
      magnet_current_raw(0),
      magnet_pwm_ratio(0),
      magnet_voltage(0),
      magnet_voltage_raw(0),
      break_assist_firing(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pressure_sensor1_actual_pressure;
      u_pressure_sensor1_actual_pressure.real = this->pressure_sensor1_actual_pressure;
      *(outbuffer + offset + 0) = (u_pressure_sensor1_actual_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_sensor1_actual_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_sensor1_actual_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_sensor1_actual_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_sensor1_actual_pressure);
      *(outbuffer + offset + 0) = (this->pressure_sensor1_actual_pressure_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_sensor1_actual_pressure_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressure_sensor1_actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_travel_sensor;
      u_travel_sensor.real = this->travel_sensor;
      *(outbuffer + offset + 0) = (u_travel_sensor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_travel_sensor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_travel_sensor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_travel_sensor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->travel_sensor);
      *(outbuffer + offset + 0) = (this->travel_sensor_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->travel_sensor_raw);
      union {
        float real;
        uint32_t base;
      } u_magnet_current;
      u_magnet_current.real = this->magnet_current;
      *(outbuffer + offset + 0) = (u_magnet_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magnet_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magnet_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magnet_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magnet_current);
      *(outbuffer + offset + 0) = (this->magnet_current_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->magnet_current_raw);
      *(outbuffer + offset + 0) = (this->magnet_pwm_ratio >> (8 * 0)) & 0xFF;
      offset += sizeof(this->magnet_pwm_ratio);
      union {
        float real;
        uint32_t base;
      } u_magnet_voltage;
      u_magnet_voltage.real = this->magnet_voltage;
      *(outbuffer + offset + 0) = (u_magnet_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magnet_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magnet_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magnet_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magnet_voltage);
      *(outbuffer + offset + 0) = (this->magnet_voltage_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->magnet_voltage_raw);
      union {
        bool real;
        uint8_t base;
      } u_break_assist_firing;
      u_break_assist_firing.real = this->break_assist_firing;
      *(outbuffer + offset + 0) = (u_break_assist_firing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->break_assist_firing);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pressure_sensor1_actual_pressure;
      u_pressure_sensor1_actual_pressure.base = 0;
      u_pressure_sensor1_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure_sensor1_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure_sensor1_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure_sensor1_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure_sensor1_actual_pressure = u_pressure_sensor1_actual_pressure.real;
      offset += sizeof(this->pressure_sensor1_actual_pressure);
      this->pressure_sensor1_actual_pressure_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->pressure_sensor1_actual_pressure_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pressure_sensor1_actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_travel_sensor;
      u_travel_sensor.base = 0;
      u_travel_sensor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_travel_sensor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_travel_sensor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_travel_sensor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->travel_sensor = u_travel_sensor.real;
      offset += sizeof(this->travel_sensor);
      this->travel_sensor_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->travel_sensor_raw);
      union {
        float real;
        uint32_t base;
      } u_magnet_current;
      u_magnet_current.base = 0;
      u_magnet_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magnet_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magnet_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magnet_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magnet_current = u_magnet_current.real;
      offset += sizeof(this->magnet_current);
      this->magnet_current_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->magnet_current_raw);
      this->magnet_pwm_ratio =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->magnet_pwm_ratio);
      union {
        float real;
        uint32_t base;
      } u_magnet_voltage;
      u_magnet_voltage.base = 0;
      u_magnet_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magnet_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magnet_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magnet_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magnet_voltage = u_magnet_voltage.real;
      offset += sizeof(this->magnet_voltage);
      this->magnet_voltage_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->magnet_voltage_raw);
      union {
        bool real;
        uint8_t base;
      } u_break_assist_firing;
      u_break_assist_firing.base = 0;
      u_break_assist_firing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->break_assist_firing = u_break_assist_firing.real;
      offset += sizeof(this->break_assist_firing);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGBrakeStatus1"; };
    const char * getMD5(){ return "45b1741ef0b5a431dc56a8150e031b1e"; };

  };

}
#endif