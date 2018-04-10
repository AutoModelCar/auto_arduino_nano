#ifndef _ROS_ibeo_sdk_object_msgs_ObjectClass_h
#define _ROS_ibeo_sdk_object_msgs_ObjectClass_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_object_msgs
{

  class ObjectClass : public ros::Msg
  {
    public:
      typedef uint32_t _classification_label_type;
      _classification_label_type classification_label;
      enum { UNCLASSIFIED =  0 };
      enum { UNKNOWN_SMALL =  1 };
      enum { UNKNOWN_BIG =  2 };
      enum { PEDESTRIAN =  3 };
      enum { BIKE =  4 };
      enum { CAR =  5 };
      enum { TRUCK =  6 };
      enum { UNDERDRIVEABLE =  12 };
      enum { MOTORBIKE =  15 };
      enum { BICYCLE =  17 };

    ObjectClass():
      classification_label(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->classification_label >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_label >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classification_label >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classification_label >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_label);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->classification_label =  ((uint32_t) (*(inbuffer + offset)));
      this->classification_label |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->classification_label |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->classification_label |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->classification_label);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_msgs/ObjectClass"; };
    const char * getMD5(){ return "02b0be306c2a662cad9812fe98590335"; };

  };

}
#endif