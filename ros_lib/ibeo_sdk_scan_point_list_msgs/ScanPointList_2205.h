#ifndef _ROS_ibeo_sdk_scan_point_list_msgs_ScanPointList_2205_h
#define _ROS_ibeo_sdk_scan_point_list_msgs_ScanPointList_2205_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ibeo_sdk_time_msgs/NTP64_2205.h"
#include "ibeo_sdk_scanner_info_msgs/ScannerInfo_2205.h"
#include "ibeo_sdk_scan_point_msgs/ScanPoint_2205.h"

namespace ibeo_sdk_scan_point_list_msgs
{

  class ScanPointList_2205 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ibeo_sdk_time_msgs::NTP64_2205 _scan_start_time_type;
      _scan_start_time_type scan_start_time;
      typedef uint32_t _scan_end_time_offset_type;
      _scan_end_time_offset_type scan_end_time_offset;
      typedef uint32_t _flags_type;
      _flags_type flags;
      typedef uint16_t _scan_number_type;
      _scan_number_type scan_number;
      typedef uint16_t _num_points_type;
      _num_points_type num_points;
      typedef uint16_t _num_scanner_infos_type;
      _num_scanner_infos_type num_scanner_infos;
      typedef uint8_t _reserved0_type;
      _reserved0_type reserved0;
      typedef uint16_t _reserved1_type;
      _reserved1_type reserved1;
      uint32_t scanner_infos_length;
      typedef ibeo_sdk_scanner_info_msgs::ScannerInfo_2205 _scanner_infos_type;
      _scanner_infos_type st_scanner_infos;
      _scanner_infos_type * scanner_infos;
      uint32_t points_length;
      typedef ibeo_sdk_scan_point_msgs::ScanPoint_2205 _points_type;
      _points_type st_points;
      _points_type * points;

    ScanPointList_2205():
      header(),
      scan_start_time(),
      scan_end_time_offset(0),
      flags(0),
      scan_number(0),
      num_points(0),
      num_scanner_infos(0),
      reserved0(0),
      reserved1(0),
      scanner_infos_length(0), scanner_infos(NULL),
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->scan_start_time.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->scan_end_time_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_end_time_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scan_end_time_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scan_end_time_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_end_time_offset);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->scan_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scan_number);
      *(outbuffer + offset + 0) = (this->num_points >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_points >> (8 * 1)) & 0xFF;
      offset += sizeof(this->num_points);
      *(outbuffer + offset + 0) = (this->num_scanner_infos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_scanner_infos >> (8 * 1)) & 0xFF;
      offset += sizeof(this->num_scanner_infos);
      *(outbuffer + offset + 0) = (this->reserved0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved0);
      *(outbuffer + offset + 0) = (this->reserved1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reserved1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reserved1);
      *(outbuffer + offset + 0) = (this->scanner_infos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scanner_infos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scanner_infos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scanner_infos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scanner_infos_length);
      for( uint32_t i = 0; i < scanner_infos_length; i++){
      offset += this->scanner_infos[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->scan_start_time.deserialize(inbuffer + offset);
      this->scan_end_time_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->scan_end_time_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->scan_end_time_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->scan_end_time_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->scan_end_time_offset);
      this->flags =  ((uint32_t) (*(inbuffer + offset)));
      this->flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flags);
      this->scan_number =  ((uint16_t) (*(inbuffer + offset)));
      this->scan_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scan_number);
      this->num_points =  ((uint16_t) (*(inbuffer + offset)));
      this->num_points |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->num_points);
      this->num_scanner_infos =  ((uint16_t) (*(inbuffer + offset)));
      this->num_scanner_infos |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->num_scanner_infos);
      this->reserved0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved0);
      this->reserved1 =  ((uint16_t) (*(inbuffer + offset)));
      this->reserved1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reserved1);
      uint32_t scanner_infos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scanner_infos_length);
      if(scanner_infos_lengthT > scanner_infos_length)
        this->scanner_infos = (ibeo_sdk_scanner_info_msgs::ScannerInfo_2205*)realloc(this->scanner_infos, scanner_infos_lengthT * sizeof(ibeo_sdk_scanner_info_msgs::ScannerInfo_2205));
      scanner_infos_length = scanner_infos_lengthT;
      for( uint32_t i = 0; i < scanner_infos_length; i++){
      offset += this->st_scanner_infos.deserialize(inbuffer + offset);
        memcpy( &(this->scanner_infos[i]), &(this->st_scanner_infos), sizeof(ibeo_sdk_scanner_info_msgs::ScannerInfo_2205));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (ibeo_sdk_scan_point_msgs::ScanPoint_2205*)realloc(this->points, points_lengthT * sizeof(ibeo_sdk_scan_point_msgs::ScanPoint_2205));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(ibeo_sdk_scan_point_msgs::ScanPoint_2205));
      }
     return offset;
    }

    const char * getType(){ return "ibeo_sdk_scan_point_list_msgs/ScanPointList_2205"; };
    const char * getMD5(){ return "22a839c4da83446c9864109381debd8c"; };

  };

}
#endif