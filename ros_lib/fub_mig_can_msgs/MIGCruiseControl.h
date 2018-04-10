#ifndef _ROS_fub_mig_can_msgs_MIGCruiseControl_h
#define _ROS_fub_mig_can_msgs_MIGCruiseControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGCruiseControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _new_counter_type;
      _new_counter_type new_counter;
      typedef uint8_t _time_gap_type;
      _time_gap_type time_gap;
      typedef bool _main_switch_sign_type;
      _main_switch_sign_type main_switch_sign;
      typedef bool _cancel_type;
      _cancel_type cancel;
      typedef bool _down_short_type;
      _down_short_type down_short;
      typedef bool _down_long_type;
      _down_long_type down_long;
      typedef bool _up_short_type;
      _up_short_type up_short;
      typedef bool _up_long_type;
      _up_long_type up_long;
      typedef bool _tip_down_type;
      _tip_down_type tip_down;
      typedef bool _tip_up_type;
      _tip_up_type tip_up;
      typedef bool _reset_type;
      _reset_type reset;
      typedef bool _recall_type;
      _recall_type recall;
      typedef bool _type_type;
      _type_type type;
      enum { can_id =  906  };
      enum { can_dlc =    4  };

    MIGCruiseControl():
      header(),
      new_counter(0),
      time_gap(0),
      main_switch_sign(0),
      cancel(0),
      down_short(0),
      down_long(0),
      up_short(0),
      up_long(0),
      tip_down(0),
      tip_up(0),
      reset(0),
      recall(0),
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->new_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->new_counter);
      *(outbuffer + offset + 0) = (this->time_gap >> (8 * 0)) & 0xFF;
      offset += sizeof(this->time_gap);
      union {
        bool real;
        uint8_t base;
      } u_main_switch_sign;
      u_main_switch_sign.real = this->main_switch_sign;
      *(outbuffer + offset + 0) = (u_main_switch_sign.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->main_switch_sign);
      union {
        bool real;
        uint8_t base;
      } u_cancel;
      u_cancel.real = this->cancel;
      *(outbuffer + offset + 0) = (u_cancel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cancel);
      union {
        bool real;
        uint8_t base;
      } u_down_short;
      u_down_short.real = this->down_short;
      *(outbuffer + offset + 0) = (u_down_short.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->down_short);
      union {
        bool real;
        uint8_t base;
      } u_down_long;
      u_down_long.real = this->down_long;
      *(outbuffer + offset + 0) = (u_down_long.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->down_long);
      union {
        bool real;
        uint8_t base;
      } u_up_short;
      u_up_short.real = this->up_short;
      *(outbuffer + offset + 0) = (u_up_short.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->up_short);
      union {
        bool real;
        uint8_t base;
      } u_up_long;
      u_up_long.real = this->up_long;
      *(outbuffer + offset + 0) = (u_up_long.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->up_long);
      union {
        bool real;
        uint8_t base;
      } u_tip_down;
      u_tip_down.real = this->tip_down;
      *(outbuffer + offset + 0) = (u_tip_down.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tip_down);
      union {
        bool real;
        uint8_t base;
      } u_tip_up;
      u_tip_up.real = this->tip_up;
      *(outbuffer + offset + 0) = (u_tip_up.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tip_up);
      union {
        bool real;
        uint8_t base;
      } u_reset;
      u_reset.real = this->reset;
      *(outbuffer + offset + 0) = (u_reset.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset);
      union {
        bool real;
        uint8_t base;
      } u_recall;
      u_recall.real = this->recall;
      *(outbuffer + offset + 0) = (u_recall.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recall);
      union {
        bool real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->new_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->new_counter);
      this->time_gap =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->time_gap);
      union {
        bool real;
        uint8_t base;
      } u_main_switch_sign;
      u_main_switch_sign.base = 0;
      u_main_switch_sign.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->main_switch_sign = u_main_switch_sign.real;
      offset += sizeof(this->main_switch_sign);
      union {
        bool real;
        uint8_t base;
      } u_cancel;
      u_cancel.base = 0;
      u_cancel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cancel = u_cancel.real;
      offset += sizeof(this->cancel);
      union {
        bool real;
        uint8_t base;
      } u_down_short;
      u_down_short.base = 0;
      u_down_short.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->down_short = u_down_short.real;
      offset += sizeof(this->down_short);
      union {
        bool real;
        uint8_t base;
      } u_down_long;
      u_down_long.base = 0;
      u_down_long.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->down_long = u_down_long.real;
      offset += sizeof(this->down_long);
      union {
        bool real;
        uint8_t base;
      } u_up_short;
      u_up_short.base = 0;
      u_up_short.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->up_short = u_up_short.real;
      offset += sizeof(this->up_short);
      union {
        bool real;
        uint8_t base;
      } u_up_long;
      u_up_long.base = 0;
      u_up_long.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->up_long = u_up_long.real;
      offset += sizeof(this->up_long);
      union {
        bool real;
        uint8_t base;
      } u_tip_down;
      u_tip_down.base = 0;
      u_tip_down.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tip_down = u_tip_down.real;
      offset += sizeof(this->tip_down);
      union {
        bool real;
        uint8_t base;
      } u_tip_up;
      u_tip_up.base = 0;
      u_tip_up.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tip_up = u_tip_up.real;
      offset += sizeof(this->tip_up);
      union {
        bool real;
        uint8_t base;
      } u_reset;
      u_reset.base = 0;
      u_reset.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset = u_reset.real;
      offset += sizeof(this->reset);
      union {
        bool real;
        uint8_t base;
      } u_recall;
      u_recall.base = 0;
      u_recall.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recall = u_recall.real;
      offset += sizeof(this->recall);
      union {
        bool real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGCruiseControl"; };
    const char * getMD5(){ return "70278e9bbd19ef0b9de797613c3a36a1"; };

  };

}
#endif