#include "AID/UbxAidIniParser.hpp"

using namespace ublox ;
using namespace ublox::aid ;

void IniParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
   pToData->clear();
   pToData->ecefXOrLat = bufferToLong( HEADER_SIZE , pbuffer ) ;
   pToData->ecefYOrLon = bufferToLong( HEADER_SIZE+4 , pbuffer ) ;
   pToData->ecefZOrAlt = bufferToLong( HEADER_SIZE+8 , pbuffer ) ;
   pToData->posAcc = bufferToULong( HEADER_SIZE+12 , pbuffer ) ;
   pToData->tmCfg = bufferToX2( HEADER_SIZE+16 , pbuffer ) ;
   pToData->wn = bufferToUShort( HEADER_SIZE+18 , pbuffer ) ;
   pToData->tow = bufferToULong( HEADER_SIZE+20 , pbuffer ) ;
   pToData->towNs = bufferToLong( HEADER_SIZE+24 , pbuffer ) ;
   pToData->tAccMs = bufferToULong( HEADER_SIZE+28 , pbuffer ) ;
   pToData->tAccNs = bufferToULong( HEADER_SIZE+32 , pbuffer ) ;
   pToData->clkDOrFreq = bufferToLong( HEADER_SIZE+36 , pbuffer ) ;
   pToData->clkDAccOrFreqAcc = bufferToULong( HEADER_SIZE+40 , pbuffer ) ;
   pToData->flags = bufferToX4( HEADER_SIZE+44 , pbuffer ) ;

   debug() ;
   pToData->unlock() ;
   if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
};
