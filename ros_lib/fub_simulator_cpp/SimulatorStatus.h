#ifndef _ROS_fub_simulator_cpp_SimulatorStatus_h
#define _ROS_fub_simulator_cpp_SimulatorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace fub_simulator_cpp
{

  class SimulatorStatus : public ros::Msg
  {
    public:
      typedef bool _is_running_type;
      _is_running_type is_running;
      typedef ros::Duration _current_loop_duration_type;
      _current_loop_duration_type current_loop_duration;
      typedef ros::Duration _max_loop_duration_type;
      _max_loop_duration_type max_loop_duration;
      typedef bool _is_loop_enabled_type;
      _is_loop_enabled_type is_loop_enabled;

    SimulatorStatus():
      is_running(0),
      current_loop_duration(),
      max_loop_duration(),
      is_loop_enabled(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_running;
      u_is_running.real = this->is_running;
      *(outbuffer + offset + 0) = (u_is_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_running);
      *(outbuffer + offset + 0) = (this->current_loop_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_loop_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_loop_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_loop_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_loop_duration.sec);
      *(outbuffer + offset + 0) = (this->current_loop_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_loop_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_loop_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_loop_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_loop_duration.nsec);
      *(outbuffer + offset + 0) = (this->max_loop_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_loop_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_loop_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_loop_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_loop_duration.sec);
      *(outbuffer + offset + 0) = (this->max_loop_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_loop_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_loop_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_loop_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_loop_duration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_is_loop_enabled;
      u_is_loop_enabled.real = this->is_loop_enabled;
      *(outbuffer + offset + 0) = (u_is_loop_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_loop_enabled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_running;
      u_is_running.base = 0;
      u_is_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_running = u_is_running.real;
      offset += sizeof(this->is_running);
      this->current_loop_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->current_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_loop_duration.sec);
      this->current_loop_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->current_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_loop_duration.nsec);
      this->max_loop_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_loop_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_loop_duration.sec);
      this->max_loop_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_loop_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_loop_duration.nsec);
      union {
        bool real;
        uint8_t base;
      } u_is_loop_enabled;
      u_is_loop_enabled.base = 0;
      u_is_loop_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_loop_enabled = u_is_loop_enabled.real;
      offset += sizeof(this->is_loop_enabled);
     return offset;
    }

    const char * getType(){ return "fub_simulator_cpp/SimulatorStatus"; };
    const char * getMD5(){ return "50ce5742d4772b0b87e3a6d1440c3020"; };

  };

}
#endif