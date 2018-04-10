#ifndef _ROS_autonomos_ibeo_msgs_IbeoObjects_h
#define _ROS_autonomos_ibeo_msgs_IbeoObjects_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_ibeo_msgs/IbeoObject.h"

namespace autonomos_ibeo_msgs
{

  class IbeoObjects : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _type_id_type;
      _type_id_type type_id;
      uint32_t objects_length;
      typedef autonomos_ibeo_msgs::IbeoObject _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    IbeoObjects():
      header(),
      type_id(0),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->type_id);
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
      this->type_id =  ((uint16_t) (*(inbuffer + offset)));
      this->type_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->type_id);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (autonomos_ibeo_msgs::IbeoObject*)realloc(this->objects, objects_lengthT * sizeof(autonomos_ibeo_msgs::IbeoObject));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(autonomos_ibeo_msgs::IbeoObject));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoObjects"; };
    const char * getMD5(){ return "f36dd01c55bd5e5efd30050013f46925"; };

  };

}
#endif