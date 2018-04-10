#ifndef _ROS_autonomos_obstacle_msgs_Obstacle_h
#define _ROS_autonomos_obstacle_msgs_Obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/Odometry.h"
#include "autonomos_obstacle_msgs/BoundingBox.h"
#include "autonomos_obstacle_msgs/Contour.h"
#include "ros/time.h"

namespace autonomos_obstacle_msgs
{

  class Obstacle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _id_type;
      _id_type id;
      typedef nav_msgs::Odometry _odom_type;
      _odom_type odom;
      typedef autonomos_obstacle_msgs::BoundingBox _bounding_box_type;
      _bounding_box_type bounding_box;
      typedef autonomos_obstacle_msgs::Contour _contour_type;
      _contour_type contour;
      typedef uint16_t _classification_type;
      _classification_type classification;
      typedef float _classification_certainty_type;
      _classification_certainty_type classification_certainty;
      typedef ros::Time _first_observed_type;
      _first_observed_type first_observed;
      typedef ros::Time _last_observed_type;
      _last_observed_type last_observed;
      enum { UNCLASSIFIED =  0 };
      enum { UNKNOWN_SMALL =  1 };
      enum { UNKNOWN_BIG =  2 };
      enum { PEDESTRIAN =  3 };
      enum { BIKE =  4 };
      enum { CAR =  5 };
      enum { TRUCK =  6 };
      enum { ELEVATED =  12 };

    Obstacle():
      header(),
      id(0),
      odom(),
      bounding_box(),
      contour(),
      classification(0),
      classification_certainty(0),
      first_observed(),
      last_observed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->odom.serialize(outbuffer + offset);
      offset += this->bounding_box.serialize(outbuffer + offset);
      offset += this->contour.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->classification >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification >> (8 * 1)) & 0xFF;
      offset += sizeof(this->classification);
      union {
        float real;
        uint32_t base;
      } u_classification_certainty;
      u_classification_certainty.real = this->classification_certainty;
      *(outbuffer + offset + 0) = (u_classification_certainty.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_classification_certainty.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_classification_certainty.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_classification_certainty.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_certainty);
      *(outbuffer + offset + 0) = (this->first_observed.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->first_observed.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->first_observed.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->first_observed.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->first_observed.sec);
      *(outbuffer + offset + 0) = (this->first_observed.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->first_observed.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->first_observed.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->first_observed.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->first_observed.nsec);
      *(outbuffer + offset + 0) = (this->last_observed.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_observed.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_observed.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_observed.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_observed.sec);
      *(outbuffer + offset + 0) = (this->last_observed.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_observed.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_observed.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_observed.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_observed.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += this->odom.deserialize(inbuffer + offset);
      offset += this->bounding_box.deserialize(inbuffer + offset);
      offset += this->contour.deserialize(inbuffer + offset);
      this->classification =  ((uint16_t) (*(inbuffer + offset)));
      this->classification |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->classification);
      union {
        float real;
        uint32_t base;
      } u_classification_certainty;
      u_classification_certainty.base = 0;
      u_classification_certainty.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_classification_certainty.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_classification_certainty.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_classification_certainty.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->classification_certainty = u_classification_certainty.real;
      offset += sizeof(this->classification_certainty);
      this->first_observed.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->first_observed.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->first_observed.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->first_observed.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->first_observed.sec);
      this->first_observed.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->first_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->first_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->first_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->first_observed.nsec);
      this->last_observed.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_observed.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_observed.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_observed.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_observed.sec);
      this->last_observed.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->last_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->last_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->last_observed.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->last_observed.nsec);
     return offset;
    }

    const char * getType(){ return "autonomos_obstacle_msgs/Obstacle"; };
    const char * getMD5(){ return "846ad5352c235d7c809a4ea5229629d7"; };

  };

}
#endif