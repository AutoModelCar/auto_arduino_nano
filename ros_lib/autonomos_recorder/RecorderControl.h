#ifndef _ROS_autonomos_recorder_RecorderControl_h
#define _ROS_autonomos_recorder_RecorderControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_recorder
{

  class RecorderControl : public ros::Msg
  {
    public:
      typedef bool _recorderServerEnabled_type;
      _recorderServerEnabled_type recorderServerEnabled;
      typedef bool _recording_type;
      _recording_type recording;

    RecorderControl():
      recorderServerEnabled(0),
      recording(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_recorderServerEnabled;
      u_recorderServerEnabled.real = this->recorderServerEnabled;
      *(outbuffer + offset + 0) = (u_recorderServerEnabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recorderServerEnabled);
      union {
        bool real;
        uint8_t base;
      } u_recording;
      u_recording.real = this->recording;
      *(outbuffer + offset + 0) = (u_recording.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->recording);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_recorderServerEnabled;
      u_recorderServerEnabled.base = 0;
      u_recorderServerEnabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recorderServerEnabled = u_recorderServerEnabled.real;
      offset += sizeof(this->recorderServerEnabled);
      union {
        bool real;
        uint8_t base;
      } u_recording;
      u_recording.base = 0;
      u_recording.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->recording = u_recording.real;
      offset += sizeof(this->recording);
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecorderControl"; };
    const char * getMD5(){ return "bd503dff09c9fc95626e1768d5acb798"; };

  };

}
#endif