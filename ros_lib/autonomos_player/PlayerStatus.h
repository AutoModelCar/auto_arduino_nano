#ifndef _ROS_autonomos_player_PlayerStatus_h
#define _ROS_autonomos_player_PlayerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace autonomos_player
{

  class PlayerStatus : public ros::Msg
  {
    public:
      typedef bool _is_playing_type;
      _is_playing_type is_playing;
      uint32_t filenames_length;
      typedef char* _filenames_type;
      _filenames_type st_filenames;
      _filenames_type * filenames;
      typedef ros::Time _start_time_type;
      _start_time_type start_time;
      typedef ros::Time _current_time_type;
      _current_time_type current_time;
      typedef ros::Time _end_time_type;
      _end_time_type end_time;
      typedef bool _is_loop_enabled_type;
      _is_loop_enabled_type is_loop_enabled;
      typedef float _playback_speed_factor_type;
      _playback_speed_factor_type playback_speed_factor;
      typedef bool _is_publishing_clock_type;
      _is_publishing_clock_type is_publishing_clock;
      uint32_t topics_length;
      typedef char* _topics_type;
      _topics_type st_topics;
      _topics_type * topics;
      uint32_t pause_topics_length;
      typedef char* _pause_topics_type;
      _pause_topics_type st_pause_topics;
      _pause_topics_type * pause_topics;

    PlayerStatus():
      is_playing(0),
      filenames_length(0), filenames(NULL),
      start_time(),
      current_time(),
      end_time(),
      is_loop_enabled(0),
      playback_speed_factor(0),
      is_publishing_clock(0),
      topics_length(0), topics(NULL),
      pause_topics_length(0), pause_topics(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_playing;
      u_is_playing.real = this->is_playing;
      *(outbuffer + offset + 0) = (u_is_playing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_playing);
      *(outbuffer + offset + 0) = (this->filenames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->filenames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->filenames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->filenames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filenames_length);
      for( uint32_t i = 0; i < filenames_length; i++){
      uint32_t length_filenamesi = strlen(this->filenames[i]);
      varToArr(outbuffer + offset, length_filenamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->filenames[i], length_filenamesi);
      offset += length_filenamesi;
      }
      *(outbuffer + offset + 0) = (this->start_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time.sec);
      *(outbuffer + offset + 0) = (this->start_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_time.nsec);
      *(outbuffer + offset + 0) = (this->current_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_time.sec);
      *(outbuffer + offset + 0) = (this->current_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_time.nsec);
      *(outbuffer + offset + 0) = (this->end_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time.sec);
      *(outbuffer + offset + 0) = (this->end_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_is_loop_enabled;
      u_is_loop_enabled.real = this->is_loop_enabled;
      *(outbuffer + offset + 0) = (u_is_loop_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_loop_enabled);
      union {
        float real;
        uint32_t base;
      } u_playback_speed_factor;
      u_playback_speed_factor.real = this->playback_speed_factor;
      *(outbuffer + offset + 0) = (u_playback_speed_factor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_playback_speed_factor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_playback_speed_factor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_playback_speed_factor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->playback_speed_factor);
      union {
        bool real;
        uint8_t base;
      } u_is_publishing_clock;
      u_is_publishing_clock.real = this->is_publishing_clock;
      *(outbuffer + offset + 0) = (u_is_publishing_clock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_publishing_clock);
      *(outbuffer + offset + 0) = (this->topics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topics_length);
      for( uint32_t i = 0; i < topics_length; i++){
      uint32_t length_topicsi = strlen(this->topics[i]);
      varToArr(outbuffer + offset, length_topicsi);
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_topicsi);
      offset += length_topicsi;
      }
      *(outbuffer + offset + 0) = (this->pause_topics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pause_topics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pause_topics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pause_topics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pause_topics_length);
      for( uint32_t i = 0; i < pause_topics_length; i++){
      uint32_t length_pause_topicsi = strlen(this->pause_topics[i]);
      varToArr(outbuffer + offset, length_pause_topicsi);
      offset += 4;
      memcpy(outbuffer + offset, this->pause_topics[i], length_pause_topicsi);
      offset += length_pause_topicsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_playing;
      u_is_playing.base = 0;
      u_is_playing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_playing = u_is_playing.real;
      offset += sizeof(this->is_playing);
      uint32_t filenames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      filenames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      filenames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      filenames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->filenames_length);
      if(filenames_lengthT > filenames_length)
        this->filenames = (char**)realloc(this->filenames, filenames_lengthT * sizeof(char*));
      filenames_length = filenames_lengthT;
      for( uint32_t i = 0; i < filenames_length; i++){
      uint32_t length_st_filenames;
      arrToVar(length_st_filenames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_filenames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_filenames-1]=0;
      this->st_filenames = (char *)(inbuffer + offset-1);
      offset += length_st_filenames;
        memcpy( &(this->filenames[i]), &(this->st_filenames), sizeof(char*));
      }
      this->start_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time.sec);
      this->start_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_time.nsec);
      this->current_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->current_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_time.sec);
      this->current_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->current_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_time.nsec);
      this->end_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time.sec);
      this->end_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->end_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->end_time.nsec);
      union {
        bool real;
        uint8_t base;
      } u_is_loop_enabled;
      u_is_loop_enabled.base = 0;
      u_is_loop_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_loop_enabled = u_is_loop_enabled.real;
      offset += sizeof(this->is_loop_enabled);
      union {
        float real;
        uint32_t base;
      } u_playback_speed_factor;
      u_playback_speed_factor.base = 0;
      u_playback_speed_factor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_playback_speed_factor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_playback_speed_factor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_playback_speed_factor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->playback_speed_factor = u_playback_speed_factor.real;
      offset += sizeof(this->playback_speed_factor);
      union {
        bool real;
        uint8_t base;
      } u_is_publishing_clock;
      u_is_publishing_clock.base = 0;
      u_is_publishing_clock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_publishing_clock = u_is_publishing_clock.real;
      offset += sizeof(this->is_publishing_clock);
      uint32_t topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topics_length);
      if(topics_lengthT > topics_length)
        this->topics = (char**)realloc(this->topics, topics_lengthT * sizeof(char*));
      topics_length = topics_lengthT;
      for( uint32_t i = 0; i < topics_length; i++){
      uint32_t length_st_topics;
      arrToVar(length_st_topics, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topics; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topics-1]=0;
      this->st_topics = (char *)(inbuffer + offset-1);
      offset += length_st_topics;
        memcpy( &(this->topics[i]), &(this->st_topics), sizeof(char*));
      }
      uint32_t pause_topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pause_topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pause_topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pause_topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pause_topics_length);
      if(pause_topics_lengthT > pause_topics_length)
        this->pause_topics = (char**)realloc(this->pause_topics, pause_topics_lengthT * sizeof(char*));
      pause_topics_length = pause_topics_lengthT;
      for( uint32_t i = 0; i < pause_topics_length; i++){
      uint32_t length_st_pause_topics;
      arrToVar(length_st_pause_topics, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_pause_topics; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_pause_topics-1]=0;
      this->st_pause_topics = (char *)(inbuffer + offset-1);
      offset += length_st_pause_topics;
        memcpy( &(this->pause_topics[i]), &(this->st_pause_topics), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "autonomos_player/PlayerStatus"; };
    const char * getMD5(){ return "99b5249837fff95c60ba7afaff753de0"; };

  };

}
#endif