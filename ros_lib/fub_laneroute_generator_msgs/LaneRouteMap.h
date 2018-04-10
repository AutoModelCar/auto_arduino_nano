#ifndef _ROS_fub_laneroute_generator_msgs_LaneRouteMap_h
#define _ROS_fub_laneroute_generator_msgs_LaneRouteMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fub_laneroute_generator_msgs/RoadSectionLanes.h"

namespace fub_laneroute_generator_msgs
{

  class LaneRouteMap : public ros::Msg
  {
    public:
      uint32_t lane_route_map_length;
      typedef fub_laneroute_generator_msgs::RoadSectionLanes _lane_route_map_type;
      _lane_route_map_type st_lane_route_map;
      _lane_route_map_type * lane_route_map;

    LaneRouteMap():
      lane_route_map_length(0), lane_route_map(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->lane_route_map_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_route_map_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_route_map_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_route_map_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_route_map_length);
      for( uint32_t i = 0; i < lane_route_map_length; i++){
      offset += this->lane_route_map[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t lane_route_map_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_route_map_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_route_map_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_route_map_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_route_map_length);
      if(lane_route_map_lengthT > lane_route_map_length)
        this->lane_route_map = (fub_laneroute_generator_msgs::RoadSectionLanes*)realloc(this->lane_route_map, lane_route_map_lengthT * sizeof(fub_laneroute_generator_msgs::RoadSectionLanes));
      lane_route_map_length = lane_route_map_lengthT;
      for( uint32_t i = 0; i < lane_route_map_length; i++){
      offset += this->st_lane_route_map.deserialize(inbuffer + offset);
        memcpy( &(this->lane_route_map[i]), &(this->st_lane_route_map), sizeof(fub_laneroute_generator_msgs::RoadSectionLanes));
      }
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/LaneRouteMap"; };
    const char * getMD5(){ return "dafdf2e04364e26101e2882d00f29076"; };

  };

}
#endif