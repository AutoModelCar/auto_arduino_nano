#ifndef _ROS_fub_mig_can_msgs_MIGWatchdogStatus_h
#define _ROS_fub_mig_can_msgs_MIGWatchdogStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGWatchdogStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _gas_brake_enabled_type;
      _gas_brake_enabled_type gas_brake_enabled;
      typedef bool _gear_enabled_type;
      _gear_enabled_type gear_enabled;
      typedef uint8_t _watchdog_state_type;
      _watchdog_state_type watchdog_state;
      typedef bool _voltage_monitoring_okay_type;
      _voltage_monitoring_okay_type voltage_monitoring_okay;
      typedef bool _watchdog_command_okay_type;
      _watchdog_command_okay_type watchdog_command_okay;
      typedef bool _gear_controller_okay_type;
      _gear_controller_okay_type gear_controller_okay;
      typedef bool _brake_controller_okay_type;
      _brake_controller_okay_type brake_controller_okay;
      typedef bool _throttle_controller_okay_type;
      _throttle_controller_okay_type throttle_controller_okay;
      typedef bool _function_controller_okay_type;
      _function_controller_okay_type function_controller_okay;
      typedef bool _brake_okay_type;
      _brake_okay_type brake_okay;
      typedef bool _throttle_okay_type;
      _throttle_okay_type throttle_okay;
      typedef bool _function_okay_type;
      _function_okay_type function_okay;
      typedef bool _gear_okay_type;
      _gear_okay_type gear_okay;
      typedef uint8_t _powerdown_reason_type;
      _powerdown_reason_type powerdown_reason;
      typedef bool _actoric_box_okay_type;
      _actoric_box_okay_type actoric_box_okay;
      typedef bool _driver_is_braking_type;
      _driver_is_braking_type driver_is_braking;
      typedef bool _driver_is_accelerating_type;
      _driver_is_accelerating_type driver_is_accelerating;
      typedef bool _driver_is_shifting_gear_type;
      _driver_is_shifting_gear_type driver_is_shifting_gear;
      typedef bool _powered_down_type;
      _powered_down_type powered_down;
      typedef bool _gas_brake_requested_type;
      _gas_brake_requested_type gas_brake_requested;
      typedef bool _gear_requested_type;
      _gear_requested_type gear_requested;
      enum { can_id =    3  };
      enum { can_dlc =    8  };
      enum { can_cycle =   50  };
      enum { WATCHDOG_STATE_OFF =   1 };
      enum { WATCHDOG_STATE_S1_OFF =   2 };
      enum { WATCHDOG_STATE_S2_OFF =   4 };
      enum { WATCHDOG_STATE_VOLTAGE_ON =   8 };
      enum { WATCHDOG_STATE_VOLTAGE_ON_ERROR =   9 };
      enum { WATCHDOG_STATE_OPERATION_READY =  11 };
      enum { WATCHDOG_STATE_ACTORIC_READY =  12 };
      enum { POWERDOWN_REASON_NO_POWER_OFF =  0   };
      enum { POWERDOWN_REASON_IGNITION_OFF =  1 };
      enum { POWERDOWN_REASON_S1 =  2   };
      enum { POWERDOWN_REASON_S2 =  3   };
      enum { POWERDOWN_REASON_VOLTAGE_PROBLEM =  4 };
      enum { POWERDOWN_REASON_ERROR_WATCHDOG_COMMAND =  5 };
      enum { POWERDOWN_REASON_ERROR_CONTROLLER_BRAKE =  7 };
      enum { POWERDOWN_REASON_ERROR_CONTROLLER_GAS_PEDAL =  8 };
      enum { POWERDOWN_REASON_BRAKE_MALFUNCTION =  10 };
      enum { POWERDOWN_REASON_GAS_PEDAL_MALFUNCTION =  11 };
      enum { POWERDOWN_REASON_DEACTIVATION =  12 };
      enum { POWERDOWN_REASON_DRIVER_INTERVENTION =  13 };
      enum { POWERDOWN_REASON_ACTORIC_BOX_MALFUNCTION =  16 };
      enum { POWERDOWN_REASON_NOT_ENABLED =  17 };
      enum { POWERDOWN_REASON_ERROR_CONTROLLER_GEAR =  18 };
      enum { POWERDOWN_REASON_GEAR_MALFUNCTION =  19 };
      enum { POWERDOWN_REASON_UNKNOWN =  255 };

    MIGWatchdogStatus():
      header(),
      message_counter(0),
      gas_brake_enabled(0),
      gear_enabled(0),
      watchdog_state(0),
      voltage_monitoring_okay(0),
      watchdog_command_okay(0),
      gear_controller_okay(0),
      brake_controller_okay(0),
      throttle_controller_okay(0),
      function_controller_okay(0),
      brake_okay(0),
      throttle_okay(0),
      function_okay(0),
      gear_okay(0),
      powerdown_reason(0),
      actoric_box_okay(0),
      driver_is_braking(0),
      driver_is_accelerating(0),
      driver_is_shifting_gear(0),
      powered_down(0),
      gas_brake_requested(0),
      gear_requested(0)
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
      } u_gas_brake_enabled;
      u_gas_brake_enabled.real = this->gas_brake_enabled;
      *(outbuffer + offset + 0) = (u_gas_brake_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gas_brake_enabled);
      union {
        bool real;
        uint8_t base;
      } u_gear_enabled;
      u_gear_enabled.real = this->gear_enabled;
      *(outbuffer + offset + 0) = (u_gear_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_enabled);
      *(outbuffer + offset + 0) = (this->watchdog_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->watchdog_state);
      union {
        bool real;
        uint8_t base;
      } u_voltage_monitoring_okay;
      u_voltage_monitoring_okay.real = this->voltage_monitoring_okay;
      *(outbuffer + offset + 0) = (u_voltage_monitoring_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->voltage_monitoring_okay);
      union {
        bool real;
        uint8_t base;
      } u_watchdog_command_okay;
      u_watchdog_command_okay.real = this->watchdog_command_okay;
      *(outbuffer + offset + 0) = (u_watchdog_command_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->watchdog_command_okay);
      union {
        bool real;
        uint8_t base;
      } u_gear_controller_okay;
      u_gear_controller_okay.real = this->gear_controller_okay;
      *(outbuffer + offset + 0) = (u_gear_controller_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_brake_controller_okay;
      u_brake_controller_okay.real = this->brake_controller_okay;
      *(outbuffer + offset + 0) = (u_brake_controller_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_throttle_controller_okay;
      u_throttle_controller_okay.real = this->throttle_controller_okay;
      *(outbuffer + offset + 0) = (u_throttle_controller_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->throttle_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_function_controller_okay;
      u_function_controller_okay.real = this->function_controller_okay;
      *(outbuffer + offset + 0) = (u_function_controller_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->function_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_brake_okay;
      u_brake_okay.real = this->brake_okay;
      *(outbuffer + offset + 0) = (u_brake_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_okay);
      union {
        bool real;
        uint8_t base;
      } u_throttle_okay;
      u_throttle_okay.real = this->throttle_okay;
      *(outbuffer + offset + 0) = (u_throttle_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->throttle_okay);
      union {
        bool real;
        uint8_t base;
      } u_function_okay;
      u_function_okay.real = this->function_okay;
      *(outbuffer + offset + 0) = (u_function_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->function_okay);
      union {
        bool real;
        uint8_t base;
      } u_gear_okay;
      u_gear_okay.real = this->gear_okay;
      *(outbuffer + offset + 0) = (u_gear_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_okay);
      *(outbuffer + offset + 0) = (this->powerdown_reason >> (8 * 0)) & 0xFF;
      offset += sizeof(this->powerdown_reason);
      union {
        bool real;
        uint8_t base;
      } u_actoric_box_okay;
      u_actoric_box_okay.real = this->actoric_box_okay;
      *(outbuffer + offset + 0) = (u_actoric_box_okay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->actoric_box_okay);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_braking;
      u_driver_is_braking.real = this->driver_is_braking;
      *(outbuffer + offset + 0) = (u_driver_is_braking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_is_braking);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_accelerating;
      u_driver_is_accelerating.real = this->driver_is_accelerating;
      *(outbuffer + offset + 0) = (u_driver_is_accelerating.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_is_accelerating);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_shifting_gear;
      u_driver_is_shifting_gear.real = this->driver_is_shifting_gear;
      *(outbuffer + offset + 0) = (u_driver_is_shifting_gear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_is_shifting_gear);
      union {
        bool real;
        uint8_t base;
      } u_powered_down;
      u_powered_down.real = this->powered_down;
      *(outbuffer + offset + 0) = (u_powered_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->powered_down);
      union {
        bool real;
        uint8_t base;
      } u_gas_brake_requested;
      u_gas_brake_requested.real = this->gas_brake_requested;
      *(outbuffer + offset + 0) = (u_gas_brake_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gas_brake_requested);
      union {
        bool real;
        uint8_t base;
      } u_gear_requested;
      u_gear_requested.real = this->gear_requested;
      *(outbuffer + offset + 0) = (u_gear_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_requested);
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
      } u_gas_brake_enabled;
      u_gas_brake_enabled.base = 0;
      u_gas_brake_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gas_brake_enabled = u_gas_brake_enabled.real;
      offset += sizeof(this->gas_brake_enabled);
      union {
        bool real;
        uint8_t base;
      } u_gear_enabled;
      u_gear_enabled.base = 0;
      u_gear_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_enabled = u_gear_enabled.real;
      offset += sizeof(this->gear_enabled);
      this->watchdog_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->watchdog_state);
      union {
        bool real;
        uint8_t base;
      } u_voltage_monitoring_okay;
      u_voltage_monitoring_okay.base = 0;
      u_voltage_monitoring_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->voltage_monitoring_okay = u_voltage_monitoring_okay.real;
      offset += sizeof(this->voltage_monitoring_okay);
      union {
        bool real;
        uint8_t base;
      } u_watchdog_command_okay;
      u_watchdog_command_okay.base = 0;
      u_watchdog_command_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->watchdog_command_okay = u_watchdog_command_okay.real;
      offset += sizeof(this->watchdog_command_okay);
      union {
        bool real;
        uint8_t base;
      } u_gear_controller_okay;
      u_gear_controller_okay.base = 0;
      u_gear_controller_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_controller_okay = u_gear_controller_okay.real;
      offset += sizeof(this->gear_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_brake_controller_okay;
      u_brake_controller_okay.base = 0;
      u_brake_controller_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_controller_okay = u_brake_controller_okay.real;
      offset += sizeof(this->brake_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_throttle_controller_okay;
      u_throttle_controller_okay.base = 0;
      u_throttle_controller_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->throttle_controller_okay = u_throttle_controller_okay.real;
      offset += sizeof(this->throttle_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_function_controller_okay;
      u_function_controller_okay.base = 0;
      u_function_controller_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->function_controller_okay = u_function_controller_okay.real;
      offset += sizeof(this->function_controller_okay);
      union {
        bool real;
        uint8_t base;
      } u_brake_okay;
      u_brake_okay.base = 0;
      u_brake_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_okay = u_brake_okay.real;
      offset += sizeof(this->brake_okay);
      union {
        bool real;
        uint8_t base;
      } u_throttle_okay;
      u_throttle_okay.base = 0;
      u_throttle_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->throttle_okay = u_throttle_okay.real;
      offset += sizeof(this->throttle_okay);
      union {
        bool real;
        uint8_t base;
      } u_function_okay;
      u_function_okay.base = 0;
      u_function_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->function_okay = u_function_okay.real;
      offset += sizeof(this->function_okay);
      union {
        bool real;
        uint8_t base;
      } u_gear_okay;
      u_gear_okay.base = 0;
      u_gear_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_okay = u_gear_okay.real;
      offset += sizeof(this->gear_okay);
      this->powerdown_reason =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->powerdown_reason);
      union {
        bool real;
        uint8_t base;
      } u_actoric_box_okay;
      u_actoric_box_okay.base = 0;
      u_actoric_box_okay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->actoric_box_okay = u_actoric_box_okay.real;
      offset += sizeof(this->actoric_box_okay);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_braking;
      u_driver_is_braking.base = 0;
      u_driver_is_braking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_is_braking = u_driver_is_braking.real;
      offset += sizeof(this->driver_is_braking);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_accelerating;
      u_driver_is_accelerating.base = 0;
      u_driver_is_accelerating.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_is_accelerating = u_driver_is_accelerating.real;
      offset += sizeof(this->driver_is_accelerating);
      union {
        bool real;
        uint8_t base;
      } u_driver_is_shifting_gear;
      u_driver_is_shifting_gear.base = 0;
      u_driver_is_shifting_gear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_is_shifting_gear = u_driver_is_shifting_gear.real;
      offset += sizeof(this->driver_is_shifting_gear);
      union {
        bool real;
        uint8_t base;
      } u_powered_down;
      u_powered_down.base = 0;
      u_powered_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->powered_down = u_powered_down.real;
      offset += sizeof(this->powered_down);
      union {
        bool real;
        uint8_t base;
      } u_gas_brake_requested;
      u_gas_brake_requested.base = 0;
      u_gas_brake_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gas_brake_requested = u_gas_brake_requested.real;
      offset += sizeof(this->gas_brake_requested);
      union {
        bool real;
        uint8_t base;
      } u_gear_requested;
      u_gear_requested.base = 0;
      u_gear_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gear_requested = u_gear_requested.real;
      offset += sizeof(this->gear_requested);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGWatchdogStatus"; };
    const char * getMD5(){ return "7b85ecc1cb55332c1e4203d4e5cd1ab4"; };

  };

}
#endif