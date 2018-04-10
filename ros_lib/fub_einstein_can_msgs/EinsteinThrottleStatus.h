#ifndef _ROS_fub_einstein_can_msgs_EinsteinThrottleStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinThrottleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinThrottleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _throttle_type;
      _throttle_type throttle;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  528  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };

    EinsteinThrottleStatus():
      header(),
      throttle(0),
      message_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->throttle >> (8 * 0)) & 0xFF;
      offset += sizeof(this->throttle);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->throttle =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->throttle);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinThrottleStatus"; };
    const char * getMD5(){ return "2d53214a005cddf66f74daa8df510eed"; };

  };

}
#endif