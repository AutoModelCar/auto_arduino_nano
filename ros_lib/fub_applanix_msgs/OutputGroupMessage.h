#ifndef _ROS_fub_applanix_msgs_OutputGroupMessage_h
#define _ROS_fub_applanix_msgs_OutputGroupMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fub_applanix_msgs
{

  class OutputGroupMessage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _id_type;
      _id_type id;
      uint32_t data_length;
      typedef uint8_t _data_type;
      _data_type st_data;
      _data_type * data;
      enum { NAV =  1    };
      enum { STATUS_PERF =  2    };
      enum { STATUS_GNSS_PRIMARY =  3    };
      enum { IMU =  4    };
      enum { EVENTS_1 =  5    };
      enum { EVENTS_2 =  6    };
      enum { STATUS_PPS =  7    };
      enum { STATUS_LOGGING =  8    };
      enum { GAMS =  9    };
      enum { STATUS_GENERAL =  10   };
      enum { STATUS_GNSS_SECONDARY =  11   };
      enum { STATUS_GNSS_AUX_1 =  12   };
      enum { STATUS_GNSS_AUX_2 =  13   };
      enum { STATUS_INSTALLATION =  14   };
      enum { DMI =  15   };
      enum { STATUS_USER_TIME =  17   };
      enum { STATUS_IIN =  20   };
      enum { STATUS_BASE_GNSS_1_MODEM =  21   };
      enum { STATUS_BASE_GNSS_2_MODEM =  22   };
      enum { RAW_GNSS_AUX_1_DISPLAY =  23   };
      enum { RAW_GNSS_AUX_2_DISPLAY =  24   };
      enum { STATUS_DGPS =  25   };
      enum { STATUS_DGPS_STATIONS =  26   };
      enum { EVENTS_3 =  30   };
      enum { EVENTS_4 =  31   };
      enum { EVENTS_5 =  32   };
      enum { EVENTS_6 =  33   };
      enum { STATUS_VERSION =  99   };
      enum { RAW_GNSS_PRIMARY =  10001  };
      enum { RAW_IMU =  10002  };
      enum { RAW_PPS =  10003  };
      enum { RAW_EVENTS_1 =  10004  };
      enum { RAW_EVENTS_2 =  10005  };
      enum { RAW_DMI =  10006  };
      enum { RAW_GNSS_AUX_1 =  10007  };
      enum { RAW_GNSS_AUX_2 =  10008  };
      enum { RAW_GNSS_SECONDARY =  10009  };
      enum { RAW_BASE_GNSS_1 =  10011  };
      enum { RAW_BASE_GNSS_2 =  10012  };

    OutputGroupMessage():
      header(),
      id(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint16_t) (*(inbuffer + offset)));
      this->id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->id);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/OutputGroupMessage"; };
    const char * getMD5(){ return "9f216e0aa1c85281d754928524b38945"; };

  };

}
#endif