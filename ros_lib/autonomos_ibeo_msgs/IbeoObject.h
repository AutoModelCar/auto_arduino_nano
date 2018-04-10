#ifndef _ROS_autonomos_ibeo_msgs_IbeoObject_h
#define _ROS_autonomos_ibeo_msgs_IbeoObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "autonomos_ibeo_msgs/IbeoPoint2D.h"

namespace autonomos_ibeo_msgs
{

  class IbeoObject : public ros::Msg
  {
    public:
      typedef uint16_t _object_id_type;
      _object_id_type object_id;
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      typedef uint32_t _age_in_scans_type;
      _age_in_scans_type age_in_scans;
      typedef uint16_t _prediction_age_type;
      _prediction_age_type prediction_age;
      typedef uint16_t _classification_type;
      _classification_type classification;
      typedef uint32_t _classification_age_type;
      _classification_age_type classification_age;
      typedef uint16_t _classification_certainty_type;
      _classification_certainty_type classification_certainty;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _bounding_box_center_type;
      _bounding_box_center_type bounding_box_center;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _bounding_box_size_type;
      _bounding_box_size_type bounding_box_size;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _object_box_center_type;
      _object_box_center_type object_box_center;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _object_box_sigma_type;
      _object_box_sigma_type object_box_sigma;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _object_box_size_type;
      _object_box_size_type object_box_size;
      typedef uint16_t _reference_point_location_type;
      _reference_point_location_type reference_point_location;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _reference_point_type;
      _reference_point_type reference_point;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _reference_point_sigma_type;
      _reference_point_sigma_type reference_point_sigma;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _closest_point_type;
      _closest_point_type closest_point;
      typedef float _object_orientation_type;
      _object_orientation_type object_orientation;
      typedef float _object_orientation_sigma_type;
      _object_orientation_sigma_type object_orientation_sigma;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _absolute_velocity_type;
      _absolute_velocity_type absolute_velocity;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _absolute_velocity_sigma_type;
      _absolute_velocity_sigma_type absolute_velocity_sigma;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _relative_velocity_type;
      _relative_velocity_type relative_velocity;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _relative_velocity_sigma_type;
      _relative_velocity_sigma_type relative_velocity_sigma;
      uint32_t contour_points_length;
      typedef autonomos_ibeo_msgs::IbeoPoint2D _contour_points_type;
      _contour_points_type st_contour_points;
      _contour_points_type * contour_points;
      enum { UNCLASSIFIED =  0 };
      enum { UNKNOWN_SMALL =  1 };
      enum { UNKNOWN_BIG =  2 };
      enum { PEDESTRIAN =  3 };
      enum { BIKE =  4 };
      enum { CAR =  5 };
      enum { TRUCK =  6 };
      enum { UNDERDRIVABLE =  12 };

