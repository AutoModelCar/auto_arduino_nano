#ifndef _ROS_fub_applanix_msgs_CalibratedInstallationParameters_h
#define _ROS_fub_applanix_msgs_CalibratedInstallationParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class CalibratedInstallationParameters : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint16_t _calibration_status_type;
      _calibration_status_type calibration_status;
      typedef float _reference_to_primary_gps_x_lever_arm_type;
      _reference_to_primary_gps_x_lever_arm_type reference_to_primary_gps_x_lever_arm;
      typedef float _reference_to_primary_gps_y_lever_arm_type;
      _reference_to_primary_gps_y_lever_arm_type reference_to_primary_gps_y_lever_arm;
      typedef float _reference_to_primary_gps_z_lever_arm_type;
      _reference_to_primary_gps_z_lever_arm_type reference_to_primary_gps_z_lever_arm;
      typedef uint16_t _reference_to_primary_gps_lever_arm_calibration_FOM_type;
      _reference_to_primary_gps_lever_arm_calibration_FOM_type reference_to_primary_gps_lever_arm_calibration_FOM;
      typedef float _reference_to_auxiliary_1_gps_x_lever_arm_type;
      _reference_to_auxiliary_1_gps_x_lever_arm_type reference_to_auxiliary_1_gps_x_lever_arm;
      typedef float _reference_to_auxiliary_1_gps_y_lever_arm_type;
      _reference_to_auxiliary_1_gps_y_lever_arm_type reference_to_auxiliary_1_gps_y_lever_arm;
      typedef float _reference_to_auxiliary_1_gps_z_lever_arm_type;
      _reference_to_auxiliary_1_gps_z_lever_arm_type reference_to_auxiliary_1_gps_z_lever_arm;
      typedef uint16_t _reference_to_auxiliary_1_gps_lever_arm_calibration_FOM_type;
      _reference_to_auxiliary_1_gps_lever_arm_calibration_FOM_type reference_to_auxiliary_1_gps_lever_arm_calibration_FOM;
      typedef float _reference_to_auxiliary_2_gps_x_lever_arm_type;
      _reference_to_auxiliary_2_gps_x_lever_arm_type reference_to_auxiliary_2_gps_x_lever_arm;
      typedef float _reference_to_auxiliary_2_gps_y_lever_arm_type;
      _reference_to_auxiliary_2_gps_y_lever_arm_type reference_to_auxiliary_2_gps_y_lever_arm;
      typedef float _reference_to_auxiliary_2_gps_z_lever_arm_type;
      _reference_to_auxiliary_2_gps_z_lever_arm_type reference_to_auxiliary_2_gps_z_lever_arm;
      typedef uint16_t _reference_to_auxiliary_2_gps_lever_arm_calibration_FOM_type;
      _reference_to_auxiliary_2_gps_lever_arm_calibration_FOM_type reference_to_auxiliary_2_gps_lever_arm_calibration_FOM;
      typedef float _reference_to_dmi_x_lever_arm_type;
      _reference_to_dmi_x_lever_arm_type reference_to_dmi_x_lever_arm;
      typedef float _reference_to_dmi_y_lever_arm_type;
      _reference_to_dmi_y_lever_arm_type reference_to_dmi_y_lever_arm;
      typedef float _reference_to_dmi_z_lever_arm_type;
      _reference_to_dmi_z_lever_arm_type reference_to_dmi_z_lever_arm;
      typedef uint16_t _reference_to_dmi_lever_arm_calibration_FOM_type;
      _reference_to_dmi_lever_arm_calibration_FOM_type reference_to_dmi_lever_arm_calibration_FOM;
      typedef float _dmi_scale_factor_type;
      _dmi_scale_factor_type dmi_scale_factor;
      typedef uint16_t _dmi_scale_factor_calibration_FOM_type;
      _dmi_scale_factor_calibration_FOM_type dmi_scale_factor_calibration_FOM;
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_PRIMARY_GPS_LEVER_ARM_CALIBRATION_IS_IN_PROGRESS =  1 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_AUXILIARY_1_GPS_LEVER_ARM_CALIBRATION_IS_IN_PROGRESS =  2 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_AUXILIARY_2_GPS_LEVER_ARM_CALIBRATION_IS_IN_PROGRESS =  4 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_DMI_LEVER_ARM_CALIBRATION_IS_IN_PROGRESS =  8 };
      enum { CALIBRATION_STATUS_FLAG_DMI_SCALE_FACTOR_CALIBRATION_IS_IN_PROGRESS =  16 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_POSITION_FIX_LEVER_ARM_CALIBRATION_IS_IN_PROGRESS =  64 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_PRIMARY_GPS_LEVER_ARM_CALIBRATION_IS_COMPLETED =  256 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_AUXILIARY_1_GPS_LEVER_ARM_CALIBRATION_IS_COMPLETED =  512 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_AUXILIARY_2_GPS_LEVER_ARM_CALIBRATION_IS_COMPLETED =  1024 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_DMI_LEVER_ARM_CALIBRATION_IS_COMPLETED =  2048 };
      enum { CALIBRATION_STATUS_FLAG_DMI_SCALE_FACTOR_CALIBRATION_IS_COMPLETED =  4096 };
      enum { CALIBRATION_STATUS_FLAG_REFERENCE_TO_POSITION_FIX_LEVER_ARM_CALIBRATION_IS_COMPLETED =  16384 };

    CalibratedInstallationParameters():
      header(),
      td(),
      calibration_status(0),
      reference_to_primary_gps_x_lever_arm(0),
      reference_to_primary_gps_y_lever_arm(0),
      reference_to_primary_gps_z_lever_arm(0),
      reference_to_primary_gps_lever_arm_calibration_FOM(0),
      reference_to_auxiliary_1_gps_x_lever_arm(0),
      reference_to_auxiliary_1_gps_y_lever_arm(0),
      reference_to_auxiliary_1_gps_z_lever_arm(0),
      reference_to_auxiliary_1_gps_lever_arm_calibration_FOM(0),
      reference_to_auxiliary_2_gps_x_lever_arm(0),
      reference_to_auxiliary_2_gps_y_lever_arm(0),
      reference_to_auxiliary_2_gps_z_lever_arm(0),
      reference_to_auxiliary_2_gps_lever_arm_calibration_FOM(0),
      reference_to_dmi_x_lever_arm(0),
      reference_to_dmi_y_lever_arm(0),
      reference_to_dmi_z_lever_arm(0),
      reference_to_dmi_lever_arm_calibration_FOM(0),
      dmi_scale_factor(0),
      dmi_scale_factor_calibration_FOM(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->calibration_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->calibration_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->calibration_status);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_x_lever_arm;
      u_reference_to_primary_gps_x_lever_arm.real = this->reference_to_primary_gps_x_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_primary_gps_x_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_primary_gps_x_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_primary_gps_x_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_primary_gps_x_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_primary_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_y_lever_arm;
      u_reference_to_primary_gps_y_lever_arm.real = this->reference_to_primary_gps_y_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_primary_gps_y_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_primary_gps_y_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_primary_gps_y_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_primary_gps_y_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_primary_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_z_lever_arm;
      u_reference_to_primary_gps_z_lever_arm.real = this->reference_to_primary_gps_z_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_primary_gps_z_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_primary_gps_z_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_primary_gps_z_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_primary_gps_z_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_primary_gps_z_lever_arm);
      *(outbuffer + offset + 0) = (this->reference_to_primary_gps_lever_arm_calibration_FOM >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_to_primary_gps_lever_arm_calibration_FOM >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reference_to_primary_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_x_lever_arm;
      u_reference_to_auxiliary_1_gps_x_lever_arm.real = this->reference_to_auxiliary_1_gps_x_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_1_gps_x_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_1_gps_x_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_1_gps_x_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_1_gps_x_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_1_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_y_lever_arm;
      u_reference_to_auxiliary_1_gps_y_lever_arm.real = this->reference_to_auxiliary_1_gps_y_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_1_gps_y_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_1_gps_y_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_1_gps_y_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_1_gps_y_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_1_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_z_lever_arm;
      u_reference_to_auxiliary_1_gps_z_lever_arm.real = this->reference_to_auxiliary_1_gps_z_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_1_gps_z_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_1_gps_z_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_1_gps_z_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_1_gps_z_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_1_gps_z_lever_arm);
      *(outbuffer + offset + 0) = (this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_x_lever_arm;
      u_reference_to_auxiliary_2_gps_x_lever_arm.real = this->reference_to_auxiliary_2_gps_x_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_2_gps_x_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_2_gps_x_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_2_gps_x_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_2_gps_x_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_2_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_y_lever_arm;
      u_reference_to_auxiliary_2_gps_y_lever_arm.real = this->reference_to_auxiliary_2_gps_y_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_2_gps_y_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_2_gps_y_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_2_gps_y_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_2_gps_y_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_2_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_z_lever_arm;
      u_reference_to_auxiliary_2_gps_z_lever_arm.real = this->reference_to_auxiliary_2_gps_z_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_auxiliary_2_gps_z_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_auxiliary_2_gps_z_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_auxiliary_2_gps_z_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_auxiliary_2_gps_z_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_2_gps_z_lever_arm);
      *(outbuffer + offset + 0) = (this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_x_lever_arm;
      u_reference_to_dmi_x_lever_arm.real = this->reference_to_dmi_x_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_dmi_x_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_dmi_x_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_dmi_x_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_dmi_x_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_dmi_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_y_lever_arm;
      u_reference_to_dmi_y_lever_arm.real = this->reference_to_dmi_y_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_dmi_y_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_dmi_y_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_dmi_y_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_dmi_y_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_dmi_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_z_lever_arm;
      u_reference_to_dmi_z_lever_arm.real = this->reference_to_dmi_z_lever_arm;
      *(outbuffer + offset + 0) = (u_reference_to_dmi_z_lever_arm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_to_dmi_z_lever_arm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_to_dmi_z_lever_arm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_to_dmi_z_lever_arm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_to_dmi_z_lever_arm);
      *(outbuffer + offset + 0) = (this->reference_to_dmi_lever_arm_calibration_FOM >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_to_dmi_lever_arm_calibration_FOM >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reference_to_dmi_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_dmi_scale_factor;
      u_dmi_scale_factor.real = this->dmi_scale_factor;
      *(outbuffer + offset + 0) = (u_dmi_scale_factor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dmi_scale_factor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dmi_scale_factor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dmi_scale_factor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dmi_scale_factor);
      *(outbuffer + offset + 0) = (this->dmi_scale_factor_calibration_FOM >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dmi_scale_factor_calibration_FOM >> (8 * 1)) & 0xFF;
      offset += sizeof(this->dmi_scale_factor_calibration_FOM);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->calibration_status =  ((uint16_t) (*(inbuffer + offset)));
      this->calibration_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->calibration_status);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_x_lever_arm;
      u_reference_to_primary_gps_x_lever_arm.base = 0;
      u_reference_to_primary_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_primary_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_primary_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_primary_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_primary_gps_x_lever_arm = u_reference_to_primary_gps_x_lever_arm.real;
      offset += sizeof(this->reference_to_primary_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_y_lever_arm;
      u_reference_to_primary_gps_y_lever_arm.base = 0;
      u_reference_to_primary_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_primary_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_primary_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_primary_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_primary_gps_y_lever_arm = u_reference_to_primary_gps_y_lever_arm.real;
      offset += sizeof(this->reference_to_primary_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_primary_gps_z_lever_arm;
      u_reference_to_primary_gps_z_lever_arm.base = 0;
      u_reference_to_primary_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_primary_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_primary_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_primary_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_primary_gps_z_lever_arm = u_reference_to_primary_gps_z_lever_arm.real;
      offset += sizeof(this->reference_to_primary_gps_z_lever_arm);
      this->reference_to_primary_gps_lever_arm_calibration_FOM =  ((uint16_t) (*(inbuffer + offset)));
      this->reference_to_primary_gps_lever_arm_calibration_FOM |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reference_to_primary_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_x_lever_arm;
      u_reference_to_auxiliary_1_gps_x_lever_arm.base = 0;
      u_reference_to_auxiliary_1_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_1_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_1_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_1_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_1_gps_x_lever_arm = u_reference_to_auxiliary_1_gps_x_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_1_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_y_lever_arm;
      u_reference_to_auxiliary_1_gps_y_lever_arm.base = 0;
      u_reference_to_auxiliary_1_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_1_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_1_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_1_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_1_gps_y_lever_arm = u_reference_to_auxiliary_1_gps_y_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_1_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_1_gps_z_lever_arm;
      u_reference_to_auxiliary_1_gps_z_lever_arm.base = 0;
      u_reference_to_auxiliary_1_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_1_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_1_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_1_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_1_gps_z_lever_arm = u_reference_to_auxiliary_1_gps_z_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_1_gps_z_lever_arm);
      this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM =  ((uint16_t) (*(inbuffer + offset)));
      this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reference_to_auxiliary_1_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_x_lever_arm;
      u_reference_to_auxiliary_2_gps_x_lever_arm.base = 0;
      u_reference_to_auxiliary_2_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_2_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_2_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_2_gps_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_2_gps_x_lever_arm = u_reference_to_auxiliary_2_gps_x_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_2_gps_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_y_lever_arm;
      u_reference_to_auxiliary_2_gps_y_lever_arm.base = 0;
      u_reference_to_auxiliary_2_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_2_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_2_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_2_gps_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_2_gps_y_lever_arm = u_reference_to_auxiliary_2_gps_y_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_2_gps_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_auxiliary_2_gps_z_lever_arm;
      u_reference_to_auxiliary_2_gps_z_lever_arm.base = 0;
      u_reference_to_auxiliary_2_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_auxiliary_2_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_auxiliary_2_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_auxiliary_2_gps_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_auxiliary_2_gps_z_lever_arm = u_reference_to_auxiliary_2_gps_z_lever_arm.real;
      offset += sizeof(this->reference_to_auxiliary_2_gps_z_lever_arm);
      this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM =  ((uint16_t) (*(inbuffer + offset)));
      this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reference_to_auxiliary_2_gps_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_x_lever_arm;
      u_reference_to_dmi_x_lever_arm.base = 0;
      u_reference_to_dmi_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_dmi_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_dmi_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_dmi_x_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_dmi_x_lever_arm = u_reference_to_dmi_x_lever_arm.real;
      offset += sizeof(this->reference_to_dmi_x_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_y_lever_arm;
      u_reference_to_dmi_y_lever_arm.base = 0;
      u_reference_to_dmi_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_dmi_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_dmi_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_dmi_y_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_dmi_y_lever_arm = u_reference_to_dmi_y_lever_arm.real;
      offset += sizeof(this->reference_to_dmi_y_lever_arm);
      union {
        float real;
        uint32_t base;
      } u_reference_to_dmi_z_lever_arm;
      u_reference_to_dmi_z_lever_arm.base = 0;
      u_reference_to_dmi_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_to_dmi_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_to_dmi_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_to_dmi_z_lever_arm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reference_to_dmi_z_lever_arm = u_reference_to_dmi_z_lever_arm.real;
      offset += sizeof(this->reference_to_dmi_z_lever_arm);
      this->reference_to_dmi_lever_arm_calibration_FOM =  ((uint16_t) (*(inbuffer + offset)));
      this->reference_to_dmi_lever_arm_calibration_FOM |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reference_to_dmi_lever_arm_calibration_FOM);
      union {
        float real;
        uint32_t base;
      } u_dmi_scale_factor;
      u_dmi_scale_factor.base = 0;
      u_dmi_scale_factor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dmi_scale_factor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dmi_scale_factor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dmi_scale_factor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dmi_scale_factor = u_dmi_scale_factor.real;
      offset += sizeof(this->dmi_scale_factor);
      this->dmi_scale_factor_calibration_FOM =  ((uint16_t) (*(inbuffer + offset)));
      this->dmi_scale_factor_calibration_FOM |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->dmi_scale_factor_calibration_FOM);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/CalibratedInstallationParameters"; };
    const char * getMD5(){ return "728c2cb20e6c4d1ec431ce2b0337afef"; };

  };

}
#endif