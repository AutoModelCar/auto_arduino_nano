#ifndef _ROS_fub_applanix_msgs_GNSSChannelStatus_h
#define _ROS_fub_applanix_msgs_GNSSChannelStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fub_applanix_msgs
{

  class GNSSChannelStatus : public ros::Msg
  {
    public:
      typedef uint16_t _sv_prn_type;
      _sv_prn_type sv_prn;
      typedef uint16_t _status_type;
      _status_type status;
      typedef float _sv_azimuth_type;
      _sv_azimuth_type sv_azimuth;
      typedef float _sv_elevation_type;
      _sv_elevation_type sv_elevation;
      typedef float _sv_l1_snr_type;
      _sv_l1_snr_type sv_l1_snr;
      typedef float _sv_l2_snr_type;
      _sv_l2_snr_type sv_l2_snr;
      enum { STATUS_L1_IDLE =  0 };
      enum { STATUS_L1_ACQUISITION =  2 };
      enum { STATUS_L1_CODE_LOCK =  3 };
      enum { STATUS_L1_PHASE_LOCK =  5 };
      enum { STATUS_L2_IDLE =  6 };
      enum { STATUS_L2_ACQUISITION =  8 };
      enum { STATUS_L2_CODE_LOCK =  9 };
      enum { STATUS_L2_PHASE_LOCK =  11 };

    GNSSChannelStatus():
      sv_prn(0),
      status(0),
      sv_azimuth(0),
      sv_elevation(0),
      sv_l1_snr(0),
      sv_l2_snr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sv_prn >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sv_prn >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sv_prn);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      union {
        float real;
        uint32_t base;
      } u_sv_azimuth;
      u_sv_azimuth.real = this->sv_azimuth;
      *(outbuffer + offset + 0) = (u_sv_azimuth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sv_azimuth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sv_azimuth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sv_azimuth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sv_azimuth);
      union {
        float real;
        uint32_t base;
      } u_sv_elevation;
      u_sv_elevation.real = this->sv_elevation;
      *(outbuffer + offset + 0) = (u_sv_elevation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sv_elevation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sv_elevation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sv_elevation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sv_elevation);
      union {
        float real;
        uint32_t base;
      } u_sv_l1_snr;
      u_sv_l1_snr.real = this->sv_l1_snr;
      *(outbuffer + offset + 0) = (u_sv_l1_snr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sv_l1_snr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sv_l1_snr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sv_l1_snr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sv_l1_snr);
      union {
        float real;
        uint32_t base;
      } u_sv_l2_snr;
      u_sv_l2_snr.real = this->sv_l2_snr;
      *(outbuffer + offset + 0) = (u_sv_l2_snr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sv_l2_snr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sv_l2_snr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sv_l2_snr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sv_l2_snr);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->sv_prn =  ((uint16_t) (*(inbuffer + offset)));
      this->sv_prn |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sv_prn);
      this->status =  ((uint16_t) (*(inbuffer + offset)));
      this->status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->status);
      union {
        float real;
        uint32_t base;
      } u_sv_azimuth;
      u_sv_azimuth.base = 0;
      u_sv_azimuth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sv_azimuth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sv_azimuth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sv_azimuth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sv_azimuth = u_sv_azimuth.real;
      offset += sizeof(this->sv_azimuth);
      union {
        float real;
        uint32_t base;
      } u_sv_elevation;
      u_sv_elevation.base = 0;
      u_sv_elevation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sv_elevation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sv_elevation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sv_elevation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sv_elevation = u_sv_elevation.real;
      offset += sizeof(this->sv_elevation);
      union {
        float real;
        uint32_t base;
      } u_sv_l1_snr;
      u_sv_l1_snr.base = 0;
      u_sv_l1_snr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sv_l1_snr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sv_l1_snr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sv_l1_snr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sv_l1_snr = u_sv_l1_snr.real;
      offset += sizeof(this->sv_l1_snr);
      union {
        float real;
        uint32_t base;
      } u_sv_l2_snr;
      u_sv_l2_snr.base = 0;
      u_sv_l2_snr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sv_l2_snr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sv_l2_snr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sv_l2_snr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sv_l2_snr = u_sv_l2_snr.real;
      offset += sizeof(this->sv_l2_snr);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/GNSSChannelStatus"; };
    const char * getMD5(){ return "761945e18c48f7cce29ddc7d375feb58"; };

  };

}
#endif