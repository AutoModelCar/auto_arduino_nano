#ifndef _ROS_ibeo_sdk_object_list_msgs_DeviceType_h
#define _ROS_ibeo_sdk_object_list_msgs_DeviceType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_object_list_msgs
{

  class DeviceType : public ros::Msg
  {
    public:
      typedef uint32_t _type_type;
      _type_type type;
      enum { UNDEFINED =    0 };
      enum { LASERSCANNER =    1 };
      enum { RADAR =   50 };
      enum { CAMERA =   60 };
      enum { REFERNCE =   90 };
      enum { DUT =  120 };

    DeviceType():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_list_msgs/DeviceType"; };
    const char * getMD5(){ return "5c015ef8f14af2c6473f778a2eb1c97f"; };

  };

}
#endif