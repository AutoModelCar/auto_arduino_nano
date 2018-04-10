#ifndef _ROS_autonomos_player_UserAnnotationArray_h
#define _ROS_autonomos_player_UserAnnotationArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_player/UserAnnotation.h"

namespace autonomos_player
{

  class UserAnnotationArray : public ros::Msg
  {
    public:
      uint32_t data_length;
      typedef autonomos_player::UserAnnotation _data_type;
      _data_type st_data;
      _data_type * data;

    UserAnnotationArray():
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (autonomos_player::UserAnnotation*)realloc(this->data, data_lengthT * sizeof(autonomos_player::UserAnnotation));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(autonomos_player::UserAnnotation));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_player/UserAnnotationArray"; };
    const char * getMD5(){ return "0a5b35c31d7f5c8528de2a6ff2762e3e"; };

  };

}
#endif