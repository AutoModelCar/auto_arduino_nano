#ifndef _ROS_fub_laneroute_generator_msgs_LaneRoutes_h
#define _ROS_fub_laneroute_generator_msgs_LaneRoutes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fub_laneroute_generator_msgs/LaneRoute.h"

namespace fub_laneroute_generator_msgs
{

  class LaneRoutes : public ros::Msg
  {
    public:
      uint32_t lane_routes_length;
      typedef fub_laneroute_generator_msgs::LaneRoute _lane_routes_type;
      _lane_routes_type st_lane_routes;
      _lane_routes_type * lane_routes;

    LaneRoutes():
      lane_routes_length(0), lane_routes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->lane_routes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_routes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_routes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_routes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_routes_length);
      for( uint32_t i = 0; i < lane_routes_length; i++){
      offset += this->lane_routes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t lane_routes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_routes_length);
      if(lane_routes_lengthT > lane_routes_length)
        this->lane_routes = (fub_laneroute_generator_msgs::LaneRoute*)realloc(this->lane_routes, lane_routes_lengthT * sizeof(fub_laneroute_generator_msgs::LaneRoute));
      lane_routes_length = lane_routes_lengthT;
      for( uint32_t i = 0; i < lane_routes_length; i++){
      offset += this->st_lane_routes.deserialize(inbuffer + offset);
        memcpy( &(this->lane_routes[i]), &(this->st_lane_routes), sizeof(fub_laneroute_generator_msgs::LaneRoute));
      }
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/LaneRoutes"; };
    const char * getMD5(){ return "f5938037085185015713fa461ddaa2f1"; };

  };

}
#endif