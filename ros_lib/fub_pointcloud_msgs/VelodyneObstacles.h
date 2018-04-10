#ifndef _ROS_fub_pointcloud_msgs_VelodyneObstacles_h
#define _ROS_fub_pointcloud_msgs_VelodyneObstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fub_pointcloud_msgs/VelodyneObstacle.h"

namespace fub_pointcloud_msgs
{

  class VelodyneObstacles : public ros::Msg
  {
    public:
      uint32_t objects_length;
      typedef fub_pointcloud_msgs::VelodyneObstacle _objects_type;
      _objects_type st_objects;
      _objects_type * objects;

    VelodyneObstacles():
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objects_length);
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->objects_length);
      if(objects_lengthT > objects_length)
        this->objects = (fub_pointcloud_msgs::VelodyneObstacle*)realloc(this->objects, objects_lengthT * sizeof(fub_pointcloud_msgs::VelodyneObstacle));
      objects_length = objects_lengthT;
      for( uint32_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(fub_pointcloud_msgs::VelodyneObstacle));
      }
     return offset;
    }

    const char * getType(){ return "fub_pointcloud_msgs/VelodyneObstacles"; };
    const char * getMD5(){ return "09120075ca61c2521fa5813585fa032b"; };

  };

}
#endif