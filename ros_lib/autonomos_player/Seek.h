#ifndef _ROS_SERVICE_Seek_h
#define _ROS_SERVICE_Seek_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_player
{

static const char SEEK[] = "autonomos_player/Seek";

  class SeekRequest : public ros::Msg
  {
    public:
      typedef float _second_type;
      _second_type second;

    SeekRequest():
      second(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_second;
      u_second.real = this->second;
      *(outbuffer + offset + 0) = (u_second.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_second.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_second.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_second.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->second);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_second;
      u_second.base = 0;
      u_second.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_second.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_second.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_second.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->second = u_second.real;
      offset += sizeof(this->second);
     return offset;
    }

    const char * getType(){ return SEEK; };
    const char * getMD5(){ return "32f0e121979b7e779fb75ed2e3b00a62"; };

  };

  class SeekResponse : public ros::Msg
  {
    public:

    SeekResponse()
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

    const char * getType(){ return SEEK; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Seek {
    public:
    typedef SeekRequest Request;
    typedef SeekResponse Response;
  };

}
#endif
