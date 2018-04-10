#ifndef _ROS_ibeo_sdk_scanner_info_msgs_ScannerInfo_2205_h
#define _ROS_ibeo_sdk_scanner_info_msgs_ScannerInfo_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ibeo_sdk_time_msgs/NTP64_2205.h"
#include "ibeo_sdk_scanner_resolution_info_msgs/ScannerResolutionInfo_2205.h"

namespace ibeo_sdk_scanner_info_msgs
{

  class ScannerInfo_2205 : public ros::Msg
  {
    public:
      typedef uint8_t _device_id_type;
      _device_id_type device_id;
      typedef uint8_t _scanner_type_type;
      _scanner_type_type scanner_type;
      typedef uint16_t _scan_number_type;
      _scan_number_type scan_number;
      typedef uint32_t _scanner_status_type;
      _scanner_status_type scanner_status;
      typedef float _start_angle_type;
      _start_angle_type start_angle;
      typedef float _end_angle_type;
      _end_angle_type end_angle;
      typedef ibeo_sdk_time_msgs::NTP64_2205 _scan_start_time_type;
      _scan_start_time_type scan_start_time;
      typedef ibeo_sdk_time_msgs::NTP64_2205 _scan_end_time_type;
      _scan_end_time_type scan_end_time;
      typedef ibeo_sdk_time_msgs::NTP64_2205 _scan_start_device_time_type;
      _scan_start_device_time_type scan_start_device_time;
      typedef ibeo_sdk_time_msgs::NTP64_2205 _scan_end_device_time_type;
      _scan_end_device_time_type scan_end_device_time;
      typedef float _scan_frequency_type;
      _scan_frequency_type scan_frequency;
      typedef float _beam_tilt_type;
      _beam_tilt_type beam_tilt;
      typedef uint32_t _scan_flags_type;
      _scan_flags_type scan_flags;
      typedef float _mounting_position_yaw_angle_type;
      _mounting_position_yaw_angle_type mounting_position_yaw_angle;
      typedef float _mounting_position_pitch_angle_type;
      _mounting_position_pitch_angle_type mounting_position_pitch_angle;
      typedef float _mounting_position_roll_angle_type;
      _mounting_position_roll_angle_type mounting_position_roll_angle;
      typedef float _mounting_position_x_type;
      _mounting_position_x_type mounting_position_x;
      typedef float _mounting_position_y_type;
      _mounting_position_y_type mounting_position_y;
      typedef float _mounting_position_z_type;
      _mounting_position_z_type mounting_position_z;
      uint32_t scanner_resolution_infos_length;
      typedef ibeo_sdk_scanner_resolution_info_msgs::ScannerResolutionInfo_2205 _scanner_resolution_infos_type;
      _scanner_resolution_infos_type st_scanner_resolution_infos;
      _scanner_resolution_infos_type * scanner_resolution_infos;

