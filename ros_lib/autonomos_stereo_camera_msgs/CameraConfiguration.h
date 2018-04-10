#ifndef _ROS_autonomos_stereo_camera_msgs_CameraConfiguration_h
#define _ROS_autonomos_stereo_camera_msgs_CameraConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_stereo_camera_msgs/ConnectionConfiguration.h"
#include "autonomos_stereo_camera_msgs/StereoConfiguration.h"

namespace autonomos_stereo_camera_msgs
{

  class CameraConfiguration : public ros::Msg
  {
    public:
      typedef autonomos_stereo_camera_msgs::ConnectionConfiguration _connection_type;
      _connection_type connection;
      uint32_t stereo_configuration_length;
      typedef autonomos_stereo_camera_msgs::StereoConfiguration _stereo_configuration_type;
      _stereo_configuration_type st_stereo_configuration;
      _stereo_configuration_type * stereo_configuration;

    CameraConfiguration():
      connection(),
      stereo_configuration_length(0), stereo_configuration(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->connection.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->stereo_configuration_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stereo_configuration_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stereo_configuration_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stereo_configuration_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stereo_configuration_length);
      for( uint32_t i = 0; i < stereo_configuration_length; i++){
      offset += this->stereo_configuration[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->connection.deserialize(inbuffer + offset);
      uint32_t stereo_configuration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stereo_configuration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stereo_configuration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stereo_configuration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stereo_configuration_length);
      if(stereo_configuration_lengthT > stereo_configuration_length)
        this->stereo_configuration = (autonomos_stereo_camera_msgs::StereoConfiguration*)realloc(this->stereo_configuration, stereo_configuration_lengthT * sizeof(autonomos_stereo_camera_msgs::StereoConfiguration));
      stereo_configuration_length = stereo_configuration_lengthT;
      for( uint32_t i = 0; i < stereo_configuration_length; i++){
      offset += this->st_stereo_configuration.deserialize(inbuffer + offset);
        memcpy( &(this->stereo_configuration[i]), &(this->st_stereo_configuration), sizeof(autonomos_stereo_camera_msgs::StereoConfiguration));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/CameraConfiguration"; };
    const char * getMD5(){ return "581558beacc615673114ab68babc6954"; };

  };

}
#endif