    IbeoObject():
      object_id(0),
      timestamp(),
      age_in_scans(0),
      prediction_age(0),
      classification(0),
      classification_age(0),
      classification_certainty(0),
      bounding_box_center(),
      bounding_box_size(),
      object_box_center(),
      object_box_sigma(),
      object_box_size(),
      reference_point_location(0),
      reference_point(),
      reference_point_sigma(),
      closest_point(),
      object_orientation(0),
      object_orientation_sigma(0),
      absolute_velocity(),
      absolute_velocity_sigma(),
      relative_velocity(),
      relative_velocity_sigma(),
      contour_points_length(0), contour_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->object_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_id);
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      *(outbuffer + offset + 0) = (this->age_in_scans >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age_in_scans >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age_in_scans >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age_in_scans >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age_in_scans);
      *(outbuffer + offset + 0) = (this->prediction_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->prediction_age >> (8 * 1)) & 0xFF;
      offset += sizeof(this->prediction_age);
      *(outbuffer + offset + 0) = (this->classification >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification >> (8 * 1)) & 0xFF;
      offset += sizeof(this->classification);
      *(outbuffer + offset + 0) = (this->classification_age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_age >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classification_age >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classification_age >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classification_age);
      *(outbuffer + offset + 0) = (this->classification_certainty >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classification_certainty >> (8 * 1)) & 0xFF;
      offset += sizeof(this->classification_certainty);
      offset += this->bounding_box_center.serialize(outbuffer + offset);
      offset += this->bounding_box_size.serialize(outbuffer + offset);
      offset += this->object_box_center.serialize(outbuffer + offset);
      offset += this->object_box_sigma.serialize(outbuffer + offset);
      offset += this->object_box_size.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->reference_point_location >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_point_location >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reference_point_location);
      offset += this->reference_point.serialize(outbuffer + offset);
      offset += this->reference_point_sigma.serialize(outbuffer + offset);
      offset += this->closest_point.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_orientation;
      u_object_orientation.real = this->object_orientation;
      *(outbuffer + offset + 0) = (u_object_orientation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_orientation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_orientation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_orientation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_orientation);
      union {
        float real;
        uint32_t base;
      } u_object_orientation_sigma;
      u_object_orientation_sigma.real = this->object_orientation_sigma;
      *(outbuffer + offset + 0) = (u_object_orientation_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_orientation_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_orientation_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_orientation_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_orientation_sigma);
      offset += this->absolute_velocity.serialize(outbuffer + offset);
      offset += this->absolute_velocity_sigma.serialize(outbuffer + offset);
      offset += this->relative_velocity.serialize(outbuffer + offset);
      offset += this->relative_velocity_sigma.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contour_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contour_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contour_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contour_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contour_points_length);
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->contour_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->object_id =  ((uint16_t) (*(inbuffer + offset)));
      this->object_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->object_id);
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      this->age_in_scans =  ((uint32_t) (*(inbuffer + offset)));
      this->age_in_scans |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age_in_scans |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age_in_scans |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age_in_scans);
      this->prediction_age =  ((uint16_t) (*(inbuffer + offset)));
      this->prediction_age |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->prediction_age);
      this->classification =  ((uint16_t) (*(inbuffer + offset)));
      this->classification |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->classification);
      this->classification_age =  ((uint32_t) (*(inbuffer + offset)));
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->classification_age |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->classification_age);
      this->classification_certainty =  ((uint16_t) (*(inbuffer + offset)));
      this->classification_certainty |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->classification_certainty);
      offset += this->bounding_box_center.deserialize(inbuffer + offset);
      offset += this->bounding_box_size.deserialize(inbuffer + offset);
      offset += this->object_box_center.deserialize(inbuffer + offset);
      offset += this->object_box_sigma.deserialize(inbuffer + offset);
      offset += this->object_box_size.deserialize(inbuffer + offset);
      this->reference_point_location =  ((uint16_t) (*(inbuffer + offset)));
      this->reference_point_location |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->reference_point_location);
      offset += this->reference_point.deserialize(inbuffer + offset);
      offset += this->reference_point_sigma.deserialize(inbuffer + offset);
      offset += this->closest_point.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_object_orientation;
      u_object_orientation.base = 0;
      u_object_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_orientation = u_object_orientation.real;
      offset += sizeof(this->object_orientation);
      union {
        float real;
        uint32_t base;
      } u_object_orientation_sigma;
      u_object_orientation_sigma.base = 0;
      u_object_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->object_orientation_sigma = u_object_orientation_sigma.real;
      offset += sizeof(this->object_orientation_sigma);
      offset += this->absolute_velocity.deserialize(inbuffer + offset);
      offset += this->absolute_velocity_sigma.deserialize(inbuffer + offset);
      offset += this->relative_velocity.deserialize(inbuffer + offset);
      offset += this->relative_velocity_sigma.deserialize(inbuffer + offset);
      uint32_t contour_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contour_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contour_points_length);
      if(contour_points_lengthT > contour_points_length)
        this->contour_points = (autonomos_ibeo_msgs::IbeoPoint2D*)realloc(this->contour_points, contour_points_lengthT * sizeof(autonomos_ibeo_msgs::IbeoPoint2D));
      contour_points_length = contour_points_lengthT;
      for( uint32_t i = 0; i < contour_points_length; i++){
      offset += this->st_contour_points.deserialize(inbuffer + offset);
        memcpy( &(this->contour_points[i]), &(this->st_contour_points), sizeof(autonomos_ibeo_msgs::IbeoPoint2D));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_ibeo_msgs/IbeoObject"; };
    const char * getMD5(){ return "71379777845577f5a8a490e2b5da15e5"; };

  };

}
#endif