    ScannerInfo_2205():
      device_id(0),
      scanner_type(0),
      scan_number(0),
      scanner_status(0),
      start_angle(0),
      end_angle(0),
      scan_start_time(),
      scan_end_time(),
      scan_start_device_time(),
      scan_end_device_time(),
      scan_frequency(0),
      beam_tilt(0),
      scan_flags(0),
      mounting_position_yaw_angle(0),
      mounting_position_pitch_angle(0),
      mounting_position_roll_angle(0),
      mounting_position_x(0),
      mounting_position_y(0),
      mounting_position_z(0),
      scanner_resolution_infos_length(0), scanner_resolution_infos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->device_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->device_id);
      *(outbuffer + offset + 0) = (this->scanner_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->scanner_type);
      *(outbuffer + offset + 0) = (this->scan_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scan_number);
      *(outbuffer + offset + 0) = (this->scanner_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scanner_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scanner_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scanner_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scanner_status);
      union {
        float real;
        uint32_t base;
      } u_start_angle;
      u_start_angle.real = this->start_angle;
      *(outbuffer + offset + 0) = (u_start_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_angle);
      union {
        float real;
        uint32_t base;
      } u_end_angle;
      u_end_angle.real = this->end_angle;
      *(outbuffer + offset + 0) = (u_end_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_end_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_end_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_end_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_angle);
      offset += this->scan_start_time.serialize(outbuffer + offset);
      offset += this->scan_end_time.serialize(outbuffer + offset);
      offset += this->scan_start_device_time.serialize(outbuffer + offset);
      offset += this->scan_end_device_time.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_scan_frequency;
      u_scan_frequency.real = this->scan_frequency;
      *(outbuffer + offset + 0) = (u_scan_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_frequency);
      union {
        float real;
        uint32_t base;
      } u_beam_tilt;
      u_beam_tilt.real = this->beam_tilt;
      *(outbuffer + offset + 0) = (u_beam_tilt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beam_tilt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beam_tilt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beam_tilt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beam_tilt);
      *(outbuffer + offset + 0) = (this->scan_flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scan_flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scan_flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_flags);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_yaw_angle;
      u_mounting_position_yaw_angle.real = this->mounting_position_yaw_angle;
      *(outbuffer + offset + 0) = (u_mounting_position_yaw_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_yaw_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_yaw_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_yaw_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_pitch_angle;
      u_mounting_position_pitch_angle.real = this->mounting_position_pitch_angle;
      *(outbuffer + offset + 0) = (u_mounting_position_pitch_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_pitch_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_pitch_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_pitch_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_pitch_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_roll_angle;
      u_mounting_position_roll_angle.real = this->mounting_position_roll_angle;
      *(outbuffer + offset + 0) = (u_mounting_position_roll_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_roll_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_roll_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_roll_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_roll_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_x;
      u_mounting_position_x.real = this->mounting_position_x;
      *(outbuffer + offset + 0) = (u_mounting_position_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_x);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_y;
      u_mounting_position_y.real = this->mounting_position_y;
      *(outbuffer + offset + 0) = (u_mounting_position_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_y);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_z;
      u_mounting_position_z.real = this->mounting_position_z;
      *(outbuffer + offset + 0) = (u_mounting_position_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mounting_position_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mounting_position_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mounting_position_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mounting_position_z);
      *(outbuffer + offset + 0) = (this->scanner_resolution_infos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scanner_resolution_infos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scanner_resolution_infos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scanner_resolution_infos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scanner_resolution_infos_length);
      for( uint32_t i = 0; i < scanner_resolution_infos_length; i++){
      offset += this->scanner_resolution_infos[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->device_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->device_id);
      this->scanner_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->scanner_type);
      this->scan_number =  ((uint16_t) (*(inbuffer + offset)));
      this->scan_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scan_number);
      this->scanner_status =  ((uint32_t) (*(inbuffer + offset)));
      this->scanner_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->scanner_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->scanner_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->scanner_status);
      union {
        float real;
        uint32_t base;
      } u_start_angle;
      u_start_angle.base = 0;
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->start_angle = u_start_angle.real;
      offset += sizeof(this->start_angle);
      union {
        float real;
        uint32_t base;
      } u_end_angle;
      u_end_angle.base = 0;
      u_end_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_end_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_end_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_end_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->end_angle = u_end_angle.real;
      offset += sizeof(this->end_angle);
      offset += this->scan_start_time.deserialize(inbuffer + offset);
      offset += this->scan_end_time.deserialize(inbuffer + offset);
      offset += this->scan_start_device_time.deserialize(inbuffer + offset);
      offset += this->scan_end_device_time.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_scan_frequency;
      u_scan_frequency.base = 0;
      u_scan_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_frequency = u_scan_frequency.real;
      offset += sizeof(this->scan_frequency);
      union {
        float real;
        uint32_t base;
      } u_beam_tilt;
      u_beam_tilt.base = 0;
      u_beam_tilt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_beam_tilt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_beam_tilt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_beam_tilt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->beam_tilt = u_beam_tilt.real;
      offset += sizeof(this->beam_tilt);
      this->scan_flags =  ((uint32_t) (*(inbuffer + offset)));
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->scan_flags);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_yaw_angle;
      u_mounting_position_yaw_angle.base = 0;
      u_mounting_position_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_yaw_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_yaw_angle = u_mounting_position_yaw_angle.real;
      offset += sizeof(this->mounting_position_yaw_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_pitch_angle;
      u_mounting_position_pitch_angle.base = 0;
      u_mounting_position_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_pitch_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_pitch_angle = u_mounting_position_pitch_angle.real;
      offset += sizeof(this->mounting_position_pitch_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_roll_angle;
      u_mounting_position_roll_angle.base = 0;
      u_mounting_position_roll_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_roll_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_roll_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_roll_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_roll_angle = u_mounting_position_roll_angle.real;
      offset += sizeof(this->mounting_position_roll_angle);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_x;
      u_mounting_position_x.base = 0;
      u_mounting_position_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_x = u_mounting_position_x.real;
      offset += sizeof(this->mounting_position_x);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_y;
      u_mounting_position_y.base = 0;
      u_mounting_position_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_y = u_mounting_position_y.real;
      offset += sizeof(this->mounting_position_y);
      union {
        float real;
        uint32_t base;
      } u_mounting_position_z;
      u_mounting_position_z.base = 0;
      u_mounting_position_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mounting_position_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mounting_position_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mounting_position_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mounting_position_z = u_mounting_position_z.real;
      offset += sizeof(this->mounting_position_z);
      uint32_t scanner_resolution_infos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scanner_resolution_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scanner_resolution_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scanner_resolution_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scanner_resolution_infos_length);
      if(scanner_resolution_infos_lengthT > scanner_resolution_infos_length)
        this->scanner_resolution_infos = (ibeo_sdk_scanner_resolution_info_msgs::ScannerResolutionInfo_2205*)realloc(this->scanner_resolution_infos, scanner_resolution_infos_lengthT * sizeof(ibeo_sdk_scanner_resolution_info_msgs::ScannerResolutionInfo_2205));
      scanner_resolution_infos_length = scanner_resolution_infos_lengthT;
      for( uint32_t i = 0; i < scanner_resolution_infos_length; i++){
      offset += this->st_scanner_resolution_infos.deserialize(inbuffer + offset);
        memcpy( &(this->scanner_resolution_infos[i]), &(this->st_scanner_resolution_infos), sizeof(ibeo_sdk_scanner_resolution_info_msgs::ScannerResolutionInfo_2205));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_scanner_info_msgs/ScannerInfo_2205"; };
    const char * getMD5(){ return "b55ed55388e4de4c852329c50fa31bc6"; };

  };

}
#endif