#ifndef _ROS_ibeo_sdk_scan_point_msgs_ScanPoint_2205_h
#define _ROS_ibeo_sdk_scan_point_msgs_ScanPoint_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_scan_point_msgs/ScanPointFlags_2205.h"

namespace ibeo_sdk_scan_point_msgs
{

  class ScanPoint_2205 : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _echo_width_type;
      _echo_width_type echo_width;
      typedef uint8_t _device_ID_type;
      _device_ID_type device_ID;
      typedef uint8_t _layer_type;
      _layer_type layer;
      typedef uint8_t _echo_type;
      _echo_type echo;
      typedef uint8_t _reserved_type;
      _reserved_type reserved;
      typedef uint32_t _time_offset_micro_sec_type;
      _time_offset_micro_sec_type time_offset_micro_sec;
      typedef ibeo_sdk_scan_point_msgs::ScanPointFlags_2205 _flags_type;
      _flags_type flags;
      typedef uint16_t _segment_ID_type;
      _segment_ID_type segment_ID;

    ScanPoint_2205():
      x(0),
      y(0),
      z(0),
      echo_width(0),
      device_ID(0),
      layer(0),
      echo(0),
      reserved(0),
      time_offset_micro_sec(0),
      flags(),
      segment_ID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_echo_width;
      u_echo_width.real = this->echo_width;
      *(outbuffer + offset + 0) = (u_echo_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_echo_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_echo_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_echo_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->echo_width);
      *(outbuffer + offset + 0) = (this->device_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->device_ID);
      *(outbuffer + offset + 0) = (this->layer >> (8 * 0)) & 0xFF;
      offset += sizeof(this->layer);
      *(outbuffer + offset + 0) = (this->echo >> (8 * 0)) & 0xFF;
      offset += sizeof(this->echo);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved);
      *(outbuffer + offset + 0) = (this->time_offset_micro_sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_offset_micro_sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_offset_micro_sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_offset_micro_sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_offset_micro_sec);
      offset += this->flags.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->segment_ID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segment_ID >> (8 * 1)) & 0xFF;
      offset += sizeof(this->segment_ID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_echo_width;
      u_echo_width.base = 0;
      u_echo_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_echo_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_echo_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_echo_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->echo_width = u_echo_width.real;
      offset += sizeof(this->echo_width);
      this->device_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->device_ID);
      this->layer =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->layer);
      this->echo =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->echo);
      this->reserved =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved);
      this->time_offset_micro_sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_offset_micro_sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_offset_micro_sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_offset_micro_sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_offset_micro_sec);
      offset += this->flags.deserialize(inbuffer + offset);
      this->segment_ID =  ((uint16_t) (*(inbuffer + offset)));
      this->segment_ID |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->segment_ID);
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_scan_point_msgs/ScanPoint_2205"; };
    const char * getMD5(){ return "607013b5cf895e61ff8ff1cde648eaa2"; };

  };

}
#endif