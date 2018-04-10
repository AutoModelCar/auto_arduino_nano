#ifndef _ROS_ibeo_sdk_measurement_msgs_MeasurementType_h
#define _ROS_ibeo_sdk_measurement_msgs_MeasurementType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_measurement_msgs
{

  class MeasurementType : public ros::Msg
  {
    public:
      typedef uint32_t _type_type;
      _type_type type;
      enum { VOID =  0 };
      enum { FLOAT =  1 };
      enum { DOUBLE =  2 };
      enum { INT8 =  3 };
      enum { UINT8 =  4 };
      enum { INT16 =  5 };
      enum { UINT16 =  6 };
      enum { INT32 =  7 };
      enum { UINT32 =  8 };
      enum { INT64 =  9 };
      enum { UINT64 =  10 };
      enum { BOOL =  11 };
      enum { STD_STRING =  12 };

    MeasurementType():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_measurement_msgs/MeasurementType"; };
    const char * getMD5(){ return "468b3d304716f69a1796d8b911e397ea"; };

  };

}
#endif