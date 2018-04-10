#ifndef _ROS_ibeo_sdk_measurement_msgs_Measurement_2821_h
#define _ROS_ibeo_sdk_measurement_msgs_Measurement_2821_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_measurement_msgs/MeasurementType.h"

namespace ibeo_sdk_measurement_msgs
{

  class Measurement_2821 : public ros::Msg
  {
    public:
      typedef uint16_t _key_type;
      _key_type key;
      typedef ibeo_sdk_measurement_msgs::MeasurementType _measurement_type_type;
      _measurement_type_type measurement_type;
      typedef float _data_type;
      _data_type data;
      typedef const char* _data_string_type;
      _data_string_type data_string;

    Measurement_2821():
      key(0),
      measurement_type(),
      data(0),
      data_string("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->key >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->key >> (8 * 1)) & 0xFF;
      offset += sizeof(this->key);
      offset += this->measurement_type.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->data);
      uint32_t length_data_string = strlen(this->data_string);
      varToArr(outbuffer + offset, length_data_string);
      offset += 4;
      memcpy(outbuffer + offset, this->data_string, length_data_string);
      offset += length_data_string;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->key =  ((uint16_t) (*(inbuffer + offset)));
      this->key |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->key);
      offset += this->measurement_type.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->data));
      uint32_t length_data_string;
      arrToVar(length_data_string, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data_string-1]=0;
      this->data_string = (char *)(inbuffer + offset-1);
      offset += length_data_string;
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_measurement_msgs/Measurement_2821"; };
    const char * getMD5(){ return "9cd8e0f077743e39157ecbce44b45c83"; };

  };

}
#endif