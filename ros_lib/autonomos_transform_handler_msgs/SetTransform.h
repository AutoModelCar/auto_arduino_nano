#ifndef _ROS_SERVICE_SetTransform_h
#define _ROS_SERVICE_SetTransform_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_transform_handler_msgs/Transform.h"

namespace autonomos_transform_handler_msgs
{

static const char SETTRANSFORM[] = "autonomos_transform_handler_msgs/SetTransform";

  class SetTransformRequest : public ros::Msg
  {
    public:
      typedef autonomos_transform_handler_msgs::Transform _transform_type;
      _transform_type transform;
      typedef bool _save_type;
      _save_type save;

    SetTransformRequest():
      transform(),
      save(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->transform.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_save;
      u_save.real = this->save;
      *(outbuffer + offset + 0) = (u_save.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->save);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->transform.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_save;
      u_save.base = 0;
      u_save.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->save = u_save.real;
      offset += sizeof(this->save);
     return offset;
    }

    const char * getType(){ return SETTRANSFORM; };
    const char * getMD5(){ return "d3b2bc190c9cb063bb5fde1f3c93dc8c"; };

  };

  class SetTransformResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetTransformResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETTRANSFORM; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetTransform {
    public:
    typedef SetTransformRequest Request;
    typedef SetTransformResponse Response;
  };

}
#endif
