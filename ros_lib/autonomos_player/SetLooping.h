#ifndef _ROS_SERVICE_SetLooping_h
#define _ROS_SERVICE_SetLooping_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char SETLOOPING[] = "autonomos_player/SetLooping";

  class SetLoopingRequest : public ros::Msg
  {
    public:
      typedef bool _looping_type;
      _looping_type looping;

    SetLoopingRequest():
      looping(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_looping;
      u_looping.real = this->looping;
      *(outbuffer + offset + 0) = (u_looping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->looping);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_looping;
      u_looping.base = 0;
      u_looping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->looping = u_looping.real;
      offset += sizeof(this->looping);
     return offset;
    }

    const char * getType(){ return SETLOOPING; };
    const char * getMD5(){ return "c0daff69a7930d69d1c476ab106939d6"; };

  };

  class SetLoopingResponse : public ros::Msg
  {
    public:

    SetLoopingResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETLOOPING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetLooping {
    public:
    typedef SetLoopingRequest Request;
    typedef SetLoopingResponse Response;
  };

}
#endif
