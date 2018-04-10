#ifndef _ROS_fub_mig_can_msgs_MIGSignalAndWipersStatus_h
#define _ROS_fub_mig_can_msgs_MIGSignalAndWipersStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGSignalAndWipersStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _turn_signal_left_type;
      _turn_signal_left_type turn_signal_left;
      typedef bool _turn_signal_right_type;
      _turn_signal_right_type turn_signal_right;
      typedef bool _flash_light_type;
      _flash_light_type flash_light;
      typedef bool _high_beam_type;
      _high_beam_type high_beam;
      typedef bool _horn_type;
      _horn_type horn;
      typedef bool _wipe_tip_type;
      _wipe_tip_type wipe_tip;
      typedef bool _wipe_interval_type;
      _wipe_interval_type wipe_interval;
      typedef bool _wipe_level_1_type;
      _wipe_level_1_type wipe_level_1;
      typedef bool _wipe_level_2_type;
      _wipe_level_2_type wipe_level_2;
      typedef bool _wash_front_type;
      _wash_front_type wash_front;
      typedef bool _wash_front_moving_type;
      _wash_front_moving_type wash_front_moving;
      typedef bool _wipe_rear_interval_type;
      _wipe_rear_interval_type wipe_rear_interval;
      typedef bool _wash_rear_type;
      _wash_rear_type wash_rear;
      typedef uint8_t _interval_level_type;
      _interval_level_type interval_level;
      enum { can_id =  705  };
      enum { can_dlc =    6 };

    MIGSignalAndWipersStatus():
      header(),
      turn_signal_left(0),
      turn_signal_right(0),
      flash_light(0),
      high_beam(0),
      horn(0),
      wipe_tip(0),
      wipe_interval(0),
      wipe_level_1(0),
      wipe_level_2(0),
      wash_front(0),
      wash_front_moving(0),
      wipe_rear_interval(0),
      wash_rear(0),
      interval_level(0)
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
      } u_turn_signal_right;
      u_turn_signal_right.real = this->turn_signal_right;
      *(outbuffer + offset + 0) = (u_turn_signal_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_signal_right);
      union {
        bool real;
        uint8_t base;
      } u_flash_light;
      u_flash_light.real = this->flash_light;
      *(outbuffer + offset + 0) = (u_flash_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flash_light);
      union {
        bool real;
        uint8_t base;
      } u_high_beam;
      u_high_beam.real = this->high_beam;
      *(outbuffer + offset + 0) = (u_high_beam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_beam);
      union {
        bool real;
        uint8_t base;
      } u_horn;
      u_horn.real = this->horn;
      *(outbuffer + offset + 0) = (u_horn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->horn);
      union {
        bool real;
        uint8_t base;
      } u_wipe_tip;
      u_wipe_tip.real = this->wipe_tip;
      *(outbuffer + offset + 0) = (u_wipe_tip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipe_tip);
      union {
        bool real;
        uint8_t base;
      } u_wipe_interval;
      u_wipe_interval.real = this->wipe_interval;
      *(outbuffer + offset + 0) = (u_wipe_interval.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipe_interval);
      union {
        bool real;
        uint8_t base;
      } u_wipe_level_1;
      u_wipe_level_1.real = this->wipe_level_1;
      *(outbuffer + offset + 0) = (u_wipe_level_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipe_level_1);
      union {
        bool real;
        uint8_t base;
      } u_wipe_level_2;
      u_wipe_level_2.real = this->wipe_level_2;
      *(outbuffer + offset + 0) = (u_wipe_level_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipe_level_2);
      union {
        bool real;
        uint8_t base;
      } u_wash_front;
      u_wash_front.real = this->wash_front;
      *(outbuffer + offset + 0) = (u_wash_front.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wash_front);
      union {
        bool real;
        uint8_t base;
      } u_wash_front_moving;
      u_wash_front_moving.real = this->wash_front_moving;
      *(outbuffer + offset + 0) = (u_wash_front_moving.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wash_front_moving);
      union {
        bool real;
        uint8_t base;
      } u_wipe_rear_interval;
      u_wipe_rear_interval.real = this->wipe_rear_interval;
      *(outbuffer + offset + 0) = (u_wipe_rear_interval.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wipe_rear_interval);
      union {
        bool real;
        uint8_t base;
      } u_wash_rear;
      u_wash_rear.real = this->wash_rear;
      *(outbuffer + offset + 0) = (u_wash_rear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wash_rear);
      *(outbuffer + offset + 0) = (this->interval_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interval_level);
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
      } u_turn_signal_right;
      u_turn_signal_right.base = 0;
      u_turn_signal_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_signal_right = u_turn_signal_right.real;
      offset += sizeof(this->turn_signal_right);
      union {
        bool real;
        uint8_t base;
      } u_flash_light;
      u_flash_light.base = 0;
      u_flash_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flash_light = u_flash_light.real;
      offset += sizeof(this->flash_light);
      union {
        bool real;
        uint8_t base;
      } u_high_beam;
      u_high_beam.base = 0;
      u_high_beam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->high_beam = u_high_beam.real;
      offset += sizeof(this->high_beam);
      union {
        bool real;
        uint8_t base;
      } u_horn;
      u_horn.base = 0;
      u_horn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->horn = u_horn.real;
      offset += sizeof(this->horn);
      union {
        bool real;
        uint8_t base;
      } u_wipe_tip;
      u_wipe_tip.base = 0;
      u_wipe_tip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipe_tip = u_wipe_tip.real;
      offset += sizeof(this->wipe_tip);
      union {
        bool real;
        uint8_t base;
      } u_wipe_interval;
      u_wipe_interval.base = 0;
      u_wipe_interval.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipe_interval = u_wipe_interval.real;
      offset += sizeof(this->wipe_interval);
      union {
        bool real;
        uint8_t base;
      } u_wipe_level_1;
      u_wipe_level_1.base = 0;
      u_wipe_level_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipe_level_1 = u_wipe_level_1.real;
      offset += sizeof(this->wipe_level_1);
      union {
        bool real;
        uint8_t base;
      } u_wipe_level_2;
      u_wipe_level_2.base = 0;
      u_wipe_level_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipe_level_2 = u_wipe_level_2.real;
      offset += sizeof(this->wipe_level_2);
      union {
        bool real;
        uint8_t base;
      } u_wash_front;
      u_wash_front.base = 0;
      u_wash_front.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wash_front = u_wash_front.real;
      offset += sizeof(this->wash_front);
      union {
        bool real;
        uint8_t base;
      } u_wash_front_moving;
      u_wash_front_moving.base = 0;
      u_wash_front_moving.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wash_front_moving = u_wash_front_moving.real;
      offset += sizeof(this->wash_front_moving);
      union {
        bool real;
        uint8_t base;
      } u_wipe_rear_interval;
      u_wipe_rear_interval.base = 0;
      u_wipe_rear_interval.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wipe_rear_interval = u_wipe_rear_interval.real;
      offset += sizeof(this->wipe_rear_interval);
      union {
        bool real;
        uint8_t base;
      } u_wash_rear;
      u_wash_rear.base = 0;
      u_wash_rear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wash_rear = u_wash_rear.real;
      offset += sizeof(this->wash_rear);
      this->interval_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interval_level);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGSignalAndWipersStatus"; };
    const char * getMD5(){ return "0ecb41a1a3eeff65bf03962d85a82101"; };

  };

}
#endif