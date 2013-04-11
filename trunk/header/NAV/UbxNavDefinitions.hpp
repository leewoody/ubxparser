#ifndef __UBLOX_UBX_NAV_DEFINITIONS__
#define __UBLOX_UBX_NAV_DEFINITIONS__

#include <iostream>
#include <vector>

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 NAV = 0x01 ;

namespace nav
{

const I1 AOPSTATUS = 0x60 ;
const I1 CLOCK = 0x22 ;
const I1 DGPS = 0x31 ;
const I1 DOP = 0x04 ;
const I1 EKFSTATUS = 0x40 ;
const I1 POSECEF = 0x01 ;
const I1 POSLLH = 0x02 ;
const I1 SBAS = 0x32 ;
const I1 SOL = 0x06 ;
const I1 STATUS = 0x03 ;
const I1 SVINFO = 0x30 ;
const I1 TIMEGPS = 0x20 ;
const I1 TIMEUTC = 0x21 ;
const I1 VELECEF = 0x11 ;
const I1 VELNED = 0x12 ;

/*!
 * Provides information about AssistNow Autonomous configuration
 */
class AopstatusData : public BaseData
{
public :
  AopstatusData() : ublox::BaseData( NAV , AOPSTATUS )
  {
    this->clear() ;
  } ;
  void clear() ;
  U1 config ; 	//!< AssistNow Autonomous is enabled or disabled
  U1 status ;	//!< AssistNow Autonomous is running or idle
  U4 avail ;	//!< Data avaliability GPS SV
} ;

/*!
 * Receiver clock information
 */
class ClockData : public BaseData
{
public :
  ClockData() : ublox::BaseData(NAV,CLOCK)
  {
    this->clear() ;
  } ;
  void clear() ;
  I4 clkB ; //!< receiver clock bias (ns)
  I4 clkD ; //!< receiver clock drift (ns/s)
  U4 tAcc ; //!< Estimated time accuracy (ns)
  U4 fAcc ; //!< Estimated frequency accuracy (ps/s)
};

/*!
 * Message sub-blocks for UBX-NAV-DGPS
 * \see ublox::nav::DgpsData
 */
struct DgpsBlock
{
  U1 svid ; //!< Satellite ID
  U1 flags ; //!< Bitmask / Channel number
  U2 ageC ; //!< Age of the latest correction
  R4 prc ; //!< Pseudorange correction (m)
  R4 prrc ; //!< Pseudorange-rate correction (m/s)
} ;

/*!
 * Applied DGPS corrections from the NAV solution
 */
class DgpsData : public BaseData
{
public:
  DgpsData() : ublox::BaseData(NAV,DGPS)
  {
    this->clear() ;
  } ;
  void clear() ;
  I4 age ; 		//!< Age of the newest correction (ms)
  I2 baseId ; 		//!< DGPS Base station ID
  I2 baseHealth ; 	//!< DGPS Base health
  U1 numCh ; 		//!< Number of sub-blocks to follow
  U1 status ; 		//!< DGPS Correction type status : 0 -> none / 1-> PR + PRR
  std::vector<DgpsBlock> chData ; //!< Data-Sublock for each channel
};

/*!
 * \brief Dilution of precision
 * Periodic/Polled
 * DOP values are dimensionless
 * All DOP values are scaled b a factor of 100
 */
class DopData : public BaseData
{
public :
    DopData() : ublox::BaseData(NAV,DOP)
    {
       this->clear ();
    }
    void clear() ;
    void display() ;
    U2 gDOP ;	//!< Geometric dilution of precision.
    U2 pDOP ;	//!< Position dilution of precision.
    U2 tDOP ;	//!< Time dilution of precision.
    U2 vDOP ;	//!< Vertical dilution of precision.
    U2 hDOP ;	//!< Horizontal dilution of precision.
    U2 nDOP ;	//!< North dilution of precision.
    U2 eDOP ;	//!< East dilution of precision.
};

/*!
 * \brief Dead Reckoning Software Status
 * \warning This message is only provided for backwards compatibility and should not be
 * utilized for future designs. Instead, the messages ESF-STATUS and ESF-MEAS should be used.
 *
 * For u-blox 6 firmware the gyroscope value (gyroMean) is only output if the gyroscope is
 * used in the navigation solution. This message is only available on LEA-4R and
 * LEA-6R GPS Receivers.
 */
class EkfstatusData : public BaseData
{
public :
   EkfstatusData() : ublox::BaseData( NAV , EKFSTATUS )
   {
      this->clear() ;
   };
   void clear() ;
   void display() {} ;
   I4 pulses ;		//!< number of pulsed in last update period
   I4 period ;   	//!< Duration of last period (ms)
   U4 gyroMean ; 	//!< Uncorrected average Gyro value in last period
   I2 temperature ; 	//!< Temperature (deg Celsius) ;
   I1 direction ;      	//!< Direction flag
   X1 calibStatus ;    	//!< Calibration Status (see graphic below)
   I4 pulseScale ;     	//!< Current Scale Factor of Speed Pulse
   I4 gyroBias ;      	//!< Current Bias of Gyro
   I4 gyroScale ;     	//!< Current Scale Factor of Gyro
   I2 accPulseScale;  	//!< Accuracy of Speed Pulse Scale Factor [percentage of initial value]
   I2 accGyroBias ;    	//!< Accuracy of Bias of Gyro [percentage of initial value]
   I2 accGyroScale;    	//!< Accuracy of Scale Factor of Gyro [percentage of initial value]
   X1 measUsed ;      	//!<Measurements used
};

class PosecefData : public BaseData
{
public :
  PosecefData() ;
  I4 Xecef ; 		//!< ECEF X Coordinate (cm)
  I4 Yecef ; 		//!< ECEF Y Coordinate (cm)
  I4 Zecef ; 		//!< ECEF Z Coordinate (cm)
  U4 pAcc ; 	//!< Posistion Accuracy Estimate (cm)
  void clear() ;
  void display() ;
} ;

//! Handles the measurements provided by the RXM-RAW message
class PosllhData : public BaseData
{
public :
  PosllhData() ;
  I4 longitude ; 		//!< (deg)
  I4 latitude ; 		//!< (deg)
  I4 hElli ; 		//!< height aboce Ellipsoid (mm)
  I4 hMsl ; 		//!< height above mean sea level (mm)
  U4 hAcc ;	//!< Horisontal accuracy (mm)
  U4 vAcc ;	//!< Vertical accuracy (mm)
  void clear() ;
  void display() ;
} ;

class SolData : public ublox::BaseData
{
public :
  SolData() ;
  I4 fTow ; //!< Fractionnal Nanosecond remainder
  U1 gpsFix ; //!< GPS Fix type
  X1 flags ;  //!< Fix status flag ; 0- GPSFixOk / 1- DGPS Use / 2- WeekNb valid / 3 - TOW Set
  U2 pdop ; //!< PDOP
  U1 numSV ; //!< Number of SV used in the navigation solution
  I4 Xecef ; 		//!< ECEF X Coordinate (cm)
  I4 Yecef ; 		//!< ECEF Y Coordinate (cm)
  I4 Zecef ; 		//!< ECEF Z Coordinate (cm)
  U4 pAcc ; 	//!< Posistion Accuracy Estimate (cm)
  I4 vXecef ; 		//!< ECEF X velocity (cm)
  I4 vYecef ; 		//!< ECEF Y velocity (cm)
  I4 vZecef ; 		//!< ECEF Z velocity (cm)
  U4 sAcc ; 	//!< Posistion Accuracy Estimate (cm)
  void clear() ;
  void display() ;
};

/*!
 * \brief Receiver Navigation Status
 */
class StatusData : public BaseData
{
public :
   StatusData() : ublox::BaseData(NAV,STATUS)
   {
      this->clear() ;
   }
   void clear() ;
   U1 gpsFix ; 	//!< GPS Fix
   X1 flags ; 	//!< Navigation status flag
   X1 fixStat ; //!< Fix status
   X1 flags2 ; 	//!< Information about navigation output
   U4 ttff ; 	//!< Time to first fix
   U4 msss ; 	//!< Millisecond since startup/clear
} ;

struct SvinfoBlock
{
  U1 chId ;
  U1 svId ;
  X1 flags ; //! 0: SVUsed, 1: diffCorr, 2: OrbitAvail, 3: OrbitEph, 4: Unhealty,5: OrbitAl, 6: OrbitAop, 7: smoothed
  I1 quality ;
  U1 cn0 ; //! (dbHz)
  I1 elev ; //! (deg)
  I2 azim ; //! (deg)
  I4 prRes; //! cm
} ;

class SvinfoData : public BaseData
{
public :
  SvinfoData() ;
  void clear() ;
  void display() ;
  U1 numCh ;	//! Number of channel recorded
  I1 globalFlags ;
  std::vector<SvinfoBlock> chData ; //! ID of the recorded channel
};

struct SbasBlock
{
   U1 svid;
   U1 flags;
   U1 udre ;
   U1 svSys ;
   X1 svService;
   I2 prc ;
   I2 ic ;
};

class SbasData : public ublox::BaseData
{
public :
   SbasData() : ublox::BaseData(NAV,SBAS)
   {
      this->clear() ;
   };
   void clear() ;
   U1 geo ;
   U1 mode ;
   I1 sys ;
   X1 service ;
   U1 cnt ;
   std::vector<SbasBlock> sv ;
};

/*!
 * \brief GPS Time solution
 */
class TimegpsData : public BaseData
{
public :
  TimegpsData() : ublox::BaseData(NAV,TIMEGPS)
  {
    this->clear() ;
  };
  void clear() ;
  I4 fTow ; //!< Fractionnal Nanosecond remainder
  I1 leapS ; //!< Leap Seconds (GPS-UTC)
  X1 valid ;
  U4 tAcc ;
};

/*!
 * \brief UTC Time solution
 */
class TimeutcData : public BaseData
{
public :
   TimeutcData() : ublox::BaseData(NAV,TIMEUTC)
   {
      this->clear();
   }
   void clear() ;
   U4 tAcc ; 	//!< Time Accuracy Estimate
   I4 nano ; 	//!< Nanoseconds of second, range -1e9 .. 1e9 (UTC)
   U2 year ; 	//!< Year, range 1999..2099 (UTC)
   U1 month ; 	//!< Month, range 1..12 (UTC)
   U1 day ;  	//!< Day of Month, range 1..31 (UTC)
   U1 hour ; 	//!< Hour of Day, range 0..23 (UTC)
   U1 min ;  	//!< Minute of Hour, range 0..59 (UTC)
   U1 sec ;  	//!< Seconds of Minute, range 0..59 (UTC)
   X1 valid ; 	//!< Validity Flags
};


/*!
 * \brief Velocity solution in ECEF
 */
class VelecefData : public BaseData
{
public :
  VelecefData();
  I4 vXecef ; 	//!< ECEF X velocity (cm)
  I4 vYecef ; 	//!< ECEF Y velocity (cm)
  I4 vZecef ; 	//!< ECEF Z velocity (cm)
  U4 sAcc ;	//!< Posistion Accuracy Estimate (cm)
  void clear() ;
  void display() ;

} ;

/*!
 * \brief Velocity Solution in NED
 */
class VelnedData : public BaseData
{
public :
  VelnedData() ;
  void clear() ;
  void display() ;
  I4 velN ; 			//!< NED North velocity (cm/s)
  I4 velE ;			//!< NED East velocity (cm/s)
  I4 velD ; 			//!< NED Down velocity (cm/s)
  U4 speed ;		//!< 3D speed (cm/s)
  U4 gSpeed ;	//!< Ground speed (cm/s)
  I4 heading ; 		//!< Heading of 2D motion (deg)
  U4 sAcc ; 		//!< Speed Accuracy estimate
  U4 cAcc ;		//!< Course / Heading accuracy estimate.
} ;


};
} ;

#endif
