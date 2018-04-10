#ifndef _ROS_SERVICE_SetPlaybackSpeed_h
#define _ROS_SERVICE_SetPlaybackSpeed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char SETPLAYBACKSPEED[] = "autonomos_player/SetPlaybackSpeed";

  class SetPlaybackSpeedRequest : public ros::Msg
  {
    public:
      typedef float _factor_type;
      _factor_type factor;

    SetPlaybackSpeedRequest():
      factor(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_factor;
      u_factor.real = this->factor;
      *(outbuffer + offset + 0) = (u_factor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_factor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_factor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_factor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->factor);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_factor;
      u_factor.base = 0;
      u_factor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_factor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_factor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_factor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->factor = u_factor.real;
      offset += sizeof(this->factor);
     return offset;
    }

    const char * getType(){ return SETPLAYBACKSPEED; };
    const char * getMD5(){ return "8f47c590743a0fca57e45bd040e1469b"; };

  };

  class SetPlaybackSpeedResponse : public ros::Msg
  {
    public:

    SetPlaybackSpeedResponse()
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

    const char * getType(){ return SETPLAYBACKSPEED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPlaybackSpeed {
    public:
    typedef SetPlaybackSpeedRequest Request;
    typedef SetPlaybackSpeedResponse Response;
  };

}
#endif
