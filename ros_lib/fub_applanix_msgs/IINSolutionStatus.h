#ifndef _ROS_fub_applanix_msgs_IINSolutionStatus_h
#define _ROS_fub_applanix_msgs_IINSolutionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class IINSolutionStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint16_t _num_satellites_type;
      _num_satellites_type num_satellites;
      typedef float _a_priori_pdop_type;
      _a_priori_pdop_type a_priori_pdop;
      typedef float _baseline_length_type;
      _baseline_length_type baseline_length;
      typedef uint16_t _status_type;
      _status_type status;
      uint8_t prn_assignment[12];
      typedef uint16_t _l1_cycle_slip_flag_type;
      _l1_cycle_slip_flag_type l1_cycle_slip_flag;
      typedef uint16_t _l2_cycle_slip_flag_type;
      _l2_cycle_slip_flag_type l2_cycle_slip_flag;
      enum { STATUS_FIXED_NARROW_LANE_RTK = 1 };
      enum { STATUS_FIXED_WIDE_LANE_RTK = 2 };
      enum { STATUS_FLOAT_RTK = 3 };
      enum { STATUS_CODE_DGPS = 4 };
      enum { STATUS_RTCM_DGPS = 5 };
      enum { STATUS_AUTONOMOUS_CA = 6 };
      enum { STATUS_GNSS_NAV_SOLUTION = 7 };
      enum { STATUS_NO_SOLUTION = 8 };

    IINSolutionStatus():
      header(),
      td(),
      num_satellites(0),
      a_priori_pdop(0),
      baseline_length(0),
      status(0),
      prn_assignment(),
      l1_cycle_slip_flag(0),
      l2_cycle_slip_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_satellites >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_satellites >> (8 * 1)) & 0xFF;
      offset += sizeof(this->num_satellites);
      union {
        float real;
        uint32_t base;
      } u_a_priori_pdop;
      u_a_priori_pdop.real = this->a_priori_pdop;
      *(outbuffer + offset + 0) = (u_a_priori_pdop.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_a_priori_pdop.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_a_priori_pdop.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_a_priori_pdop.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->a_priori_pdop);
      union {
        float real;
        uint32_t base;
      } u_baseline_length;
      u_baseline_length.real = this->baseline_length;
      *(outbuffer + offset + 0) = (u_baseline_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baseline_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baseline_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baseline_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baseline_length);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      for( uint32_t i = 0; i < 12; i++){
      *(outbuffer + offset + 0) = (this->prn_assignment[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->prn_assignment[i]);
      }
      *(outbuffer + offset + 0) = (this->l1_cycle_slip_flag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->l1_cycle_slip_flag >> (8 * 1)) & 0xFF;
      offset += sizeof(this->l1_cycle_slip_flag);
      *(outbuffer + offset + 0) = (this->l2_cycle_slip_flag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->l2_cycle_slip_flag >> (8 * 1)) & 0xFF;
      offset += sizeof(this->l2_cycle_slip_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->num_satellites =  ((uint16_t) (*(inbuffer + offset)));
      this->num_satellites |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->num_satellites);
      union {
        float real;
        uint32_t base;
      } u_a_priori_pdop;
      u_a_priori_pdop.base = 0;
      u_a_priori_pdop.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_a_priori_pdop.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_a_priori_pdop.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_a_priori_pdop.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->a_priori_pdop = u_a_priori_pdop.real;
      offset += sizeof(this->a_priori_pdop);
      union {
        float real;
        uint32_t base;
      } u_baseline_length;
      u_baseline_length.base = 0;
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_baseline_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baseline_length = u_baseline_length.real;
      offset += sizeof(this->baseline_length);
      this->status =  ((uint16_t) (*(inbuffer + offset)));
      this->status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->status);
      for( uint32_t i = 0; i < 12; i++){
      this->prn_assignment[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->prn_assignment[i]);
      }
      this->l1_cycle_slip_flag =  ((uint16_t) (*(inbuffer + offset)));
      this->l1_cycle_slip_flag |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->l1_cycle_slip_flag);
      this->l2_cycle_slip_flag =  ((uint16_t) (*(inbuffer + offset)));
      this->l2_cycle_slip_flag |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->l2_cycle_slip_flag);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/IINSolutionStatus"; };
    const char * getMD5(){ return "ddeebb7c53ed880af0ad9d78969f67a0"; };

  };

}
#endif