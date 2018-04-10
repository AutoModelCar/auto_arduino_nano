#ifndef _ROS_ibeo_sdk_measurement_list_msgs_MeasurementList_2281_h
#define _ROS_ibeo_sdk_measurement_list_msgs_MeasurementList_2281_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_measurement_msgs/Measurement_2281.h"

namespace ibeo_sdk_measurement_list_msgs
{

  class MeasurementList_2281 : public ros::Msg
  {
    public:
      typedef uint16_t _measurement_size_type;
      _measurement_size_type measurement_size;
      uint32_t measurements_length;
      typedef ibeo_sdk_measurement_msgs::Measurement_2281 _measurements_type;
      _measurements_type st_measurements;
      _measurements_type * measurements;

    MeasurementList_2281():
      measurement_size(0),
      measurements_length(0), measurements(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->measurement_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->measurement_size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->measurement_size);
      *(outbuffer + offset + 0) = (this->measurements_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->measurements_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->measurements_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->measurements_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurements_length);
      for( uint32_t i = 0; i < measurements_length; i++){
      offset += this->measurements[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->measurement_size =  ((uint16_t) (*(inbuffer + offset)));
      this->measurement_size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->measurement_size);
      uint32_t measurements_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->measurements_length);
      if(measurements_lengthT > measurements_length)
        this->measurements = (ibeo_sdk_measurement_msgs::Measurement_2281*)realloc(this->measurements, measurements_lengthT * sizeof(ibeo_sdk_measurement_msgs::Measurement_2281));
      measurements_length = measurements_lengthT;
      for( uint32_t i = 0; i < measurements_length; i++){
      offset += this->st_measurements.deserialize(inbuffer + offset);
        memcpy( &(this->measurements[i]), &(this->st_measurements), sizeof(ibeo_sdk_measurement_msgs::Measurement_2281));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_measurement_list_msgs/MeasurementList_2281"; };
    const char * getMD5(){ return "d7ba93eaa5712b14a41bc9afe7f24e61"; };

  };

}
#endif