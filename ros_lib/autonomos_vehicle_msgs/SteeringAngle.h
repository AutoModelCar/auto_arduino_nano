#ifndef _ROS_autonomos_vehicle_msgs_SteeringAngle_h
#define _ROS_autonomos_vehicle_msgs_SteeringAngle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class SteeringAngle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _steering_angle_type;
      _steering_angle_type steering_angle;

    SteeringAngle():
      header(),
      steering_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_steering_angle;
      u_steering_angle.real = this->steering_angle;
      *(outbuffer + offset + 0) = (u_steering_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_steering_angle;
      u_steering_angle.base = 0;
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_angle = u_steering_angle.real;
      offset += sizeof(this->steering_angle);
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/SteeringAngle"; };
    const char * getMD5(){ return "ab7b1e5a2c2ec7531126b10c3c9e22ad"; };

  };

}
#endif