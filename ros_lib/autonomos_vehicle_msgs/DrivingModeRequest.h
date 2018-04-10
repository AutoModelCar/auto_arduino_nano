#ifndef _ROS_SERVICE_DrivingModeRequest_h
#define _ROS_SERVICE_DrivingModeRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_vehicle_msgs
{

static const char DRIVINGMODEREQUEST[] = "autonomos_vehicle_msgs/DrivingModeRequest";

  class DrivingModeRequestRequest : public ros::Msg
  {
    public:
      typedef uint8_t _requested_mode_type;
      _requested_mode_type requested_mode;
      enum { MODE_MANUAL =  1 };
      enum { MODE_AUTONOMOUS =  2 };

    DrivingModeRequestRequest():
      requested_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->requested_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->requested_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->requested_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->requested_mode);
     return offset;
    }

    const char * getType(){ return DRIVINGMODEREQUEST; };
    const char * getMD5(){ return "38e626e1b8bf21fb49e9d4ccf268b54e"; };

  };

  class DrivingModeRequestResponse : public ros::Msg
  {
    public:

    DrivingModeRequestResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return DRIVINGMODEREQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DrivingModeRequest {
    public:
    typedef DrivingModeRequestRequest Request;
    typedef DrivingModeRequestResponse Response;
  };

}
#endif
