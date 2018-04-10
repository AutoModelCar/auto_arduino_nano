#ifndef _ROS_fub_mig_can_msgs_MIGAbsEsp_h
#define _ROS_fub_mig_can_msgs_MIGAbsEsp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGAbsEsp : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _esp_sign_type;
      _esp_sign_type esp_sign;
      typedef bool _abs_sign_type;
      _abs_sign_type abs_sign;
      typedef bool _backup_sign_type;
      _backup_sign_type backup_sign;
      typedef float _speed_type;
      _speed_type speed;
      typedef uint16_t _speed_raw_type;
      _speed_raw_type speed_raw;
      enum { can_id =  416  };
      enum { can_dlc =    8  };

    MIGAbsEsp():
      header(),
      message_counter(0),
      esp_sign(0),
      abs_sign(0),
      backup_sign(0),
      speed(0),
      speed_raw(0)
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
      } u_esp_sign;
      u_esp_sign.real = this->esp_sign;
      *(outbuffer + offset + 0) = (u_esp_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->esp_sign);
      union {
        bool real;
        uint8_t base;
      } u_abs_sign;
      u_abs_sign.real = this->abs_sign;
      *(outbuffer + offset + 0) = (u_abs_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->abs_sign);
      union {
        bool real;
        uint8_t base;
      } u_backup_sign;
      u_backup_sign.real = this->backup_sign;
      *(outbuffer + offset + 0) = (u_backup_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->backup_sign);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      *(outbuffer + offset + 0) = (this->speed_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->speed_raw);
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
      } u_esp_sign;
      u_esp_sign.base = 0;
      u_esp_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->esp_sign = u_esp_sign.real;
      offset += sizeof(this->esp_sign);
      union {
        bool real;
        uint8_t base;
      } u_abs_sign;
      u_abs_sign.base = 0;
      u_abs_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->abs_sign = u_abs_sign.real;
      offset += sizeof(this->abs_sign);
      union {
        bool real;
        uint8_t base;
      } u_backup_sign;
      u_backup_sign.base = 0;
      u_backup_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->backup_sign = u_backup_sign.real;
      offset += sizeof(this->backup_sign);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      this->speed_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->speed_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->speed_raw);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGAbsEsp"; };
    const char * getMD5(){ return "d61659b5d5ec557b3801b72f598a234f"; };

  };

}
#endif