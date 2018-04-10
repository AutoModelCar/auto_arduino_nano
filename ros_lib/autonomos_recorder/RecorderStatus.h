#ifndef _ROS_autonomos_recorder_RecorderStatus_h
#define _ROS_autonomos_recorder_RecorderStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace autonomos_recorder
{

  class RecorderStatus : public ros::Msg
  {
    public:
      typedef uint8_t _diskSpaceStatus_type;
      _diskSpaceStatus_type diskSpaceStatus;
      typedef uint64_t _diskSpaceRemaining_type;
      _diskSpaceRemaining_type diskSpaceRemaining;
      typedef bool _recordingActive_type;
      _recordingActive_type recordingActive;
      typedef const char* _filename_type;
      _filename_type filename;
      typedef const char* _infoMsg_type;
      _infoMsg_type infoMsg;
      typedef ros::Time _recordingStartTime_type;
      _recordingStartTime_type recordingStartTime;
      typedef ros::Time _recordingEndTime_type;
      _recordingEndTime_type recordingEndTime;
      uint32_t topics_length;
      typedef char* _topics_type;
      _topics_type st_topics;
      _topics_type * topics;
      typedef uint32_t _messageCount_type;
      _messageCount_type messageCount;
      typedef uint64_t _messageSize_type;
      _messageSize_type messageSize;
      enum { DISKSPACE_SUFFICIENT =  0   };
      enum { DISKSPACE_LIMITED =  1   };
      enum { DISKSPACE_FULL =  2   };

    RecorderStatus():
      diskSpaceStatus(0),
      diskSpaceRemaining(0),
      recordingActive(0),
      filename(""),
      infoMsg(""),
      recordingStartTime(),
      recordingEndTime(),
      topics_length(0), topics(NULL),
      messageCount(0),
      messageSize(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_recordingActive;
      u_recordingActive.real = this->recordingActive;
      *(outbuffer + offset + 0) = (u_recordingActive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recordingActive);
      uint32_t length_filename = strlen(this->filename);
      varToArr(outbuffer + offset, length_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      uint32_t length_infoMsg = strlen(this->infoMsg);
      varToArr(outbuffer + offset, length_infoMsg);
      offset += 4;
      memcpy(outbuffer + offset, this->infoMsg, length_infoMsg);
      offset += length_infoMsg;
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
      *(outbuffer + offset + 0) = (this->recordingEndTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recordingEndTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recordingEndTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recordingEndTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recordingEndTime.sec);
      *(outbuffer + offset + 0) = (this->recordingEndTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recordingEndTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recordingEndTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recordingEndTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recordingEndTime.nsec);
      *(outbuffer + offset + 0) = (this->topics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topics_length);
      for( uint32_t i = 0; i < topics_length; i++){
      uint32_t length_topicsi = strlen(this->topics[i]);
      varToArr(outbuffer + offset, length_topicsi);
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_topicsi);
      offset += length_topicsi;
      }
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      union {
        bool real;
        uint8_t base;
      } u_recordingActive;
      u_recordingActive.base = 0;
      u_recordingActive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recordingActive = u_recordingActive.real;
      offset += sizeof(this->recordingActive);
      uint32_t length_filename;
      arrToVar(length_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
      uint32_t length_infoMsg;
      arrToVar(length_infoMsg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_infoMsg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_infoMsg-1]=0;
      this->infoMsg = (char *)(inbuffer + offset-1);
      offset += length_infoMsg;
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
      this->recordingEndTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->recordingEndTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recordingEndTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->recordingEndTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->recordingEndTime.sec);
      this->recordingEndTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->recordingEndTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recordingEndTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->recordingEndTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->recordingEndTime.nsec);
      uint32_t topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topics_length);
      if(topics_lengthT > topics_length)
        this->topics = (char**)realloc(this->topics, topics_lengthT * sizeof(char*));
      topics_length = topics_lengthT;
      for( uint32_t i = 0; i < topics_length; i++){
      uint32_t length_st_topics;
      arrToVar(length_st_topics, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topics; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topics-1]=0;
      this->st_topics = (char *)(inbuffer + offset-1);
      offset += length_st_topics;
        memcpy( &(this->topics[i]), &(this->st_topics), sizeof(char*));
      }
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
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecorderStatus"; };
    const char * getMD5(){ return "e92faf8e7cd32c2236ec9d86440f174a"; };

  };

}
#endif