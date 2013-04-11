/*!
 * \file UbxAidDefinitions.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines constnates and data structures for UBX-AID messages.
 *
 */

#ifndef __UBLOX_UBX_AID_DEFINITIONS__
#define __UBLOX_UBX_AID_DEFINITIONS__

#include <iostream>

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 AID = 0x0B ;

namespace aid
{
  const I1 ALM = 0x30 ;
  const I1 ALPSRV = 0x32 ;
  const I1 ALP = 0x50 ;
  const I1 AOP = 0x33 ;
  const I1 DATA = 0x10 ;
  const I1 EPH = 0x31 ;
  const I1 HUI = 0x02 ;
  const I1 INI = 0x01 ;
  const I1 REQ = 0x00 ;

/*!
 * \brief GPS Aiding almanach data
 */
class AlmData : public BaseData
{
public :
   AlmData() : ublox::BaseData(AID,ALM) { this->clear() ; };
   void clear();
   U4 svid ;    //!< SVid for wich the almanach is
   U4 almWeek ; //!< Issue data of almanach
   U4 dwrd[8] ; //!< Almanach words
} ;

/*!
 * \brief AlmanachPlus data from server
 */
class AlpsrvData ;
class AlpData ;
class AopData ;

/*!
 * \brief GPS Aiding ephemeris data
 */
class EphData : public BaseData
{
public :
   EphData() : BaseData(AID,EPH) { this->clear(); };
   void clear() ;
   U4 svid , how ;
   U4 sf1d[8] , sf2d[8] , sf3d[8] ;
};

/*!
 * \brief GPS Health, UTC and iono parameters.
 *
 * This message contains a health bit mask, UTC time and Klobuchar parameters.
 * For more information on these parameters, please see the ICD-GPS-200 documentation.
 */
class HuiData : public BaseData
{
public :
  HuiData() : BaseData(AID,HUI) { this->clear() ; } ;
  void clear() ;
  X4 health , flags ;
  R8 utcA[2] ;
  R4 klobA[4] , klobB[4] ;
  I4 utcTOW ;
  I2 utcWNT , utcLS , utcDN , utcLSF , utcSpare , utcWNF;
} ;

/*!
 * \brief Aiding position, time, frequency, clock drift
 */
class IniData : public BaseData
{
public :
   IniData() : BaseData(AID,INI) { this->clear() ; };
   void clear() ;
   I4 ecefXOrLat ;
   I4 ecefYOrLon ;
   I4 ecefZOrAlt ;
   U4 posAcc ;
   X2 tmCfg ;
   U2 wn ;
   U4 tow ;
   I4 towNs ;
   U4 tAccMs ;
   U4 tAccNs ;
   I4 clkDOrFreq ;
   U4 clkDAccOrFreqAcc ;
   X4 flags ;
};

} ;
} ;

#endif