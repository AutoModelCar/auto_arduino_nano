#ifndef _ROS_autonomos_stereo_camera_msgs_StereoConfiguration_h
#define _ROS_autonomos_stereo_camera_msgs_StereoConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_stereo_camera_msgs
{

  class StereoConfiguration : public ros::Msg
  {
    public:
      typedef int16_t _disparityRate_type;
      _disparityRate_type disparityRate;
      typedef int16_t _pointcloudRate_type;
      _pointcloudRate_type pointcloudRate;
      typedef int16_t _rowDownsamplingSize_type;
      _rowDownsamplingSize_type rowDownsamplingSize;
      typedef int16_t _colDownsamplingSize_type;
      _colDownsamplingSize_type colDownsamplingSize;
      typedef int16_t _leftImageRate_type;
      _leftImageRate_type leftImageRate;
      typedef int16_t _rightImageRate_type;
      _rightImageRate_type rightImageRate;

    StereoConfiguration():
      disparityRate(0),
      pointcloudRate(0),
      rowDownsamplingSize(0),
      colDownsamplingSize(0),
      leftImageRate(0),
      rightImageRate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_disparityRate;
      u_disparityRate.real = this->disparityRate;
      *(outbuffer + offset + 0) = (u_disparityRate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_disparityRate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->disparityRate);
      union {
        int16_t real;
        uint16_t base;
      } u_pointcloudRate;
      u_pointcloudRate.real = this->pointcloudRate;
      *(outbuffer + offset + 0) = (u_pointcloudRate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pointcloudRate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pointcloudRate);
      union {
        int16_t real;
        uint16_t base;
      } u_rowDownsamplingSize;
      u_rowDownsamplingSize.real = this->rowDownsamplingSize;
      *(outbuffer + offset + 0) = (u_rowDownsamplingSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rowDownsamplingSize.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rowDownsamplingSize);
      union {
        int16_t real;
        uint16_t base;
      } u_colDownsamplingSize;
      u_colDownsamplingSize.real = this->colDownsamplingSize;
      *(outbuffer + offset + 0) = (u_colDownsamplingSize.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_colDownsamplingSize.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->colDownsamplingSize);
      union {
        int16_t real;
        uint16_t base;
      } u_leftImageRate;
      u_leftImageRate.real = this->leftImageRate;
      *(outbuffer + offset + 0) = (u_leftImageRate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftImageRate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->leftImageRate);
      union {
        int16_t real;
        uint16_t base;
      } u_rightImageRate;
      u_rightImageRate.real = this->rightImageRate;
      *(outbuffer + offset + 0) = (u_rightImageRate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightImageRate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rightImageRate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_disparityRate;
      u_disparityRate.base = 0;
      u_disparityRate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_disparityRate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->disparityRate = u_disparityRate.real;
      offset += sizeof(this->disparityRate);
      union {
        int16_t real;
        uint16_t base;
      } u_pointcloudRate;
      u_pointcloudRate.base = 0;
      u_pointcloudRate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pointcloudRate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pointcloudRate = u_pointcloudRate.real;
      offset += sizeof(this->pointcloudRate);
      union {
        int16_t real;
        uint16_t base;
      } u_rowDownsamplingSize;
      u_rowDownsamplingSize.base = 0;
      u_rowDownsamplingSize.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rowDownsamplingSize.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rowDownsamplingSize = u_rowDownsamplingSize.real;
      offset += sizeof(this->rowDownsamplingSize);
      union {
        int16_t real;
        uint16_t base;
      } u_colDownsamplingSize;
      u_colDownsamplingSize.base = 0;
      u_colDownsamplingSize.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_colDownsamplingSize.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->colDownsamplingSize = u_colDownsamplingSize.real;
      offset += sizeof(this->colDownsamplingSize);
      union {
        int16_t real;
        uint16_t base;
      } u_leftImageRate;
      u_leftImageRate.base = 0;
      u_leftImageRate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftImageRate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->leftImageRate = u_leftImageRate.real;
      offset += sizeof(this->leftImageRate);
      union {
        int16_t real;
        uint16_t base;
      } u_rightImageRate;
      u_rightImageRate.base = 0;
      u_rightImageRate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightImageRate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rightImageRate = u_rightImageRate.real;
      offset += sizeof(this->rightImageRate);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/StereoConfiguration"; };
    const char * getMD5(){ return "f65671e57bf6763a3af5ef2cfa8c69fa"; };

  };

}
#endif