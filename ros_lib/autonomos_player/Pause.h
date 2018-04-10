#ifndef _ROS_SERVICE_Pause_h
#define _ROS_SERVICE_Pause_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char PAUSE[] = "autonomos_player/Pause";

  class PauseRequest : public ros::Msg
  {
    public:

    PauseRequest()
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

    const char * getType(){ return PAUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PauseResponse : public ros::Msg
  {
    public:

    PauseResponse()
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

    const char * getType(){ return PAUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Pause {
    public:
    typedef PauseRequest Request;
    typedef PauseResponse Response;
  };

}
#endif
