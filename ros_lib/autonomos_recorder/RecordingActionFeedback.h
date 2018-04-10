#ifndef _ROS_autonomos_recorder_RecordingActionFeedback_h
#define _ROS_autonomos_recorder_RecordingActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "autonomos_recorder/RecordingFeedback.h"

namespace autonomos_recorder
{

  class RecordingActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef autonomos_recorder::RecordingFeedback _feedback_type;
      _feedback_type feedback;

    RecordingActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "autonomos_recorder/RecordingActionFeedback"; };
    const char * getMD5(){ return "0f7a7e9db58baffa7bc1a6352928420e"; };

  };

}
#endif