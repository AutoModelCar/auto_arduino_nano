#ifndef _ROS_SERVICE_Navigation_h
#define _ROS_SERVICE_Navigation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "autonomos_navigation_msgs/NavigationSolution.h"

namespace autonomos_navigation_msgs
{

static const char NAVIGATION[] = "autonomos_navigation_msgs/Navigation";

  class NavigationRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _start_type;
      _start_type start;
      typedef geometry_msgs::Point _end_type;
      _end_type end;

    NavigationRequest():
      header(),
      start(),
      end()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->end.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->end.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return NAVIGATION; };
    const char * getMD5(){ return "b33889de7563531bdca406d6f009b0bc"; };

  };

  class NavigationResponse : public ros::Msg
  {
    public:
      typedef autonomos_navigation_msgs::NavigationSolution _navigation_solution_type;
      _navigation_solution_type navigation_solution;
      typedef bool _error_type;
      _error_type error;
      typedef const char* _error_reason_type;
      _error_reason_type error_reason;

    NavigationResponse():
      navigation_solution(),
      error(0),
      error_reason("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->navigation_solution.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error);
      uint32_t length_error_reason = strlen(this->error_reason);
      varToArr(outbuffer + offset, length_error_reason);
      offset += 4;
      memcpy(outbuffer + offset, this->error_reason, length_error_reason);
      offset += length_error_reason;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->navigation_solution.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->error = u_error.real;
      offset += sizeof(this->error);
      uint32_t length_error_reason;
      arrToVar(length_error_reason, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_reason-1]=0;
      this->error_reason = (char *)(inbuffer + offset-1);
      offset += length_error_reason;
     return offset;
    }

    const char * getType(){ return NAVIGATION; };
    const char * getMD5(){ return "66968d3e124dd5c5bc24f3fe6df4aa1c"; };

  };

  class Navigation {
    public:
    typedef NavigationRequest Request;
    typedef NavigationResponse Response;
  };

}
#endif
