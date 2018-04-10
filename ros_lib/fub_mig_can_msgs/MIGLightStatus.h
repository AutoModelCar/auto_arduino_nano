#ifndef _ROS_fub_mig_can_msgs_MIGLightStatus_h
#define _ROS_fub_mig_can_msgs_MIGLightStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_mig_can_msgs
{

  class MIGLightStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _parking_light_type;
      _parking_light_type parking_light;
      typedef bool _low_beam_type;
      _low_beam_type low_beam;
      typedef bool _warning_lights_type;
      _warning_lights_type warning_lights;
      typedef uint8_t _message_counter_type;
      _message_counter_type message_counter;
      enum { can_id =  1329  };
      enum { can_dlc =     4 };

    MIGLightStatus():
      header(),
      parking_light(0),
      low_beam(0),
      warning_lights(0),
      message_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_parking_light;
      u_parking_light.real = this->parking_light;
      *(outbuffer + offset + 0) = (u_parking_light.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_light);
      union {
        bool real;
        uint8_t base;
      } u_low_beam;
      u_low_beam.real = this->low_beam;
      *(outbuffer + offset + 0) = (u_low_beam.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_beam);
      union {
        bool real;
        uint8_t base;
      } u_warning_lights;
      u_warning_lights.real = this->warning_lights;
      *(outbuffer + offset + 0) = (u_warning_lights.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->warning_lights);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->message_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_parking_light;
      u_parking_light.base = 0;
      u_parking_light.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_light = u_parking_light.real;
      offset += sizeof(this->parking_light);
      union {
        bool real;
        uint8_t base;
      } u_low_beam;
      u_low_beam.base = 0;
      u_low_beam.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_beam = u_low_beam.real;
      offset += sizeof(this->low_beam);
      union {
        bool real;
        uint8_t base;
      } u_warning_lights;
      u_warning_lights.base = 0;
      u_warning_lights.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->warning_lights = u_warning_lights.real;
      offset += sizeof(this->warning_lights);
      this->message_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->message_counter);
     return offset;
    }

    const char * getType(){ return "fub_mig_can_msgs/MIGLightStatus"; };
    const char * getMD5(){ return "07fad3467af1e5220f9fa02f4c416a68"; };

  };

}
#endif