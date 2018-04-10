#ifndef _ROS_autonomos_vehicle_msgs_Signals_h
#define _ROS_autonomos_vehicle_msgs_Signals_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class Signals : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _turn_signal_left_type;
      _turn_signal_left_type turn_signal_left;
      typedef bool _turn_signal_left_light_status_type;
      _turn_signal_left_light_status_type turn_signal_left_light_status;
      typedef bool _turn_signal_right_type;
      _turn_signal_right_type turn_signal_right;
      typedef bool _turn_signal_right_light_status_type;
      _turn_signal_right_light_status_type turn_signal_right_light_status;
      typedef bool _hazard_warning_signal_type;
      _hazard_warning_signal_type hazard_warning_signal;
      typedef bool _hazard_warning_signal_light_status_type;
      _hazard_warning_signal_light_status_type hazard_warning_signal_light_status;
      typedef bool _headlight_flashing_type;
      _headlight_flashing_type headlight_flashing;

    Signals():
      header(),
      turn_signal_left(0),
      turn_signal_left_light_status(0),
      turn_signal_right(0),
      turn_signal_right_light_status(0),
      hazard_warning_signal(0),
      hazard_warning_signal_light_status(0),
      headlight_flashing(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_left;
      u_turn_signal_left.real = this->turn_signal_left;
      *(outbuffer + offset + 0) = (u_turn_signal_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal_left);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_left_light_status;
      u_turn_signal_left_light_status.real = this->turn_signal_left_light_status;
      *(outbuffer + offset + 0) = (u_turn_signal_left_light_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal_left_light_status);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_right;
      u_turn_signal_right.real = this->turn_signal_right;
      *(outbuffer + offset + 0) = (u_turn_signal_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal_right);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_right_light_status;
      u_turn_signal_right_light_status.real = this->turn_signal_right_light_status;
      *(outbuffer + offset + 0) = (u_turn_signal_right_light_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal_right_light_status);
      union {
        bool real;
        uint8_t base;
      } u_hazard_warning_signal;
      u_hazard_warning_signal.real = this->hazard_warning_signal;
      *(outbuffer + offset + 0) = (u_hazard_warning_signal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hazard_warning_signal);
      union {
        bool real;
        uint8_t base;
      } u_hazard_warning_signal_light_status;
      u_hazard_warning_signal_light_status.real = this->hazard_warning_signal_light_status;
      *(outbuffer + offset + 0) = (u_hazard_warning_signal_light_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hazard_warning_signal_light_status);
      union {
        bool real;
        uint8_t base;
      } u_headlight_flashing;
      u_headlight_flashing.real = this->headlight_flashing;
      *(outbuffer + offset + 0) = (u_headlight_flashing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlight_flashing);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_left;
      u_turn_signal_left.base = 0;
      u_turn_signal_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_signal_left = u_turn_signal_left.real;
      offset += sizeof(this->turn_signal_left);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_left_light_status;
      u_turn_signal_left_light_status.base = 0;
      u_turn_signal_left_light_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_signal_left_light_status = u_turn_signal_left_light_status.real;
      offset += sizeof(this->turn_signal_left_light_status);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_right;
      u_turn_signal_right.base = 0;
      u_turn_signal_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_signal_right = u_turn_signal_right.real;
      offset += sizeof(this->turn_signal_right);
      union {
        bool real;
        uint8_t base;
      } u_turn_signal_right_light_status;
      u_turn_signal_right_light_status.base = 0;
      u_turn_signal_right_light_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_signal_right_light_status = u_turn_signal_right_light_status.real;
      offset += sizeof(this->turn_signal_right_light_status);
      union {
        bool real;
        uint8_t base;
      } u_hazard_warning_signal;
      u_hazard_warning_signal.base = 0;
      u_hazard_warning_signal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hazard_warning_signal = u_hazard_warning_signal.real;
      offset += sizeof(this->hazard_warning_signal);
      union {
        bool real;
        uint8_t base;
      } u_hazard_warning_signal_light_status;
      u_hazard_warning_signal_light_status.base = 0;
      u_hazard_warning_signal_light_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hazard_warning_signal_light_status = u_hazard_warning_signal_light_status.real;
      offset += sizeof(this->hazard_warning_signal_light_status);
      union {
        bool real;
        uint8_t base;
      } u_headlight_flashing;
      u_headlight_flashing.base = 0;
      u_headlight_flashing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->headlight_flashing = u_headlight_flashing.real;
      offset += sizeof(this->headlight_flashing);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/Signals"; };
    const char * getMD5(){ return "4661f583f14a8a0167aeb67d633bb745"; };

  };

}
#endif