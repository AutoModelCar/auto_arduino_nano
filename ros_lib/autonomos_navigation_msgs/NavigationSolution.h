#ifndef _ROS_autonomos_navigation_msgs_NavigationSolution_h
#define _ROS_autonomos_navigation_msgs_NavigationSolution_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "autonomos_navigation_msgs/Route.h"

namespace autonomos_navigation_msgs
{

  class NavigationSolution : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _start_point_type;
      _start_point_type start_point;
      typedef geometry_msgs::Point _goal_point_type;
      _goal_point_type goal_point;
      uint32_t routes_length;
      typedef autonomos_navigation_msgs::Route _routes_type;
      _routes_type st_routes;
      _routes_type * routes;

    NavigationSolution():
      header(),
      start_point(),
      goal_point(),
      routes_length(0), routes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->start_point.serialize(outbuffer + offset);
      offset += this->goal_point.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->routes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routes_length);
      for( uint32_t i = 0; i < routes_length; i++){
      offset += this->routes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->start_point.deserialize(inbuffer + offset);
      offset += this->goal_point.deserialize(inbuffer + offset);
      uint32_t routes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      routes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->routes_length);
      if(routes_lengthT > routes_length)
        this->routes = (autonomos_navigation_msgs::Route*)realloc(this->routes, routes_lengthT * sizeof(autonomos_navigation_msgs::Route));
      routes_length = routes_lengthT;
      for( uint32_t i = 0; i < routes_length; i++){
      offset += this->st_routes.deserialize(inbuffer + offset);
        memcpy( &(this->routes[i]), &(this->st_routes), sizeof(autonomos_navigation_msgs::Route));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_navigation_msgs/NavigationSolution"; };
    const char * getMD5(){ return "216e9afaab1c8bb626f40b3526ed2b5a"; };

  };

}
#endif