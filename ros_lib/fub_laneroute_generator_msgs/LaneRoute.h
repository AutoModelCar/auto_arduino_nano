#ifndef _ROS_fub_laneroute_generator_msgs_LaneRoute_h
#define _ROS_fub_laneroute_generator_msgs_LaneRoute_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fub_laneroute_generator_msgs/RoadSectionLane.h"

namespace fub_laneroute_generator_msgs
{

  class LaneRoute : public ros::Msg
  {
    public:
      uint32_t lane_route_length;
      typedef fub_laneroute_generator_msgs::RoadSectionLane _lane_route_type;
      _lane_route_type st_lane_route;
      _lane_route_type * lane_route;

    LaneRoute():
      lane_route_length(0), lane_route(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->lane_route_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_route_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_route_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_route_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_route_length);
      for( uint32_t i = 0; i < lane_route_length; i++){
      offset += this->lane_route[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t lane_route_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_route_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_route_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_route_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_route_length);
      if(lane_route_lengthT > lane_route_length)
        this->lane_route = (fub_laneroute_generator_msgs::RoadSectionLane*)realloc(this->lane_route, lane_route_lengthT * sizeof(fub_laneroute_generator_msgs::RoadSectionLane));
      lane_route_length = lane_route_lengthT;
      for( uint32_t i = 0; i < lane_route_length; i++){
      offset += this->st_lane_route.deserialize(inbuffer + offset);
        memcpy( &(this->lane_route[i]), &(this->st_lane_route), sizeof(fub_laneroute_generator_msgs::RoadSectionLane));
      }
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/LaneRoute"; };
    const char * getMD5(){ return "0871826cacf7eb2024740535bc356d60"; };

  };

}
#endif