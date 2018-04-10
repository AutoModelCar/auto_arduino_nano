#ifndef _ROS_autonomos_atlas_msgs_FullAnnotations_h
#define _ROS_autonomos_atlas_msgs_FullAnnotations_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_atlas_msgs
{

  class FullAnnotations : public ros::Msg
  {
    public:
      typedef uint8_t _annotation_format_type;
      _annotation_format_type annotation_format;
      typedef const char* _source_name_type;
      _source_name_type source_name;
      typedef const char* _annotation_data_type;
      _annotation_data_type annotation_data;
      enum { ANNOTATION_TYPE_INVALID =  0 };
      enum { ANNOTATION_TYPE_ATLAS_XML =  1 };

    FullAnnotations():
      annotation_format(0),
      source_name(""),
      annotation_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->annotation_format >> (8 * 0)) & 0xFF;
      offset += sizeof(this->annotation_format);
      uint32_t length_source_name = strlen(this->source_name);
      varToArr(outbuffer + offset, length_source_name);
      offset += 4;
      memcpy(outbuffer + offset, this->source_name, length_source_name);
      offset += length_source_name;
      uint32_t length_annotation_data = strlen(this->annotation_data);
      varToArr(outbuffer + offset, length_annotation_data);
      offset += 4;
      memcpy(outbuffer + offset, this->annotation_data, length_annotation_data);
      offset += length_annotation_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->annotation_format =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->annotation_format);
      uint32_t length_source_name;
      arrToVar(length_source_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_name-1]=0;
      this->source_name = (char *)(inbuffer + offset-1);
      offset += length_source_name;
      uint32_t length_annotation_data;
      arrToVar(length_annotation_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_annotation_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_annotation_data-1]=0;
      this->annotation_data = (char *)(inbuffer + offset-1);
      offset += length_annotation_data;
     return offset;
    }

    const char * getType(){ return "autonomos_atlas_msgs/FullAnnotations"; };
    const char * getMD5(){ return "a9f57b9503b71325facc8b8349dc74c9"; };

  };

}
#endif