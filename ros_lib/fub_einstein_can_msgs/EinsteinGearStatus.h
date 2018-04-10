#ifndef _ROS_fub_einstein_can_msgs_EinsteinGearStatus_h
#define _ROS_fub_einstein_can_msgs_EinsteinGearStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_einstein_can_msgs
{

  class EinsteinGearStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _gear_position_type;
      _gear_position_type gear_position;
      enum { can_id =  1686  };
      enum { can_dlc =    8  };
      enum { can_cycle =   28  };
      enum { GEAR_POSITION_ERROR =  1 };
      enum { GEAR_POSITION_R =  130 };
      enum { GEAR_POSITION_P =  65 };
      enum { GEAR_POSITION_C =  32 };
      enum { GEAR_POSITION_B =  16 };
      enum { GEAR_POSITION_D =  8 };
      enum { GEAR_POSITION_N =  4 };
      enum { GEAR_POSITION_BETWEEN_POSITIONS =  0 };

    EinsteinGearStatus():
      header(),
      gear_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gear_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gear_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->gear_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gear_position);
     return offset;
    }

    const char * getType(){ return "fub_einstein_can_msgs/EinsteinGearStatus"; };
    const char * getMD5(){ return "076a836b978304af6be2ca9241764a9b"; };

  };

}
#endif