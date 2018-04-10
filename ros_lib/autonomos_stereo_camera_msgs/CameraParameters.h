#ifndef _ROS_autonomos_stereo_camera_msgs_CameraParameters_h
#define _ROS_autonomos_stereo_camera_msgs_CameraParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_stereo_camera_msgs/KeyValue.h"

namespace autonomos_stereo_camera_msgs
{

  class CameraParameters : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t parameters_length;
      typedef autonomos_stereo_camera_msgs::KeyValue _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    CameraParameters():
      header(),
      parameters_length(0), parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameters_length);
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameters_length);
      if(parameters_lengthT > parameters_length)
        this->parameters = (autonomos_stereo_camera_msgs::KeyValue*)realloc(this->parameters, parameters_lengthT * sizeof(autonomos_stereo_camera_msgs::KeyValue));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(autonomos_stereo_camera_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/CameraParameters"; };
    const char * getMD5(){ return "f3f1feb5a68d7c7a3bb2d072bd8b724e"; };

  };

}
#endif