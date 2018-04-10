#ifndef _ROS_autonomos_hella_swa_msgs_HellaSWAObjects_h
#define _ROS_autonomos_hella_swa_msgs_HellaSWAObjects_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_hella_swa_msgs/HellaSWAObject.h"

namespace autonomos_hella_swa_msgs
{

  class HellaSWAObjects : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _message_counter_type;
      _message_counter_type message_counter;
      typedef uint8_t _number_of_objects_type;
      _number_of_objects_type number_of_objects;
      typedef uint8_t _number_of_messages_type;
      _number_of_messages_type number_of_messages;
      typedef uint8_t _t_scan_type;
      _t_scan_type t_scan;
      typedef uint8_t _spare_type;
      _spare_type spare;
      uint32_t objects_length;
      typedef autonomos_hella_swa_msgs::HellaSWAObject _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    HellaSWAObjects():
      header(),
      message_counter(0),
      number_of_objects(0),
      number_of_messages(0),
      t_scan(0),
      spare(0),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->message_counter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->message_counter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->message_counter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->message_counter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->message_counter);
      *(outbuffer + offset + 0) = (this->number_of_objects >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_objects);
      *(outbuffer + offset + 0) = (this->number_of_messages >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number_of_messages);
      *(outbuffer + offset + 0) = (this->t_scan >> (8 * 0)) & 0xFF;
      offset += sizeof(this->t_scan);
      *(outbuffer + offset + 0) = (this->spare >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spare);
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
      this->message_counter =  ((uint32_t) (*(inbuffer + offset)));
      this->message_counter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->message_counter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->message_counter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->message_counter);
      this->number_of_objects =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number_of_objects);
      this->number_of_messages =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number_of_messages);
      this->t_scan =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->t_scan);
      this->spare =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->spare);
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (autonomos_hella_swa_msgs::HellaSWAObject*)realloc(this->objects, objects_lengthT * sizeof(autonomos_hella_swa_msgs::HellaSWAObject));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(autonomos_hella_swa_msgs::HellaSWAObject));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_hella_swa_msgs/HellaSWAObjects"; };
    const char * getMD5(){ return "73e7375259eb1bf9416eb74ab47234c8"; };

  };

}
#endif