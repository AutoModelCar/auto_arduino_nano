#ifndef _ROS_autonomos_vehicle_msgs_MovementState_h
#define _ROS_autonomos_vehicle_msgs_MovementState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class MovementState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _state_type;
      _state_type state;
      enum { MOVEMENT_STATE_UNKNOWN =  -9999 };
      enum { MOVEMENT_STATE_REVERSE =  -1 };
      enum { MOVEMENT_STATE_STANDING =  0 };
      enum { MOVEMENT_STATE_FORWARD =  1 };

    MovementState():
      header(),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/MovementState"; };
    const char * getMD5(){ return "227b20d662386994990a5e60f7da2ecd"; };

  };

}
#endif