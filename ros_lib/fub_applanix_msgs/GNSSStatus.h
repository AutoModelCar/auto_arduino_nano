#ifndef _ROS_fub_applanix_msgs_GNSSStatus_h
#define _ROS_fub_applanix_msgs_GNSSStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"
#include "fub_applanix_msgs/GNSSChannelStatus.h"

namespace fub_applanix_msgs
{

  class GNSSStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint8_t _solution_status_type;
      _solution_status_type solution_status;
      typedef uint8_t _channels_count_type;
      _channels_count_type channels_count;
      typedef uint16_t _reserved_type;
      _reserved_type reserved;
      uint32_t channels_length;
      typedef fub_applanix_msgs::GNSSChannelStatus _channels_type;
      _channels_type st_channels;
      _channels_type * channels;
      typedef float _hdop_type;
      _hdop_type hdop;
      typedef float _vdop_type;
      _vdop_type vdop;
      typedef float _dgps_latency_type;
      _dgps_latency_type dgps_latency;
      typedef uint16_t _dgps_reference_id_type;
      _dgps_reference_id_type dgps_reference_id;
      typedef uint32_t _gps_week_type;
      _gps_week_type gps_week;
      typedef float _gps_time_offset_type;
      _gps_time_offset_type gps_time_offset;
      typedef float _gnss_latency_type;
      _gnss_latency_type gnss_latency;
      typedef float _geoidal_separation_type;
      _geoidal_separation_type geoidal_separation;
      typedef uint16_t _gnss_type_type;
      _gnss_type_type gnss_type;
      typedef uint32_t _gnss_status_type;
      _gnss_status_type gnss_status;
      enum { SOLUTION_UNKNOWN =  255 };
      enum { SOLUTION_NO_DATA =    0  };
      enum { SOLUTION_HORIZONTAL_CA =    1  };
      enum { SOLUTION_3D_CA =    2  };
      enum { SOLUTION_HORIZONTAL_DGPS =    3  };
      enum { SOLUTION_3D_DGPS =    4  };
      enum { SOLUTION_FLOAT_RTK =    5  };
      enum { SOLUTION_WIDE_LANE_RTK =    6  };
      enum { SOLUTION_NARROW_LANE_RTK =    7  };
      enum { SOLUTION_P_CODE =    8  };
      enum { SOLUTION_OMNISTAR_HP =    9 };
      enum { SOLUTION_OMNISTAR_XP =   10 };
      enum { SOLUTION_OMNISTAR_VBS =   11 };
      enum { TYPE_NONE = 0 };
      enum { TYPE_TRIMBLE_BD960 = 16 };

    GNSSStatus():
      header(),
      td(),
      solution_status(0),
      channels_count(0),
      reserved(0),
      channels_length(0), channels(NULL),
      hdop(0),
      vdop(0),
      dgps_latency(0),
      dgps_reference_id(0),
      gps_week(0),
      gps_time_offset(0),
      gnss_latency(0),
      geoidal_separation(0),
      gnss_type(0),
      gnss_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->solution_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->solution_status);
      *(outbuffer + offset + 0) = (this->channels_count >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channels_count);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved);
      *(outbuffer + offset + 0) = (this->channels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channels_length);
      for( uint32_t i = 0; i < channels_length; i++){
      offset += this->channels[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_hdop;
      u_hdop.real = this->hdop;
      *(outbuffer + offset + 0) = (u_hdop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hdop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hdop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hdop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hdop);
      union {
        float real;
        uint32_t base;
      } u_vdop;
      u_vdop.real = this->vdop;
      *(outbuffer + offset + 0) = (u_vdop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vdop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vdop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vdop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vdop);
      union {
        float real;
        uint32_t base;
      } u_dgps_latency;
      u_dgps_latency.real = this->dgps_latency;
      *(outbuffer + offset + 0) = (u_dgps_latency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dgps_latency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dgps_latency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dgps_latency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dgps_latency);
      *(outbuffer + offset + 0) = (this->dgps_reference_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dgps_reference_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->dgps_reference_id);
      *(outbuffer + offset + 0) = (this->gps_week >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gps_week >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gps_week >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gps_week >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_week);
      offset += serializeAvrFloat64(outbuffer + offset, this->gps_time_offset);
      union {
        float real;
        uint32_t base;
      } u_gnss_latency;
      u_gnss_latency.real = this->gnss_latency;
      *(outbuffer + offset + 0) = (u_gnss_latency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gnss_latency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gnss_latency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gnss_latency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gnss_latency);
      union {
        float real;
        uint32_t base;
      } u_geoidal_separation;
      u_geoidal_separation.real = this->geoidal_separation;
      *(outbuffer + offset + 0) = (u_geoidal_separation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_geoidal_separation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_geoidal_separation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_geoidal_separation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->geoidal_separation);
      *(outbuffer + offset + 0) = (this->gnss_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gnss_type >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gnss_type);
      *(outbuffer + offset + 0) = (this->gnss_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gnss_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gnss_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gnss_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gnss_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->solution_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->solution_status);
      this->channels_count =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channels_count);
      this->reserved =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved);
      uint32_t channels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channels_length);
      if(channels_lengthT > channels_length)
        this->channels = (fub_applanix_msgs::GNSSChannelStatus*)realloc(this->channels, channels_lengthT * sizeof(fub_applanix_msgs::GNSSChannelStatus));
      channels_length = channels_lengthT;
      for( uint32_t i = 0; i < channels_length; i++){
      offset += this->st_channels.deserialize(inbuffer + offset);
        memcpy( &(this->channels[i]), &(this->st_channels), sizeof(fub_applanix_msgs::GNSSChannelStatus));
      }
      union {
        float real;
        uint32_t base;
      } u_hdop;
      u_hdop.base = 0;
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hdop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hdop = u_hdop.real;
      offset += sizeof(this->hdop);
      union {
        float real;
        uint32_t base;
      } u_vdop;
      u_vdop.base = 0;
      u_vdop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vdop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vdop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vdop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vdop = u_vdop.real;
      offset += sizeof(this->vdop);
      union {
        float real;
        uint32_t base;
      } u_dgps_latency;
      u_dgps_latency.base = 0;
      u_dgps_latency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dgps_latency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dgps_latency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dgps_latency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dgps_latency = u_dgps_latency.real;
      offset += sizeof(this->dgps_latency);
      this->dgps_reference_id =  ((uint16_t) (*(inbuffer + offset)));
      this->dgps_reference_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->dgps_reference_id);
      this->gps_week =  ((uint32_t) (*(inbuffer + offset)));
      this->gps_week |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gps_week |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gps_week |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gps_week);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gps_time_offset));
      union {
        float real;
        uint32_t base;
      } u_gnss_latency;
      u_gnss_latency.base = 0;
      u_gnss_latency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gnss_latency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gnss_latency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gnss_latency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gnss_latency = u_gnss_latency.real;
      offset += sizeof(this->gnss_latency);
      union {
        float real;
        uint32_t base;
      } u_geoidal_separation;
      u_geoidal_separation.base = 0;
      u_geoidal_separation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_geoidal_separation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_geoidal_separation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_geoidal_separation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->geoidal_separation = u_geoidal_separation.real;
      offset += sizeof(this->geoidal_separation);
      this->gnss_type =  ((uint16_t) (*(inbuffer + offset)));
      this->gnss_type |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gnss_type);
      this->gnss_status =  ((uint32_t) (*(inbuffer + offset)));
      this->gnss_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gnss_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gnss_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gnss_status);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/GNSSStatus"; };
    const char * getMD5(){ return "0eb824902a0250038f348a9700fa1aaf"; };

  };

}
#endif