#ifndef _ROS_autonomos_recorder_RecorderTestMessage_h
#define _ROS_autonomos_recorder_RecorderTestMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_recorder
{

  class RecorderTestMessage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _payload_type;
      _payload_type payload;

    RecorderTestMessage():
      header(),
      payload("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_payload = strlen(this->payload);
      varToArr(outbuffer + offset, length_payload);
      offset += 4;
      memcpy(outbuffer + offset, this->payload, length_payload);
      offset += length_payload;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_payload;
      arrToVar(length_payload, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_payload; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_payload-1]=0;
      this->payload = (char *)(inbuffer + offset-1);
      offset += length_payload;
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecorderTestMessage"; };
    const char * getMD5(){ return "29b7d95c02e35ad24d90a42e65fc12e9"; };

  };

}
#endif