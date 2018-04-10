#ifndef _ROS_autonomos_obstacle_msgs_PredictedObstacle_h
#define _ROS_autonomos_obstacle_msgs_PredictedObstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_obstacle_msgs/Obstacle.h"
#include "fub_trajectory_msgs/Trajectory.h"

namespace autonomos_obstacle_msgs
{

  class PredictedObstacle : public ros::Msg
  {
    public:
      typedef autonomos_obstacle_msgs::Obstacle _obstacle_type;
      _obstacle_type obstacle;
      uint32_t trajectories_length;
      typedef fub_trajectory_msgs::Trajectory _trajectories_type;
      _trajectories_type st_trajectories;
      _trajectories_type * trajectories;

    PredictedObstacle():
      obstacle(),
      trajectories_length(0), trajectories(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->obstacle.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->trajectories_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectories_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectories_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectories_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectories_length);
      for( uint32_t i = 0; i < trajectories_length; i++){
      offset += this->trajectories[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->obstacle.deserialize(inbuffer + offset);
      uint32_t trajectories_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectories_length);
      if(trajectories_lengthT > trajectories_length)
        this->trajectories = (fub_trajectory_msgs::Trajectory*)realloc(this->trajectories, trajectories_lengthT * sizeof(fub_trajectory_msgs::Trajectory));
      trajectories_length = trajectories_lengthT;
      for( uint32_t i = 0; i < trajectories_length; i++){
      offset += this->st_trajectories.deserialize(inbuffer + offset);
        memcpy( &(this->trajectories[i]), &(this->st_trajectories), sizeof(fub_trajectory_msgs::Trajectory));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_obstacle_msgs/PredictedObstacle"; };
    const char * getMD5(){ return "e2f017cecb10e6c6c9d1de5f60285a38"; };

  };

}
#endif