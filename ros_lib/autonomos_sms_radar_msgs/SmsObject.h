#ifndef _ROS_autonomos_sms_radar_msgs_SmsObject_h
#define _ROS_autonomos_sms_radar_msgs_SmsObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_sms_radar_msgs
{

  class SmsObject : public ros::Msg
  {
    public:
      typedef float _level_type;
      _level_type level;
      typedef uint8_t _type_type;
      _type_type type;
      typedef float _signal_noise_ratio_type;
      _signal_noise_ratio_type signal_noise_ratio;
      typedef float _radial_velocity_type;
      _radial_velocity_type radial_velocity;
      typedef float _angle_type;
      _angle_type angle;
      typedef float _angle_raw_type;
      _angle_raw_type angle_raw;
      typedef float _range_type;
      _range_type range;
      typedef uint8_t _object_id_type;
      _object_id_type object_id;
      enum { TYPE_BLIND_SPOT_TARGET =  0                          };
      enum { TYPE_PRESENCE_DETECTION =  1                         };
      enum { TYPE_ACKNOWLEDGED_TARGET =  2                        };
      enum { TYPE_UNACKNOWLEDGED_PARTNER_IN_FREQUENCY_GAP =  4    };
      enum { TYPE_UNACKNOWLEDGED_TARGET_IN_FREQUENCY_GAP =  5     };
      enum { TYPE_ACKNOWLEDGED_TARGET_NEGATIVE_RANGE =  7         };
      enum { TYPE_UNACKNOWLEDGED_TARGET =  8                      };
      enum { TYPE_GUARD_RAIL_POSITIVE_Y_POSITION =  10            };
      enum { TYPE_GUARD_RAIL_NEGATIVE_Y_POSITION =  11            };
      enum { TYPE_ACKNOWLEDGED_TARGET_CLUSTER_GAP =  12           };
      enum { TYPE_ACKNOWLEDGED_TARGET_HIGH_ACCELERATION =  14     };

    SmsObject():
      level(0),
      type(0),
      signal_noise_ratio(0),
      radial_velocity(0),
      angle(0),
      angle_raw(0),
      range(0),
      object_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_level;
      u_level.real = this->level;
      *(outbuffer + offset + 0) = (u_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->level);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_signal_noise_ratio;
      u_signal_noise_ratio.real = this->signal_noise_ratio;
      *(outbuffer + offset + 0) = (u_signal_noise_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signal_noise_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signal_noise_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signal_noise_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal_noise_ratio);
      union {
        float real;
        uint32_t base;
      } u_radial_velocity;
      u_radial_velocity.real = this->radial_velocity;
      *(outbuffer + offset + 0) = (u_radial_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radial_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radial_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radial_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radial_velocity);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_angle_raw;
      u_angle_raw.real = this->angle_raw;
      *(outbuffer + offset + 0) = (u_angle_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_raw);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_level;
      u_level.base = 0;
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->level = u_level.real;
      offset += sizeof(this->level);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_signal_noise_ratio;
      u_signal_noise_ratio.base = 0;
      u_signal_noise_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signal_noise_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signal_noise_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signal_noise_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signal_noise_ratio = u_signal_noise_ratio.real;
      offset += sizeof(this->signal_noise_ratio);
      union {
        float real;
        uint32_t base;
      } u_radial_velocity;
      u_radial_velocity.base = 0;
      u_radial_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radial_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radial_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radial_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radial_velocity = u_radial_velocity.real;
      offset += sizeof(this->radial_velocity);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_angle_raw;
      u_angle_raw.base = 0;
      u_angle_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_raw = u_angle_raw.real;
      offset += sizeof(this->angle_raw);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
      this->object_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_id);
     return offset;
    }

    const char * getType(){ return "autonomos_sms_radar_msgs/SmsObject"; };
    const char * getMD5(){ return "40bcdaa2deab7218fa3f258314d0fe2b"; };

  };

}
#endif