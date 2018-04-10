#ifndef _ROS_fub_simulator_cpp_AgentToSimulator_h
#define _ROS_fub_simulator_cpp_AgentToSimulator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/Odometry.h"
#include "fub_cargate_msgs/NormalizedThrottleBrake.h"
#include "fub_cargate_msgs/NormalizedSteeringAngle.h"
#include "fub_cargate_msgs/Gear.h"

namespace fub_simulator_cpp
{

  class AgentToSimulator : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef const char* _model_type;
      _model_type model;
      typedef nav_msgs::Odometry _start_pos_type;
      _start_pos_type start_pos;
      typedef fub_cargate_msgs::NormalizedThrottleBrake _normalizedThrottleBrake_type;
      _normalizedThrottleBrake_type normalizedThrottleBrake;
      typedef fub_cargate_msgs::NormalizedSteeringAngle _normalizedSteeringAngle_type;
      _normalizedSteeringAngle_type normalizedSteeringAngle;
      typedef fub_cargate_msgs::Gear _gear_type;
      _gear_type gear;

    AgentToSimulator():
      header(),
      id(""),
      model(""),
      start_pos(),
      normalizedThrottleBrake(),
      normalizedSteeringAngle(),
      gear()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      offset += this->start_pos.serialize(outbuffer + offset);
      offset += this->normalizedThrottleBrake.serialize(outbuffer + offset);
      offset += this->normalizedSteeringAngle.serialize(outbuffer + offset);
      offset += this->gear.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      offset += this->start_pos.deserialize(inbuffer + offset);
      offset += this->normalizedThrottleBrake.deserialize(inbuffer + offset);
      offset += this->normalizedSteeringAngle.deserialize(inbuffer + offset);
      offset += this->gear.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "fub_simulator_cpp/AgentToSimulator"; };
    const char * getMD5(){ return "a1d8ef880a0f1beb488f3f6ce3d64610"; };

  };

}
#endif