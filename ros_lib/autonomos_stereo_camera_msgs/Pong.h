#ifndef _ROS_autonomos_stereo_camera_msgs_Pong_h
#define _ROS_autonomos_stereo_camera_msgs_Pong_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace autonomos_stereo_camera_msgs
{

  class Pong : public ros::Msg
  {
    public:
      typedef ros::Time _device_time_type;
      _device_time_type device_time;
      typedef ros::Time _client_sending_time_type;
      _client_sending_time_type client_sending_time;

    Pong():
      device_time(),
      client_sending_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->device_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->device_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->device_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->device_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device_time.sec);
      *(outbuffer + offset + 0) = (this->device_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->device_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->device_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->device_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device_time.nsec);
      *(outbuffer + offset + 0) = (this->client_sending_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->client_sending_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->client_sending_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->client_sending_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->client_sending_time.sec);
      *(outbuffer + offset + 0) = (this->client_sending_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->client_sending_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->client_sending_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->client_sending_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->client_sending_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->device_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->device_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->device_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->device_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->device_time.sec);
      this->device_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->device_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->device_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->device_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->device_time.nsec);
      this->client_sending_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->client_sending_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->client_sending_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->client_sending_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->client_sending_time.sec);
      this->client_sending_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->client_sending_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->client_sending_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->client_sending_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->client_sending_time.nsec);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/Pong"; };
    const char * getMD5(){ return "bb74506ebb2b5a975b44061c1b12eda4"; };

  };

}
#endif