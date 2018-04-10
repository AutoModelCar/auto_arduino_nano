#ifndef _ROS_fub_mig_can_msgs_MIGParkAssist_h
#define _ROS_fub_mig_can_msgs_MIGParkAssist_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGParkAssist : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _distance_front_left_type;
      _distance_front_left_type distance_front_left;
      typedef uint8_t _distance_front_right_type;
      _distance_front_right_type distance_front_right;
      typedef uint8_t _distance_rear_left_type;
      _distance_rear_left_type distance_rear_left;
      typedef uint8_t _distance_rear_right_type;
      _distance_rear_right_type distance_rear_right;
      typedef uint8_t _distance_front_middle_left_type;
      _distance_front_middle_left_type distance_front_middle_left;
      typedef uint8_t _distance_front_middle_right_type;
      _distance_front_middle_right_type distance_front_middle_right;
      typedef uint8_t _distance_rear_middle_left_type;
      _distance_rear_middle_left_type distance_rear_middle_left;
      typedef uint8_t _distance_rear_middle_right_type;
      _distance_rear_middle_right_type distance_rear_middle_right;
      enum { can_id =  1355  };
      enum { can_dlc =     8 };

    MIGParkAssist():
      header(),
      distance_front_left(0),
      distance_front_right(0),
      distance_rear_left(0),
      distance_rear_right(0),
      distance_front_middle_left(0),
      distance_front_middle_right(0),
      distance_rear_middle_left(0),
      distance_rear_middle_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->distance_front_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_front_left);
      *(outbuffer + offset + 0) = (this->distance_front_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_front_right);
      *(outbuffer + offset + 0) = (this->distance_rear_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_rear_left);
      *(outbuffer + offset + 0) = (this->distance_rear_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_rear_right);
      *(outbuffer + offset + 0) = (this->distance_front_middle_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_front_middle_left);
      *(outbuffer + offset + 0) = (this->distance_front_middle_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_front_middle_right);
      *(outbuffer + offset + 0) = (this->distance_rear_middle_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_rear_middle_left);
      *(outbuffer + offset + 0) = (this->distance_rear_middle_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_rear_middle_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->distance_front_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_front_left);
      this->distance_front_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_front_right);
      this->distance_rear_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_rear_left);
      this->distance_rear_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_rear_right);
      this->distance_front_middle_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_front_middle_left);
      this->distance_front_middle_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_front_middle_right);
      this->distance_rear_middle_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_rear_middle_left);
      this->distance_rear_middle_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_rear_middle_right);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGParkAssist"; };
    const char * getMD5(){ return "d413b67a19a1092c74a1dab73c386e98"; };

  };

}
#endif