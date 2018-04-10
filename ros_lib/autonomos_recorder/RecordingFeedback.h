#ifndef _ROS_autonomos_recorder_RecordingFeedback_h
#define _ROS_autonomos_recorder_RecordingFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace autonomos_recorder
{

  class RecordingFeedback : public ros::Msg
  {
    public:
      typedef uint32_t _messageCount_type;
      _messageCount_type messageCount;
      typedef uint64_t _messageSize_type;
      _messageSize_type messageSize;
      typedef ros::Time _recordingStartTime_type;
      _recordingStartTime_type recordingStartTime;
      typedef uint8_t _diskSpaceStatus_type;
      _diskSpaceStatus_type diskSpaceStatus;
      typedef uint64_t _diskSpaceRemaining_type;
      _diskSpaceRemaining_type diskSpaceRemaining;
      enum { DISKSPACE_SUFFICIENT =  0   };
      enum { DISKSPACE_LIMITED =  1   };
      enum { DISKSPACE_FULL =  2   };

    RecordingFeedback():
      messageCount(0),
      messageSize(0),
      recordingStartTime(),
      diskSpaceStatus(0),
      diskSpaceRemaining(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->messageCount >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->messageCount >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->messageCount >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->messageCount >> (8 * 3)) & 0xFF;
      offset += sizeof(this->messageCount);
      union {
        uint64_t real;
        uint32_t base;
      } u_messageSize;
      u_messageSize.real = this->messageSize;
      *(outbuffer + offset + 0) = (u_messageSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_messageSize.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_messageSize.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_messageSize.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->messageSize);
      *(outbuffer + offset + 0) = (this->recordingStartTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recordingStartTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recordingStartTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recordingStartTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recordingStartTime.sec);
      *(outbuffer + offset + 0) = (this->recordingStartTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recordingStartTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recordingStartTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recordingStartTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recordingStartTime.nsec);
      *(outbuffer + offset + 0) = (this->diskSpaceStatus >> (8 * 0)) & 0xFF;
      offset += sizeof(this->diskSpaceStatus);
      union {
        uint64_t real;
        uint32_t base;
      } u_diskSpaceRemaining;
      u_diskSpaceRemaining.real = this->diskSpaceRemaining;
      *(outbuffer + offset + 0) = (u_diskSpaceRemaining.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_diskSpaceRemaining.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_diskSpaceRemaining.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_diskSpaceRemaining.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->diskSpaceRemaining);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->messageCount =  ((uint32_t) (*(inbuffer + offset)));
      this->messageCount |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->messageCount |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->messageCount |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->messageCount);
      union {
        uint64_t real;
        uint32_t base;
      } u_messageSize;
      u_messageSize.base = 0;
      u_messageSize.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_messageSize.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_messageSize.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_messageSize.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->messageSize = u_messageSize.real;
      offset += sizeof(this->messageSize);
      this->recordingStartTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->recordingStartTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recordingStartTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->recordingStartTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->recordingStartTime.sec);
      this->recordingStartTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->recordingStartTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recordingStartTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->recordingStartTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->recordingStartTime.nsec);
      this->diskSpaceStatus =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->diskSpaceStatus);
      union {
        uint64_t real;
        uint32_t base;
      } u_diskSpaceRemaining;
      u_diskSpaceRemaining.base = 0;
      u_diskSpaceRemaining.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_diskSpaceRemaining.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_diskSpaceRemaining.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_diskSpaceRemaining.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->diskSpaceRemaining = u_diskSpaceRemaining.real;
      offset += sizeof(this->diskSpaceRemaining);
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecordingFeedback"; };
    const char * getMD5(){ return "7ccc6d71d0ff0d9b25f0b5b39886297e"; };

  };

}
#endif