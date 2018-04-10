#ifndef _ROS_fub_mig_can_msgs_MIGAirBag_h
#define _ROS_fub_mig_can_msgs_MIGAirBag_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGAirBag : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _seatbelt_status_type;
      _seatbelt_status_type seatbelt_status;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  80  };
      enum { can_dlc =   4  };
      enum { SEATBELT_NOT_AVAILABLE =  0 };
      enum { SEATBELT_ERROR =  1 };
      enum { SEATBELT_NOT_FASTENED =  2 };
      enum { SEATBELT_FASTENED =  3 };

    MIGAirBag():
      header(),
      seatbelt_status(0),
      message_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->seatbelt_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seatbelt_status);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->seatbelt_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seatbelt_status);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGAirBag"; };
    const char * getMD5(){ return "aed9c58603e4c0821b3d583651ccf030"; };

  };

}
#endif