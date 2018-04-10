#ifndef _ROS_autonomos_sms_radar_msgs_SmsSensorControl_h
#define _ROS_autonomos_sms_radar_msgs_SmsSensorControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "ros/time.h"

namespace autonomos_sms_radar_msgs
{

  class SmsSensorControl : public ros::Msg
  {
    public:
      typedef uint8_t _sensor_status_type;
      _sensor_status_type sensor_status;
      typedef uint8_t _sensor_mode_signal_type;
      _sensor_mode_signal_type sensor_mode_signal;
      typedef uint8_t _sensor_mode_type;
      _sensor_mode_type sensor_mode;
      typedef uint8_t _sensor_sub_mode_type;
      _sensor_sub_mode_type sensor_sub_mode;
      typedef ros::Duration _cycle_duration_type;
      _cycle_duration_type cycle_duration;
      typedef uint8_t _sensor_id_type;
      _sensor_id_type sensor_id;
      typedef uint8_t _number_of_objects_type;
      _number_of_objects_type number_of_objects;
      typedef ros::Time _time_stamp_type;
      _time_stamp_type time_stamp;
      enum { SENSOR_MODE_FSK3FM =  13   };
      enum { SENSOR_MODE_PLL =  6       };

    SmsSensorControl():
      sensor_status(0),
      sensor_mode_signal(0),
      sensor_mode(0),
      sensor_sub_mode(0),
      cycle_duration(),
      sensor_id(0),
      number_of_objects(0),
      time_stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sensor_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_status);
      *(outbuffer + offset + 0) = (this->sensor_mode_signal >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_mode_signal);
      *(outbuffer + offset + 0) = (this->sensor_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_mode);
      *(outbuffer + offset + 0) = (this->sensor_sub_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_sub_mode);
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
      *(outbuffer + offset + 0) = (this->sensor_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_id);
      *(outbuffer + offset + 0) = (this->number_of_objects >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_objects);
      *(outbuffer + offset + 0) = (this->time_stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_stamp.sec);
      *(outbuffer + offset + 0) = (this->time_stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_stamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->sensor_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_status);
      this->sensor_mode_signal =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_mode_signal);
      this->sensor_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_mode);
      this->sensor_sub_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_sub_mode);
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
      this->sensor_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_id);
      this->number_of_objects =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number_of_objects);
      this->time_stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_stamp.sec);
      this->time_stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_stamp.nsec);
     return offset;
    }

    const char * getType(){ return "autonomos_sms_radar_msgs/SmsSensorControl"; };
    const char * getMD5(){ return "572482a2b5fca34ad4d50072bc71035b"; };

  };

}
#endif