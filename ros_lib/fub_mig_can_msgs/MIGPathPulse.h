#ifndef _ROS_fub_mig_can_msgs_MIGPathPulse_h
#define _ROS_fub_mig_can_msgs_MIGPathPulse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGPathPulse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _qbit_front_left_type;
      _qbit_front_left_type qbit_front_left;
      typedef bool _qbit_front_right_type;
      _qbit_front_right_type qbit_front_right;
      typedef bool _qbit_rear_left_type;
      _qbit_rear_left_type qbit_rear_left;
      typedef bool _qbit_rear_right_type;
      _qbit_rear_right_type qbit_rear_right;
      typedef uint16_t _pulse_front_left_type;
      _pulse_front_left_type pulse_front_left;
      typedef uint16_t _pulse_front_right_type;
      _pulse_front_right_type pulse_front_right;
      typedef uint16_t _pulse_rear_left_type;
      _pulse_rear_left_type pulse_rear_left;
      typedef uint16_t _pulse_rear_right_type;
      _pulse_rear_right_type pulse_rear_right;
      enum { can_id =  928 };
      enum { can_dlc =    8 };

    MIGPathPulse():
      header(),
      message_counter(0),
      qbit_front_left(0),
      qbit_front_right(0),
      qbit_rear_left(0),
      qbit_rear_right(0),
      pulse_front_left(0),
      pulse_front_right(0),
      pulse_rear_left(0),
      pulse_rear_right(0)
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
      } u_qbit_front_left;
      u_qbit_front_left.real = this->qbit_front_left;
      *(outbuffer + offset + 0) = (u_qbit_front_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->qbit_front_left);
      union {
        bool real;
        uint8_t base;
      } u_qbit_front_right;
      u_qbit_front_right.real = this->qbit_front_right;
      *(outbuffer + offset + 0) = (u_qbit_front_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->qbit_front_right);
      union {
        bool real;
        uint8_t base;
      } u_qbit_rear_left;
      u_qbit_rear_left.real = this->qbit_rear_left;
      *(outbuffer + offset + 0) = (u_qbit_rear_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->qbit_rear_left);
      union {
        bool real;
        uint8_t base;
      } u_qbit_rear_right;
      u_qbit_rear_right.real = this->qbit_rear_right;
      *(outbuffer + offset + 0) = (u_qbit_rear_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->qbit_rear_right);
      *(outbuffer + offset + 0) = (this->pulse_front_left >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pulse_front_left >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pulse_front_left);
      *(outbuffer + offset + 0) = (this->pulse_front_right >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pulse_front_right >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pulse_front_right);
      *(outbuffer + offset + 0) = (this->pulse_rear_left >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pulse_rear_left >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pulse_rear_left);
      *(outbuffer + offset + 0) = (this->pulse_rear_right >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pulse_rear_right >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pulse_rear_right);
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
      } u_qbit_front_left;
      u_qbit_front_left.base = 0;
      u_qbit_front_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->qbit_front_left = u_qbit_front_left.real;
      offset += sizeof(this->qbit_front_left);
      union {
        bool real;
        uint8_t base;
      } u_qbit_front_right;
      u_qbit_front_right.base = 0;
      u_qbit_front_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->qbit_front_right = u_qbit_front_right.real;
      offset += sizeof(this->qbit_front_right);
      union {
        bool real;
        uint8_t base;
      } u_qbit_rear_left;
      u_qbit_rear_left.base = 0;
      u_qbit_rear_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->qbit_rear_left = u_qbit_rear_left.real;
      offset += sizeof(this->qbit_rear_left);
      union {
        bool real;
        uint8_t base;
      } u_qbit_rear_right;
      u_qbit_rear_right.base = 0;
      u_qbit_rear_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->qbit_rear_right = u_qbit_rear_right.real;
      offset += sizeof(this->qbit_rear_right);
      this->pulse_front_left =  ((uint16_t) (*(inbuffer + offset)));
      this->pulse_front_left |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pulse_front_left);
      this->pulse_front_right =  ((uint16_t) (*(inbuffer + offset)));
      this->pulse_front_right |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pulse_front_right);
      this->pulse_rear_left =  ((uint16_t) (*(inbuffer + offset)));
      this->pulse_rear_left |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pulse_rear_left);
      this->pulse_rear_right =  ((uint16_t) (*(inbuffer + offset)));
      this->pulse_rear_right |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pulse_rear_right);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGPathPulse"; };
    const char * getMD5(){ return "4a7b1ae97f8f3a7a7f76918fa9cffb59"; };

  };

}
#endif