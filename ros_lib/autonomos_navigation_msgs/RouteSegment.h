#ifndef _ROS_autonomos_navigation_msgs_RouteSegment_h
#define _ROS_autonomos_navigation_msgs_RouteSegment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_navigation_msgs/WeightedLane.h"

namespace autonomos_navigation_msgs
{

  class RouteSegment : public ros::Msg
  {
    public:
      typedef uint64_t _roadsection_id_type;
      _roadsection_id_type roadsection_id;
      uint32_t lanes_length;
      typedef autonomos_navigation_msgs::WeightedLane _lanes_type;
      _lanes_type st_lanes;
      _lanes_type * lanes;

    RouteSegment():
      roadsection_id(0),
      lanes_length(0), lanes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.real = this->roadsection_id;
      *(outbuffer + offset + 0) = (u_roadsection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roadsection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roadsection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roadsection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roadsection_id);
      *(outbuffer + offset + 0) = (this->lanes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lanes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lanes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lanes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lanes_length);
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->lanes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.base = 0;
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roadsection_id = u_roadsection_id.real;
      offset += sizeof(this->roadsection_id);
      uint32_t lanes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lanes_length);
      if(lanes_lengthT > lanes_length)
        this->lanes = (autonomos_navigation_msgs::WeightedLane*)realloc(this->lanes, lanes_lengthT * sizeof(autonomos_navigation_msgs::WeightedLane));
      lanes_length = lanes_lengthT;
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->st_lanes.deserialize(inbuffer + offset);
        memcpy( &(this->lanes[i]), &(this->st_lanes), sizeof(autonomos_navigation_msgs::WeightedLane));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_navigation_msgs/RouteSegment"; };
    const char * getMD5(){ return "bab3f2614f89a3ff9dc440694471359e"; };

  };

}
#endif