#ifndef _ROS_autonomos_obstacle_msgs_PredictedObstacles_h
#define _ROS_autonomos_obstacle_msgs_PredictedObstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_obstacle_msgs/PredictedObstacle.h"

namespace autonomos_obstacle_msgs
{

  class PredictedObstacles : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t obstacles_length;
      typedef autonomos_obstacle_msgs::PredictedObstacle _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;

    PredictedObstacles():
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
        this->obstacles = (autonomos_obstacle_msgs::PredictedObstacle*)realloc(this->obstacles, obstacles_lengthT * sizeof(autonomos_obstacle_msgs::PredictedObstacle));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(autonomos_obstacle_msgs::PredictedObstacle));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_obstacle_msgs/PredictedObstacles"; };
    const char * getMD5(){ return "8f2977564e42aa930e8df0d024d9aa64"; };

  };

}
#endif