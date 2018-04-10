#ifndef _ROS_autonomos_rviz_carstate_msgs_Widgets_h
#define _ROS_autonomos_rviz_carstate_msgs_Widgets_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "autonomos_rviz_carstate_msgs/DeleteWidget.h"
#include "autonomos_rviz_carstate_msgs/TextBoxWidget.h"
#include "autonomos_rviz_carstate_msgs/TwoLineTextBoxWidget.h"
#include "autonomos_rviz_carstate_msgs/MultiLineTextBoxWidget.h"
#include "autonomos_rviz_carstate_msgs/SpeedLimitWidget.h"
#include "autonomos_rviz_carstate_msgs/TrafficLightWidget.h"
#include "autonomos_rviz_carstate_msgs/TwoValueGaugeWidget.h"
#include "autonomos_rviz_carstate_msgs/PlotWidget.h"

namespace autonomos_rviz_carstate_msgs
{

  class Widgets : public ros::Msg
  {
    public:
      uint32_t deleteWidgets_length;
      typedef autonomos_rviz_carstate_msgs::DeleteWidget _deleteWidgets_type;
      _deleteWidgets_type st_deleteWidgets;
      _deleteWidgets_type * deleteWidgets;
      uint32_t textBoxWidgets_length;
      typedef autonomos_rviz_carstate_msgs::TextBoxWidget _textBoxWidgets_type;
      _textBoxWidgets_type st_textBoxWidgets;
      _textBoxWidgets_type * textBoxWidgets;
      uint32_t twoLineTextBoxWidgets_length;
      typedef autonomos_rviz_carstate_msgs::TwoLineTextBoxWidget _twoLineTextBoxWidgets_type;
      _twoLineTextBoxWidgets_type st_twoLineTextBoxWidgets;
      _twoLineTextBoxWidgets_type * twoLineTextBoxWidgets;
      uint32_t multiLineTextBoxWidgets_length;
      typedef autonomos_rviz_carstate_msgs::MultiLineTextBoxWidget _multiLineTextBoxWidgets_type;
      _multiLineTextBoxWidgets_type st_multiLineTextBoxWidgets;
      _multiLineTextBoxWidgets_type * multiLineTextBoxWidgets;
      uint32_t speedLimitWidgets_length;
      typedef autonomos_rviz_carstate_msgs::SpeedLimitWidget _speedLimitWidgets_type;
      _speedLimitWidgets_type st_speedLimitWidgets;
      _speedLimitWidgets_type * speedLimitWidgets;
      uint32_t trafficLightWidgets_length;
      typedef autonomos_rviz_carstate_msgs::TrafficLightWidget _trafficLightWidgets_type;
      _trafficLightWidgets_type st_trafficLightWidgets;
      _trafficLightWidgets_type * trafficLightWidgets;
      uint32_t gaugeWidgets_length;
      typedef autonomos_rviz_carstate_msgs::TwoValueGaugeWidget _gaugeWidgets_type;
      _gaugeWidgets_type st_gaugeWidgets;
      _gaugeWidgets_type * gaugeWidgets;
      uint32_t plotWidgets_length;
      typedef autonomos_rviz_carstate_msgs::PlotWidget _plotWidgets_type;
      _plotWidgets_type st_plotWidgets;
      _plotWidgets_type * plotWidgets;

