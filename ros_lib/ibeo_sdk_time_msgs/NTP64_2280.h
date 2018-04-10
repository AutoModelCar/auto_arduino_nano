#ifndef _ROS_ibeo_sdk_time_msgs_NTP64_2280_h
#define _ROS_ibeo_sdk_time_msgs_NTP64_2280_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_time_msgs
{

  class NTP64_2280 : public ros::Msg
  {
    public:
      typedef uint64_t _time_type;
      _time_type time;

    NTP64_2280():
      time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time = u_time.real;
      offset += sizeof(this->time);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_time_msgs/NTP64_2280"; };
    const char * getMD5(){ return "fc2f6dd4d066c80a2708ee256a0cb8c8"; };

  };

}
#endif