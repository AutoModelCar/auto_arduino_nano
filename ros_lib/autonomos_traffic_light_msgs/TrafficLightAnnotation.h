#ifndef _ROS_autonomos_traffic_light_msgs_TrafficLightAnnotation_h
#define _ROS_autonomos_traffic_light_msgs_TrafficLightAnnotation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeoPoint.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "autonomos_traffic_light_msgs/AtlasLane.h"

namespace autonomos_traffic_light_msgs
{

  class TrafficLightAnnotation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _id_type;
      _id_type id;
      typedef geographic_msgs::GeoPoint _position_type;
      _position_type position;
      typedef geometry_msgs::Pose _map_pose_type;
      _map_pose_type map_pose;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _lightSource_type;
      _lightSource_type lightSource;
      typedef uint8_t _orientation_type;
      _orientation_type orientation;
      typedef uint8_t _mounting_type;
      _mounting_type mounting;
      typedef geometry_msgs::Point _mounting_point_type;
      _mounting_point_type mounting_point;
      uint32_t stop_points_length;
      typedef geometry_msgs::Point _stop_points_type;
      _stop_points_type st_stop_points;
      _stop_points_type * stop_points;
      uint32_t lanes_length;
      typedef autonomos_traffic_light_msgs::AtlasLane _lanes_type;
      _lanes_type st_lanes;
      _lanes_type * lanes;
      enum { TYPE_UNKNOWN =  0 };
      enum { LIGHT_SOURCE_UNKNOWN =  0 };
      enum { LIGHT_SOURCE_INCANDESCENT =  1 };
      enum { LIGHT_SOURCE_LED =  2 };
      enum { ORIENTATION_UNKNOWN =  0 };
      enum { ORIENTATION_VERTICAL =  1 };
      enum { ORIENTATION_HORIZONTAL =  2 };
      enum { MOUNTING_UNKNOWN =  0 };
      enum { MOUNTING_SUPPORTED =  1 };
      enum { MOUNTING_SUSPENDED =  2 };
      enum { MOUNTING_OTHER =  255 };

    TrafficLightAnnotation():
      header(),
      id(0),
      position(),
      map_pose(),
      type(0),
      lightSource(0),
      orientation(0),
      mounting(0),
      mounting_point(),
      stop_points_length(0), stop_points(NULL),
      lanes_length(0), lanes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->map_pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->lightSource >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lightSource);
      *(outbuffer + offset + 0) = (this->orientation >> (8 * 0)) & 0xFF;
      offset += sizeof(this->orientation);
      *(outbuffer + offset + 0) = (this->mounting >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mounting);
      offset += this->mounting_point.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->stop_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_points_length);
      for( uint32_t i = 0; i < stop_points_length; i++){
      offset += this->stop_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->lanes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lanes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lanes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lanes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lanes_length);
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->lanes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->map_pose.deserialize(inbuffer + offset);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->lightSource =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lightSource);
      this->orientation =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->orientation);
      this->mounting =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mounting);
      offset += this->mounting_point.deserialize(inbuffer + offset);
      uint32_t stop_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_points_length);
      if(stop_points_lengthT > stop_points_length)
        this->stop_points = (geometry_msgs::Point*)realloc(this->stop_points, stop_points_lengthT * sizeof(geometry_msgs::Point));
      stop_points_length = stop_points_lengthT;
      for( uint32_t i = 0; i < stop_points_length; i++){
      offset += this->st_stop_points.deserialize(inbuffer + offset);
        memcpy( &(this->stop_points[i]), &(this->st_stop_points), sizeof(geometry_msgs::Point));
      }
      uint32_t lanes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lanes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lanes_length);
      if(lanes_lengthT > lanes_length)
        this->lanes = (autonomos_traffic_light_msgs::AtlasLane*)realloc(this->lanes, lanes_lengthT * sizeof(autonomos_traffic_light_msgs::AtlasLane));
      lanes_length = lanes_lengthT;
      for( uint32_t i = 0; i < lanes_length; i++){
      offset += this->st_lanes.deserialize(inbuffer + offset);
        memcpy( &(this->lanes[i]), &(this->st_lanes), sizeof(autonomos_traffic_light_msgs::AtlasLane));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/TrafficLightAnnotation"; };
    const char * getMD5(){ return "1ab5452a7f8248c6526049033a7f6767"; };

  };

}
#endif