#ifndef _ROS_ibeo_sdk_measurement_list_msgs_MeasurementList_2821_h
#define _ROS_ibeo_sdk_measurement_list_msgs_MeasurementList_2821_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2821.h"
#include "ibeo_sdk_measurement_msgs/Measurement_2821.h"

namespace ibeo_sdk_measurement_list_msgs
{

  class MeasurementList_2821 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _microseconds_type;
      _microseconds_type microseconds;
      typedef ibeo_sdk_time_msgs::NTP64_2821 _time_stamp_type;
      _time_stamp_type time_stamp;
      typedef const char* _list_name_type;
      _list_name_type list_name;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef uint16_t _number_of_measurements_type;
      _number_of_measurements_type number_of_measurements;
      uint32_t measurements_length;
      typedef ibeo_sdk_measurement_msgs::Measurement_2821 _measurements_type;
      _measurements_type st_measurements;
      _measurements_type * measurements;

    MeasurementList_2821():
      header(),
      microseconds(0),
      time_stamp(),
      list_name(""),
      group_name(""),
      number_of_measurements(0),
      measurements_length(0), measurements(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->microseconds >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->microseconds >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->microseconds >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->microseconds >> (8 * 3)) & 0xFF;
      offset += sizeof(this->microseconds);
      offset += this->time_stamp.serialize(outbuffer + offset);
      uint32_t length_list_name = strlen(this->list_name);
      varToArr(outbuffer + offset, length_list_name);
      offset += 4;
      memcpy(outbuffer + offset, this->list_name, length_list_name);
      offset += length_list_name;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      *(outbuffer + offset + 0) = (this->number_of_measurements >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->number_of_measurements >> (8 * 1)) & 0xFF;
      offset += sizeof(this->number_of_measurements);
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
      offset += this->header.deserialize(inbuffer + offset);
      this->microseconds =  ((uint32_t) (*(inbuffer + offset)));
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->microseconds |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->microseconds);
      offset += this->time_stamp.deserialize(inbuffer + offset);
      uint32_t length_list_name;
      arrToVar(length_list_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_list_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_list_name-1]=0;
      this->list_name = (char *)(inbuffer + offset-1);
      offset += length_list_name;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      this->number_of_measurements =  ((uint16_t) (*(inbuffer + offset)));
      this->number_of_measurements |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->number_of_measurements);
      uint32_t measurements_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      measurements_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->measurements_length);
      if(measurements_lengthT > measurements_length)
        this->measurements = (ibeo_sdk_measurement_msgs::Measurement_2821*)realloc(this->measurements, measurements_lengthT * sizeof(ibeo_sdk_measurement_msgs::Measurement_2821));
      measurements_length = measurements_lengthT;
      for( uint32_t i = 0; i < measurements_length; i++){
      offset += this->st_measurements.deserialize(inbuffer + offset);
        memcpy( &(this->measurements[i]), &(this->st_measurements), sizeof(ibeo_sdk_measurement_msgs::Measurement_2821));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_measurement_list_msgs/MeasurementList_2821"; };
    const char * getMD5(){ return "abeca454184c130e9149c0bb5520cacd"; };

  };

}
#endif