#ifndef _ROS_SERVICE_Step_h
#define _ROS_SERVICE_Step_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char STEP[] = "autonomos_player/Step";

  class StepRequest : public ros::Msg
  {
    public:

    StepRequest()
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

    const char * getType(){ return STEP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StepResponse : public ros::Msg
  {
    public:

    StepResponse()
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

    const char * getType(){ return STEP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Step {
    public:
    typedef StepRequest Request;
    typedef StepResponse Response;
  };

}
#endif
