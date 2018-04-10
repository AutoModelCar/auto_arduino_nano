#ifndef _ROS_fub_obstacle_msgs_Obstacles_h
#define _ROS_fub_obstacle_msgs_Obstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_obstacle_msgs/Obstacle.h"

namespace fub_obstacle_msgs
{

  class Obstacles : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t obstacles_length;
      typedef fub_obstacle_msgs::Obstacle _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;

    Obstacles():
      header(),
      obstacles_length(0), obstacles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (fub_obstacle_msgs::Obstacle*)realloc(this->obstacles, obstacles_lengthT * sizeof(fub_obstacle_msgs::Obstacle));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(fub_obstacle_msgs::Obstacle));
      }
     return offset;
    }

    const char * getType(){ return "fub_obstacle_msgs/Obstacles"; };
    const char * getMD5(){ return "bd5a4bc101d0799505ddfd03792ae7c5"; };

  };

}
#endif