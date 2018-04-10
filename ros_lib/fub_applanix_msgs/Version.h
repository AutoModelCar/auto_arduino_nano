#ifndef _ROS_fub_applanix_msgs_Version_h
#define _ROS_fub_applanix_msgs_Version_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class Version : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      uint8_t system_version[120];
      uint8_t primary_gnss_version[80];
      uint8_t secondary_gnss_version[80];
      typedef float _total_hours_type;
      _total_hours_type total_hours;
      typedef uint32_t _num_runs_type;
      _num_runs_type num_runs;
      typedef float _avg_run_length_type;
      _avg_run_length_type avg_run_length;
      typedef float _longest_run_type;
      _longest_run_type longest_run;
      typedef float _current_run_type;
      _current_run_type current_run;

    Version():
      header(),
      td(),
      system_version(),
      primary_gnss_version(),
      secondary_gnss_version(),
      total_hours(0),
      num_runs(0),
      avg_run_length(0),
      longest_run(0),
      current_run(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 120; i++){
      *(outbuffer + offset + 0) = (this->system_version[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_version[i]);
      }
      for( uint32_t i = 0; i < 80; i++){
      *(outbuffer + offset + 0) = (this->primary_gnss_version[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->primary_gnss_version[i]);
      }
      for( uint32_t i = 0; i < 80; i++){
      *(outbuffer + offset + 0) = (this->secondary_gnss_version[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->secondary_gnss_version[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_total_hours;
      u_total_hours.real = this->total_hours;
      *(outbuffer + offset + 0) = (u_total_hours.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_hours.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_hours.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_hours.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_hours);
      *(outbuffer + offset + 0) = (this->num_runs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_runs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_runs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_runs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_runs);
      union {
        float real;
        uint32_t base;
      } u_avg_run_length;
      u_avg_run_length.real = this->avg_run_length;
      *(outbuffer + offset + 0) = (u_avg_run_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_run_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_run_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_run_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avg_run_length);
      union {
        float real;
        uint32_t base;
      } u_longest_run;
      u_longest_run.real = this->longest_run;
      *(outbuffer + offset + 0) = (u_longest_run.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longest_run.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longest_run.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longest_run.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longest_run);
      union {
        float real;
        uint32_t base;
      } u_current_run;
      u_current_run.real = this->current_run;
      *(outbuffer + offset + 0) = (u_current_run.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_run.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_run.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_run.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_run);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 120; i++){
      this->system_version[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->system_version[i]);
      }
      for( uint32_t i = 0; i < 80; i++){
      this->primary_gnss_version[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->primary_gnss_version[i]);
      }
      for( uint32_t i = 0; i < 80; i++){
      this->secondary_gnss_version[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->secondary_gnss_version[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_total_hours;
      u_total_hours.base = 0;
      u_total_hours.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_hours.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_hours.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_hours.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_hours = u_total_hours.real;
      offset += sizeof(this->total_hours);
      this->num_runs =  ((uint32_t) (*(inbuffer + offset)));
      this->num_runs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_runs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_runs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_runs);
      union {
        float real;
        uint32_t base;
      } u_avg_run_length;
      u_avg_run_length.base = 0;
      u_avg_run_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_run_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_run_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_run_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->avg_run_length = u_avg_run_length.real;
      offset += sizeof(this->avg_run_length);
      union {
        float real;
        uint32_t base;
      } u_longest_run;
      u_longest_run.base = 0;
      u_longest_run.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longest_run.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longest_run.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longest_run.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longest_run = u_longest_run.real;
      offset += sizeof(this->longest_run);
      union {
        float real;
        uint32_t base;
      } u_current_run;
      u_current_run.base = 0;
      u_current_run.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_run.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_run.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_run.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_run = u_current_run.real;
      offset += sizeof(this->current_run);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/Version"; };
    const char * getMD5(){ return "c2dfb8b539d2af2d90a3dc27b2f95b25"; };

  };

}
#endif