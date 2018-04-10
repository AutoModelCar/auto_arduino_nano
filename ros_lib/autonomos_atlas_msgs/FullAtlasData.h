#ifndef _ROS_autonomos_atlas_msgs_FullAtlasData_h
#define _ROS_autonomos_atlas_msgs_FullAtlasData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_atlas_msgs/FullMap.h"
#include "autonomos_atlas_msgs/FullAnnotations.h"

namespace autonomos_atlas_msgs
{

  class FullAtlasData : public ros::Msg
  {
    public:
      typedef autonomos_atlas_msgs::FullMap _map_type;
      _map_type map;
      typedef autonomos_atlas_msgs::FullAnnotations _annotations_type;
      _annotations_type annotations;

    FullAtlasData():
      map(),
      annotations()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      offset += this->annotations.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
      offset += this->annotations.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_atlas_msgs/FullAtlasData"; };
    const char * getMD5(){ return "ce5ea21f5eba9cad11224709cbf71fff"; };

  };

}
#endif