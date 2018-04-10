#ifndef _ROS_fub_applanix_msgs_LoggingStatus_h
#define _ROS_fub_applanix_msgs_LoggingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"
#include "ros/duration.h"

namespace fub_applanix_msgs
{

  class LoggingStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint32_t _disk_kbytes_remaining_type;
      _disk_kbytes_remaining_type disk_kbytes_remaining;
      typedef uint32_t _disk_kbytes_logged_type;
      _disk_kbytes_logged_type disk_kbytes_logged;
      typedef ros::Duration _disk_logging_time_remaining_type;
      _disk_logging_time_remaining_type disk_logging_time_remaining;
      typedef uint32_t _disk_kbytes_total_type;
      _disk_kbytes_total_type disk_kbytes_total;
      typedef uint8_t _logging_state_type;
      _logging_state_type logging_state;
      enum { STATE_STANDBY =  0 };
      enum { STATE_LOGGING =  1 };
      enum { STATE_BUFFERING =  2 };
      enum { STATE_INVALID =  255 };

    LoggingStatus():
      header(),
      td(),
      disk_kbytes_remaining(0),
      disk_kbytes_logged(0),
      disk_logging_time_remaining(),
      disk_kbytes_total(0),
      logging_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->disk_kbytes_remaining >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disk_kbytes_remaining >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->disk_kbytes_remaining >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->disk_kbytes_remaining >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_kbytes_remaining);
      *(outbuffer + offset + 0) = (this->disk_kbytes_logged >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disk_kbytes_logged >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->disk_kbytes_logged >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->disk_kbytes_logged >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_kbytes_logged);
      *(outbuffer + offset + 0) = (this->disk_logging_time_remaining.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disk_logging_time_remaining.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->disk_logging_time_remaining.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->disk_logging_time_remaining.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_logging_time_remaining.sec);
      *(outbuffer + offset + 0) = (this->disk_logging_time_remaining.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disk_logging_time_remaining.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->disk_logging_time_remaining.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->disk_logging_time_remaining.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_logging_time_remaining.nsec);
      *(outbuffer + offset + 0) = (this->disk_kbytes_total >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disk_kbytes_total >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->disk_kbytes_total >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->disk_kbytes_total >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_kbytes_total);
      *(outbuffer + offset + 0) = (this->logging_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->logging_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->disk_kbytes_remaining =  ((uint32_t) (*(inbuffer + offset)));
      this->disk_kbytes_remaining |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disk_kbytes_remaining |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->disk_kbytes_remaining |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->disk_kbytes_remaining);
      this->disk_kbytes_logged =  ((uint32_t) (*(inbuffer + offset)));
      this->disk_kbytes_logged |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disk_kbytes_logged |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->disk_kbytes_logged |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->disk_kbytes_logged);
      this->disk_logging_time_remaining.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->disk_logging_time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disk_logging_time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->disk_logging_time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->disk_logging_time_remaining.sec);
      this->disk_logging_time_remaining.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->disk_logging_time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disk_logging_time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->disk_logging_time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->disk_logging_time_remaining.nsec);
      this->disk_kbytes_total =  ((uint32_t) (*(inbuffer + offset)));
      this->disk_kbytes_total |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disk_kbytes_total |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->disk_kbytes_total |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->disk_kbytes_total);
      this->logging_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->logging_state);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/LoggingStatus"; };
    const char * getMD5(){ return "42009917ed4d23a4ac717788f3b9c1b1"; };

  };

}
#endif