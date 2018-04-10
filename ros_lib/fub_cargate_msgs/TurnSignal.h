#ifndef _ROS_fub_cargate_msgs_TurnSignal_h
#define _ROS_fub_cargate_msgs_TurnSignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_cargate_msgs
{

  class TurnSignal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _data_type;
      _data_type data;
      enum { TURN_SIGNAL_OFF =  0 };
      enum { TURN_SIGNAL_LEFT =  1 };
      enum { TURN_SIGNAL_RIGHT =  2 };
      enum { TURN_SIGNAL_HAZARDS =  3 };

    TurnSignal():
      header(),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "fub_cargate_msgs/TurnSignal"; };
    const char * getMD5(){ return "0acf8b22c99e0b3d9d6953d0d8ed6e6a"; };

  };

}
#endif