#ifndef _ROS_fub_mig_can_msgs_MIGBrakeStatus2_h
#define _ROS_fub_mig_can_msgs_MIGBrakeStatus2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGBrakeStatus2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enable_brake_assist_request_type;
      _enable_brake_assist_request_type enable_brake_assist_request;
      typedef bool _enable_prc_request_type;
      _enable_prc_request_type enable_prc_request;
      typedef uint8_t _status_type;
      _status_type status;
      typedef bool _status_error_type;
      _status_error_type status_error;
      typedef bool _status_voltage_high_low_type;
      _status_voltage_high_low_type status_voltage_high_low;
      typedef bool _status_brake_assist_warn_lamp_type;
      _status_brake_assist_warn_lamp_type status_brake_assist_warn_lamp;
      typedef bool _status_prc_warn_lamp_type;
      _status_prc_warn_lamp_type status_prc_warn_lamp;
      typedef bool _status_mode_type;
      _status_mode_type status_mode;
      typedef bool _status_release_switch_type;
      _status_release_switch_type status_release_switch;
      typedef bool _status_pressure_control_active_type;
      _status_pressure_control_active_type status_pressure_control_active;
      typedef uint8_t _detected_failure_type;
      _detected_failure_type detected_failure;
      typedef bool _detected_failure_intern_type;
      _detected_failure_intern_type detected_failure_intern;
      typedef bool _detected_failure_pressure_sensor_type;
      _detected_failure_pressure_sensor_type detected_failure_pressure_sensor;
      typedef bool _detected_failure_travel_sensor_type;
      _detected_failure_travel_sensor_type detected_failure_travel_sensor;
      typedef bool _detected_failure_release_switch_type;
      _detected_failure_release_switch_type detected_failure_release_switch;
      typedef bool _detected_failure_solenoid_type;
      _detected_failure_solenoid_type detected_failure_solenoid;
      typedef bool _detected_failure_press_control_type;
      _detected_failure_press_control_type detected_failure_press_control;
      typedef bool _detected_failure_can_type;
      _detected_failure_can_type detected_failure_can;
      typedef bool _detected_failure_precharge_pump_type;
      _detected_failure_precharge_pump_type detected_failure_precharge_pump;
      typedef float _pressure_sensor2_actual_pressure_type;
      _pressure_sensor2_actual_pressure_type pressure_sensor2_actual_pressure;
      typedef uint16_t _pressure_sensor2_actual_pressure_raw_type;
      _pressure_sensor2_actual_pressure_raw_type pressure_sensor2_actual_pressure_raw;
      typedef float _pressure_demand_type;
      _pressure_demand_type pressure_demand;
      typedef uint8_t _pressure_demand_raw_type;
      _pressure_demand_raw_type pressure_demand_raw;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  545  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };
      enum { STATUS_ERROR =    1 };
      enum { STATUS_VOLTAGE_HIGH_LOW =    4 };
      enum { STATUS_BRAKE_ASSIST_WARN_LAMP =    8 };
      enum { STATUS_PRC_WARN_LAMP =   16 };
      enum { STATUS_MODE =   32 };
      enum { STATUS_RELEASE_SWITCH =   64 };
      enum { STATUS_PRESSURE_CONTROL_ACTIVE =  128 };
      enum { DETECTED_FAILURE_INTERN =    1 };
      enum { DETECTED_FAILURE_PRESSURE_SENSOR =    2 };
      enum { DETECTED_FAILURE_TRAVEL_SENSOR =    4 };
      enum { DETECTED_FAILURE_RELEASE_SWITCH =    8 };
      enum { DETECTED_FAILURE_SOLENOID =   16 };
      enum { DETECTED_FAILURE_PRESS_CONTROL =   32 };
      enum { DETECTED_FAILURE_CAN =   64 };
      enum { DETECTED_FAILURE_PRECHARGE_PUMP =  128 };

    MIGBrakeStatus2():
      header(),
      enable_brake_assist_request(0),
      enable_prc_request(0),
      status(0),
      status_error(0),
      status_voltage_high_low(0),
      status_brake_assist_warn_lamp(0),
      status_prc_warn_lamp(0),
      status_mode(0),
      status_release_switch(0),
      status_pressure_control_active(0),
      detected_failure(0),
      detected_failure_intern(0),
      detected_failure_pressure_sensor(0),
      detected_failure_travel_sensor(0),
      detected_failure_release_switch(0),
      detected_failure_solenoid(0),
      detected_failure_press_control(0),
      detected_failure_can(0),
      detected_failure_precharge_pump(0),
      pressure_sensor2_actual_pressure(0),
      pressure_sensor2_actual_pressure_raw(0),
      pressure_demand(0),
      pressure_demand_raw(0),
      message_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enable_brake_assist_request;
      u_enable_brake_assist_request.real = this->enable_brake_assist_request;
      *(outbuffer + offset + 0) = (u_enable_brake_assist_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_brake_assist_request);
      union {
        bool real;
        uint8_t base;
      } u_enable_prc_request;
      u_enable_prc_request.real = this->enable_prc_request;
      *(outbuffer + offset + 0) = (u_enable_prc_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_prc_request);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_status_error;
      u_status_error.real = this->status_error;
      *(outbuffer + offset + 0) = (u_status_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_error);
      union {
        bool real;
        uint8_t base;
      } u_status_voltage_high_low;
      u_status_voltage_high_low.real = this->status_voltage_high_low;
      *(outbuffer + offset + 0) = (u_status_voltage_high_low.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_voltage_high_low);
      union {
        bool real;
        uint8_t base;
      } u_status_brake_assist_warn_lamp;
      u_status_brake_assist_warn_lamp.real = this->status_brake_assist_warn_lamp;
      *(outbuffer + offset + 0) = (u_status_brake_assist_warn_lamp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_brake_assist_warn_lamp);
      union {
        bool real;
        uint8_t base;
      } u_status_prc_warn_lamp;
      u_status_prc_warn_lamp.real = this->status_prc_warn_lamp;
      *(outbuffer + offset + 0) = (u_status_prc_warn_lamp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_prc_warn_lamp);
      union {
        bool real;
        uint8_t base;
      } u_status_mode;
      u_status_mode.real = this->status_mode;
      *(outbuffer + offset + 0) = (u_status_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_mode);
      union {
        bool real;
        uint8_t base;
      } u_status_release_switch;
      u_status_release_switch.real = this->status_release_switch;
      *(outbuffer + offset + 0) = (u_status_release_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_release_switch);
      union {
        bool real;
        uint8_t base;
      } u_status_pressure_control_active;
      u_status_pressure_control_active.real = this->status_pressure_control_active;
      *(outbuffer + offset + 0) = (u_status_pressure_control_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_pressure_control_active);
      *(outbuffer + offset + 0) = (this->detected_failure >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_intern;
      u_detected_failure_intern.real = this->detected_failure_intern;
      *(outbuffer + offset + 0) = (u_detected_failure_intern.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_intern);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_pressure_sensor;
      u_detected_failure_pressure_sensor.real = this->detected_failure_pressure_sensor;
      *(outbuffer + offset + 0) = (u_detected_failure_pressure_sensor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_pressure_sensor);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_travel_sensor;
      u_detected_failure_travel_sensor.real = this->detected_failure_travel_sensor;
      *(outbuffer + offset + 0) = (u_detected_failure_travel_sensor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_travel_sensor);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_release_switch;
      u_detected_failure_release_switch.real = this->detected_failure_release_switch;
      *(outbuffer + offset + 0) = (u_detected_failure_release_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_release_switch);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_solenoid;
      u_detected_failure_solenoid.real = this->detected_failure_solenoid;
      *(outbuffer + offset + 0) = (u_detected_failure_solenoid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_solenoid);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_press_control;
      u_detected_failure_press_control.real = this->detected_failure_press_control;
      *(outbuffer + offset + 0) = (u_detected_failure_press_control.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_press_control);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_can;
      u_detected_failure_can.real = this->detected_failure_can;
      *(outbuffer + offset + 0) = (u_detected_failure_can.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_can);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_precharge_pump;
      u_detected_failure_precharge_pump.real = this->detected_failure_precharge_pump;
      *(outbuffer + offset + 0) = (u_detected_failure_precharge_pump.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected_failure_precharge_pump);
      union {
        float real;
        uint32_t base;
      } u_pressure_sensor2_actual_pressure;
      u_pressure_sensor2_actual_pressure.real = this->pressure_sensor2_actual_pressure;
      *(outbuffer + offset + 0) = (u_pressure_sensor2_actual_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_sensor2_actual_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_sensor2_actual_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_sensor2_actual_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_sensor2_actual_pressure);
      *(outbuffer + offset + 0) = (this->pressure_sensor2_actual_pressure_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_sensor2_actual_pressure_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressure_sensor2_actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_pressure_demand;
      u_pressure_demand.real = this->pressure_demand;
      *(outbuffer + offset + 0) = (u_pressure_demand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_demand.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_demand.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_demand.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_demand);
      *(outbuffer + offset + 0) = (this->pressure_demand_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pressure_demand_raw);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_enable_brake_assist_request;
      u_enable_brake_assist_request.base = 0;
      u_enable_brake_assist_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_brake_assist_request = u_enable_brake_assist_request.real;
      offset += sizeof(this->enable_brake_assist_request);
      union {
        bool real;
        uint8_t base;
      } u_enable_prc_request;
      u_enable_prc_request.base = 0;
      u_enable_prc_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_prc_request = u_enable_prc_request.real;
      offset += sizeof(this->enable_prc_request);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_status_error;
      u_status_error.base = 0;
      u_status_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_error = u_status_error.real;
      offset += sizeof(this->status_error);
      union {
        bool real;
        uint8_t base;
      } u_status_voltage_high_low;
      u_status_voltage_high_low.base = 0;
      u_status_voltage_high_low.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_voltage_high_low = u_status_voltage_high_low.real;
      offset += sizeof(this->status_voltage_high_low);
      union {
        bool real;
        uint8_t base;
      } u_status_brake_assist_warn_lamp;
      u_status_brake_assist_warn_lamp.base = 0;
      u_status_brake_assist_warn_lamp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_brake_assist_warn_lamp = u_status_brake_assist_warn_lamp.real;
      offset += sizeof(this->status_brake_assist_warn_lamp);
      union {
        bool real;
        uint8_t base;
      } u_status_prc_warn_lamp;
      u_status_prc_warn_lamp.base = 0;
      u_status_prc_warn_lamp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_prc_warn_lamp = u_status_prc_warn_lamp.real;
      offset += sizeof(this->status_prc_warn_lamp);
      union {
        bool real;
        uint8_t base;
      } u_status_mode;
      u_status_mode.base = 0;
      u_status_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_mode = u_status_mode.real;
      offset += sizeof(this->status_mode);
      union {
        bool real;
        uint8_t base;
      } u_status_release_switch;
      u_status_release_switch.base = 0;
      u_status_release_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_release_switch = u_status_release_switch.real;
      offset += sizeof(this->status_release_switch);
      union {
        bool real;
        uint8_t base;
      } u_status_pressure_control_active;
      u_status_pressure_control_active.base = 0;
      u_status_pressure_control_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status_pressure_control_active = u_status_pressure_control_active.real;
      offset += sizeof(this->status_pressure_control_active);
      this->detected_failure =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->detected_failure);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_intern;
      u_detected_failure_intern.base = 0;
      u_detected_failure_intern.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_intern = u_detected_failure_intern.real;
      offset += sizeof(this->detected_failure_intern);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_pressure_sensor;
      u_detected_failure_pressure_sensor.base = 0;
      u_detected_failure_pressure_sensor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_pressure_sensor = u_detected_failure_pressure_sensor.real;
      offset += sizeof(this->detected_failure_pressure_sensor);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_travel_sensor;
      u_detected_failure_travel_sensor.base = 0;
      u_detected_failure_travel_sensor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_travel_sensor = u_detected_failure_travel_sensor.real;
      offset += sizeof(this->detected_failure_travel_sensor);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_release_switch;
      u_detected_failure_release_switch.base = 0;
      u_detected_failure_release_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_release_switch = u_detected_failure_release_switch.real;
      offset += sizeof(this->detected_failure_release_switch);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_solenoid;
      u_detected_failure_solenoid.base = 0;
      u_detected_failure_solenoid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_solenoid = u_detected_failure_solenoid.real;
      offset += sizeof(this->detected_failure_solenoid);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_press_control;
      u_detected_failure_press_control.base = 0;
      u_detected_failure_press_control.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_press_control = u_detected_failure_press_control.real;
      offset += sizeof(this->detected_failure_press_control);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_can;
      u_detected_failure_can.base = 0;
      u_detected_failure_can.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_can = u_detected_failure_can.real;
      offset += sizeof(this->detected_failure_can);
      union {
        bool real;
        uint8_t base;
      } u_detected_failure_precharge_pump;
      u_detected_failure_precharge_pump.base = 0;
      u_detected_failure_precharge_pump.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected_failure_precharge_pump = u_detected_failure_precharge_pump.real;
      offset += sizeof(this->detected_failure_precharge_pump);
      union {
        float real;
        uint32_t base;
      } u_pressure_sensor2_actual_pressure;
      u_pressure_sensor2_actual_pressure.base = 0;
      u_pressure_sensor2_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure_sensor2_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure_sensor2_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure_sensor2_actual_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure_sensor2_actual_pressure = u_pressure_sensor2_actual_pressure.real;
      offset += sizeof(this->pressure_sensor2_actual_pressure);
      this->pressure_sensor2_actual_pressure_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->pressure_sensor2_actual_pressure_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pressure_sensor2_actual_pressure_raw);
      union {
        float real;
        uint32_t base;
      } u_pressure_demand;
      u_pressure_demand.base = 0;
      u_pressure_demand.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure_demand.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure_demand.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure_demand.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure_demand = u_pressure_demand.real;
      offset += sizeof(this->pressure_demand);
      this->pressure_demand_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pressure_demand_raw);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGBrakeStatus2"; };
    const char * getMD5(){ return "ba9e691bf1b8f2b8ebea41c1af76fe61"; };

  };

}
#endif