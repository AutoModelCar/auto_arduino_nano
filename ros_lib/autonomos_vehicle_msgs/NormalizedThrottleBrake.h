#ifndef _ROS_autonomos_vehicle_msgs_NormalizedThrottleBrake_h
#define _ROS_autonomos_vehicle_msgs_NormalizedThrottleBrake_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_vehicle_msgs
{

  class NormalizedThrottleBrake : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _normalized_throttle_type;
      _normalized_throttle_type normalized_throttle;
      typedef float _normalized_brake_type;
      _normalized_brake_type normalized_brake;

    NormalizedThrottleBrake():
      header(),
      normalized_throttle(0),
      normalized_brake(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->normalized_throttle);
      offset += serializeAvrFloat64(outbuffer + offset, this->normalized_brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->normalized_throttle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->normalized_brake));
     return offset;
    }

    const char * getType(){ return "autonomos_vehicle_msgs/NormalizedThrottleBrake"; };
    const char * getMD5(){ return "9fea523cf8335eb8dc22f9d843fef3ca"; };

  };

}
#endif