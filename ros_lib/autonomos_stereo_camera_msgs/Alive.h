#ifndef _ROS_autonomos_stereo_camera_msgs_Alive_h
#define _ROS_autonomos_stereo_camera_msgs_Alive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_stereo_camera_msgs
{

  class Alive : public ros::Msg
  {
    public:
      typedef uint32_t _alive_type;
      _alive_type alive;

    Alive():
      alive(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->alive >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alive >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alive >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alive >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alive);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->alive =  ((uint32_t) (*(inbuffer + offset)));
      this->alive |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->alive |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->alive |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->alive);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/Alive"; };
    const char * getMD5(){ return "15556f9f7857ad57312c2ce542c250e1"; };

  };

}
#endif