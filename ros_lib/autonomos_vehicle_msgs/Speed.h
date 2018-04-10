#ifndef _ROS_autonomos_vehicle_msgs_Speed_h
#define _ROS_autonomos_vehicle_msgs_Speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class Speed : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _value_type;
      _value_type value;

    Speed():
      header(),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/Speed"; };
    const char * getMD5(){ return "d053817de0764f9ee90dbc89c4cdd751"; };

  };

}
#endif