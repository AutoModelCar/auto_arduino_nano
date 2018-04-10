#ifndef _ROS_autonomos_vehicle_msgs_Drivability_h
#define _ROS_autonomos_vehicle_msgs_Drivability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace autonomos_vehicle_msgs
{

  class Drivability : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _aspect_type;
      _aspect_type aspect;
      typedef uint8_t _status_type;
      _status_type status;
      typedef ros::Duration _timeout_type;
      _timeout_type timeout;
      typedef const char* _reason_type;
      _reason_type reason;
      enum { STATUS_OK =  0 };
      enum { STATUS_WARNING =  1 };
      enum { STATUS_ERROR =  2 };
      enum { STATUS_CRITICAL =  3 };

    Drivability():
      header(),
      name(""),
      aspect(""),
      status(0),
      timeout(),
      reason("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_aspect = strlen(this->aspect);
      varToArr(outbuffer + offset, length_aspect);
      offset += 4;
      memcpy(outbuffer + offset, this->aspect, length_aspect);
      offset += length_aspect;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      uint32_t length_reason = strlen(this->reason);
      varToArr(outbuffer + offset, length_reason);
      offset += 4;
      memcpy(outbuffer + offset, this->reason, length_reason);
      offset += length_reason;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_aspect;
      arrToVar(length_aspect, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_aspect; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_aspect-1]=0;
      this->aspect = (char *)(inbuffer + offset-1);
      offset += length_aspect;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
      uint32_t length_reason;
      arrToVar(length_reason, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reason-1]=0;
      this->reason = (char *)(inbuffer + offset-1);
      offset += length_reason;
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/Drivability"; };
    const char * getMD5(){ return "141393f0789182a911249442ca1bbbaf"; };

  };

}
#endif