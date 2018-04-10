#ifndef _ROS_autonomos_stereo_camera_msgs_CameraStatus_h
#define _ROS_autonomos_stereo_camera_msgs_CameraStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace autonomos_stereo_camera_msgs
{

  class CameraStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef uint64_t _device_serial_number_type;
      _device_serial_number_type device_serial_number;
      typedef uint8_t _temperature_grade_type;
      _temperature_grade_type temperature_grade;
      typedef ros::Time _build_time_type;
      _build_time_type build_time;
      typedef bool _has_color_sensor_type;
      _has_color_sensor_type has_color_sensor;
      typedef bool _has_ir_cut_filter_type;
      _has_ir_cut_filter_type has_ir_cut_filter;
      typedef bool _has_polarization_filter_type;
      _has_polarization_filter_type has_polarization_filter;
      typedef float _nd_filter_transmittance_type;
      _nd_filter_transmittance_type nd_filter_transmittance;
      typedef float _optics_focal_length_type;
      _optics_focal_length_type optics_focal_length;
      typedef float _optics_aperture_type;
      _optics_aperture_type optics_aperture;
      typedef float _optics_image_circle_type;
      _optics_image_circle_type optics_image_circle;
      typedef uint8_t _electronics_revision_type;
      _electronics_revision_type electronics_revision;
      typedef uint8_t _sensor_board_revision_type;
      _sensor_board_revision_type sensor_board_revision;
      typedef uint8_t _mechanics_revision_type;
      _mechanics_revision_type mechanics_revision;
      typedef uint64_t _driver_version_type;
      _driver_version_type driver_version;
      typedef uint64_t _firmware_version_type;
      _firmware_version_type firmware_version;
      typedef uint64_t _fpga_version_type;
      _fpga_version_type fpga_version;
      typedef float _frame_rate_type;
      _frame_rate_type frame_rate;
      typedef uint8_t _cpu_usage_type;
      _cpu_usage_type cpu_usage;
      typedef uint8_t _mem_usage_type;
      _mem_usage_type mem_usage;
      typedef uint64_t _disk_bytes_free_type;
      _disk_bytes_free_type disk_bytes_free;
      typedef ros::Time _time_type;
      _time_type time;
      typedef ros::Duration _uptime_type;
      _uptime_type uptime;
      enum { TEMPERATURE_GRADE_UNDEFINED =  0 };
      enum { TEMPERATURE_GRADE_COMMERCIAL =  1  };
      enum { TEMPERATURE_GRADE_INDUSTRIAL =  2  };
      enum { TEMPERATURE_GRADE_AUTOMOTIVE =  3  };
      enum { TEMPERATURE_GRADE_MILITARY =  4  };

    CameraStatus():
      header(),
      model_name(""),
      device_serial_number(0),
      temperature_grade(0),
      build_time(),
      has_color_sensor(0),
      has_ir_cut_filter(0),
      has_polarization_filter(0),
      nd_filter_transmittance(0),
      optics_focal_length(0),
      optics_aperture(0),
      optics_image_circle(0),
      electronics_revision(0),
      sensor_board_revision(0),
      mechanics_revision(0),
      driver_version(0),
      firmware_version(0),
      fpga_version(0),
      frame_rate(0),
      cpu_usage(0),
      mem_usage(0),
      disk_bytes_free(0),
      time(),
      uptime()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_device_serial_number;
      u_device_serial_number.real = this->device_serial_number;
      *(outbuffer + offset + 0) = (u_device_serial_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device_serial_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_device_serial_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_device_serial_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device_serial_number);
      *(outbuffer + offset + 0) = (this->temperature_grade >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature_grade);
      *(outbuffer + offset + 0) = (this->build_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->build_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->build_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->build_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->build_time.sec);
      *(outbuffer + offset + 0) = (this->build_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->build_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->build_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->build_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->build_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_color_sensor;
      u_has_color_sensor.real = this->has_color_sensor;
      *(outbuffer + offset + 0) = (u_has_color_sensor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_color_sensor);
      union {
        bool real;
        uint8_t base;
      } u_has_ir_cut_filter;
      u_has_ir_cut_filter.real = this->has_ir_cut_filter;
      *(outbuffer + offset + 0) = (u_has_ir_cut_filter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_ir_cut_filter);
      union {
        bool real;
        uint8_t base;
      } u_has_polarization_filter;
      u_has_polarization_filter.real = this->has_polarization_filter;
      *(outbuffer + offset + 0) = (u_has_polarization_filter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_polarization_filter);
      union {
        float real;
        uint32_t base;
      } u_nd_filter_transmittance;
      u_nd_filter_transmittance.real = this->nd_filter_transmittance;
      *(outbuffer + offset + 0) = (u_nd_filter_transmittance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nd_filter_transmittance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nd_filter_transmittance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nd_filter_transmittance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nd_filter_transmittance);
      union {
        float real;
        uint32_t base;
      } u_optics_focal_length;
      u_optics_focal_length.real = this->optics_focal_length;
      *(outbuffer + offset + 0) = (u_optics_focal_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_optics_focal_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_optics_focal_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_optics_focal_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->optics_focal_length);
      union {
        float real;
        uint32_t base;
      } u_optics_aperture;
      u_optics_aperture.real = this->optics_aperture;
      *(outbuffer + offset + 0) = (u_optics_aperture.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_optics_aperture.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_optics_aperture.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_optics_aperture.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->optics_aperture);
      union {
        float real;
        uint32_t base;
      } u_optics_image_circle;
      u_optics_image_circle.real = this->optics_image_circle;
      *(outbuffer + offset + 0) = (u_optics_image_circle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_optics_image_circle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_optics_image_circle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_optics_image_circle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->optics_image_circle);
      *(outbuffer + offset + 0) = (this->electronics_revision >> (8 * 0)) & 0xFF;
      offset += sizeof(this->electronics_revision);
      *(outbuffer + offset + 0) = (this->sensor_board_revision >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_board_revision);
      *(outbuffer + offset + 0) = (this->mechanics_revision >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mechanics_revision);
      union {
        uint64_t real;
        uint32_t base;
      } u_driver_version;
      u_driver_version.real = this->driver_version;
      *(outbuffer + offset + 0) = (u_driver_version.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driver_version.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_driver_version.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_driver_version.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->driver_version);
      union {
        uint64_t real;
        uint32_t base;
      } u_firmware_version;
      u_firmware_version.real = this->firmware_version;
      *(outbuffer + offset + 0) = (u_firmware_version.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_firmware_version.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_firmware_version.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_firmware_version.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_version);
      union {
        uint64_t real;
        uint32_t base;
      } u_fpga_version;
      u_fpga_version.real = this->fpga_version;
      *(outbuffer + offset + 0) = (u_fpga_version.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fpga_version.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fpga_version.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fpga_version.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fpga_version);
      union {
        float real;
        uint32_t base;
      } u_frame_rate;
      u_frame_rate.real = this->frame_rate;
      *(outbuffer + offset + 0) = (u_frame_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frame_rate);
      *(outbuffer + offset + 0) = (this->cpu_usage >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cpu_usage);
      *(outbuffer + offset + 0) = (this->mem_usage >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mem_usage);
      union {
        uint64_t real;
        uint32_t base;
      } u_disk_bytes_free;
      u_disk_bytes_free.real = this->disk_bytes_free;
      *(outbuffer + offset + 0) = (u_disk_bytes_free.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_disk_bytes_free.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_disk_bytes_free.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_disk_bytes_free.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->disk_bytes_free);
      *(outbuffer + offset + 0) = (this->time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.sec);
      *(outbuffer + offset + 0) = (this->time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.nsec);
      *(outbuffer + offset + 0) = (this->uptime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime.sec);
      *(outbuffer + offset + 0) = (this->uptime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      union {
        uint64_t real;
        uint32_t base;
      } u_device_serial_number;
      u_device_serial_number.base = 0;
      u_device_serial_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device_serial_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_device_serial_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_device_serial_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->device_serial_number = u_device_serial_number.real;
      offset += sizeof(this->device_serial_number);
      this->temperature_grade =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->temperature_grade);
      this->build_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->build_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->build_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->build_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->build_time.sec);
      this->build_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->build_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->build_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->build_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->build_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_has_color_sensor;
      u_has_color_sensor.base = 0;
      u_has_color_sensor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_color_sensor = u_has_color_sensor.real;
      offset += sizeof(this->has_color_sensor);
      union {
        bool real;
        uint8_t base;
      } u_has_ir_cut_filter;
      u_has_ir_cut_filter.base = 0;
      u_has_ir_cut_filter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_ir_cut_filter = u_has_ir_cut_filter.real;
      offset += sizeof(this->has_ir_cut_filter);
      union {
        bool real;
        uint8_t base;
      } u_has_polarization_filter;
      u_has_polarization_filter.base = 0;
      u_has_polarization_filter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_polarization_filter = u_has_polarization_filter.real;
      offset += sizeof(this->has_polarization_filter);
      union {
        float real;
        uint32_t base;
      } u_nd_filter_transmittance;
      u_nd_filter_transmittance.base = 0;
      u_nd_filter_transmittance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nd_filter_transmittance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nd_filter_transmittance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nd_filter_transmittance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nd_filter_transmittance = u_nd_filter_transmittance.real;
      offset += sizeof(this->nd_filter_transmittance);
      union {
        float real;
        uint32_t base;
      } u_optics_focal_length;
      u_optics_focal_length.base = 0;
      u_optics_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_optics_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_optics_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_optics_focal_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->optics_focal_length = u_optics_focal_length.real;
      offset += sizeof(this->optics_focal_length);
      union {
        float real;
        uint32_t base;
      } u_optics_aperture;
      u_optics_aperture.base = 0;
      u_optics_aperture.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_optics_aperture.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_optics_aperture.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_optics_aperture.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->optics_aperture = u_optics_aperture.real;
      offset += sizeof(this->optics_aperture);
      union {
        float real;
        uint32_t base;
      } u_optics_image_circle;
      u_optics_image_circle.base = 0;
      u_optics_image_circle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_optics_image_circle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_optics_image_circle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_optics_image_circle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->optics_image_circle = u_optics_image_circle.real;
      offset += sizeof(this->optics_image_circle);
      this->electronics_revision =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->electronics_revision);
      this->sensor_board_revision =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor_board_revision);
      this->mechanics_revision =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mechanics_revision);
      union {
        uint64_t real;
        uint32_t base;
      } u_driver_version;
      u_driver_version.base = 0;
      u_driver_version.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_driver_version.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_driver_version.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_driver_version.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->driver_version = u_driver_version.real;
      offset += sizeof(this->driver_version);
      union {
        uint64_t real;
        uint32_t base;
      } u_firmware_version;
      u_firmware_version.base = 0;
      u_firmware_version.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_firmware_version.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_firmware_version.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_firmware_version.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->firmware_version = u_firmware_version.real;
      offset += sizeof(this->firmware_version);
      union {
        uint64_t real;
        uint32_t base;
      } u_fpga_version;
      u_fpga_version.base = 0;
      u_fpga_version.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fpga_version.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fpga_version.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fpga_version.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fpga_version = u_fpga_version.real;
      offset += sizeof(this->fpga_version);
      union {
        float real;
        uint32_t base;
      } u_frame_rate;
      u_frame_rate.base = 0;
      u_frame_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frame_rate = u_frame_rate.real;
      offset += sizeof(this->frame_rate);
      this->cpu_usage =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cpu_usage);
      this->mem_usage =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mem_usage);
      union {
        uint64_t real;
        uint32_t base;
      } u_disk_bytes_free;
      u_disk_bytes_free.base = 0;
      u_disk_bytes_free.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_disk_bytes_free.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_disk_bytes_free.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_disk_bytes_free.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->disk_bytes_free = u_disk_bytes_free.real;
      offset += sizeof(this->disk_bytes_free);
      this->time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.sec);
      this->time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.nsec);
      this->uptime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime.sec);
      this->uptime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime.nsec);
     return offset;
    }

    const char * getType(){ return "autonomos_stereo_camera_msgs/CameraStatus"; };
    const char * getMD5(){ return "bfcf6c124e591609ea6e8e041cc6fe2a"; };

  };

}
#endif