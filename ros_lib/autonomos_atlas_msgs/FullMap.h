#ifndef _ROS_autonomos_atlas_msgs_FullMap_h
#define _ROS_autonomos_atlas_msgs_FullMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_atlas_msgs
{

  class FullMap : public ros::Msg
  {
    public:
      typedef uint8_t _map_type_type;
      _map_type_type map_type;
      typedef const char* _source_name_type;
      _source_name_type source_name;
      typedef const char* _map_data_type;
      _map_data_type map_data;
      enum { MAP_TYPE_INVALID =  0 };
      enum { MAP_TYPE_ARND3 =  1 };
      enum { MAP_TYPE_ATLAS_HD =  2 };
      enum { MAP_TYPE_3DLANE =  3 };

    FullMap():
      map_type(0),
      source_name(""),
      map_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->map_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->map_type);
      uint32_t length_source_name = strlen(this->source_name);
      varToArr(outbuffer + offset, length_source_name);
      offset += 4;
      memcpy(outbuffer + offset, this->source_name, length_source_name);
      offset += length_source_name;
      uint32_t length_map_data = strlen(this->map_data);
      varToArr(outbuffer + offset, length_map_data);
      offset += 4;
      memcpy(outbuffer + offset, this->map_data, length_map_data);
      offset += length_map_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->map_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->map_type);
      uint32_t length_source_name;
      arrToVar(length_source_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_name-1]=0;
      this->source_name = (char *)(inbuffer + offset-1);
      offset += length_source_name;
      uint32_t length_map_data;
      arrToVar(length_map_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_map_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_map_data-1]=0;
      this->map_data = (char *)(inbuffer + offset-1);
      offset += length_map_data;
     return offset;
    }

    const char * getType(){ return "autonomos_atlas_msgs/FullMap"; };
    const char * getMD5(){ return "c062c69320cdf72ddb99ba1f4e62f14d"; };

  };

}
#endif