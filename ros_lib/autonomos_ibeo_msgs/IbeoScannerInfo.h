#ifndef _ROS_autonomos_ibeo_msgs_IbeoScannerInfo_h
#define _ROS_autonomos_ibeo_msgs_IbeoScannerInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "autonomos_ibeo_msgs/IbeoScannerResolution.h"

namespace autonomos_ibeo_msgs
{

  class IbeoScannerInfo : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _start_angle_type;
      _start_angle_type start_angle;
      typedef float _end_angle_type;
      _end_angle_type end_angle;
      typedef uint32_t _scan_flags_type;
      _scan_flags_type scan_flags;
      typedef uint16_t _scanner_status_type;
      _scanner_status_type scanner_status;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      autonomos_ibeo_msgs::IbeoScannerResolution resolutions[8];
      enum { GROUND_DETECTION_WAS_PERFORMED =     1  };
      enum { DIRT_DETECTION_WAS_PERFORMED =     2  };
      enum { CLUTTER_DETECTION_WAS_PERFORMED =     4  };
      enum { SCAN_IS_RESULT_FROM_SCAN_DATA_FUSION =   512  };
      enum { MIRROR_SIDE =  1024  };

    IbeoScannerInfo():
      id(0),
      start_angle(0),
      end_angle(0),
      scan_flags(0),
      scanner_status(0),
      pose(),
      resolutions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
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
      *(outbuffer + offset + 0) = (this->scan_flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scan_flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scan_flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_flags);
      *(outbuffer + offset + 0) = (this->scanner_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scanner_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scanner_status);
      offset += this->pose.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 8; i++){
      offset += this->resolutions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
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
      this->scan_flags =  ((uint32_t) (*(inbuffer + offset)));
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->scan_flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->scan_flags);
      this->scanner_status =  ((uint16_t) (*(inbuffer + offset)));
      this->scanner_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scanner_status);
      offset += this->pose.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 8; i++){
      offset += this->resolutions[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoScannerInfo"; };
    const char * getMD5(){ return "6a59a3d1c007f2d551ea47946bb54f6c"; };

  };

}
#endif