#include "NAV/UbxNavVelnedParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void VelnedParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->velN = bufferToLong( i0+4 , pbuffer ) ;
  pToData->velE = bufferToLong( i0+8 , pbuffer );
  pToData->velD = bufferToLong( i0+12 , pbuffer );
  pToData->speed = bufferToULong( i0+16 , pbuffer );
  pToData->gSpeed = bufferToULong( i0+20 , pbuffer );
  pToData->heading = bufferToLong( i0+24 , pbuffer );
  pToData->sAcc = bufferToULong( i0+28 , pbuffer );
  pToData->cAcc = bufferToULong( i0+32 , pbuffer );
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
