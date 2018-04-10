#ifndef _ROS_ibeo_sdk_scan_point_msgs_ScanPointFlags_2205_h
#define _ROS_ibeo_sdk_scan_point_msgs_ScanPointFlags_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_scan_point_msgs
{

  class ScanPointFlags_2205 : public ros::Msg
  {
    public:
      typedef uint32_t _flag_type;
      _flag_type flag;
      enum { GROUND =  1 };
      enum { DIRT =  2 };
      enum { RAIN =  4 };
      enum { ROADMARKING =  8 };
      enum { THRESHOLD_SWITCHING =  16 };
      enum { REFLECTOR =  32 };
      enum { NEAR_RANGE =  64 };
      enum { CURBSTONE =  128 };
      enum { LEFT_COVERED =  256 };
      enum { RIGHT_COVERED =  512 };
      enum { BACKGROUND =  1024 };
      enum { MARKER =  2048 };
      enum { TRANSPARENT =  4096 };
      enum { DYNAMIC =  8192 };
      enum { MASKINVALID =  1167 };
      enum { MASKCOVERED =  765 };
      enum { GUARDRAIL =  136 };

    ScanPointFlags_2205():
      flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->flag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flag >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flag >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flag >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->flag =  ((uint32_t) (*(inbuffer + offset)));
      this->flag |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flag |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flag |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flag);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_scan_point_msgs/ScanPointFlags_2205"; };
    const char * getMD5(){ return "020e73483b025b9d98e2bc13b9559923"; };

  };

}
#endif