#ifndef _ROS_fub_applanix_msgs_NavigationSolution_h
#define _ROS_fub_applanix_msgs_NavigationSolution_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class NavigationSolution : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;
      typedef float _altitude_type;
      _altitude_type altitude;
      typedef float _north_vel_type;
      _north_vel_type north_vel;
      typedef float _east_vel_type;
      _east_vel_type east_vel;
      typedef float _down_vel_type;
      _down_vel_type down_vel;
      typedef float _roll_type;
      _roll_type roll;
      typedef float _pitch_type;
      _pitch_type pitch;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _wander_angle_type;
      _wander_angle_type wander_angle;
      typedef float _track_angle_type;
      _track_angle_type track_angle;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _ang_rate_long_type;
      _ang_rate_long_type ang_rate_long;
      typedef float _ang_rate_trans_type;
      _ang_rate_trans_type ang_rate_trans;
      typedef float _ang_rate_down_type;
      _ang_rate_down_type ang_rate_down;
      typedef float _long_accel_type;
      _long_accel_type long_accel;
      typedef float _trans_accel_type;
      _trans_accel_type trans_accel;
      typedef float _down_accel_type;
      _down_accel_type down_accel;
      typedef uint8_t _alignment_status_type;
      _alignment_status_type alignment_status;
      enum { ALIGNMENT_FULL_NAVIGATION =  0  };
      enum { ALIGNMENT_FINE_ALIGNMENT_ACTIVE =  1  };
      enum { ALIGNMENT_GC_CHI_2 =  2  };
      enum { ALIGNMENT_PC_CHI_2 =  3  };
      enum { ALIGNMENT_GC_CHI_1 =  4  };
      enum { ALIGNMENT_PC_CHI_1 =  5  };
      enum { ALIGNMENT_COARSE_LEVELING =  6  };
      enum { ALIGNMENT_INITIAL_SOLUTION =  7  };
      enum { ALIGNMENT_NO_VALID_SOLUTION =  8  };

    NavigationSolution():
      header(),
      td(),
      latitude(0),
      longitude(0),
      altitude(0),
      north_vel(0),
      east_vel(0),
      down_vel(0),
      roll(0),
      pitch(0),
      yaw(0),
      wander_angle(0),
      track_angle(0),
      speed(0),
      ang_rate_long(0),
      ang_rate_trans(0),
      ang_rate_down(0),
      long_accel(0),
      trans_accel(0),
      down_accel(0),
      alignment_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->latitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->longitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->altitude);
      union {
        float real;
        uint32_t base;
      } u_north_vel;
      u_north_vel.real = this->north_vel;
      *(outbuffer + offset + 0) = (u_north_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_north_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_north_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_north_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->north_vel);
      union {
        float real;
        uint32_t base;
      } u_east_vel;
      u_east_vel.real = this->east_vel;
      *(outbuffer + offset + 0) = (u_east_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_east_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_east_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_east_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->east_vel);
      union {
        float real;
        uint32_t base;
      } u_down_vel;
      u_down_vel.real = this->down_vel;
      *(outbuffer + offset + 0) = (u_down_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_down_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_down_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_down_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->down_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->roll);
      offset += serializeAvrFloat64(outbuffer + offset, this->pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->wander_angle);
      union {
        float real;
        uint32_t base;
      } u_track_angle;
      u_track_angle.real = this->track_angle;
      *(outbuffer + offset + 0) = (u_track_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_angle);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_long;
      u_ang_rate_long.real = this->ang_rate_long;
      *(outbuffer + offset + 0) = (u_ang_rate_long.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ang_rate_long.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ang_rate_long.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ang_rate_long.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ang_rate_long);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_trans;
      u_ang_rate_trans.real = this->ang_rate_trans;
      *(outbuffer + offset + 0) = (u_ang_rate_trans.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ang_rate_trans.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ang_rate_trans.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ang_rate_trans.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ang_rate_trans);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_down;
      u_ang_rate_down.real = this->ang_rate_down;
      *(outbuffer + offset + 0) = (u_ang_rate_down.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ang_rate_down.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ang_rate_down.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ang_rate_down.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ang_rate_down);
      union {
        float real;
        uint32_t base;
      } u_long_accel;
      u_long_accel.real = this->long_accel;
      *(outbuffer + offset + 0) = (u_long_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_long_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_long_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_long_accel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->long_accel);
      union {
        float real;
        uint32_t base;
      } u_trans_accel;
      u_trans_accel.real = this->trans_accel;
      *(outbuffer + offset + 0) = (u_trans_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans_accel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trans_accel);
      union {
        float real;
        uint32_t base;
      } u_down_accel;
      u_down_accel.real = this->down_accel;
      *(outbuffer + offset + 0) = (u_down_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_down_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_down_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_down_accel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->down_accel);
      *(outbuffer + offset + 0) = (this->alignment_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alignment_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->latitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->longitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->altitude));
      union {
        float real;
        uint32_t base;
      } u_north_vel;
      u_north_vel.base = 0;
      u_north_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_north_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_north_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_north_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->north_vel = u_north_vel.real;
      offset += sizeof(this->north_vel);
      union {
        float real;
        uint32_t base;
      } u_east_vel;
      u_east_vel.base = 0;
      u_east_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_east_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_east_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_east_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->east_vel = u_east_vel.real;
      offset += sizeof(this->east_vel);
      union {
        float real;
        uint32_t base;
      } u_down_vel;
      u_down_vel.base = 0;
      u_down_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_down_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_down_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_down_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->down_vel = u_down_vel.real;
      offset += sizeof(this->down_vel);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->roll));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wander_angle));
      union {
        float real;
        uint32_t base;
      } u_track_angle;
      u_track_angle.base = 0;
      u_track_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_angle = u_track_angle.real;
      offset += sizeof(this->track_angle);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_long;
      u_ang_rate_long.base = 0;
      u_ang_rate_long.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ang_rate_long.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ang_rate_long.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ang_rate_long.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ang_rate_long = u_ang_rate_long.real;
      offset += sizeof(this->ang_rate_long);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_trans;
      u_ang_rate_trans.base = 0;
      u_ang_rate_trans.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ang_rate_trans.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ang_rate_trans.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ang_rate_trans.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ang_rate_trans = u_ang_rate_trans.real;
      offset += sizeof(this->ang_rate_trans);
      union {
        float real;
        uint32_t base;
      } u_ang_rate_down;
      u_ang_rate_down.base = 0;
      u_ang_rate_down.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ang_rate_down.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ang_rate_down.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ang_rate_down.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ang_rate_down = u_ang_rate_down.real;
      offset += sizeof(this->ang_rate_down);
      union {
        float real;
        uint32_t base;
      } u_long_accel;
      u_long_accel.base = 0;
      u_long_accel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_long_accel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_long_accel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_long_accel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->long_accel = u_long_accel.real;
      offset += sizeof(this->long_accel);
      union {
        float real;
        uint32_t base;
      } u_trans_accel;
      u_trans_accel.base = 0;
      u_trans_accel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans_accel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans_accel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans_accel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->trans_accel = u_trans_accel.real;
      offset += sizeof(this->trans_accel);
      union {
        float real;
        uint32_t base;
      } u_down_accel;
      u_down_accel.base = 0;
      u_down_accel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_down_accel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_down_accel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_down_accel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->down_accel = u_down_accel.real;
      offset += sizeof(this->down_accel);
      this->alignment_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->alignment_status);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/NavigationSolution"; };
    const char * getMD5(){ return "4ffd67ae16246ac0c9966b54aa0b5b23"; };

  };

}
#endif