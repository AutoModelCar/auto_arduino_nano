#ifndef _ROS_ibeo_sdk_scanner_resolution_info_msgs_ScannerResolutionInfo_2205_h
#define _ROS_ibeo_sdk_scanner_resolution_info_msgs_ScannerResolutionInfo_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ibeo_sdk_scanner_resolution_info_msgs
{

  class ScannerResolutionInfo_2205 : public ros::Msg
  {
    public:
      typedef float _resolution_start_angle_type;
      _resolution_start_angle_type resolution_start_angle;
      typedef float _resolution_value_type;
      _resolution_value_type resolution_value;

    ScannerResolutionInfo_2205():
      resolution_start_angle(0),
      resolution_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_resolution_start_angle;
      u_resolution_start_angle.real = this->resolution_start_angle;
      *(outbuffer + offset + 0) = (u_resolution_start_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution_start_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution_start_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution_start_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution_start_angle);
      union {
        float real;
        uint32_t base;
      } u_resolution_value;
      u_resolution_value.real = this->resolution_value;
      *(outbuffer + offset + 0) = (u_resolution_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_resolution_start_angle;
      u_resolution_start_angle.base = 0;
      u_resolution_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution_start_angle = u_resolution_start_angle.real;
      offset += sizeof(this->resolution_start_angle);
      union {
        float real;
        uint32_t base;
      } u_resolution_value;
      u_resolution_value.base = 0;
      u_resolution_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution_value = u_resolution_value.real;
      offset += sizeof(this->resolution_value);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_scanner_resolution_info_msgs/ScannerResolutionInfo_2205"; };
    const char * getMD5(){ return "2132e5f13dcb4b446b5d30c3ecc34787"; };

  };

}
#endif