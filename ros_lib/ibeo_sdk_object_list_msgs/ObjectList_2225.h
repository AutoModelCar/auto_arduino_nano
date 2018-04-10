#ifndef _ROS_ibeo_sdk_object_list_msgs_ObjectList_2225_h
#define _ROS_ibeo_sdk_object_list_msgs_ObjectList_2225_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2225.h"
#include "ibeo_sdk_object_msgs/Object_2225.h"

namespace ibeo_sdk_object_list_msgs
{

  class ObjectList_2225 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ibeo_sdk_time_msgs::NTP64_2225 _creation_time_type;
      _creation_time_type creation_time;
      typedef uint16_t _num_objects_type;
      _num_objects_type num_objects;
      uint32_t objects_length;
      typedef ibeo_sdk_object_msgs::Object_2225 _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    ObjectList_2225():
      header(),
      creation_time(),
      num_objects(0),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->creation_time.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_objects >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_objects >> (8 * 1)) & 0xFF;
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
      offset += this->creation_time.deserialize(inbuffer + offset);
      this->num_objects =  ((uint16_t) (*(inbuffer + offset)));
      this->num_objects |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->num_objects);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (ibeo_sdk_object_msgs::Object_2225*)realloc(this->objects, objects_lengthT * sizeof(ibeo_sdk_object_msgs::Object_2225));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(ibeo_sdk_object_msgs::Object_2225));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_list_msgs/ObjectList_2225"; };
    const char * getMD5(){ return "02c1139669c9f767186e0f9ce9bc57d6"; };

  };

}
#endif