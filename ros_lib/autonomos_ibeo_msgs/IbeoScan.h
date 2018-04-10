#ifndef _ROS_autonomos_ibeo_msgs_IbeoScan_h
#define _ROS_autonomos_ibeo_msgs_IbeoScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "ros/duration.h"
#include "autonomos_ibeo_msgs/IbeoScannerInfo.h"
#include "autonomos_ibeo_msgs/IbeoScanPoint.h"

namespace autonomos_ibeo_msgs
{

  class IbeoScan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ros::Time _start_type;
      _start_type start;
      typedef ros::Duration _duration_type;
      _duration_type duration;
      typedef uint16_t _scan_number_type;
      _scan_number_type scan_number;
      typedef uint32_t _flags_type;
      _flags_type flags;
      uint32_t scanner_infos_length;
      typedef autonomos_ibeo_msgs::IbeoScannerInfo _scanner_infos_type;
      _scanner_infos_type st_scanner_infos;
      _scanner_infos_type * scanner_infos;
      uint32_t points_length;
      typedef autonomos_ibeo_msgs::IbeoScanPoint _points_type;
      _points_type st_points;
      _points_type * points;
      enum { GROUND_DETECTION_WAS_PERFORMED =     1  };
      enum { DIRT_DETECTION_WAS_PERFORMED =     2  };
      enum { CLUTTER_DETECTION_WAS_PERFORMED =     4  };
      enum { SCAN_IS_RESULT_FROM_SCAN_DATA_FUSION =   512  };
      enum { MIRROR_SIDE =  1024  };
      enum { VEHICLE_COORDINATE_SYSTEM =  2048  };

    IbeoScan():
      header(),
      start(),
      duration(),
      scan_number(0),
      flags(0),
      scanner_infos_length(0), scanner_infos(NULL),
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.sec);
      *(outbuffer + offset + 0) = (this->start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start.nsec);
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      *(outbuffer + offset + 0) = (this->scan_number >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_number >> (8 * 1)) & 0xFF;
      offset += sizeof(this->scan_number);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags);
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
      this->start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.sec);
      this->start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start.nsec);
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      this->scan_number =  ((uint16_t) (*(inbuffer + offset)));
      this->scan_number |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->scan_number);
      this->flags =  ((uint32_t) (*(inbuffer + offset)));
      this->flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flags);
      uint32_t scanner_infos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scanner_infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scanner_infos_length);
      if(scanner_infos_lengthT > scanner_infos_length)
        this->scanner_infos = (autonomos_ibeo_msgs::IbeoScannerInfo*)realloc(this->scanner_infos, scanner_infos_lengthT * sizeof(autonomos_ibeo_msgs::IbeoScannerInfo));
      scanner_infos_length = scanner_infos_lengthT;
      for( uint32_t i = 0; i < scanner_infos_length; i++){
      offset += this->st_scanner_infos.deserialize(inbuffer + offset);
        memcpy( &(this->scanner_infos[i]), &(this->st_scanner_infos), sizeof(autonomos_ibeo_msgs::IbeoScannerInfo));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (autonomos_ibeo_msgs::IbeoScanPoint*)realloc(this->points, points_lengthT * sizeof(autonomos_ibeo_msgs::IbeoScanPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(autonomos_ibeo_msgs::IbeoScanPoint));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoScan"; };
    const char * getMD5(){ return "4a52ffc2ab348bc384c16286f7963a1a"; };

  };

}
#endif