#ifndef _ROS_autonomos_vehicle_msgs_DrivingMode_h
#define _ROS_autonomos_vehicle_msgs_DrivingMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class DrivingMode : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _requested_mode_type;
      _requested_mode_type requested_mode;
      typedef int8_t _current_mode_type;
      _current_mode_type current_mode;
      typedef const char* _current_mode_reason_type;
      _current_mode_reason_type current_mode_reason;
      enum { MODE_UNKNOWN =  0   };
      enum { MODE_ERROR =  1   };
      enum { MODE_MANUAL =  2   };
      enum { MODE_AUTONOMY_READY =  3   };
      enum { MODE_AUTONOMOUS =  4   };

    DrivingMode():
      header(),
      requested_mode(0),
      current_mode(0),
      current_mode_reason("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_requested_mode;
      u_requested_mode.real = this->requested_mode;
      *(outbuffer + offset + 0) = (u_requested_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->requested_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_current_mode;
      u_current_mode.real = this->current_mode;
      *(outbuffer + offset + 0) = (u_current_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_mode);
      uint32_t length_current_mode_reason = strlen(this->current_mode_reason);
      varToArr(outbuffer + offset, length_current_mode_reason);
      offset += 4;
      memcpy(outbuffer + offset, this->current_mode_reason, length_current_mode_reason);
      offset += length_current_mode_reason;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_requested_mode;
      u_requested_mode.base = 0;
      u_requested_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->requested_mode = u_requested_mode.real;
      offset += sizeof(this->requested_mode);
      union {
        int8_t real;
        uint8_t base;
      } u_current_mode;
      u_current_mode.base = 0;
      u_current_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_mode = u_current_mode.real;
      offset += sizeof(this->current_mode);
      uint32_t length_current_mode_reason;
      arrToVar(length_current_mode_reason, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_mode_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_mode_reason-1]=0;
      this->current_mode_reason = (char *)(inbuffer + offset-1);
      offset += length_current_mode_reason;
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/DrivingMode"; };
    const char * getMD5(){ return "ce96e8644299b03e53310c4a14765bfc"; };

  };

}
#endif