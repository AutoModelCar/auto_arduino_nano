#ifndef _ROS_autonomos_lane_msgs_Lanes_h
#define _ROS_autonomos_lane_msgs_Lanes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_lane_msgs/Lane.h"

namespace autonomos_lane_msgs
{

  class Lanes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t lanes_length;
      typedef autonomos_lane_msgs::Lane _lanes_type;
      _lanes_type st_lanes;
      _lanes_type * lanes;

    Lanes():
      header(),
      lanes_length(0), lanes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t lanes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lanes_length);
      if(lanes_lengthT > lanes_length)
        this->lanes = (autonomos_lane_msgs::Lane*)realloc(this->lanes, lanes_lengthT * sizeof(autonomos_lane_msgs::Lane));
      lanes_length = lanes_lengthT;
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->st_lanes.deserialize(inbuffer + offset);
        memcpy( &(this->lanes[i]), &(this->st_lanes), sizeof(autonomos_lane_msgs::Lane));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_lane_msgs/Lanes"; };
    const char * getMD5(){ return "cd249b9b16672ba8cd0c2cdfa156aada"; };

  };

}
#endif