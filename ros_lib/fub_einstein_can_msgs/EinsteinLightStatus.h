#ifndef _ROS_fub_einstein_can_msgs_EinsteinLightStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinLightStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinLightStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _turn_indicator_left_type;
      _turn_indicator_left_type turn_indicator_left;
      typedef bool _turn_indicator_right_type;
      _turn_indicator_right_type turn_indicator_right;
      typedef bool _warning_lights_type;
      _warning_lights_type warning_lights;
      typedef bool _parking_light_type;
      _parking_light_type parking_light;
      typedef bool _low_beam_type;
      _low_beam_type low_beam;
      typedef bool _full_beam_type;
      _full_beam_type full_beam;
      typedef bool _fog_light_type;
      _fog_light_type fog_light;
      typedef bool _rear_fog_light_type;
      _rear_fog_light_type rear_fog_light;
      typedef bool _wiper_front_interval_type;
      _wiper_front_interval_type wiper_front_interval;
      typedef bool _wiper_front_type;
      _wiper_front_type wiper_front;
      typedef bool _wiper_rear_interval_type;
      _wiper_rear_interval_type wiper_rear_interval;
      typedef bool _wiper_rear_type;
      _wiper_rear_type wiper_rear;
      typedef bool _driver_door_open_type;
      _driver_door_open_type driver_door_open;
      typedef bool _other_door_open_type;
      _other_door_open_type other_door_open;
      enum { can_id =  1060  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinLightStatus():
      header(),
      message_counter(0),
      turn_indicator_left(0),
      turn_indicator_right(0),
      warning_lights(0),
      parking_light(0),
      low_beam(0),
      full_beam(0),
      fog_light(0),
      rear_fog_light(0),
      wiper_front_interval(0),
      wiper_front(0),
      wiper_rear_interval(0),
      wiper_rear(0),
      driver_door_open(0),
      other_door_open(0)
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
      } u_turn_indicator_left;
      u_turn_indicator_left.real = this->turn_indicator_left;
      *(outbuffer + offset + 0) = (u_turn_indicator_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_indicator_left);
      union {
        bool real;
        uint8_t base;
      } u_turn_indicator_right;
      u_turn_indicator_right.real = this->turn_indicator_right;
      *(outbuffer + offset + 0) = (u_turn_indicator_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_indicator_right);
      union {
        bool real;
        uint8_t base;
      } u_warning_lights;
      u_warning_lights.real = this->warning_lights;
      *(outbuffer + offset + 0) = (u_warning_lights.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->warning_lights);
      union {
        bool real;
        uint8_t base;
      } u_parking_light;
      u_parking_light.real = this->parking_light;
      *(outbuffer + offset + 0) = (u_parking_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_light);
      union {
        bool real;
        uint8_t base;
      } u_low_beam;
      u_low_beam.real = this->low_beam;
      *(outbuffer + offset + 0) = (u_low_beam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_beam);
      union {
        bool real;
        uint8_t base;
      } u_full_beam;
      u_full_beam.real = this->full_beam;
      *(outbuffer + offset + 0) = (u_full_beam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->full_beam);
      union {
        bool real;
        uint8_t base;
      } u_fog_light;
      u_fog_light.real = this->fog_light;
      *(outbuffer + offset + 0) = (u_fog_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fog_light);
      union {
        bool real;
        uint8_t base;
      } u_rear_fog_light;
      u_rear_fog_light.real = this->rear_fog_light;
      *(outbuffer + offset + 0) = (u_rear_fog_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_fog_light);
      union {
        bool real;
        uint8_t base;
      } u_wiper_front_interval;
      u_wiper_front_interval.real = this->wiper_front_interval;
      *(outbuffer + offset + 0) = (u_wiper_front_interval.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wiper_front_interval);
      union {
        bool real;
        uint8_t base;
      } u_wiper_front;
      u_wiper_front.real = this->wiper_front;
      *(outbuffer + offset + 0) = (u_wiper_front.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wiper_front);
      union {
        bool real;
        uint8_t base;
      } u_wiper_rear_interval;
      u_wiper_rear_interval.real = this->wiper_rear_interval;
      *(outbuffer + offset + 0) = (u_wiper_rear_interval.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wiper_rear_interval);
      union {
        bool real;
        uint8_t base;
      } u_wiper_rear;
      u_wiper_rear.real = this->wiper_rear;
      *(outbuffer + offset + 0) = (u_wiper_rear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wiper_rear);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open;
      u_driver_door_open.real = this->driver_door_open;
      *(outbuffer + offset + 0) = (u_driver_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_other_door_open;
      u_other_door_open.real = this->other_door_open;
      *(outbuffer + offset + 0) = (u_other_door_open.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->other_door_open);
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
      } u_turn_indicator_left;
      u_turn_indicator_left.base = 0;
      u_turn_indicator_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_indicator_left = u_turn_indicator_left.real;
      offset += sizeof(this->turn_indicator_left);
      union {
        bool real;
        uint8_t base;
      } u_turn_indicator_right;
      u_turn_indicator_right.base = 0;
      u_turn_indicator_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn_indicator_right = u_turn_indicator_right.real;
      offset += sizeof(this->turn_indicator_right);
      union {
        bool real;
        uint8_t base;
      } u_warning_lights;
      u_warning_lights.base = 0;
      u_warning_lights.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->warning_lights = u_warning_lights.real;
      offset += sizeof(this->warning_lights);
      union {
        bool real;
        uint8_t base;
      } u_parking_light;
      u_parking_light.base = 0;
      u_parking_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_light = u_parking_light.real;
      offset += sizeof(this->parking_light);
      union {
        bool real;
        uint8_t base;
      } u_low_beam;
      u_low_beam.base = 0;
      u_low_beam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_beam = u_low_beam.real;
      offset += sizeof(this->low_beam);
      union {
        bool real;
        uint8_t base;
      } u_full_beam;
      u_full_beam.base = 0;
      u_full_beam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->full_beam = u_full_beam.real;
      offset += sizeof(this->full_beam);
      union {
        bool real;
        uint8_t base;
      } u_fog_light;
      u_fog_light.base = 0;
      u_fog_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fog_light = u_fog_light.real;
      offset += sizeof(this->fog_light);
      union {
        bool real;
        uint8_t base;
      } u_rear_fog_light;
      u_rear_fog_light.base = 0;
      u_rear_fog_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_fog_light = u_rear_fog_light.real;
      offset += sizeof(this->rear_fog_light);
      union {
        bool real;
        uint8_t base;
      } u_wiper_front_interval;
      u_wiper_front_interval.base = 0;
      u_wiper_front_interval.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wiper_front_interval = u_wiper_front_interval.real;
      offset += sizeof(this->wiper_front_interval);
      union {
        bool real;
        uint8_t base;
      } u_wiper_front;
      u_wiper_front.base = 0;
      u_wiper_front.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wiper_front = u_wiper_front.real;
      offset += sizeof(this->wiper_front);
      union {
        bool real;
        uint8_t base;
      } u_wiper_rear_interval;
      u_wiper_rear_interval.base = 0;
      u_wiper_rear_interval.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wiper_rear_interval = u_wiper_rear_interval.real;
      offset += sizeof(this->wiper_rear_interval);
      union {
        bool real;
        uint8_t base;
      } u_wiper_rear;
      u_wiper_rear.base = 0;
      u_wiper_rear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wiper_rear = u_wiper_rear.real;
      offset += sizeof(this->wiper_rear);
      union {
        bool real;
        uint8_t base;
      } u_driver_door_open;
      u_driver_door_open.base = 0;
      u_driver_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driver_door_open = u_driver_door_open.real;
      offset += sizeof(this->driver_door_open);
      union {
        bool real;
        uint8_t base;
      } u_other_door_open;
      u_other_door_open.base = 0;
      u_other_door_open.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->other_door_open = u_other_door_open.real;
      offset += sizeof(this->other_door_open);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinLightStatus"; };
    const char * getMD5(){ return "08a4be0d6143aafd3df3a8143902dd67"; };

  };

}
#endif