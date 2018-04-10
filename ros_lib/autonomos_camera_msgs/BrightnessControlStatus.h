#ifndef _ROS_autonomos_camera_msgs_BrightnessControlStatus_h
#define _ROS_autonomos_camera_msgs_BrightnessControlStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace autonomos_camera_msgs
{

  class BrightnessControlStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _histogram_median_type;
      _histogram_median_type histogram_median;
      typedef ros::Duration _shutter_time_type;
      _shutter_time_type shutter_time;
      typedef float _analog_gain_factor_type;
      _analog_gain_factor_type analog_gain_factor;

    BrightnessControlStatus():
      header(),
      histogram_median(0),
      shutter_time(),
      analog_gain_factor(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_histogram_median;
      u_histogram_median.real = this->histogram_median;
      *(outbuffer + offset + 0) = (u_histogram_median.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_histogram_median.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_histogram_median.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_histogram_median.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->histogram_median);
      *(outbuffer + offset + 0) = (this->shutter_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shutter_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shutter_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shutter_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter_time.sec);
      *(outbuffer + offset + 0) = (this->shutter_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shutter_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shutter_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shutter_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_analog_gain_factor;
      u_analog_gain_factor.real = this->analog_gain_factor;
      *(outbuffer + offset + 0) = (u_analog_gain_factor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analog_gain_factor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_analog_gain_factor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_analog_gain_factor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_gain_factor);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_histogram_median;
      u_histogram_median.base = 0;
      u_histogram_median.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_histogram_median.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_histogram_median.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_histogram_median.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->histogram_median = u_histogram_median.real;
      offset += sizeof(this->histogram_median);
      this->shutter_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->shutter_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->shutter_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->shutter_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->shutter_time.sec);
      this->shutter_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->shutter_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->shutter_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->shutter_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->shutter_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_analog_gain_factor;
      u_analog_gain_factor.base = 0;
      u_analog_gain_factor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_analog_gain_factor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_analog_gain_factor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_analog_gain_factor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->analog_gain_factor = u_analog_gain_factor.real;
      offset += sizeof(this->analog_gain_factor);
     return offset;
    }

    const char * getType(){ return "autonomos_camera_msgs/BrightnessControlStatus"; };
    const char * getMD5(){ return "b9b16980a91a80ac0a3a708d4f241ce8"; };

  };

}
#endif