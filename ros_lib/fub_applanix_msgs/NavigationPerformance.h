#ifndef _ROS_fub_applanix_msgs_NavigationPerformance_h
#define _ROS_fub_applanix_msgs_NavigationPerformance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class NavigationPerformance : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef float _north_pos_rms_err_type;
      _north_pos_rms_err_type north_pos_rms_err;
      typedef float _east_pos_rms_err_type;
      _east_pos_rms_err_type east_pos_rms_err;
      typedef float _down_pos_rms_err_type;
      _down_pos_rms_err_type down_pos_rms_err;
      typedef float _north_vel_rms_err_type;
      _north_vel_rms_err_type north_vel_rms_err;
      typedef float _east_vel_rms_err_type;
      _east_vel_rms_err_type east_vel_rms_err;
      typedef float _down_vel_rms_err_type;
      _down_vel_rms_err_type down_vel_rms_err;
      typedef float _roll_rms_err_type;
      _roll_rms_err_type roll_rms_err;
      typedef float _pitch_rms_err_type;
      _pitch_rms_err_type pitch_rms_err;
      typedef float _yaw_rms_err_type;
      _yaw_rms_err_type yaw_rms_err;
      typedef float _err_ellipsoid_semi_major_type;
      _err_ellipsoid_semi_major_type err_ellipsoid_semi_major;
      typedef float _err_ellipsoid_semi_minor_type;
      _err_ellipsoid_semi_minor_type err_ellipsoid_semi_minor;
      typedef float _err_ellipsoid_orientation_type;
      _err_ellipsoid_orientation_type err_ellipsoid_orientation;

    NavigationPerformance():
      header(),
      td(),
      north_pos_rms_err(0),
      east_pos_rms_err(0),
      down_pos_rms_err(0),
      north_vel_rms_err(0),
      east_vel_rms_err(0),
      down_vel_rms_err(0),
      roll_rms_err(0),
      pitch_rms_err(0),
      yaw_rms_err(0),
      err_ellipsoid_semi_major(0),
      err_ellipsoid_semi_minor(0),
      err_ellipsoid_orientation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_north_pos_rms_err;
      u_north_pos_rms_err.real = this->north_pos_rms_err;
      *(outbuffer + offset + 0) = (u_north_pos_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_pos_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_pos_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_pos_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->north_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_east_pos_rms_err;
      u_east_pos_rms_err.real = this->east_pos_rms_err;
      *(outbuffer + offset + 0) = (u_east_pos_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_pos_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_pos_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_pos_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->east_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_down_pos_rms_err;
      u_down_pos_rms_err.real = this->down_pos_rms_err;
      *(outbuffer + offset + 0) = (u_down_pos_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_down_pos_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_down_pos_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_down_pos_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->down_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_north_vel_rms_err;
      u_north_vel_rms_err.real = this->north_vel_rms_err;
      *(outbuffer + offset + 0) = (u_north_vel_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_vel_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_vel_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_vel_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->north_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_east_vel_rms_err;
      u_east_vel_rms_err.real = this->east_vel_rms_err;
      *(outbuffer + offset + 0) = (u_east_vel_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_vel_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_vel_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_vel_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->east_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_down_vel_rms_err;
      u_down_vel_rms_err.real = this->down_vel_rms_err;
      *(outbuffer + offset + 0) = (u_down_vel_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_down_vel_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_down_vel_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_down_vel_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->down_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_roll_rms_err;
      u_roll_rms_err.real = this->roll_rms_err;
      *(outbuffer + offset + 0) = (u_roll_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll_rms_err);
      union {
        float real;
        uint32_t base;
      } u_pitch_rms_err;
      u_pitch_rms_err.real = this->pitch_rms_err;
      *(outbuffer + offset + 0) = (u_pitch_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch_rms_err);
      union {
        float real;
        uint32_t base;
      } u_yaw_rms_err;
      u_yaw_rms_err.real = this->yaw_rms_err;
      *(outbuffer + offset + 0) = (u_yaw_rms_err.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rms_err.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_rms_err.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_rms_err.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_rms_err);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_semi_major;
      u_err_ellipsoid_semi_major.real = this->err_ellipsoid_semi_major;
      *(outbuffer + offset + 0) = (u_err_ellipsoid_semi_major.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_err_ellipsoid_semi_major.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_err_ellipsoid_semi_major.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_err_ellipsoid_semi_major.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->err_ellipsoid_semi_major);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_semi_minor;
      u_err_ellipsoid_semi_minor.real = this->err_ellipsoid_semi_minor;
      *(outbuffer + offset + 0) = (u_err_ellipsoid_semi_minor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_err_ellipsoid_semi_minor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_err_ellipsoid_semi_minor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_err_ellipsoid_semi_minor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->err_ellipsoid_semi_minor);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_orientation;
      u_err_ellipsoid_orientation.real = this->err_ellipsoid_orientation;
      *(outbuffer + offset + 0) = (u_err_ellipsoid_orientation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_err_ellipsoid_orientation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_err_ellipsoid_orientation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_err_ellipsoid_orientation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->err_ellipsoid_orientation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_north_pos_rms_err;
      u_north_pos_rms_err.base = 0;
      u_north_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->north_pos_rms_err = u_north_pos_rms_err.real;
      offset += sizeof(this->north_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_east_pos_rms_err;
      u_east_pos_rms_err.base = 0;
      u_east_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->east_pos_rms_err = u_east_pos_rms_err.real;
      offset += sizeof(this->east_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_down_pos_rms_err;
      u_down_pos_rms_err.base = 0;
      u_down_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_down_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_down_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_down_pos_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->down_pos_rms_err = u_down_pos_rms_err.real;
      offset += sizeof(this->down_pos_rms_err);
      union {
        float real;
        uint32_t base;
      } u_north_vel_rms_err;
      u_north_vel_rms_err.base = 0;
      u_north_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->north_vel_rms_err = u_north_vel_rms_err.real;
      offset += sizeof(this->north_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_east_vel_rms_err;
      u_east_vel_rms_err.base = 0;
      u_east_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->east_vel_rms_err = u_east_vel_rms_err.real;
      offset += sizeof(this->east_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_down_vel_rms_err;
      u_down_vel_rms_err.base = 0;
      u_down_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_down_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_down_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_down_vel_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->down_vel_rms_err = u_down_vel_rms_err.real;
      offset += sizeof(this->down_vel_rms_err);
      union {
        float real;
        uint32_t base;
      } u_roll_rms_err;
      u_roll_rms_err.base = 0;
      u_roll_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll_rms_err = u_roll_rms_err.real;
      offset += sizeof(this->roll_rms_err);
      union {
        float real;
        uint32_t base;
      } u_pitch_rms_err;
      u_pitch_rms_err.base = 0;
      u_pitch_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch_rms_err = u_pitch_rms_err.real;
      offset += sizeof(this->pitch_rms_err);
      union {
        float real;
        uint32_t base;
      } u_yaw_rms_err;
      u_yaw_rms_err.base = 0;
      u_yaw_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_rms_err.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_rms_err = u_yaw_rms_err.real;
      offset += sizeof(this->yaw_rms_err);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_semi_major;
      u_err_ellipsoid_semi_major.base = 0;
      u_err_ellipsoid_semi_major.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_err_ellipsoid_semi_major.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_err_ellipsoid_semi_major.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_err_ellipsoid_semi_major.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->err_ellipsoid_semi_major = u_err_ellipsoid_semi_major.real;
      offset += sizeof(this->err_ellipsoid_semi_major);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_semi_minor;
      u_err_ellipsoid_semi_minor.base = 0;
      u_err_ellipsoid_semi_minor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_err_ellipsoid_semi_minor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_err_ellipsoid_semi_minor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_err_ellipsoid_semi_minor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->err_ellipsoid_semi_minor = u_err_ellipsoid_semi_minor.real;
      offset += sizeof(this->err_ellipsoid_semi_minor);
      union {
        float real;
        uint32_t base;
      } u_err_ellipsoid_orientation;
      u_err_ellipsoid_orientation.base = 0;
      u_err_ellipsoid_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_err_ellipsoid_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_err_ellipsoid_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_err_ellipsoid_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->err_ellipsoid_orientation = u_err_ellipsoid_orientation.real;
      offset += sizeof(this->err_ellipsoid_orientation);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/NavigationPerformance"; };
    const char * getMD5(){ return "dd7fe2a12042fc3740df4da7fddbc787"; };

  };

}
#endif