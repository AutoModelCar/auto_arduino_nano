#ifndef _ROS_autonomos_vehicle_msgs_PlanarEgoState_h
#define _ROS_autonomos_vehicle_msgs_PlanarEgoState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class PlanarEgoState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _heading_type;
      _heading_type heading;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;

    PlanarEgoState():
      header(),
      x(0),
      y(0),
      speed(0),
      heading(0),
      yaw_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->heading);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heading));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_rate));
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/PlanarEgoState"; };
    const char * getMD5(){ return "205ebd6d8537d48161cb1270ff074044"; };

  };

}
#endif