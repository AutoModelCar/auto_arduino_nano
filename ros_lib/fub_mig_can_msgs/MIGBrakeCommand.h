#ifndef _ROS_fub_mig_can_msgs_MIGBrakeCommand_h
#define _ROS_fub_mig_can_msgs_MIGBrakeCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGBrakeCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _enable_brake_assist_type;
      _enable_brake_assist_type enable_brake_assist;
      typedef bool _enable_PRC_type;
      _enable_PRC_type enable_PRC;
      typedef float _pressure_demand_type;
      _pressure_demand_type pressure_demand;
      typedef uint16_t _pressure_demand_raw_type;
      _pressure_demand_raw_type pressure_demand_raw;
      typedef uint8_t _brake_light_switch_type;
      _brake_light_switch_type brake_light_switch;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  151  };
      enum { can_dlc =    8  };
      enum { can_cycle =   10  };
      enum { BRAKE_LIGHT_SWITCH_INACTIVE =  0 };
      enum { BRAKE_LIGHT_SWITCH_ACTIVE =  1 };
      enum { BRAKE_LIGHT_SWITCH_UNDEFINED =  2 };
      enum { BRAKE_LIGHT_SWITCH_FAILURE =  3 };

    MIGBrakeCommand():
      header(),
      enable_brake_assist(0),
      enable_PRC(0),
      pressure_demand(0),
      pressure_demand_raw(0),
      brake_light_switch(0),
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
      } u_enable_brake_assist;
      u_enable_brake_assist.real = this->enable_brake_assist;
      *(outbuffer + offset + 0) = (u_enable_brake_assist.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_brake_assist);
      union {
        bool real;
        uint8_t base;
      } u_enable_PRC;
      u_enable_PRC.real = this->enable_PRC;
      *(outbuffer + offset + 0) = (u_enable_PRC.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_PRC);
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
      *(outbuffer + offset + 1) = (this->pressure_demand_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressure_demand_raw);
      *(outbuffer + offset + 0) = (this->brake_light_switch >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_light_switch);
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
      } u_enable_brake_assist;
      u_enable_brake_assist.base = 0;
      u_enable_brake_assist.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_brake_assist = u_enable_brake_assist.real;
      offset += sizeof(this->enable_brake_assist);
      union {
        bool real;
        uint8_t base;
      } u_enable_PRC;
      u_enable_PRC.base = 0;
      u_enable_PRC.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_PRC = u_enable_PRC.real;
      offset += sizeof(this->enable_PRC);
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
      this->pressure_demand_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->pressure_demand_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pressure_demand_raw);
      this->brake_light_switch =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->brake_light_switch);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGBrakeCommand"; };
    const char * getMD5(){ return "03fa1e94eea95507105fef7af9794cdd"; };

  };

}
#endif