#ifndef _ROS_autonomos_rviz_keyboard_msgs_ActiveKey_h
#define _ROS_autonomos_rviz_keyboard_msgs_ActiveKey_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_rviz_keyboard_msgs
{

  class ActiveKey : public ros::Msg
  {
    public:
      typedef int32_t _key_type;
      _key_type key;
      typedef uint32_t _modifier_type;
      _modifier_type modifier;
      typedef const char* _key_string_type;
      _key_string_type key_string;
      enum { NO_MODIFIER =          0  };
      enum { SHIFT_MODIFIER =   33554432  };
      enum { CONTROL_MODIFIER =   67108864  };
      enum { ALT_MODIFIER =  134217728  };
      enum { META_MODIFIER =  268435456  };

    ActiveKey():
      key(0),
      modifier(0),
      key_string("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_key;
      u_key.real = this->key;
      *(outbuffer + offset + 0) = (u_key.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_key.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_key.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_key.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->key);
      *(outbuffer + offset + 0) = (this->modifier >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modifier >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modifier >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modifier >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modifier);
      uint32_t length_key_string = strlen(this->key_string);
      varToArr(outbuffer + offset, length_key_string);
      offset += 4;
      memcpy(outbuffer + offset, this->key_string, length_key_string);
      offset += length_key_string;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_key;
      u_key.base = 0;
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_key.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->key = u_key.real;
      offset += sizeof(this->key);
      this->modifier =  ((uint32_t) (*(inbuffer + offset)));
      this->modifier |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->modifier |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->modifier |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->modifier);
      uint32_t length_key_string;
      arrToVar(length_key_string, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key_string-1]=0;
      this->key_string = (char *)(inbuffer + offset-1);
      offset += length_key_string;
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_keyboard_msgs/ActiveKey"; };
    const char * getMD5(){ return "6911f1424f330a32712e3d2007226df4"; };

  };

}
#endif