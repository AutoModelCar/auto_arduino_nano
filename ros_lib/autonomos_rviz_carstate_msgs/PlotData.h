#ifndef _ROS_autonomos_rviz_carstate_msgs_PlotData_h
#define _ROS_autonomos_rviz_carstate_msgs_PlotData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_rviz_carstate_msgs
{

  class PlotData : public ros::Msg
  {
    public:
      uint32_t x_length;
      typedef float _x_type;
      _x_type st_x;
      _x_type * x;
      uint32_t y_length;
      typedef float _y_type;
      _y_type st_y;
      _y_type * y;

    PlotData():
      x_length(0), x(NULL),
      y_length(0), y(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_length);
      for( uint32_t i = 0; i < x_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->x[i]);
      }
      *(outbuffer + offset + 0) = (this->y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_length);
      for( uint32_t i = 0; i < y_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->y[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x_length);
      if(x_lengthT > x_length)
        this->x = (float*)realloc(this->x, x_lengthT * sizeof(float));
      x_length = x_lengthT;
      for( uint32_t i = 0; i < x_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_x));
        memcpy( &(this->x[i]), &(this->st_x), sizeof(float));
      }
      uint32_t y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y_length);
      if(y_lengthT > y_length)
        this->y = (float*)realloc(this->y, y_lengthT * sizeof(float));
      y_length = y_lengthT;
      for( uint32_t i = 0; i < y_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_y));
        memcpy( &(this->y[i]), &(this->st_y), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/PlotData"; };
    const char * getMD5(){ return "796182af49bd48aa8ba60ed21519725c"; };

  };

}
#endif