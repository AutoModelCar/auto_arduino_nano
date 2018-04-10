#ifndef _ROS_fub_mig_can_msgs_MIGAccelerationAndTeeth_h
#define _ROS_fub_mig_can_msgs_MIGAccelerationAndTeeth_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGAccelerationAndTeeth : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef bool _mux_type;
      _mux_type mux;
      typedef uint8_t _number_of_teeth_type;
      _number_of_teeth_type number_of_teeth;
      typedef float _lateral_acceleration_type;
      _lateral_acceleration_type lateral_acceleration;
      typedef uint8_t _lateral_acceleration_raw_type;
      _lateral_acceleration_raw_type lateral_acceleration_raw;
      typedef bool _lateral_acceleration_valid_type;
      _lateral_acceleration_valid_type lateral_acceleration_valid;
      enum { can_id =  1440  };
      enum { can_dlc =     8  };

    MIGAccelerationAndTeeth():
      header(),
      message_counter(0),
      mux(0),
      number_of_teeth(0),
      lateral_acceleration(0),
      lateral_acceleration_raw(0),
      lateral_acceleration_valid(0)
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
      } u_mux;
      u_mux.real = this->mux;
      *(outbuffer + offset + 0) = (u_mux.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mux);
      *(outbuffer + offset + 0) = (this->number_of_teeth >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_teeth);
      union {
        float real;
        uint32_t base;
      } u_lateral_acceleration;
      u_lateral_acceleration.real = this->lateral_acceleration;
      *(outbuffer + offset + 0) = (u_lateral_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lateral_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lateral_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lateral_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lateral_acceleration);
      *(outbuffer + offset + 0) = (this->lateral_acceleration_raw >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lateral_acceleration_raw);
      union {
        bool real;
        uint8_t base;
      } u_lateral_acceleration_valid;
      u_lateral_acceleration_valid.real = this->lateral_acceleration_valid;
      *(outbuffer + offset + 0) = (u_lateral_acceleration_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lateral_acceleration_valid);
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
      } u_mux;
      u_mux.base = 0;
      u_mux.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mux = u_mux.real;
      offset += sizeof(this->mux);
      this->number_of_teeth =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number_of_teeth);
      union {
        float real;
        uint32_t base;
      } u_lateral_acceleration;
      u_lateral_acceleration.base = 0;
      u_lateral_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lateral_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lateral_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lateral_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lateral_acceleration = u_lateral_acceleration.real;
      offset += sizeof(this->lateral_acceleration);
      this->lateral_acceleration_raw =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lateral_acceleration_raw);
      union {
        bool real;
        uint8_t base;
      } u_lateral_acceleration_valid;
      u_lateral_acceleration_valid.base = 0;
      u_lateral_acceleration_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lateral_acceleration_valid = u_lateral_acceleration_valid.real;
      offset += sizeof(this->lateral_acceleration_valid);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGAccelerationAndTeeth"; };
    const char * getMD5(){ return "3c5f2d5823fddd184207bbb0ff56bfa0"; };

  };

}
#endif