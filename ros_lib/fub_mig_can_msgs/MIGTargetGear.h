#ifndef _ROS_fub_mig_can_msgs_MIGTargetGear_h
#define _ROS_fub_mig_can_msgs_MIGTargetGear_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGTargetGear : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      typedef uint8_t _selected_gear_position_type;
      _selected_gear_position_type selected_gear_position;
      typedef uint8_t _target_gear_position_type;
      _target_gear_position_type target_gear_position;
      enum { can_id =  1088  };
      enum { can_dlc =     8  };
      enum { SELECTED_GEAR_POSITION_BETWEEN_POSITIONS =  0 };
      enum { SELECTED_GEAR_POSITION_1 =  1 };
      enum { SELECTED_GEAR_POSITION_2 =  2 };
      enum { SELECTED_GEAR_POSITION_3 =  3 };
      enum { SELECTED_GEAR_POSITION_4 =  4 };
      enum { SELECTED_GEAR_POSITION_D =  5 };
      enum { SELECTED_GEAR_POSITION_N =  6 };
      enum { SELECTED_GEAR_POSITION_R =  7 };
      enum { SELECTED_GEAR_POSITION_P =  8 };
      enum { SELECTED_GEAR_POSITION_RSP_MANUAL_SPORT =  9 };
      enum { SELECTED_GEAR_POSITION_Z1 =  10 };
      enum { SELECTED_GEAR_POSITION_Z2 =  11 };
      enum { SELECTED_GEAR_POSITION_S =  12 };
      enum { SELECTED_GEAR_POSITION_L =  13 };
      enum { SELECTED_GEAR_POSITION_TIPTRONIC =  14 };
      enum { SELECTED_GEAR_POSITION_ERROR =  15 };
      enum { TARGET_GEAR_POSITION_GEAR_P_N_NONE =  0 };
      enum { TARGET_GEAR_POSITION_GEAR_1 =  1 };
      enum { TARGET_GEAR_POSITION_GEAR_2 =  2 };
      enum { TARGET_GEAR_POSITION_GEAR_3 =  3 };
      enum { TARGET_GEAR_POSITION_GEAR_4 =  4 };
      enum { TARGET_GEAR_POSITION_GEAR_5 =  5 };
      enum { TARGET_GEAR_POSITION_GEAR_1M =  6 };
      enum { TARGET_GEAR_POSITION_GEAR_R =  7 };
      enum { TARGET_GEAR_POSITION_GEAR_6 =  8 };
      enum { TARGET_GEAR_POSITION_GEAR_7 =  9 };
      enum { TARGET_GEAR_POSITION_FREE_0 =  10 };
      enum { TARGET_GEAR_POSITION_FREE_1 =  11 };
      enum { TARGET_GEAR_POSITION_FREE_2 =  12 };
      enum { TARGET_GEAR_POSITION_FREE_3 =  13 };
      enum { TARGET_GEAR_POSITION_CURRENT_GEAR_NOT_DEFINED =  14 };
      enum { TARGET_GEAR_POSITION_ERROR =  15 };

    MIGTargetGear():
      header(),
      message_counter(0),
      selected_gear_position(0),
      target_gear_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      *(outbuffer + offset + 0) = (this->selected_gear_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->selected_gear_position);
      *(outbuffer + offset + 0) = (this->target_gear_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target_gear_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
      this->selected_gear_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->selected_gear_position);
      this->target_gear_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->target_gear_position);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGTargetGear"; };
    const char * getMD5(){ return "82bc796c71a2a6ee57783861e87bb4eb"; };

  };

}
#endif