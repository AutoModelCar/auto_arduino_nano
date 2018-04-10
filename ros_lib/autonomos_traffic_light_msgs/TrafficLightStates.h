#ifndef _ROS_autonomos_traffic_light_msgs_TrafficLightStates_h
#define _ROS_autonomos_traffic_light_msgs_TrafficLightStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "autonomos_traffic_light_msgs/TrafficLightState.h"

namespace autonomos_traffic_light_msgs
{

  class TrafficLightStates : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t states_length;
      typedef autonomos_traffic_light_msgs::TrafficLightState _states_type;
      _states_type st_states;
      _states_type * states;

    TrafficLightStates():
      header(),
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (autonomos_traffic_light_msgs::TrafficLightState*)realloc(this->states, states_lengthT * sizeof(autonomos_traffic_light_msgs::TrafficLightState));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(autonomos_traffic_light_msgs::TrafficLightState));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_traffic_light_msgs/TrafficLightStates"; };
    const char * getMD5(){ return "789e86cf5605527579fc43fbc56f64fd"; };

  };

}
#endif