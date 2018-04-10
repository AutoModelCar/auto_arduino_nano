#ifndef _ROS_ibeo_sdk_object_msgs_Flags_h
#define _ROS_ibeo_sdk_object_msgs_Flags_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_object_msgs
{

  class Flags : public ros::Msg
  {
    public:
      enum { TRACKED_BY_STATIONARY_MODEL =  64 };
      enum { MOBILE =  128 };
      enum { VALIDATED =  256 };

    Flags()
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

    const char * getType(){ return "ibeo_sdk_object_msgs/Flags"; };
    const char * getMD5(){ return "6e6b520d942def07b619fddb175c10da"; };

  };

}
#endif