#ifndef _ROS_autonomos_traffic_light_msgs_AtlasLane_h
#define _ROS_autonomos_traffic_light_msgs_AtlasLane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_traffic_light_msgs
{

  class AtlasLane : public ros::Msg
  {
    public:
      typedef uint64_t _roadsection_id_type;
      _roadsection_id_type roadsection_id;
      typedef uint64_t _lane_id_type;
      _lane_id_type lane_id;

    AtlasLane():
      roadsection_id(0),
      lane_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.real = this->roadsection_id;
      *(outbuffer + offset + 0) = (u_roadsection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roadsection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roadsection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roadsection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roadsection_id);
      union {
        uint64_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.real = this->lane_id;
      *(outbuffer + offset + 0) = (u_lane_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lane_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lane_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lane_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_roadsection_id;
      u_roadsection_id.base = 0;
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roadsection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roadsection_id = u_roadsection_id.real;
      offset += sizeof(this->roadsection_id);
      union {
        uint64_t real;
        uint32_t base;
      } u_lane_id;
      u_lane_id.base = 0;
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lane_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lane_id = u_lane_id.real;
      offset += sizeof(this->lane_id);
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/AtlasLane"; };
    const char * getMD5(){ return "6ace888de3d8cf88429949c5e7df229e"; };

  };

}
#endif