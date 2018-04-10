#ifndef _ROS_autonomos_ibeo_msgs_IbeoScannerResolution_h
#define _ROS_autonomos_ibeo_msgs_IbeoScannerResolution_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_ibeo_msgs
{

  class IbeoScannerResolution : public ros::Msg
  {
    public:
      typedef float _start_angle_type;
      _start_angle_type start_angle;
      typedef float _resolution_type;
      _resolution_type resolution;

    IbeoScannerResolution():
      start_angle(0),
      resolution(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_start_angle;
      u_start_angle.real = this->start_angle;
      *(outbuffer + offset + 0) = (u_start_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_angle);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_start_angle;
      u_start_angle.base = 0;
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_angle = u_start_angle.real;
      offset += sizeof(this->start_angle);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoScannerResolution"; };
    const char * getMD5(){ return "3af828db9d8981d243065600276f2aaa"; };

  };

}
#endif