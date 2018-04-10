#ifndef _ROS_fub_mig_can_msgs_MIGThrottleCommand_h
#define _ROS_fub_mig_can_msgs_MIGThrottleCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGThrottleCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef float _wanted_voltage_type;
      _wanted_voltage_type wanted_voltage;
      typedef uint16_t _wanted_voltage_raw_type;
      _wanted_voltage_raw_type wanted_voltage_raw;
      enum { can_id =  163  };
      enum { can_dlc =    8  };
      enum { can_cycle =   20  };

    MIGThrottleCommand():
      header(),
      message_counter(0),
      wanted_voltage(0),
      wanted_voltage_raw(0)
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
      } u_wanted_voltage;
      u_wanted_voltage.real = this->wanted_voltage;
      *(outbuffer + offset + 0) = (u_wanted_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wanted_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wanted_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wanted_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wanted_voltage);
      *(outbuffer + offset + 0) = (this->wanted_voltage_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wanted_voltage_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wanted_voltage_raw);
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
      } u_wanted_voltage;
      u_wanted_voltage.base = 0;
      u_wanted_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wanted_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wanted_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wanted_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wanted_voltage = u_wanted_voltage.real;
      offset += sizeof(this->wanted_voltage);
      this->wanted_voltage_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->wanted_voltage_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wanted_voltage_raw);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGThrottleCommand"; };
    const char * getMD5(){ return "d2e6b57fdf8b5c0d575cdd1868e83d10"; };

  };

}
#endif