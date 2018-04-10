#ifndef _ROS_autonomos_traffic_light_msgs_TrafficLightAnnotations_h
#define _ROS_autonomos_traffic_light_msgs_TrafficLightAnnotations_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_traffic_light_msgs/TrafficLightAnnotation.h"

namespace autonomos_traffic_light_msgs
{

  class TrafficLightAnnotations : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t annotations_length;
      typedef autonomos_traffic_light_msgs::TrafficLightAnnotation _annotations_type;
      _annotations_type st_annotations;
      _annotations_type * annotations;

    TrafficLightAnnotations():
      header(),
      annotations_length(0), annotations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->annotations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->annotations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->annotations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->annotations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->annotations_length);
      for( uint32_t i = 0; i < annotations_length; i++){
      offset += this->annotations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t annotations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->annotations_length);
      if(annotations_lengthT > annotations_length)
        this->annotations = (autonomos_traffic_light_msgs::TrafficLightAnnotation*)realloc(this->annotations, annotations_lengthT * sizeof(autonomos_traffic_light_msgs::TrafficLightAnnotation));
      annotations_length = annotations_lengthT;
      for( uint32_t i = 0; i < annotations_length; i++){
      offset += this->st_annotations.deserialize(inbuffer + offset);
        memcpy( &(this->annotations[i]), &(this->st_annotations), sizeof(autonomos_traffic_light_msgs::TrafficLightAnnotation));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/TrafficLightAnnotations"; };
    const char * getMD5(){ return "94c414044a04ca1e27d7567a16a5f557"; };

  };

}
#endif