#ifndef _ROS_fub_applanix_msgs_TimeDistance_h
#define _ROS_fub_applanix_msgs_TimeDistance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fub_applanix_msgs
{

  class TimeDistance : public ros::Msg
  {
    public:
      typedef float _time1_type;
      _time1_type time1;
      typedef float _time2_type;
      _time2_type time2;
      typedef uint8_t _time_type_type;
      _time_type_type time_type;
      typedef float _distance_type;
      _distance_type distance;
      typedef uint8_t _distance_type_type;
      _distance_type_type distance_type;
      enum { TIME_TYPE_POS =  0  };
      enum { TIME_TYPE_GPS =  1  };
      enum { TIME_TYPE_UTC =  2  };
      enum { TIME_TYPE_USER =  3  };
      enum { DIST_NA =  0  };
      enum { DIST_POS =  1  };
      enum { DIST_DMI =  2  };

    TimeDistance():
      time1(0),
      time2(0),
      time_type(0),
      distance(0),
      distance_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->time1);
      offset += serializeAvrFloat64(outbuffer + offset, this->time2);
      *(outbuffer + offset + 0) = (this->time_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->time_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      *(outbuffer + offset + 0) = (this->distance_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->distance_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time2));
      this->time_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->time_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      this->distance_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->distance_type);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/TimeDistance"; };
    const char * getMD5(){ return "21adb5aedd1cbd78c49dd86cb8eab388"; };

  };

}
#endif