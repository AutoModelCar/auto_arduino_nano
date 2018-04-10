#ifndef _ROS_SERVICE_Unpause_h
#define _ROS_SERVICE_Unpause_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char UNPAUSE[] = "autonomos_player/Unpause";

  class UnpauseRequest : public ros::Msg
  {
    public:

    UnpauseRequest()
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

    const char * getType(){ return UNPAUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class UnpauseResponse : public ros::Msg
  {
    public:

    UnpauseResponse()
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

    const char * getType(){ return UNPAUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Unpause {
    public:
    typedef UnpauseRequest Request;
    typedef UnpauseResponse Response;
  };

}
#endif
