#ifndef _ROS_autonomos_ibeo_msgs_IbeoStatus_h
#define _ROS_autonomos_ibeo_msgs_IbeoStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_ibeo_msgs
{

  class IbeoStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _firmware_version_type;
      _firmware_version_type firmware_version;
      typedef const char* _firmware_version_str_type;
      _firmware_version_str_type firmware_version_str;
      typedef uint16_t _fpga_version_type;
      _fpga_version_type fpga_version;
      typedef const char* _fpga_version_str_type;
      _fpga_version_str_type fpga_version_str;
      typedef uint16_t _scanner_status_flags_type;
      _scanner_status_flags_type scanner_status_flags;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef const char* _serial_number_type;
      _serial_number_type serial_number;
      typedef uint16_t _serial_number_raw_0_type;
      _serial_number_raw_0_type serial_number_raw_0;
      typedef uint16_t _serial_number_raw_1_type;
      _serial_number_raw_1_type serial_number_raw_1;
      typedef const char* _fpga_time_stamp_type;
      _fpga_time_stamp_type fpga_time_stamp;
      typedef const char* _dsp_time_stamp_type;
      _dsp_time_stamp_type dsp_time_stamp;

    IbeoStatus():
      header(),
      firmware_version(0),
      firmware_version_str(""),
      fpga_version(0),
      fpga_version_str(""),
      scanner_status_flags(0),
      temperature(0),
      serial_number(""),
      serial_number_raw_0(0),
      serial_number_raw_1(0),
      fpga_time_stamp(""),
      dsp_time_stamp("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->firmware_version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firmware_version >> (8 * 1)) & 0xFF;
      offset += sizeof(this->firmware_version);
      uint32_t length_firmware_version_str = strlen(this->firmware_version_str);
      varToArr(outbuffer + offset, length_firmware_version_str);
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_version_str, length_firmware_version_str);
      offset += length_firmware_version_str;
      *(outbuffer + offset + 0) = (this->fpga_version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fpga_version >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fpga_version);
      uint32_t length_fpga_version_str = strlen(this->fpga_version_str);
      varToArr(outbuffer + offset, length_fpga_version_str);
      offset += 4;
      memcpy(outbuffer + offset, this->fpga_version_str, length_fpga_version_str);
      offset += length_fpga_version_str;
      *(outbuffer + offset + 0) = (this->scanner_status_flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scanner_status_flags >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scanner_status_flags);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      uint32_t length_serial_number = strlen(this->serial_number);
      varToArr(outbuffer + offset, length_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      *(outbuffer + offset + 0) = (this->serial_number_raw_0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial_number_raw_0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->serial_number_raw_0);
      *(outbuffer + offset + 0) = (this->serial_number_raw_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial_number_raw_1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->serial_number_raw_1);
      uint32_t length_fpga_time_stamp = strlen(this->fpga_time_stamp);
      varToArr(outbuffer + offset, length_fpga_time_stamp);
      offset += 4;
      memcpy(outbuffer + offset, this->fpga_time_stamp, length_fpga_time_stamp);
      offset += length_fpga_time_stamp;
      uint32_t length_dsp_time_stamp = strlen(this->dsp_time_stamp);
      varToArr(outbuffer + offset, length_dsp_time_stamp);
      offset += 4;
      memcpy(outbuffer + offset, this->dsp_time_stamp, length_dsp_time_stamp);
      offset += length_dsp_time_stamp;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->firmware_version =  ((uint16_t) (*(inbuffer + offset)));
      this->firmware_version |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->firmware_version);
      uint32_t length_firmware_version_str;
      arrToVar(length_firmware_version_str, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_version_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_version_str-1]=0;
      this->firmware_version_str = (char *)(inbuffer + offset-1);
      offset += length_firmware_version_str;
      this->fpga_version =  ((uint16_t) (*(inbuffer + offset)));
      this->fpga_version |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fpga_version);
      uint32_t length_fpga_version_str;
      arrToVar(length_fpga_version_str, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fpga_version_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fpga_version_str-1]=0;
      this->fpga_version_str = (char *)(inbuffer + offset-1);
      offset += length_fpga_version_str;
      this->scanner_status_flags =  ((uint16_t) (*(inbuffer + offset)));
      this->scanner_status_flags |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scanner_status_flags);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      uint32_t length_serial_number;
      arrToVar(length_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
      this->serial_number_raw_0 =  ((uint16_t) (*(inbuffer + offset)));
      this->serial_number_raw_0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->serial_number_raw_0);
      this->serial_number_raw_1 =  ((uint16_t) (*(inbuffer + offset)));
      this->serial_number_raw_1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->serial_number_raw_1);
      uint32_t length_fpga_time_stamp;
      arrToVar(length_fpga_time_stamp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fpga_time_stamp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fpga_time_stamp-1]=0;
      this->fpga_time_stamp = (char *)(inbuffer + offset-1);
      offset += length_fpga_time_stamp;
      uint32_t length_dsp_time_stamp;
      arrToVar(length_dsp_time_stamp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dsp_time_stamp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dsp_time_stamp-1]=0;
      this->dsp_time_stamp = (char *)(inbuffer + offset-1);
      offset += length_dsp_time_stamp;
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoStatus"; };
    const char * getMD5(){ return "2fa151f9d5d19e458d9cb33266d0ef1e"; };

  };

}
#endif