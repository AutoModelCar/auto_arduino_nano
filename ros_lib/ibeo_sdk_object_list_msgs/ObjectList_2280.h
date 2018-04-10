#ifndef _ROS_ibeo_sdk_object_list_msgs_ObjectList_2280_h
#define _ROS_ibeo_sdk_object_list_msgs_ObjectList_2280_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2280.h"
#include "ibeo_sdk_object_msgs/Object_2280.h"

namespace ibeo_sdk_object_list_msgs
{

  class ObjectList_2280 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ibeo_sdk_time_msgs::NTP64_2280 _timestamp_type;
      _timestamp_type timestamp;
      typedef uint8_t _num_objects_type;
      _num_objects_type num_objects;
      uint32_t objects_length;
      typedef ibeo_sdk_object_msgs::Object_2280 _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    ObjectList_2280():
      header(),
      timestamp(),
      num_objects(0),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->timestamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_objects >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_objects);
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
      offset += this->timestamp.deserialize(inbuffer + offset);
      this->num_objects =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_objects);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (ibeo_sdk_object_msgs::Object_2280*)realloc(this->objects, objects_lengthT * sizeof(ibeo_sdk_object_msgs::Object_2280));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(ibeo_sdk_object_msgs::Object_2280));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_list_msgs/ObjectList_2280"; };
    const char * getMD5(){ return "254c4b46cd77c14b0ba1f0ad43b693b8"; };

  };

}
#endif