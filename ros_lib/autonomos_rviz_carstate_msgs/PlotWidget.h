#ifndef _ROS_autonomos_rviz_carstate_msgs_PlotWidget_h
#define _ROS_autonomos_rviz_carstate_msgs_PlotWidget_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/Text.h"
#include "autonomos_rviz_carstate_msgs/PlotData.h"

namespace autonomos_rviz_carstate_msgs
{

  class PlotWidget : public ros::Msg
  {
    public:
      typedef uint16_t _id_type;
      _id_type id;
      typedef autonomos_rviz_carstate_msgs::Text _caption_type;
      _caption_type caption;
      uint32_t labels_length;
      typedef autonomos_rviz_carstate_msgs::Text _labels_type;
      _labels_type st_labels;
      _labels_type * labels;
      uint32_t plots_length;
      typedef autonomos_rviz_carstate_msgs::PlotData _plots_type;
      _plots_type st_plots;
      _plots_type * plots;
      typedef float _minValue_type;
      _minValue_type minValue;
      typedef float _maxValue_type;
      _maxValue_type maxValue;

    PlotWidget():
      id(0),
      caption(),
      labels_length(0), labels(NULL),
      plots_length(0), plots(NULL),
      minValue(0),
      maxValue(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->caption.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->labels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->labels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->labels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->labels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels_length);
      for( uint32_t i = 0; i < labels_length; i++){
      offset += this->labels[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plots_length);
      for( uint32_t i = 0; i < plots_length; i++){
      offset += this->plots[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->minValue);
      offset += serializeAvrFloat64(outbuffer + offset, this->maxValue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      offset += this->caption.deserialize(inbuffer + offset);
      uint32_t labels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      labels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->labels_length);
      if(labels_lengthT > labels_length)
        this->labels = (autonomos_rviz_carstate_msgs::Text*)realloc(this->labels, labels_lengthT * sizeof(autonomos_rviz_carstate_msgs::Text));
      labels_length = labels_lengthT;
      for( uint32_t i = 0; i < labels_length; i++){
      offset += this->st_labels.deserialize(inbuffer + offset);
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(autonomos_rviz_carstate_msgs::Text));
      }
      uint32_t plots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plots_length);
      if(plots_lengthT > plots_length)
        this->plots = (autonomos_rviz_carstate_msgs::PlotData*)realloc(this->plots, plots_lengthT * sizeof(autonomos_rviz_carstate_msgs::PlotData));
      plots_length = plots_lengthT;
      for( uint32_t i = 0; i < plots_length; i++){
      offset += this->st_plots.deserialize(inbuffer + offset);
        memcpy( &(this->plots[i]), &(this->st_plots), sizeof(autonomos_rviz_carstate_msgs::PlotData));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->minValue));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->maxValue));
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/PlotWidget"; };
    const char * getMD5(){ return "72f0b6e2d4cb2faaf1794275dc50febc"; };

  };

}
#endif