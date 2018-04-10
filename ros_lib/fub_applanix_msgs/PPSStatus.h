#ifndef _ROS_fub_applanix_msgs_PPSStatus_h
#define _ROS_fub_applanix_msgs_PPSStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class PPSStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint32_t _pps_count_type;
      _pps_count_type pps_count;
      typedef uint8_t _status_type;
      _status_type status;
      enum { STATUS_NOT_SYNCHRONIZED =  0 };
      enum { STATUS_SYNCHRONIZING =  1 };
      enum { STATUS_FULLY_SYNCHRONIZED =  2 };
      enum { STATUS_USING_OLD_OFFSET =  3 };

    PPSStatus():
      header(),
      td(),
      pps_count(0),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pps_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pps_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pps_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pps_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pps_count);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->pps_count =  ((uint32_t) (*(inbuffer + offset)));
      this->pps_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pps_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pps_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pps_count);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/PPSStatus"; };
    const char * getMD5(){ return "c506def7a0d23eedadad13f81ba3102f"; };

  };

}
#endif