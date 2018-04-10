#ifndef _ROS_fub_applanix_msgs_GeneralStatus_h
#define _ROS_fub_applanix_msgs_GeneralStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fub_applanix_msgs/TimeDistance.h"

namespace fub_applanix_msgs
{

  class GeneralStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef fub_applanix_msgs::TimeDistance _td_type;
      _td_type td;
      typedef uint32_t _status_A_type;
      _status_A_type status_A;
      typedef uint32_t _status_B_type;
      _status_B_type status_B;
      typedef uint8_t _primary_gps_mode_type;
      _primary_gps_mode_type primary_gps_mode;
      typedef uint32_t _status_C_type;
      _status_C_type status_C;
      typedef uint32_t _fdir_level_1_status_type;
      _fdir_level_1_status_type fdir_level_1_status;
      typedef uint16_t _fdir_level_1_imu_failures_type;
      _fdir_level_1_imu_failures_type fdir_level_1_imu_failures;
      typedef uint16_t _fdir_level_2_status_type;
      _fdir_level_2_status_type fdir_level_2_status;
      typedef uint16_t _fdir_level_3_status_type;
      _fdir_level_3_status_type fdir_level_3_status;
      typedef uint16_t _fdir_level_4_status_type;
      _fdir_level_4_status_type fdir_level_4_status;
      typedef uint16_t _fdir_level_5_status_type;
      _fdir_level_5_status_type fdir_level_5_status;
      typedef uint32_t _extended_status_type;
      _extended_status_type extended_status;
      enum { STATUS_A_FLAG_COARSE_LEVELING_ACTIVE =  1           };
      enum { STATUS_A_FLAG_COARSE_LEVELING_FAILED =  2           };
      enum { STATUS_A_FLAG_QUADRANT_RESOLVED =  4           };
      enum { STATUS_A_FLAG_FINE_ALIGN_ACTIVE =  8           };
      enum { STATUS_A_FLAG_INERTIAL_NAVIGATOR_INITIALIZED =  16          };
      enum { STATUS_A_FLAG_INERTIAL_NAVIGATOR_ALIGNMENT_ACTIVE =  32          };
      enum { STATUS_A_FLAG_DEGRADED_NAVIGATION_SOLUTION =  64          };
      enum { STATUS_A_FLAG_FULL_NAVIGATION_SOLUTION =  128         };
      enum { STATUS_A_FLAG_INITIAL_POSITION_VALID =  256         };
      enum { STATUS_A_FLAG_REFERENCE_TO_PRIMARY_GPS_LEVER_ARMS_IS_ZERO =  512         };
      enum { STATUS_A_FLAG_REFERENCE_TO_SENSOR_1_LEVER_ARMS_IS_ZERO =  1024        };
      enum { STATUS_A_FLAG_REFERENCE_TO_SENSOR_2_LEVER_ARMS_IS_ZERO =  2048        };
      enum { STATUS_A_FLAG_LOGGING_PORT_FILE_WRITE_ERROR =  4096        };
      enum { STATUS_A_FLAG_LOGGING_PORT_FILE_OPEN =  8192        };
      enum { STATUS_A_FLAG_LOGGING_PORT_LOGGING_ENABLED =  16384       };
      enum { STATUS_A_FLAG_LOGGING_PORT_DEVICE_FULL =  32768       };
      enum { STATUS_A_FLAG_RAM_CONFIGURATION_DIFFERS_FROM_NVM =  65536       };
      enum { STATUS_A_FLAG_NVM_WRITE_SUCCESSFUL =  131072      };
      enum { STATUS_A_FLAG_NVM_WRITE_FAIL =  262144      };
      enum { STATUS_A_FLAG_NVM_READ_FAIL =  524288      };
      enum { STATUS_A_FLAG_CPU_LOAD_EXCEEDS_55_PERCENT =  1048576     };
      enum { STATUS_A_FLAG_CPU_LOAD_EXCEEDS_85_PERCENT =  2097152     };
      enum { STATUS_B_FLAG_USER_ATTITUDE_RMS_PERFORMANCE =  1           };
      enum { STATUS_B_FLAG_USER_HEADING_RMS_PERFORMANCE =  2           };
      enum { STATUS_B_FLAG_USER_POSITION_RMS_PERFORMANCE =  4           };
      enum { STATUS_B_FLAG_USER_VELOCITY_RMS_PERFORMANCE =  8           };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_IN_PROGRESS =  16          };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_COMPLETE =  32          };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_FAILED =  64          };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_REQUESTED =  128         };
      enum { STATUS_B_FLAG_GAMS_INSTALLATION_PARAMETERS_VALID =  256         };
      enum { STATUS_B_FLAG_GAMS_SOLUTION_IN_USE =  512         };
      enum { STATUS_B_FLAG_GAMS_SOLUTION_OK =  1024        };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_SUSPENDED =  2048        };
      enum { STATUS_B_FLAG_GAMS_CALIBRATION_FORCED =  4096        };
      enum { STATUS_B_FLAG_PRIMARY_GPS_NAVIGATION_SOLUTION_IN_USE =  8192        };
      enum { STATUS_B_FLAG_PRIMARY_GPS_GPS_INITIALIZATION_FAILED =  16384       };
      enum { STATUS_B_FLAG_PRIMARY_GPS_RESET_COMMAND_SENT =  32768       };
      enum { STATUS_B_FLAG_PRIMARY_GPS_CONFIGURATION_FILE_SENT =  65536       };
      enum { STATUS_B_FLAG_PRIMARY_GPS_NOT_CONFIGURED =  131072      };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_C_A_MODE =  262144      };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_DIFFERENTIAL_MODE =  524288      };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_FLOAT_RTK_MODE =  1048576     };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_WIDE_LANE_RTK_MODE =  2097152     };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_NARROW_LANE_RTK_MODE =  4194304     };
      enum { STATUS_B_FLAG_PRIMARY_GPS_OBSERVABLES_IN_USE =  8388608     };
      enum { STATUS_B_FLAG_SECONDARY_GPS_OBSERVABLES_IN_USE =  16777216    };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_NAVIGATION_SOLUTION_IN_USE =  33554432    };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_IN_P_CODE_MODE =  67108864    };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_IN_DIFFERENTIAL_MODE =  134217728   };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_IN_FLOAT_RTK_MODE =  268435456   };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_IN_WIDE_LANE_RTK_MODE =  536870912   };
      enum { STATUS_B_FLAG_AUXILIARY_GPS_IN_NARROW_LANE_RTK_MODE =  1073741824  };
      enum { STATUS_B_FLAG_PRIMARY_GPS_IN_P_CODE_MODE =  2147483648  };
      enum { PRIMARY_GPS_NAVIGATION_SOLUTION_IN_USE =  1 };
      enum { PRIMARY_GPS_GPS_INITIALIZATION_FAILED =  2 };
      enum { PRIMARY_GPS_RESET_COMMAND_SENT =  3 };
      enum { PRIMARY_GPS_CONFIGURATION_FILE_SENT =  4 };
      enum { PRIMARY_GPS_NOT_CONFIGURED =  5 };
      enum { PRIMARY_GPS_IN_C_A_MODE =  6 };
      enum { PRIMARY_GPS_IN_DIFFERENTIAL_MODE =  7 };
      enum { PRIMARY_GPS_IN_FLOAT_RTK_MODE =  8 };
      enum { PRIMARY_GPS_IN_WIDE_LANE_RTK_MODE =  9 };
      enum { PRIMARY_GPS_IN_NARROW_LANE_RTK_MODE =  10 };
      enum { PRIMARY_GPS_OBSERVABLES_IN_USE =  11 };
      enum { STATUS_C_RESERVED_0 =  1           };
      enum { STATUS_C_RESERVED_1 =  2           };
      enum { STATUS_C_DMI_DATA_IN_USE =  4           };
      enum { STATUS_C_ZUPD_PROCESSING_ENABLED =  8           };
      enum { STATUS_C_ZUPD_IN_USE =  16          };
      enum { STATUS_C_POSITION_FIX_IN_USE =  32          };
      enum { STATUS_C_RTCM_DIFFERENTIAL_CORRECTIONS_IN_USE =  64          };
      enum { STATUS_C_RTCM_RTK_MESSAGES_IN_USE =  128         };
      enum { STATUS_C_RESERVED_8 =  256         };
      enum { STATUS_C_CMR_RTK_MESSAGES_IN_USE =  512         };
      enum { STATUS_C_IIN_IN_DR_MODE =  1024        };
      enum { STATUS_C_IIN_GNSS_AIDING_IS_LOOSELY_COUPLED =  2048        };
      enum { STATUS_C_IIN_IN_C_A_GPS_AIDED_MODE =  4096        };
      enum { STATUS_C_IIN_IN_RTCM_DGPS_AIDED_MODE =  8192        };
      enum { STATUS_C_IIN_IN_CODE_DGPS_AIDED_MODE =  16384       };
      enum { STATUS_C_IIN_IN_FLOAT_RTK_AIDED_MODE =  32768       };
      enum { STATUS_C_IIN_IN_WIDE_LANE_RTK_AIDED_MODE =  65536       };
      enum { STATUS_C_IIN_IN_NARROW_LANE_RTK_AIDED_MODE =  131072      };
      enum { STATUS_C_RECEIVED_RTCM_TYPE_1_MESSAGE =  262144      };
      enum { STATUS_C_RECEIVED_RTCM_TYPE_3_MESSAGE =  524288      };
      enum { STATUS_C_RECEIVED_RTCM_TYPE_9_MESSAGE =  1048576     };
      enum { STATUS_C_RECEIVED_RTCM_TYPE_18_MESSAGE =  2097152     };
      enum { STATUS_C_RECEIVED_RTCM_TYPE_19_MESSAGE =  4194304     };
      enum { STATUS_C_RECEIVED_CMR_TYPE_0_MESSAGE =  8388608     };
      enum { STATUS_C_RECEIVED_CMR_TYPE_1_MESSAGE =  16777216    };
      enum { STATUS_C_RECEIVED_CMR_TYPE_2_MESSAGE =  33554432    };
      enum { STATUS_C_RECEIVED_CMR_TYPE_94_MESSAGE =  67108864    };
      enum { STATUS_C_RESERVED_27 =  134217728   };
      enum { STATUS_C_RESERVED_28 =  268435456   };
      enum { STATUS_C_RESERVED_29 =  536870912   };
      enum { STATUS_C_RESERVED_30 =  1073741824  };
      enum { STATUS_C_RESERVED_31 =  2147483648  };
      enum { FDIR_LEVEL_1_STATUS_IMU_POS_CHECKSUM_ERROR =  1           };
      enum { FDIR_LEVEL_1_STATUS_IMU_STATUS_BIT_SET_BY_IMU =  2           };
      enum { FDIR_LEVEL_1_STATUS_SUCCESSIVE_IMU_FAILURES =  4           };
      enum { FDIR_LEVEL_1_STATUS_IIN_CONFIGURATION_MISMATCH_FAILURE =  8           };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_4 =  16          };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_NOT_IN_NAVIGATION_MODE =  32          };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_NOT_AVAILABLE_FOR_ALIGNMENT =  64          };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_DATA_GAP =  128         };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_PPS_TIME_GAP =  256         };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_TIME_RECOVERY_DATA_NOT_RECEIVED =  512         };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_OBSERVABLE_DATA_GAP =  1024        };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_EPHEMERIS_DATA_GAP =  2048        };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_12 =  4096        };
      enum { FDIR_LEVEL_1_STATUS_PRIMARY_GNSS_MISSING_EPHEMERIS =  8192        };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_14 =  16384       };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_15 =  32768       };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_16 =  65536       };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_17 =  131072      };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_18 =  262144      };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_19 =  524288      };
      enum { FDIR_LEVEL_1_STATUS_SECONDARY_GNSS_DATA_GAP =  1048576     };
      enum { FDIR_LEVEL_1_STATUS_SECONDARY_GNSS_OBSERVABLE_DATA_GAP =  2097152     };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_22 =  4194304     };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_23 =  8388608     };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_24 =  16777216    };
      enum { FDIR_LEVEL_1_STATUS_AUXILIARY_GNSS_DATA_GAP =  33554432    };
      enum { FDIR_LEVEL_1_STATUS_GAMS_AMBIGUITY_RESOLUTION_FAILED =  67108864    };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_27 =  134217728   };
      enum { FDIR_LEVEL_1_STATUS_DMI_FAILED_OR_IS_OFFLINE =  268435456   };
      enum { FDIR_LEVEL_1_STATUS_RESERVED_29 =  536870912   };
      enum { FDIR_LEVEL_1_STATUS_IIN_WL_AMBIGUITY_ERROR =  1073741824  };
      enum { FDIR_LEVEL_1_STATUS_IIN_NL_AMBIGUITY_ERROR =  2147483648  };
      enum { FDIR_LEVEL_2_STATUS_INERTIAL_SPEED_EXCEEDS_MAXIMUM =  1      };
      enum { FDIR_LEVEL_2_STATUS_PRIMARY_GNSS_VELOCITY_EXCEEDS_MAXIMUM =  2      };
      enum { FDIR_LEVEL_2_STATUS_PRIMARY_GNSS_POSITION_ERROR_EXCEEDS_MAXIMUM =  4      };
      enum { FDIR_LEVEL_2_STATUS_AUXILIARY_GNSS_POSITION_ERROR_EXCEEDS_MAXIMUM =  8      };
      enum { FDIR_LEVEL_2_STATUS_DMI_SPEED_EXCEEDS_MAXIMUM =  16     };
      enum { FDIR_LEVEL_4_STATUS_PRIMARY_GNSS_POSITION_REJECTED =  1           };
      enum { FDIR_LEVEL_4_STATUS_PRIMARY_GNSS_VELOCITY_REJECTED =  2           };
      enum { FDIR_LEVEL_4_STATUS_GAMS_HEADING_REJECTED =  4           };
      enum { FDIR_LEVEL_4_STATUS_AUXILIARY_GNSS_DATA_REJECTED =  8           };
      enum { FDIR_LEVEL_4_STATUS_DMI_DATA_REJECTED =  16          };
      enum { FDIR_LEVEL_4_STATUS_PRIMARY_GNSS_OBSERVABLES_REJECTED =  32          };
      enum { FDIR_LEVEL_5_STATUS_X_ACCELEROMETER_FAILURE =  1           };
      enum { FDIR_LEVEL_5_STATUS_Y_ACCELEROMETER_FAILURE =  2           };
      enum { FDIR_LEVEL_5_STATUS_Z_ACCELEROMETER_FAILURE =  4           };
      enum { FDIR_LEVEL_5_STATUS_X_GYRO_FAILURE =  8           };
      enum { FDIR_LEVEL_5_STATUS_Y_GYRO_FAILURE =  16          };
      enum { FDIR_LEVEL_5_STATUS_Z_GYRO_FAILURE =  32          };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_GAMS_HEADING_OFFSET =  64          };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_PRIMARY_GNSS_LEVER_ARM_ERROR =  128         };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_AUXILIARY_1_GNSS_LEVER_ARM_ERROR =  256         };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_AUXILIARY_2_GNSS_LEVER_ARM_ERROR =  512         };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_POS_POSITION_ERROR_RMS =  1024        };
      enum { FDIR_LEVEL_5_STATUS_EXCESSIVE_PRIMARY_GNSS_CLOCK_DRIFT =  2048        };
      enum { EXTENDED_STATUS_PRIMARY_GNSS_OMNISTAR_HP_MODE =  1           };
      enum { EXTENDED_STATUS_PRIMARY_GNSS_OMNISTAR_XP_MODE =  2           };
      enum { EXTENDED_STATUS_PRIMARY_GNSS_OMNISTAR_VBS_MODE =  4           };
      enum { EXTENDED_STATUS_PRIMARY_GNSS_IN_PPP_MODE =  8           };
      enum { EXTENDED_STATUS_AUX_GNSS_IN_OMNISTAR_HP_MODE =  16          };
      enum { EXTENDED_STATUS_AUX_GNSS_IN_OMNISTAR_XP_MODE =  32          };
      enum { EXTENDED_STATUS_AUX_GNSS_IN_OMNISTAR_VBS_MODE =  64          };
      enum { EXTENDED_STATUS_AUX_GNSS_IN_PPP_MODE =  128         };
      enum { EXTENDED_STATUS_PRIMARY_GPS_IN_OMNISTAR_G2_MODE =  4096        };

    GeneralStatus():
      header(),
      td(),
      status_A(0),
      status_B(0),
      primary_gps_mode(0),
      status_C(0),
      fdir_level_1_status(0),
      fdir_level_1_imu_failures(0),
      fdir_level_2_status(0),
      fdir_level_3_status(0),
      fdir_level_4_status(0),
      fdir_level_5_status(0),
      extended_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->td.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status_A >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_A >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_A >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_A >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_A);
      *(outbuffer + offset + 0) = (this->status_B >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_B >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_B >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_B >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_B);
      *(outbuffer + offset + 0) = (this->primary_gps_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->primary_gps_mode);
      *(outbuffer + offset + 0) = (this->status_C >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_C >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_C >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_C >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_C);
      *(outbuffer + offset + 0) = (this->fdir_level_1_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_1_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fdir_level_1_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fdir_level_1_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fdir_level_1_status);
      *(outbuffer + offset + 0) = (this->fdir_level_1_imu_failures >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_1_imu_failures >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fdir_level_1_imu_failures);
      *(outbuffer + offset + 0) = (this->fdir_level_2_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_2_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fdir_level_2_status);
      *(outbuffer + offset + 0) = (this->fdir_level_3_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_3_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fdir_level_3_status);
      *(outbuffer + offset + 0) = (this->fdir_level_4_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_4_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fdir_level_4_status);
      *(outbuffer + offset + 0) = (this->fdir_level_5_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fdir_level_5_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fdir_level_5_status);
      *(outbuffer + offset + 0) = (this->extended_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extended_status >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extended_status >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extended_status >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extended_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->td.deserialize(inbuffer + offset);
      this->status_A =  ((uint32_t) (*(inbuffer + offset)));
      this->status_A |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status_A |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->status_A |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->status_A);
      this->status_B =  ((uint32_t) (*(inbuffer + offset)));
      this->status_B |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status_B |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->status_B |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->status_B);
      this->primary_gps_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->primary_gps_mode);
      this->status_C =  ((uint32_t) (*(inbuffer + offset)));
      this->status_C |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status_C |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->status_C |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->status_C);
      this->fdir_level_1_status =  ((uint32_t) (*(inbuffer + offset)));
      this->fdir_level_1_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fdir_level_1_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->fdir_level_1_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->fdir_level_1_status);
      this->fdir_level_1_imu_failures =  ((uint16_t) (*(inbuffer + offset)));
      this->fdir_level_1_imu_failures |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fdir_level_1_imu_failures);
      this->fdir_level_2_status =  ((uint16_t) (*(inbuffer + offset)));
      this->fdir_level_2_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fdir_level_2_status);
      this->fdir_level_3_status =  ((uint16_t) (*(inbuffer + offset)));
      this->fdir_level_3_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fdir_level_3_status);
      this->fdir_level_4_status =  ((uint16_t) (*(inbuffer + offset)));
      this->fdir_level_4_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fdir_level_4_status);
      this->fdir_level_5_status =  ((uint16_t) (*(inbuffer + offset)));
      this->fdir_level_5_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->fdir_level_5_status);
      this->extended_status =  ((uint32_t) (*(inbuffer + offset)));
      this->extended_status |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->extended_status |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->extended_status |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->extended_status);
     return offset;
    }

    const char * getType(){ return "fub_applanix_msgs/GeneralStatus"; };
    const char * getMD5(){ return "6335409243a8e4237e08cb05e6362a1c"; };

  };

}
#endif