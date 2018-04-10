#ifndef _ROS_fub_applanix_msgs_IMUData_h
#define _ROS_fub_applanix_msgs_IMUData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class IMUData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef int32_t _delta_velocity_x_type;
      _delta_velocity_x_type delta_velocity_x;
      typedef int32_t _delta_velocity_y_type;
      _delta_velocity_y_type delta_velocity_y;
      typedef int32_t _delta_velocity_z_type;
      _delta_velocity_z_type delta_velocity_z;
      typedef int32_t _delta_accel_x_type;
      _delta_accel_x_type delta_accel_x;
      typedef int32_t _delta_accel_y_type;
      _delta_accel_y_type delta_accel_y;
      typedef int32_t _delta_accel_z_type;
      _delta_accel_z_type delta_accel_z;
      typedef uint8_t _data_status_type;
      _data_status_type data_status;
      typedef uint8_t _imu_type_type;
      _imu_type_type imu_type;
      typedef uint8_t _imu_data_rate_type;
      _imu_data_rate_type imu_data_rate;
      typedef uint16_t _imu_status_type;
      _imu_status_type imu_status;
      enum { STATUS_1_BAD_FRAME =  1 };
      enum { STATUS_2_BAD_FRAMES =  2 };
      enum { STATUS_3_BAD_FRAMES =  4 };
      enum { DATA_RATE_50_HZ =  0 };
      enum { DATA_RATE_100_HZ =  1 };
      enum { DATA_RATE_200_HZ =  2 };
      enum { DATA_RATE_400_HZ =  3 };
      enum { DATA_RATE_125_HZ =  4 };
      enum { DATA_RATE_500_HZ =  5 };

    IMUData():
      header(),
      td(),
      delta_velocity_x(0),
      delta_velocity_y(0),
      delta_velocity_z(0),
      delta_accel_x(0),
      delta_accel_y(0),
      delta_accel_z(0),
      data_status(0),
      imu_type(0),
      imu_data_rate(0),
      imu_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_x;
      u_delta_velocity_x.real = this->delta_velocity_x;
      *(outbuffer + offset + 0) = (u_delta_velocity_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_velocity_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_velocity_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_velocity_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_velocity_x);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_y;
      u_delta_velocity_y.real = this->delta_velocity_y;
      *(outbuffer + offset + 0) = (u_delta_velocity_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_velocity_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_velocity_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_velocity_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_velocity_y);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_z;
      u_delta_velocity_z.real = this->delta_velocity_z;
      *(outbuffer + offset + 0) = (u_delta_velocity_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_velocity_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_velocity_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_velocity_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_velocity_z);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_x;
      u_delta_accel_x.real = this->delta_accel_x;
      *(outbuffer + offset + 0) = (u_delta_accel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_accel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_accel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_accel_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_accel_x);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_y;
      u_delta_accel_y.real = this->delta_accel_y;
      *(outbuffer + offset + 0) = (u_delta_accel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_accel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_accel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_accel_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_accel_y);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_z;
      u_delta_accel_z.real = this->delta_accel_z;
      *(outbuffer + offset + 0) = (u_delta_accel_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_accel_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_accel_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_accel_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_accel_z);
      *(outbuffer + offset + 0) = (this->data_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_status);
      *(outbuffer + offset + 0) = (this->imu_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_type);
      *(outbuffer + offset + 0) = (this->imu_data_rate >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_data_rate);
      *(outbuffer + offset + 0) = (this->imu_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imu_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_x;
      u_delta_velocity_x.base = 0;
      u_delta_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_velocity_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_velocity_x = u_delta_velocity_x.real;
      offset += sizeof(this->delta_velocity_x);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_y;
      u_delta_velocity_y.base = 0;
      u_delta_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_velocity_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_velocity_y = u_delta_velocity_y.real;
      offset += sizeof(this->delta_velocity_y);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_velocity_z;
      u_delta_velocity_z.base = 0;
      u_delta_velocity_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_velocity_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_velocity_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_velocity_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_velocity_z = u_delta_velocity_z.real;
      offset += sizeof(this->delta_velocity_z);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_x;
      u_delta_accel_x.base = 0;
      u_delta_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_accel_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_accel_x = u_delta_accel_x.real;
      offset += sizeof(this->delta_accel_x);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_y;
      u_delta_accel_y.base = 0;
      u_delta_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_accel_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_accel_y = u_delta_accel_y.real;
      offset += sizeof(this->delta_accel_y);
      union {
        int32_t real;
        uint32_t base;
      } u_delta_accel_z;
      u_delta_accel_z.base = 0;
      u_delta_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_accel_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_accel_z = u_delta_accel_z.real;
      offset += sizeof(this->delta_accel_z);
      this->data_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_status);
      this->imu_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->imu_type);
      this->imu_data_rate =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->imu_data_rate);
      this->imu_status =  ((uint16_t) (*(inbuffer + offset)));
      this->imu_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->imu_status);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/IMUData"; };
    const char * getMD5(){ return "96c9b7f44c0e47632916803420627ece"; };

  };

}
#endif