#ifndef _ROS_autonomos_can_msgs_CANMessage_h
#define _ROS_autonomos_can_msgs_CANMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_can_msgs
{

  class CANMessage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint8_t _dlc_type;
      _dlc_type dlc;
      uint8_t data[8];
      typedef uint8_t _format_type;
      _format_type format;
      enum { FLAG_RTR =  1 };
      enum { FLAG_EXTENDED =  2 };

    CANMessage():
      header(),
      id(0),
      dlc(0),
      data(),
      format(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->dlc >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dlc);
      for( uint32_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      *(outbuffer + offset + 0) = (this->format >> (8 * 0)) & 0xFF;
      offset += sizeof(this->format);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->dlc =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->dlc);
      for( uint32_t i = 0; i < 8; i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
      this->format =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->format);
     return offset;
    }

    const char * getType(){ return "autonomos_can_msgs/CANMessage"; };
    const char * getMD5(){ return "0ebb16d3fa35516a33620ffee0f5105f"; };

  };

}
#endif