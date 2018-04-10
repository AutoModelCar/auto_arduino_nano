#ifndef _ROS_autonomos_traffic_light_msgs_TrafficLightState_h
#define _ROS_autonomos_traffic_light_msgs_TrafficLightState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_traffic_light_msgs/TrafficLightSignal.h"
#include "sensor_msgs/RegionOfInterest.h"

namespace autonomos_traffic_light_msgs
{

  class TrafficLightState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _id_type;
      _id_type id;
      uint32_t signals_length;
      typedef autonomos_traffic_light_msgs::TrafficLightSignal _signals_type;
      _signals_type st_signals;
      _signals_type * signals;
      uint32_t rect_length;
      typedef sensor_msgs::RegionOfInterest _rect_type;
      _rect_type st_rect;
      _rect_type * rect;

    TrafficLightState():
      header(),
      id(0),
      signals_length(0), signals(NULL),
      rect_length(0), rect(NULL)
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
      *(outbuffer + offset + 0) = (this->signals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->signals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->signals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->signals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signals_length);
      for( uint32_t i = 0; i < signals_length; i++){
      offset += this->signals[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->rect_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rect_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rect_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rect_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rect_length);
      for( uint32_t i = 0; i < rect_length; i++){
      offset += this->rect[i].serialize(outbuffer + offset);
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
      uint32_t signals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      signals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->signals_length);
      if(signals_lengthT > signals_length)
        this->signals = (autonomos_traffic_light_msgs::TrafficLightSignal*)realloc(this->signals, signals_lengthT * sizeof(autonomos_traffic_light_msgs::TrafficLightSignal));
      signals_length = signals_lengthT;
      for( uint32_t i = 0; i < signals_length; i++){
      offset += this->st_signals.deserialize(inbuffer + offset);
        memcpy( &(this->signals[i]), &(this->st_signals), sizeof(autonomos_traffic_light_msgs::TrafficLightSignal));
      }
      uint32_t rect_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rect_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rect_length);
      if(rect_lengthT > rect_length)
        this->rect = (sensor_msgs::RegionOfInterest*)realloc(this->rect, rect_lengthT * sizeof(sensor_msgs::RegionOfInterest));
      rect_length = rect_lengthT;
      for( uint32_t i = 0; i < rect_length; i++){
      offset += this->st_rect.deserialize(inbuffer + offset);
        memcpy( &(this->rect[i]), &(this->st_rect), sizeof(sensor_msgs::RegionOfInterest));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/TrafficLightState"; };
    const char * getMD5(){ return "c6a247f33cc5d62ac7059cd18acb183f"; };

  };

}
#endif