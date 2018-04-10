#ifndef _ROS_autonomos_navigation_msgs_Route_h
#define _ROS_autonomos_navigation_msgs_Route_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_navigation_msgs/RouteSegment.h"

namespace autonomos_navigation_msgs
{

  class Route : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _travel_distance_type;
      _travel_distance_type travel_distance;
      uint32_t segments_length;
      typedef autonomos_navigation_msgs::RouteSegment _segments_type;
      _segments_type st_segments;
      _segments_type * segments;

    Route():
      header(),
      travel_distance(0),
      segments_length(0), segments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->travel_distance >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->travel_distance >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->travel_distance >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->travel_distance >> (8 * 3)) & 0xFF;
      offset += sizeof(this->travel_distance);
      *(outbuffer + offset + 0) = (this->segments_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->segments_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->segments_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->segments_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->segments_length);
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->travel_distance =  ((uint32_t) (*(inbuffer + offset)));
      this->travel_distance |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->travel_distance |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->travel_distance |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->travel_distance);
      uint32_t segments_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      segments_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->segments_length);
      if(segments_lengthT > segments_length)
        this->segments = (autonomos_navigation_msgs::RouteSegment*)realloc(this->segments, segments_lengthT * sizeof(autonomos_navigation_msgs::RouteSegment));
      segments_length = segments_lengthT;
      for( uint32_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(autonomos_navigation_msgs::RouteSegment));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_navigation_msgs/Route"; };
    const char * getMD5(){ return "65fba45eb7dde34cd86e5aa9035c157b"; };

  };

}
#endif