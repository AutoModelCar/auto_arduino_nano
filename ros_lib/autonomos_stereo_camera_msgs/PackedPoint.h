#ifndef _ROS_autonomos_stereo_camera_msgs_PackedPoint_h
#define _ROS_autonomos_stereo_camera_msgs_PackedPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_stereo_camera_msgs
{

  class PackedPoint : public ros::Msg
  {
    public:
      typedef int8_t _x_type;
      _x_type x;
      typedef int8_t _y_type;
      _y_type y;
      typedef int8_t _z_type;
      _z_type z;

    PackedPoint():
      x(0),
      y(0),
      z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int8_t real;
        uint8_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int8_t real;
        uint8_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z = u_z.real;
      offset += sizeof(this->z);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/PackedPoint"; };
    const char * getMD5(){ return "e3b3550bf345aadb2563e9a375d770b6"; };

  };

}
#endif