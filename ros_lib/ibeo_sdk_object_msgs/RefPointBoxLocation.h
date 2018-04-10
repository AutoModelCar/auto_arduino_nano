#ifndef _ROS_ibeo_sdk_object_msgs_RefPointBoxLocation_h
#define _ROS_ibeo_sdk_object_msgs_RefPointBoxLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_object_msgs
{

  class RefPointBoxLocation : public ros::Msg
  {
    public:
      typedef uint32_t _location_type;
      _location_type location;
      enum { CENTER_OF_GRAVITY =  0 };
      enum { FRONT_LEFT =  1 };
      enum { FRONT_RIGHT =  2 };
      enum { REAR_RIGHT =  3 };
      enum { REAR_LEFT =  4 };
      enum { FRONT_CENTER =  5 };
      enum { RIGHT_CENTER =  6 };
      enum { REAR_CENTER =  7 };
      enum { LEFT_CENTER =  8 };
      enum { OBJECT_CENTER =  9 };
      enum { UNKNOWN =  255 };

    RefPointBoxLocation():
      location(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->location >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->location >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->location >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->location >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->location =  ((uint32_t) (*(inbuffer + offset)));
      this->location |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->location |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->location |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->location);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_msgs/RefPointBoxLocation"; };
    const char * getMD5(){ return "6e2e27a21c06d09f6eabbf3d8ec0b85a"; };

  };

}
#endif