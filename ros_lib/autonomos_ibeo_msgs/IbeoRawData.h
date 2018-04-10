#ifndef _ROS_autonomos_ibeo_msgs_IbeoRawData_h
#define _ROS_autonomos_ibeo_msgs_IbeoRawData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace autonomos_ibeo_msgs
{

  class IbeoRawData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t data_header_length;
      typedef uint8_t _data_header_type;
      _data_header_type st_data_header;
      _data_header_type * data_header;
      uint32_t data_content_length;
      typedef uint8_t _data_content_type;
      _data_content_type st_data_content;
      _data_content_type * data_content;

    IbeoRawData():
      header(),
      data_header_length(0), data_header(NULL),
      data_content_length(0), data_content(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_header_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_header_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_header_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_header_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_header_length);
      for( uint32_t i = 0; i < data_header_length; i++){
      *(outbuffer + offset + 0) = (this->data_header[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_header[i]);
      }
      *(outbuffer + offset + 0) = (this->data_content_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_content_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_content_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_content_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_content_length);
      for( uint32_t i = 0; i < data_content_length; i++){
      *(outbuffer + offset + 0) = (this->data_content[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_content[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t data_header_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_header_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_header_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_header_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_header_length);
      if(data_header_lengthT > data_header_length)
        this->data_header = (uint8_t*)realloc(this->data_header, data_header_lengthT * sizeof(uint8_t));
      data_header_length = data_header_lengthT;
      for( uint32_t i = 0; i < data_header_length; i++){
      this->st_data_header =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data_header);
        memcpy( &(this->data_header[i]), &(this->st_data_header), sizeof(uint8_t));
      }
      uint32_t data_content_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_content_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_content_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_content_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_content_length);
      if(data_content_lengthT > data_content_length)
        this->data_content = (uint8_t*)realloc(this->data_content, data_content_lengthT * sizeof(uint8_t));
      data_content_length = data_content_lengthT;
      for( uint32_t i = 0; i < data_content_length; i++){
      this->st_data_content =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data_content);
        memcpy( &(this->data_content[i]), &(this->st_data_content), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoRawData"; };
    const char * getMD5(){ return "41edcecb0c807a3a418ae3304211b3d0"; };

  };

}
#endif