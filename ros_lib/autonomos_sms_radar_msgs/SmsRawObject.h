#ifndef _ROS_autonomos_sms_radar_msgs_SmsRawObject_h
#define _ROS_autonomos_sms_radar_msgs_SmsRawObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_sms_radar_msgs
{

  class SmsRawObject : public ros::Msg
  {
    public:
      typedef bool _stationary_target_type;
      _stationary_target_type stationary_target;
      typedef bool _normal_target_type;
      _normal_target_type normal_target;
      typedef bool _no_local_maximum_all_dimensions_type;
      _no_local_maximum_all_dimensions_type no_local_maximum_all_dimensions;
      typedef bool _angle_resolved_type;
      _angle_resolved_type angle_resolved;
      typedef bool _multi_way_reflection_type;
      _multi_way_reflection_type multi_way_reflection;
      typedef float _amplitude_type;
      _amplitude_type amplitude;
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

    SmsRawObject():
      stationary_target(0),
      normal_target(0),
      no_local_maximum_all_dimensions(0),
      angle_resolved(0),
      multi_way_reflection(0),
      amplitude(0),
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
        bool real;
        uint8_t base;
      } u_stationary_target;
      u_stationary_target.real = this->stationary_target;
      *(outbuffer + offset + 0) = (u_stationary_target.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stationary_target);
      union {
        bool real;
        uint8_t base;
      } u_normal_target;
      u_normal_target.real = this->normal_target;
      *(outbuffer + offset + 0) = (u_normal_target.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->normal_target);
      union {
        bool real;
        uint8_t base;
      } u_no_local_maximum_all_dimensions;
      u_no_local_maximum_all_dimensions.real = this->no_local_maximum_all_dimensions;
      *(outbuffer + offset + 0) = (u_no_local_maximum_all_dimensions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_local_maximum_all_dimensions);
      union {
        bool real;
        uint8_t base;
      } u_angle_resolved;
      u_angle_resolved.real = this->angle_resolved;
      *(outbuffer + offset + 0) = (u_angle_resolved.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angle_resolved);
      union {
        bool real;
        uint8_t base;
      } u_multi_way_reflection;
      u_multi_way_reflection.real = this->multi_way_reflection;
      *(outbuffer + offset + 0) = (u_multi_way_reflection.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->multi_way_reflection);
      union {
        float real;
        uint32_t base;
      } u_amplitude;
      u_amplitude.real = this->amplitude;
      *(outbuffer + offset + 0) = (u_amplitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amplitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amplitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amplitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->amplitude);
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
        bool real;
        uint8_t base;
      } u_stationary_target;
      u_stationary_target.base = 0;
      u_stationary_target.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stationary_target = u_stationary_target.real;
      offset += sizeof(this->stationary_target);
      union {
        bool real;
        uint8_t base;
      } u_normal_target;
      u_normal_target.base = 0;
      u_normal_target.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->normal_target = u_normal_target.real;
      offset += sizeof(this->normal_target);
      union {
        bool real;
        uint8_t base;
      } u_no_local_maximum_all_dimensions;
      u_no_local_maximum_all_dimensions.base = 0;
      u_no_local_maximum_all_dimensions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->no_local_maximum_all_dimensions = u_no_local_maximum_all_dimensions.real;
      offset += sizeof(this->no_local_maximum_all_dimensions);
      union {
        bool real;
        uint8_t base;
      } u_angle_resolved;
      u_angle_resolved.base = 0;
      u_angle_resolved.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angle_resolved = u_angle_resolved.real;
      offset += sizeof(this->angle_resolved);
      union {
        bool real;
        uint8_t base;
      } u_multi_way_reflection;
      u_multi_way_reflection.base = 0;
      u_multi_way_reflection.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->multi_way_reflection = u_multi_way_reflection.real;
      offset += sizeof(this->multi_way_reflection);
      union {
        float real;
        uint32_t base;
      } u_amplitude;
      u_amplitude.base = 0;
      u_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_amplitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->amplitude = u_amplitude.real;
      offset += sizeof(this->amplitude);
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

    const char * getType(){ return "autonomos_sms_radar_msgs/SmsRawObject"; };
    const char * getMD5(){ return "1696d9604b5c2d44d1422711a38d4485"; };

  };

}
#endif