#ifndef _ROS_fub_mig_can_msgs_MIGWatchdogBatteryStatus_h
#define _ROS_fub_mig_can_msgs_MIGWatchdogBatteryStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGWatchdogBatteryStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef uint16_t _voltage_raw_type;
      _voltage_raw_type voltage_raw;
      enum { can_id =    4  };
      enum { can_dlc =    8  };
      enum { can_cycle =   50  };

    MIGWatchdogBatteryStatus():
      header(),
      message_counter(0),
      voltage(0),
      voltage_raw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      *(outbuffer + offset + 0) = (this->voltage_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage_raw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      this->voltage_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage_raw);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGWatchdogBatteryStatus"; };
    const char * getMD5(){ return "afe79df1b488b02414734a3e823a2559"; };

  };

}
#endif