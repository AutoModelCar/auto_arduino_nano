#ifndef _ROS_autonomos_sms_radar_msgs_SmsRawObjects_h
#define _ROS_autonomos_sms_radar_msgs_SmsRawObjects_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_sms_radar_msgs/SmsSensorControlRaw.h"
#include "autonomos_sms_radar_msgs/SmsRawObject.h"

namespace autonomos_sms_radar_msgs
{

  class SmsRawObjects : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef autonomos_sms_radar_msgs::SmsSensorControlRaw _control_message_type;
      _control_message_type control_message;
      uint32_t objects_length;
      typedef autonomos_sms_radar_msgs::SmsRawObject _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    SmsRawObjects():
      header(),
      control_message(),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->control_message.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objects_length);
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->control_message.deserialize(inbuffer + offset);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (autonomos_sms_radar_msgs::SmsRawObject*)realloc(this->objects, objects_lengthT * sizeof(autonomos_sms_radar_msgs::SmsRawObject));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(autonomos_sms_radar_msgs::SmsRawObject));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_sms_radar_msgs/SmsRawObjects"; };
    const char * getMD5(){ return "ce16275e2437ac36788415096a093363"; };

  };

}
#endif