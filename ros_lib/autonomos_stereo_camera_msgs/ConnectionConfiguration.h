#ifndef _ROS_autonomos_stereo_camera_msgs_ConnectionConfiguration_h
#define _ROS_autonomos_stereo_camera_msgs_ConnectionConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_stereo_camera_msgs
{

  class ConnectionConfiguration : public ros::Msg
  {
    public:
      typedef bool _useTCP_type;
      _useTCP_type useTCP;
      typedef const char* _ip_type;
      _ip_type ip;
      typedef uint16_t _port_type;
      _port_type port;

    ConnectionConfiguration():
      useTCP(0),
      ip(""),
      port(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_useTCP;
      u_useTCP.real = this->useTCP;
      *(outbuffer + offset + 0) = (u_useTCP.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->useTCP);
      uint32_t length_ip = strlen(this->ip);
      varToArr(outbuffer + offset, length_ip);
      offset += 4;
      memcpy(outbuffer + offset, this->ip, length_ip);
      offset += length_ip;
      *(outbuffer + offset + 0) = (this->port >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->port >> (8 * 1)) & 0xFF;
      offset += sizeof(this->port);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_useTCP;
      u_useTCP.base = 0;
      u_useTCP.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->useTCP = u_useTCP.real;
      offset += sizeof(this->useTCP);
      uint32_t length_ip;
      arrToVar(length_ip, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ip-1]=0;
      this->ip = (char *)(inbuffer + offset-1);
      offset += length_ip;
      this->port =  ((uint16_t) (*(inbuffer + offset)));
      this->port |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->port);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/ConnectionConfiguration"; };
    const char * getMD5(){ return "655d8c44381efde053b413051f1d93c5"; };

  };

}
#endif