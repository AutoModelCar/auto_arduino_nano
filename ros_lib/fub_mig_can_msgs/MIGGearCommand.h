#ifndef _ROS_fub_mig_can_msgs_MIGGearCommand_h
#define _ROS_fub_mig_can_msgs_MIGGearCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGGearCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef uint8_t _gear_position_type;
      _gear_position_type gear_position;
      enum { can_id =    5  };
      enum { can_dlc =    8  };
      enum { can_cycle =   10  };
      enum { GEAR_POSITION_1 =  1 };
      enum { GEAR_POSITION_2 =  2 };
      enum { GEAR_POSITION_3 =  3 };
      enum { GEAR_POSITION_4 =  4 };
      enum { GEAR_POSITION_D =  5 };
      enum { GEAR_POSITION_N =  6 };
      enum { GEAR_POSITION_R =  7 };
      enum { GEAR_POSITION_P =  8 };
      enum { GEAR_POSITION_N_NO_SPOT =  9 };
      enum { GEAR_POSITION_TIPP_PLUS =  10 };
      enum { GEAR_POSITION_TIPP_MINUS =  11 };
      enum { GEAR_POSITION_S =  12 };
      enum { GEAR_POSITION_L =  13 };
      enum { GEAR_POSITION_TIPTRONIC =  14 };
      enum { GEAR_POSITION_ERROR =  15 };

    MIGGearCommand():
      header(),
      message_counter(0),
      gear_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      *(outbuffer + offset + 0) = (this->gear_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      this->gear_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gear_position);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGGearCommand"; };
    const char * getMD5(){ return "4a2ecc297d1e50ea3dbc5228966374df"; };

  };

}
#endif