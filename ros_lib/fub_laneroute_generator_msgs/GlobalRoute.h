#ifndef _ROS_fub_laneroute_generator_msgs_GlobalRoute_h
#define _ROS_fub_laneroute_generator_msgs_GlobalRoute_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace fub_laneroute_generator_msgs
{

  class GlobalRoute : public ros::Msg
  {
    public:
      uint32_t road_section_ids_length;
      typedef uint64_t _road_section_ids_type;
      _road_section_ids_type st_road_section_ids;
      _road_section_ids_type * road_section_ids;
      typedef geometry_msgs::Point _start_type;
      _start_type start;
      typedef geometry_msgs::Point _goal_type;
      _goal_type goal;

    GlobalRoute():
      road_section_ids_length(0), road_section_ids(NULL),
      start(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->road_section_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->road_section_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->road_section_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->road_section_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->road_section_ids_length);
      for( uint32_t i = 0; i < road_section_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_road_section_idsi;
      u_road_section_idsi.real = this->road_section_ids[i];
      *(outbuffer + offset + 0) = (u_road_section_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_road_section_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_road_section_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_road_section_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->road_section_ids[i]);
      }
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t road_section_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      road_section_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      road_section_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      road_section_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->road_section_ids_length);
      if(road_section_ids_lengthT > road_section_ids_length)
        this->road_section_ids = (uint64_t*)realloc(this->road_section_ids, road_section_ids_lengthT * sizeof(uint64_t));
      road_section_ids_length = road_section_ids_lengthT;
      for( uint32_t i = 0; i < road_section_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_road_section_ids;
      u_st_road_section_ids.base = 0;
      u_st_road_section_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_road_section_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_road_section_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_road_section_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_road_section_ids = u_st_road_section_ids.real;
      offset += sizeof(this->st_road_section_ids);
        memcpy( &(this->road_section_ids[i]), &(this->st_road_section_ids), sizeof(uint64_t));
      }
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "fub_laneroute_generator_msgs/GlobalRoute"; };
    const char * getMD5(){ return "ebd753966748e8e0665c516a5b213443"; };

  };

}
#endif