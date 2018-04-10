#ifndef _ROS_autonomos_sms_radar_msgs_SmsSensorControlRaw_h
#define _ROS_autonomos_sms_radar_msgs_SmsSensorControlRaw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace autonomos_sms_radar_msgs
{

  class SmsSensorControlRaw : public ros::Msg
  {
    public:
      typedef ros::Duration _cycle_duration_type;
      _cycle_duration_type cycle_duration;
      typedef bool _sensor_state_sensor_error_type;
      _sensor_state_sensor_error_type sensor_state_sensor_error;
      typedef bool _sensor_state_sync_error_type;
      _sensor_state_sync_error_type sensor_state_sync_error;
      typedef bool _sensor_state_sit_dynamic_type;
      _sensor_state_sit_dynamic_type sensor_state_sit_dynamic;
      typedef bool _sensor_state_application_mode_type;
      _sensor_state_application_mode_type sensor_state_application_mode;
      typedef float _sensor_noise_level_type;
      _sensor_noise_level_type sensor_noise_level;
      typedef uint8_t _sensor_mode_type;
      _sensor_mode_type sensor_mode;
      typedef uint8_t _sensor_sub_mode_type;
      _sensor_sub_mode_type sensor_sub_mode;
      typedef uint8_t _sensor_data_frame0_type;
      _sensor_data_frame0_type sensor_data_frame0;
      typedef uint8_t _sensor_data_frame1_type;
      _sensor_data_frame1_type sensor_data_frame1;
      typedef uint8_t _sensor_id_type;
      _sensor_id_type sensor_id;
      typedef uint8_t _number_of_objects_type;
      _number_of_objects_type number_of_objects;

    SmsSensorControlRaw():
      cycle_duration(),
      sensor_state_sensor_error(0),
      sensor_state_sync_error(0),
      sensor_state_sit_dynamic(0),
      sensor_state_application_mode(0),
      sensor_noise_level(0),
      sensor_mode(0),
      sensor_sub_mode(0),
      sensor_data_frame0(0),
      sensor_data_frame1(0),
      sensor_id(0),
      number_of_objects(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cycle_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cycle_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cycle_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cycle_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cycle_duration.sec);
      *(outbuffer + offset + 0) = (this->cycle_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cycle_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cycle_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cycle_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cycle_duration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sensor_error;
      u_sensor_state_sensor_error.real = this->sensor_state_sensor_error;
      *(outbuffer + offset + 0) = (u_sensor_state_sensor_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_state_sensor_error);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sync_error;
      u_sensor_state_sync_error.real = this->sensor_state_sync_error;
      *(outbuffer + offset + 0) = (u_sensor_state_sync_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_state_sync_error);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sit_dynamic;
      u_sensor_state_sit_dynamic.real = this->sensor_state_sit_dynamic;
      *(outbuffer + offset + 0) = (u_sensor_state_sit_dynamic.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_state_sit_dynamic);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_application_mode;
      u_sensor_state_application_mode.real = this->sensor_state_application_mode;
      *(outbuffer + offset + 0) = (u_sensor_state_application_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_state_application_mode);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_noise_level);
      *(outbuffer + offset + 0) = (this->sensor_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_mode);
      *(outbuffer + offset + 0) = (this->sensor_sub_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_sub_mode);
      *(outbuffer + offset + 0) = (this->sensor_data_frame0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_data_frame0);
      *(outbuffer + offset + 0) = (this->sensor_data_frame1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_data_frame1);
      *(outbuffer + offset + 0) = (this->sensor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_id);
      *(outbuffer + offset + 0) = (this->number_of_objects >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_objects);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->cycle_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->cycle_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cycle_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cycle_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cycle_duration.sec);
      this->cycle_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->cycle_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cycle_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cycle_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cycle_duration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sensor_error;
      u_sensor_state_sensor_error.base = 0;
      u_sensor_state_sensor_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_state_sensor_error = u_sensor_state_sensor_error.real;
      offset += sizeof(this->sensor_state_sensor_error);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sync_error;
      u_sensor_state_sync_error.base = 0;
      u_sensor_state_sync_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_state_sync_error = u_sensor_state_sync_error.real;
      offset += sizeof(this->sensor_state_sync_error);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_sit_dynamic;
      u_sensor_state_sit_dynamic.base = 0;
      u_sensor_state_sit_dynamic.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_state_sit_dynamic = u_sensor_state_sit_dynamic.real;
      offset += sizeof(this->sensor_state_sit_dynamic);
      union {
        bool real;
        uint8_t base;
      } u_sensor_state_application_mode;
      u_sensor_state_application_mode.base = 0;
      u_sensor_state_application_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_state_application_mode = u_sensor_state_application_mode.real;
      offset += sizeof(this->sensor_state_application_mode);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_noise_level));
      this->sensor_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_mode);
      this->sensor_sub_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_sub_mode);
      this->sensor_data_frame0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_data_frame0);
      this->sensor_data_frame1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_data_frame1);
      this->sensor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_id);
      this->number_of_objects =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number_of_objects);
     return offset;
    }

    const char * getType(){ return "autonomos_sms_radar_msgs/SmsSensorControlRaw"; };
    const char * getMD5(){ return "723058c49aeb66eae65fee60f9846a3b"; };

  };

}
#endif