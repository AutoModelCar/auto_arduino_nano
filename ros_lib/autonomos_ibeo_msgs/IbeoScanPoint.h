#ifndef _ROS_autonomos_ibeo_msgs_IbeoScanPoint_h
#define _ROS_autonomos_ibeo_msgs_IbeoScanPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace autonomos_ibeo_msgs
{

  class IbeoScanPoint : public ros::Msg
  {
    public:
      typedef uint8_t _device_type;
      _device_type device;
      typedef uint8_t _layer_type;
      _layer_type layer;
      typedef uint8_t _echo_type;
      _echo_type echo;
      typedef float _timestamp_type;
      _timestamp_type timestamp;
      typedef uint16_t _classification_flags_type;
      _classification_flags_type classification_flags;
      typedef float _echo_width_type;
      _echo_width_type echo_width;
      typedef geometry_msgs::Point32 _point_type;
      _point_type point;
      enum { GROUND =     1  };
      enum { DIRT =     2  };
      enum { ATMOSPHERIC =     4  };
      enum { FLAG_ROAD_MARKING =     8  };
      enum { FLAG_CURBSTONE =   128  };
      enum { FLAG_GUARD_RAIL =   136  };
      enum { TRANSPARENT =  4096  };

    IbeoScanPoint():
      device(0),
      layer(0),
      echo(0),
      timestamp(0),
      classification_flags(0),
      echo_width(0),
      point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->device >> (8 * 0)) & 0xFF;
      offset += sizeof(this->device);
      *(outbuffer + offset + 0) = (this->layer >> (8 * 0)) & 0xFF;
      offset += sizeof(this->layer);
      *(outbuffer + offset + 0) = (this->echo >> (8 * 0)) & 0xFF;
      offset += sizeof(this->echo);
      union {
        float real;
        uint32_t base;
      } u_timestamp;
      u_timestamp.real = this->timestamp;
      *(outbuffer + offset + 0) = (u_timestamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestamp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp);
      *(outbuffer + offset + 0) = (this->classification_flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_flags >> (8 * 1)) & 0xFF;
      offset += sizeof(this->classification_flags);
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
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->device =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->device);
      this->layer =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->layer);
      this->echo =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->echo);
      union {
        float real;
        uint32_t base;
      } u_timestamp;
      u_timestamp.base = 0;
      u_timestamp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestamp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestamp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestamp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timestamp = u_timestamp.real;
      offset += sizeof(this->timestamp);
      this->classification_flags =  ((uint16_t) (*(inbuffer + offset)));
      this->classification_flags |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->classification_flags);
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
      offset += this->point.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoScanPoint"; };
    const char * getMD5(){ return "95aac7f721dbe0feff033112ac550f41"; };

  };

}
#endif