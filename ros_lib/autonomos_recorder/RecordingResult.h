#ifndef _ROS_autonomos_recorder_RecordingResult_h
#define _ROS_autonomos_recorder_RecordingResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_recorder
{

  class RecordingResult : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef uint32_t _messageCount_type;
      _messageCount_type messageCount;
      typedef uint64_t _messageSize_type;
      _messageSize_type messageSize;

    RecordingResult():
      file(""),
      messageCount(0),
      messageSize(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
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
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
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

    const char * getType(){ return "autonomos_recorder/RecordingResult"; };
    const char * getMD5(){ return "7617e80f0fc024291f22d218a2b8e6ac"; };

  };

}
#endif