#ifndef _ROS_fub_einstein_can_msgs_EinsteinHandbrakeStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinHandbrakeStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinHandbrakeStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _brake_status_type;
      _brake_status_type brake_status;
      enum { can_id =  1506  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinHandbrakeStatus():
      header(),
      brake_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_brake_status;
      u_brake_status.real = this->brake_status;
      *(outbuffer + offset + 0) = (u_brake_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_brake_status;
      u_brake_status.base = 0;
      u_brake_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_status = u_brake_status.real;
      offset += sizeof(this->brake_status);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinHandbrakeStatus"; };
    const char * getMD5(){ return "9911c632e6238c0e25445b17bcdead93"; };

  };

}
#endif