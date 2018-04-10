#ifndef _ROS_autonomos_vehicle_msgs_DrivingModes_h
#define _ROS_autonomos_vehicle_msgs_DrivingModes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_vehicle_msgs/DrivingMode.h"

namespace autonomos_vehicle_msgs
{

  class DrivingModes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autonomos_vehicle_msgs::DrivingMode _software_type;
      _software_type software;
      typedef autonomos_vehicle_msgs::DrivingMode _hardware_type;
      _hardware_type hardware;

    DrivingModes():
      header(),
      software(),
      hardware()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->software.serialize(outbuffer + offset);
      offset += this->hardware.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->software.deserialize(inbuffer + offset);
      offset += this->hardware.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/DrivingModes"; };
    const char * getMD5(){ return "4c1b079333b5606d1da26ec1260472fd"; };

  };

}
#endif