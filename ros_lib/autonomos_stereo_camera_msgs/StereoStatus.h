#ifndef _ROS_autonomos_stereo_camera_msgs_StereoStatus_h
#define _ROS_autonomos_stereo_camera_msgs_StereoStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace autonomos_stereo_camera_msgs
{

  class StereoStatus : public ros::Msg
  {
    public:
      typedef float _uniqueness_ratio_threshold_type;
      _uniqueness_ratio_threshold_type uniqueness_ratio_threshold;
      typedef uint32_t _island_removal_size_type;
      _island_removal_size_type island_removal_size;
      typedef float _island_removal_max_diff_type;
      _island_removal_max_diff_type island_removal_max_diff;
      typedef float _sgm_p1_type;
      _sgm_p1_type sgm_p1;
      typedef float _sgm_p2_type;
      _sgm_p2_type sgm_p2;

    StereoStatus():
      uniqueness_ratio_threshold(0),
      island_removal_size(0),
      island_removal_max_diff(0),
      sgm_p1(0),
      sgm_p2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_uniqueness_ratio_threshold;
      u_uniqueness_ratio_threshold.real = this->uniqueness_ratio_threshold;
      *(outbuffer + offset + 0) = (u_uniqueness_ratio_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uniqueness_ratio_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uniqueness_ratio_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uniqueness_ratio_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uniqueness_ratio_threshold);
      *(outbuffer + offset + 0) = (this->island_removal_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->island_removal_size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->island_removal_size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->island_removal_size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->island_removal_size);
      union {
        float real;
        uint32_t base;
      } u_island_removal_max_diff;
      u_island_removal_max_diff.real = this->island_removal_max_diff;
      *(outbuffer + offset + 0) = (u_island_removal_max_diff.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_island_removal_max_diff.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_island_removal_max_diff.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_island_removal_max_diff.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->island_removal_max_diff);
      union {
        float real;
        uint32_t base;
      } u_sgm_p1;
      u_sgm_p1.real = this->sgm_p1;
      *(outbuffer + offset + 0) = (u_sgm_p1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sgm_p1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sgm_p1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sgm_p1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sgm_p1);
      union {
        float real;
        uint32_t base;
      } u_sgm_p2;
      u_sgm_p2.real = this->sgm_p2;
      *(outbuffer + offset + 0) = (u_sgm_p2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sgm_p2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sgm_p2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sgm_p2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sgm_p2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_uniqueness_ratio_threshold;
      u_uniqueness_ratio_threshold.base = 0;
      u_uniqueness_ratio_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uniqueness_ratio_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uniqueness_ratio_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uniqueness_ratio_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->uniqueness_ratio_threshold = u_uniqueness_ratio_threshold.real;
      offset += sizeof(this->uniqueness_ratio_threshold);
      this->island_removal_size =  ((uint32_t) (*(inbuffer + offset)));
      this->island_removal_size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->island_removal_size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->island_removal_size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->island_removal_size);
      union {
        float real;
        uint32_t base;
      } u_island_removal_max_diff;
      u_island_removal_max_diff.base = 0;
      u_island_removal_max_diff.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_island_removal_max_diff.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_island_removal_max_diff.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_island_removal_max_diff.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->island_removal_max_diff = u_island_removal_max_diff.real;
      offset += sizeof(this->island_removal_max_diff);
      union {
        float real;
        uint32_t base;
      } u_sgm_p1;
      u_sgm_p1.base = 0;
      u_sgm_p1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sgm_p1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sgm_p1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sgm_p1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sgm_p1 = u_sgm_p1.real;
      offset += sizeof(this->sgm_p1);
      union {
        float real;
        uint32_t base;
      } u_sgm_p2;
      u_sgm_p2.base = 0;
      u_sgm_p2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sgm_p2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sgm_p2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sgm_p2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sgm_p2 = u_sgm_p2.real;
      offset += sizeof(this->sgm_p2);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/StereoStatus"; };
    const char * getMD5(){ return "460089adbece13f4cf320bafe8adcc4d"; };

  };

}
#endif