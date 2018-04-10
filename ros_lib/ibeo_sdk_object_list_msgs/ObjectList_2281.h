#ifndef _ROS_ibeo_sdk_object_list_msgs_ObjectList_2281_h
#define _ROS_ibeo_sdk_object_list_msgs_ObjectList_2281_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2225.h"
#include "ibeo_sdk_object_list_msgs/DeviceType.h"
#include "ibeo_sdk_object_msgs/Object_2281.h"

namespace ibeo_sdk_object_list_msgs
{

  class ObjectList_2281 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ibeo_sdk_time_msgs::NTP64_2225 _timestamp_type;
      _timestamp_type timestamp;
      typedef uint8_t _object_list_id_type;
      _object_list_id_type object_list_id;
      typedef ibeo_sdk_object_list_msgs::DeviceType _device_type_type;
      _device_type_type device_type;
      typedef uint16_t _device_interface_version_type;
      _device_interface_version_type device_interface_version;
      typedef uint8_t _flags_type;
      _flags_type flags;
      typedef uint8_t _reserved_type;
      _reserved_type reserved;
      typedef uint8_t _num_objects_type;
      _num_objects_type num_objects;
      uint32_t objects_length;
      typedef ibeo_sdk_object_msgs::Object_2281 _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    ObjectList_2281():
      header(),
      timestamp(),
      object_list_id(0),
      device_type(),
      device_interface_version(0),
      flags(0),
      reserved(0),
      num_objects(0),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->timestamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->object_list_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_list_id);
      offset += this->device_type.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->device_interface_version >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->device_interface_version >> (8 * 1)) & 0xFF;
      offset += sizeof(this->device_interface_version);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved);
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
      this->object_list_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_list_id);
      offset += this->device_type.deserialize(inbuffer + offset);
      this->device_interface_version =  ((uint16_t) (*(inbuffer + offset)));
      this->device_interface_version |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->device_interface_version);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
      this->reserved =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved);
      this->num_objects =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_objects);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (ibeo_sdk_object_msgs::Object_2281*)realloc(this->objects, objects_lengthT * sizeof(ibeo_sdk_object_msgs::Object_2281));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(ibeo_sdk_object_msgs::Object_2281));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_object_list_msgs/ObjectList_2281"; };
    const char * getMD5(){ return "43aafc20670d246bccfe8fa082ad4af3"; };

  };

}
#endif