#ifndef _ROS_SERVICE_MaxLoopDuration_h
#define _ROS_SERVICE_MaxLoopDuration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Duration.h"

namespace fub_simulator_cpp
{

static const char MAXLOOPDURATION[] = "fub_simulator_cpp/MaxLoopDuration";

  class MaxLoopDurationRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Duration _duration_type;
      _duration_type duration;

    MaxLoopDurationRequest():
      duration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->duration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->duration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAXLOOPDURATION; };
    const char * getMD5(){ return "9c951fa347a8a95fcf8eb83d07ea16bc"; };

  };

  class MaxLoopDurationResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    MaxLoopDurationResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return MAXLOOPDURATION; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class MaxLoopDuration {
    public:
    typedef MaxLoopDurationRequest Request;
    typedef MaxLoopDurationResponse Response;
  };

}
#endif
