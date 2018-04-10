#ifndef _ROS_autonomos_player_UserAnnotation_h
#define _ROS_autonomos_player_UserAnnotation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace autonomos_player
{

  class UserAnnotation : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef const char* _title_type;
      _title_type title;
      typedef const char* _description_type;
      _description_type description;

    UserAnnotation():
      stamp(),
      title(""),
      description("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      uint32_t length_title = strlen(this->title);
      varToArr(outbuffer + offset, length_title);
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      uint32_t length_title;
      arrToVar(length_title, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
     return offset;
    }

    const char * getType(){ return "autonomos_player/UserAnnotation"; };
    const char * getMD5(){ return "7ada88246cf3d6201eadf83c912cf63e"; };

  };

}
#endif