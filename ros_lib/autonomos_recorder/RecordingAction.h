#ifndef _ROS_autonomos_recorder_RecordingAction_h
#define _ROS_autonomos_recorder_RecordingAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_recorder/RecordingActionGoal.h"
#include "autonomos_recorder/RecordingActionResult.h"
#include "autonomos_recorder/RecordingActionFeedback.h"

namespace autonomos_recorder
{

  class RecordingAction : public ros::Msg
  {
    public:
      typedef autonomos_recorder::RecordingActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef autonomos_recorder::RecordingActionResult _action_result_type;
      _action_result_type action_result;
      typedef autonomos_recorder::RecordingActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    RecordingAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecordingAction"; };
    const char * getMD5(){ return "30151754820e94016f90fc2567c603fe"; };

  };

}
#endif