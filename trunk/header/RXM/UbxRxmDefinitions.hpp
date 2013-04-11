#ifndef __UBLOX_UBX_RXM_DEFINITIONS__
#define __UBLOX_UBX_RXM_DEFINITIONS__

#include <iostream>
#include <vector>
#include <list>

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"


namespace ublox
{

const I1 RXM = 0x02 ;

namespace rxm
{

const unsigned int MAX_NUMBER_SFRB_BLOCKS = 500 ;

const I1 ALM = 0x30 ;
const I1 EPH = 0x31 ;
const I1 PMREQ = 0x41 ;
const I1 RAW = 0x10 ;
const I1 SFRB = 0x11 ;
const I1 SVSI = 0x20 ;

class AlmData : public BaseData
{
public :
   AlmData() : ublox::BaseData(RXM,ALM) { this->clear() ; };
   void clear();
   U4 svid , almWeek , dwrd[8] ;
} ;

class EphData : public BaseData
{
public :
   EphData() : ublox::BaseData(RXM,EPH) { this->clear() ; };
   void clear() ;
   U4 svid , how , sf1d[8] , sf2d[8] , sf3d[8] ;
} ;

class PmreqData : public BaseData
{
public :
   PmreqData() : ublox::BaseData(RXM,PMREQ) { this->clear() ; };
  void clear() ;
  U4 duration ;
  X4 flags ;
} ;

struct RawMeasBlock
{
  U1 svId ; 	//! PRN of the sv
  R8 L1 ;			//! Carrier-phase (L1 Cycles)
  R8 C1 ;			//! Pseudorange (m)
  R4 D1 ;			//! Doppler (Hz)
  I1 QualIndic ;		//! Measurements quality indicator
  I1 snr ;			//! Signal Strength
  I1 LLI ;			//! Loss-of-Lock Indicator
};

//! \struct RawData
//! Handles the measurements provided by the RXM-RAW message
class RawData : public BaseData
{
public :
  RawData() : ublox::BaseData(RXM,RAW)
  {
    this->clear();
  };
  void clear() ;
  void display() ;
  U1 numSV ;		//! Number of available measurements
  std::vector<RawMeasBlock> meas ;		//! Vector of measurements blocks
} ;


// typedef std::vector<I4> DWRD ;

struct SfrbBlock
{
  U1 chn ;
  U1 svId ;
  I4 dwrd[10] ;
  std::vector<unsigned char> sbas_buffer ;
};

//! \struct SFRBData
class SfrbData : public BaseData
{
public :
  SfrbData() : ublox::BaseData(RXM,SFRB)
  {
    this->clear();
  };
  std::list<SfrbBlock> dwrds ;
  void clear() ;
} ;

struct SvsiBlock
{
  U1 svid ;
  U1 svFlag ;
  I2 azim ;
  U1 elev ;
  U1 age ;
} ;

//! Container for UBX-SVSI messages
class SvsiData : public BaseData
{
public :
  SvsiData() : ublox::BaseData(RXM,SVSI)
  {
    this->clear();
  } ;
  void clear() ;
  U1 numVis ;
  U1 numSV ;
  std::list<SvsiBlock> svInfos ;
};



}; // end ublox::nav
} ; // end ublox

#endif
