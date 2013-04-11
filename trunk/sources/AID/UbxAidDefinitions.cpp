#include "AID/UbxAidDefinitions.hpp"

using namespace ublox ;
using namespace ublox::aid ;

//-------- RXM-ALM --------//
void AlmData::clear()
{
   svid = 0 ;
   almWeek = 0 ;
   for ( int k = 0 ; k < 8 ; k++ )
      dwrd[k] = 0 ;
} ;

//--------- AID-HUI -------//
void HuiData::clear()
{
     health.reset() ;
     flags.reset();
     utcTOW = 0 ;
     utcWNT = 0 ;
     utcLS = 0 ;
     utcDN = 0 ;
     utcLSF = 0 ;
     utcSpare = 0 ;
     utcWNF = 0 ;
     for ( int k = 0 ; k < 2 ; k++ ) utcA[k] = 0 ;
     for ( int k = 0 ; k < 4 ; k++ )
     {
	klobA[k] = 0 ;
	klobB[k] = 0 ;
     }
} ;

//-------- AID-EPH ---------//
void EphData::clear()
{
   svid = 0 ;
   how = 0 ;
   for ( int k = 0 ; k < 8 ; k++ )
   {
      sf1d[k] = 0 ;
      sf2d[k] = 0 ;
      sf3d[k] = 0 ;
   }
}

//-------- AID-INI --------//
void IniData::clear()
{
   ecefXOrLat = 0 ;
   ecefYOrLon = 0 ;
   ecefZOrAlt = 0 ;
   posAcc = 0 ;
   tmCfg.reset() ;
   wn = 0 ;
   tow = 0 ;
   towNs = 0 ;
   tAccMs = 0 ;
   tAccNs = 0 ;
   clkDOrFreq = 0 ;
   clkDAccOrFreqAcc = 0 ;
   flags.reset() ;
} ;