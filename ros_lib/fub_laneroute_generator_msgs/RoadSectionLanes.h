#ifndef _ROS_fub_laneroute_generator_msgs_RoadSectionLanes_h
#define _ROS_fub_laneroute_generator_msgs_RoadSectionLanes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fub_laneroute_generator_msgs/RoadSectionLane.h"

namespace fub_laneroute_generator_msgs
{

  class RoadSectionLanes : public ros::Msg
  {
    public:
      uint32_t road_section_lanes_length;
      typedef fub_laneroute_generator_msgs::RoadSectionLane _road_section_lanes_type;
      _road_section_lanes_type st_road_section_lanes;
      _road_section_lanes_type * road_section_lanes;

    RoadSectionLanes():
      road_section_lanes_length(0), road_section_lanes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->road_section_lanes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->road_section_lanes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->road_section_lanes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->road_section_lanes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->road_section_lanes_length);
      for( uint32_t i = 0; i < road_section_lanes_length; i++){
      offset += this->road_section_lanes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t road_section_lanes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      road_section_lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      road_section_lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      road_section_lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->road_section_lanes_length);
      if(road_section_lanes_lengthT > road_section_lanes_length)
        this->road_section_lanes = (fub_laneroute_generator_msgs::RoadSectionLane*)realloc(this->road_section_lanes, road_section_lanes_lengthT * sizeof(fub_laneroute_generator_msgs::RoadSectionLane));
      road_section_lanes_length = road_section_lanes_lengthT;
      for( uint32_t i = 0; i < road_section_lanes_length; i++){
      offset += this->st_road_section_lanes.deserialize(inbuffer + offset);
        memcpy( &(this->road_section_lanes[i]), &(this->st_road_section_lanes), sizeof(fub_laneroute_generator_msgs::RoadSectionLane));
      }
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/RoadSectionLanes"; };
    const char * getMD5(){ return "f25f46974dd42448dd64f4e1c67367c2"; };

  };

}
#endif