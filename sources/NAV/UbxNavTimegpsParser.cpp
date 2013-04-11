#include "NAV/UbxNavTimegpsParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void TimegpsParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->fTow = bufferToLong( i0+4 , pbuffer ) ;
  pToData->week = bufferToShort( i0+8 , pbuffer );
  pToData->leapS = bufferToChar(i0+10 , pbuffer ) ;
  char v = bufferToChar( i0+11 , pbuffer );
  for ( unsigned int k = 0 ; k < pToData->valid.size() ; k++ ) pToData->valid[k] = extractBit(v,k);
  pToData->tAcc = bufferToULong( i0+12 , pbuffer );
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
