#ifndef _ROS_autonomos_recorder_RecordingGoal_h
#define _ROS_autonomos_recorder_RecordingGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace autonomos_recorder
{

  class RecordingGoal : public ros::Msg
  {
    public:
      typedef ros::Duration _duration_type;
      _duration_type duration;
      typedef ros::Duration _extendedDuration_type;
      _extendedDuration_type extendedDuration;
      typedef const char* _name_type;
      _name_type name;

    RecordingGoal():
      duration(),
      extendedDuration(),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      *(outbuffer + offset + 0) = (this->extendedDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extendedDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extendedDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extendedDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extendedDuration.sec);
      *(outbuffer + offset + 0) = (this->extendedDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extendedDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extendedDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extendedDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extendedDuration.nsec);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      this->extendedDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->extendedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->extendedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->extendedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->extendedDuration.sec);
      this->extendedDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->extendedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->extendedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->extendedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->extendedDuration.nsec);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecordingGoal"; };
    const char * getMD5(){ return "fb7c914b9379c430bbec8593cf7870b2"; };

  };

}
#endif