    Widgets():
      deleteWidgets_length(0), deleteWidgets(NULL),
      textBoxWidgets_length(0), textBoxWidgets(NULL),
      twoLineTextBoxWidgets_length(0), twoLineTextBoxWidgets(NULL),
      multiLineTextBoxWidgets_length(0), multiLineTextBoxWidgets(NULL),
      speedLimitWidgets_length(0), speedLimitWidgets(NULL),
      trafficLightWidgets_length(0), trafficLightWidgets(NULL),
      gaugeWidgets_length(0), gaugeWidgets(NULL),
      plotWidgets_length(0), plotWidgets(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->deleteWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deleteWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deleteWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deleteWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deleteWidgets_length);
      for( uint32_t i = 0; i < deleteWidgets_length; i++){
      offset += this->deleteWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->textBoxWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->textBoxWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->textBoxWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->textBoxWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->textBoxWidgets_length);
      for( uint32_t i = 0; i < textBoxWidgets_length; i++){
      offset += this->textBoxWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->twoLineTextBoxWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twoLineTextBoxWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twoLineTextBoxWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twoLineTextBoxWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twoLineTextBoxWidgets_length);
      for( uint32_t i = 0; i < twoLineTextBoxWidgets_length; i++){
      offset += this->twoLineTextBoxWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->multiLineTextBoxWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->multiLineTextBoxWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->multiLineTextBoxWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->multiLineTextBoxWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->multiLineTextBoxWidgets_length);
      for( uint32_t i = 0; i < multiLineTextBoxWidgets_length; i++){
      offset += this->multiLineTextBoxWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->speedLimitWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speedLimitWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->speedLimitWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->speedLimitWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speedLimitWidgets_length);
      for( uint32_t i = 0; i < speedLimitWidgets_length; i++){
      offset += this->speedLimitWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->trafficLightWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trafficLightWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trafficLightWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trafficLightWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trafficLightWidgets_length);
      for( uint32_t i = 0; i < trafficLightWidgets_length; i++){
      offset += this->trafficLightWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->gaugeWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gaugeWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gaugeWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gaugeWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaugeWidgets_length);
      for( uint32_t i = 0; i < gaugeWidgets_length; i++){
      offset += this->gaugeWidgets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plotWidgets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plotWidgets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plotWidgets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plotWidgets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plotWidgets_length);
      for( uint32_t i = 0; i < plotWidgets_length; i++){
      offset += this->plotWidgets[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t deleteWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deleteWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deleteWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deleteWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->deleteWidgets_length);
      if(deleteWidgets_lengthT > deleteWidgets_length)
        this->deleteWidgets = (autonomos_rviz_carstate_msgs::DeleteWidget*)realloc(this->deleteWidgets, deleteWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::DeleteWidget));
      deleteWidgets_length = deleteWidgets_lengthT;
      for( uint32_t i = 0; i < deleteWidgets_length; i++){
      offset += this->st_deleteWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->deleteWidgets[i]), &(this->st_deleteWidgets), sizeof(autonomos_rviz_carstate_msgs::DeleteWidget));
      }
      uint32_t textBoxWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      textBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      textBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      textBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->textBoxWidgets_length);
      if(textBoxWidgets_lengthT > textBoxWidgets_length)
        this->textBoxWidgets = (autonomos_rviz_carstate_msgs::TextBoxWidget*)realloc(this->textBoxWidgets, textBoxWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::TextBoxWidget));
      textBoxWidgets_length = textBoxWidgets_lengthT;
      for( uint32_t i = 0; i < textBoxWidgets_length; i++){
      offset += this->st_textBoxWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->textBoxWidgets[i]), &(this->st_textBoxWidgets), sizeof(autonomos_rviz_carstate_msgs::TextBoxWidget));
      }
      uint32_t twoLineTextBoxWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twoLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twoLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twoLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->twoLineTextBoxWidgets_length);
      if(twoLineTextBoxWidgets_lengthT > twoLineTextBoxWidgets_length)
        this->twoLineTextBoxWidgets = (autonomos_rviz_carstate_msgs::TwoLineTextBoxWidget*)realloc(this->twoLineTextBoxWidgets, twoLineTextBoxWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::TwoLineTextBoxWidget));
      twoLineTextBoxWidgets_length = twoLineTextBoxWidgets_lengthT;
      for( uint32_t i = 0; i < twoLineTextBoxWidgets_length; i++){
      offset += this->st_twoLineTextBoxWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->twoLineTextBoxWidgets[i]), &(this->st_twoLineTextBoxWidgets), sizeof(autonomos_rviz_carstate_msgs::TwoLineTextBoxWidget));
      }
      uint32_t multiLineTextBoxWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      multiLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      multiLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      multiLineTextBoxWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->multiLineTextBoxWidgets_length);
      if(multiLineTextBoxWidgets_lengthT > multiLineTextBoxWidgets_length)
        this->multiLineTextBoxWidgets = (autonomos_rviz_carstate_msgs::MultiLineTextBoxWidget*)realloc(this->multiLineTextBoxWidgets, multiLineTextBoxWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::MultiLineTextBoxWidget));
      multiLineTextBoxWidgets_length = multiLineTextBoxWidgets_lengthT;
      for( uint32_t i = 0; i < multiLineTextBoxWidgets_length; i++){
      offset += this->st_multiLineTextBoxWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->multiLineTextBoxWidgets[i]), &(this->st_multiLineTextBoxWidgets), sizeof(autonomos_rviz_carstate_msgs::MultiLineTextBoxWidget));
      }
      uint32_t speedLimitWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      speedLimitWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      speedLimitWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      speedLimitWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->speedLimitWidgets_length);
      if(speedLimitWidgets_lengthT > speedLimitWidgets_length)
        this->speedLimitWidgets = (autonomos_rviz_carstate_msgs::SpeedLimitWidget*)realloc(this->speedLimitWidgets, speedLimitWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::SpeedLimitWidget));
      speedLimitWidgets_length = speedLimitWidgets_lengthT;
      for( uint32_t i = 0; i < speedLimitWidgets_length; i++){
      offset += this->st_speedLimitWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->speedLimitWidgets[i]), &(this->st_speedLimitWidgets), sizeof(autonomos_rviz_carstate_msgs::SpeedLimitWidget));
      }
      uint32_t trafficLightWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trafficLightWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trafficLightWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trafficLightWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trafficLightWidgets_length);
      if(trafficLightWidgets_lengthT > trafficLightWidgets_length)
        this->trafficLightWidgets = (autonomos_rviz_carstate_msgs::TrafficLightWidget*)realloc(this->trafficLightWidgets, trafficLightWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::TrafficLightWidget));
      trafficLightWidgets_length = trafficLightWidgets_lengthT;
      for( uint32_t i = 0; i < trafficLightWidgets_length; i++){
      offset += this->st_trafficLightWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->trafficLightWidgets[i]), &(this->st_trafficLightWidgets), sizeof(autonomos_rviz_carstate_msgs::TrafficLightWidget));
      }
      uint32_t gaugeWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gaugeWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gaugeWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gaugeWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gaugeWidgets_length);
      if(gaugeWidgets_lengthT > gaugeWidgets_length)
        this->gaugeWidgets = (autonomos_rviz_carstate_msgs::TwoValueGaugeWidget*)realloc(this->gaugeWidgets, gaugeWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::TwoValueGaugeWidget));
      gaugeWidgets_length = gaugeWidgets_lengthT;
      for( uint32_t i = 0; i < gaugeWidgets_length; i++){
      offset += this->st_gaugeWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->gaugeWidgets[i]), &(this->st_gaugeWidgets), sizeof(autonomos_rviz_carstate_msgs::TwoValueGaugeWidget));
      }
      uint32_t plotWidgets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plotWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plotWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plotWidgets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plotWidgets_length);
      if(plotWidgets_lengthT > plotWidgets_length)
        this->plotWidgets = (autonomos_rviz_carstate_msgs::PlotWidget*)realloc(this->plotWidgets, plotWidgets_lengthT * sizeof(autonomos_rviz_carstate_msgs::PlotWidget));
      plotWidgets_length = plotWidgets_lengthT;
      for( uint32_t i = 0; i < plotWidgets_length; i++){
      offset += this->st_plotWidgets.deserialize(inbuffer + offset);
        memcpy( &(this->plotWidgets[i]), &(this->st_plotWidgets), sizeof(autonomos_rviz_carstate_msgs::PlotWidget));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_rviz_carstate_msgs/Widgets"; };
    const char * getMD5(){ return "1cdb66f4de9ce3eeb6183dffe5c31617"; };

  };

}
#endif