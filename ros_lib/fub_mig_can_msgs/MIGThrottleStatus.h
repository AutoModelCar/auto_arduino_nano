#ifndef _ROS_fub_mig_can_msgs_MIGThrottleStatus_h
#define _ROS_fub_mig_can_msgs_MIGThrottleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGThrottleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef float _voltage_gas_pedal_1_type;
      _voltage_gas_pedal_1_type voltage_gas_pedal_1;
      typedef uint16_t _voltage_gas_pedal_1_raw_type;
      _voltage_gas_pedal_1_raw_type voltage_gas_pedal_1_raw;
      typedef float _voltage_gas_pedal_2_type;
      _voltage_gas_pedal_2_type voltage_gas_pedal_2;
      typedef uint16_t _voltage_gas_pedal_2_raw_type;
      _voltage_gas_pedal_2_raw_type voltage_gas_pedal_2_raw;
      typedef float _voltage_motor1_type;
      _voltage_motor1_type voltage_motor1;
      typedef uint16_t _voltage_motor1_raw_type;
      _voltage_motor1_raw_type voltage_motor1_raw;
      typedef float _voltage_motor2_type;
      _voltage_motor2_type voltage_motor2;
      typedef uint16_t _voltage_motor2_raw_type;
      _voltage_motor2_raw_type voltage_motor2_raw;
      enum { can_id =  161  };
      enum { can_dlc =    8  };
      enum { can_cycle =   20  };

    MIGThrottleStatus():
      header(),
      message_counter(0),
      voltage_gas_pedal_1(0),
      voltage_gas_pedal_1_raw(0),
      voltage_gas_pedal_2(0),
      voltage_gas_pedal_2_raw(0),
      voltage_motor1(0),
      voltage_motor1_raw(0),
      voltage_motor2(0),
      voltage_motor2_raw(0)
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
      } u_voltage_gas_pedal_1;
      u_voltage_gas_pedal_1.real = this->voltage_gas_pedal_1;
      *(outbuffer + offset + 0) = (u_voltage_gas_pedal_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage_gas_pedal_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage_gas_pedal_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage_gas_pedal_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_gas_pedal_1);
      *(outbuffer + offset + 0) = (this->voltage_gas_pedal_1_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_gas_pedal_1_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage_gas_pedal_1_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_gas_pedal_2;
      u_voltage_gas_pedal_2.real = this->voltage_gas_pedal_2;
      *(outbuffer + offset + 0) = (u_voltage_gas_pedal_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage_gas_pedal_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage_gas_pedal_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage_gas_pedal_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_gas_pedal_2);
      *(outbuffer + offset + 0) = (this->voltage_gas_pedal_2_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_gas_pedal_2_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage_gas_pedal_2_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_motor1;
      u_voltage_motor1.real = this->voltage_motor1;
      *(outbuffer + offset + 0) = (u_voltage_motor1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage_motor1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage_motor1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage_motor1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_motor1);
      *(outbuffer + offset + 0) = (this->voltage_motor1_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_motor1_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage_motor1_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_motor2;
      u_voltage_motor2.real = this->voltage_motor2;
      *(outbuffer + offset + 0) = (u_voltage_motor2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage_motor2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage_motor2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage_motor2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_motor2);
      *(outbuffer + offset + 0) = (this->voltage_motor2_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_motor2_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->voltage_motor2_raw);
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
      } u_voltage_gas_pedal_1;
      u_voltage_gas_pedal_1.base = 0;
      u_voltage_gas_pedal_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage_gas_pedal_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage_gas_pedal_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage_gas_pedal_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage_gas_pedal_1 = u_voltage_gas_pedal_1.real;
      offset += sizeof(this->voltage_gas_pedal_1);
      this->voltage_gas_pedal_1_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage_gas_pedal_1_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage_gas_pedal_1_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_gas_pedal_2;
      u_voltage_gas_pedal_2.base = 0;
      u_voltage_gas_pedal_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage_gas_pedal_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage_gas_pedal_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage_gas_pedal_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage_gas_pedal_2 = u_voltage_gas_pedal_2.real;
      offset += sizeof(this->voltage_gas_pedal_2);
      this->voltage_gas_pedal_2_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage_gas_pedal_2_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage_gas_pedal_2_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_motor1;
      u_voltage_motor1.base = 0;
      u_voltage_motor1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage_motor1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage_motor1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage_motor1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage_motor1 = u_voltage_motor1.real;
      offset += sizeof(this->voltage_motor1);
      this->voltage_motor1_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage_motor1_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage_motor1_raw);
      union {
        float real;
        uint32_t base;
      } u_voltage_motor2;
      u_voltage_motor2.base = 0;
      u_voltage_motor2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage_motor2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage_motor2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage_motor2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage_motor2 = u_voltage_motor2.real;
      offset += sizeof(this->voltage_motor2);
      this->voltage_motor2_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->voltage_motor2_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->voltage_motor2_raw);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGThrottleStatus"; };
    const char * getMD5(){ return "6f0f8302fa16f896ec05a890b974ea38"; };

  };

}
#endif