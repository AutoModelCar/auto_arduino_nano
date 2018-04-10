#ifndef _ROS_fub_applanix_msgs_DMIData_h
#define _ROS_fub_applanix_msgs_DMIData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class DMIData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef float _signed_distance_type;
      _signed_distance_type signed_distance;
      typedef float _unsigned_distance_type;
      _unsigned_distance_type unsigned_distance;
      typedef uint16_t _scale_factor_type;
      _scale_factor_type scale_factor;
      typedef uint8_t _status_type;
      _status_type status;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _rate_type;
      _rate_type rate;
      enum { STATUS_INVALID = 0 };
      enum { STATUS_VALID = 1 };
      enum { STATUS_SCALE_FACTOR_CHANGE = 2 };
      enum { TYPE_NONE = 0 };
      enum { TYPE_PULSE_DIR = 1 };
      enum { TYPE_QUADRATURE = 2 };
      enum { RATE_50HZ = 0 };
      enum { RATE_100HZ = 1 };
      enum { RATE_200HZ = 2 };
      enum { RATE_400HZ = 3 };
      enum { RATE_125HZ = 4 };

    DMIData():
      header(),
      td(),
      signed_distance(0),
      unsigned_distance(0),
      scale_factor(0),
      status(0),
      type(0),
      rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->signed_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->unsigned_distance);
      *(outbuffer + offset + 0) = (this->scale_factor >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scale_factor >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scale_factor);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->rate >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->signed_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->unsigned_distance));
      this->scale_factor =  ((uint16_t) (*(inbuffer + offset)));
      this->scale_factor |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scale_factor);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->rate =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rate);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/DMIData"; };
    const char * getMD5(){ return "39c05f457500207903809ef6985ae5f9"; };

  };

}
#endif