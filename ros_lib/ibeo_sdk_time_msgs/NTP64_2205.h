#ifndef _ROS_ibeo_sdk_time_msgs_NTP64_2205_h
#define _ROS_ibeo_sdk_time_msgs_NTP64_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_time_msgs
{

  class NTP64_2205 : public ros::Msg
  {
    public:
      typedef uint32_t _seconds_type;
      _seconds_type seconds;
      typedef uint32_t _fractional_seconds_type;
      _fractional_seconds_type fractional_seconds;

    NTP64_2205():
      seconds(0),
      fractional_seconds(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->seconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seconds >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seconds >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seconds >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seconds);
      *(outbuffer + offset + 0) = (this->fractional_seconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fractional_seconds >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fractional_seconds >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fractional_seconds >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fractional_seconds);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->seconds =  ((uint32_t) (*(inbuffer + offset)));
      this->seconds |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seconds |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seconds |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->seconds);
      this->fractional_seconds =  ((uint32_t) (*(inbuffer + offset)));
      this->fractional_seconds |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fractional_seconds |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->fractional_seconds |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->fractional_seconds);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_time_msgs/NTP64_2205"; };
    const char * getMD5(){ return "5244c9f5ad624d8e6547d2dbf72f27e8"; };

  };

}
#endif