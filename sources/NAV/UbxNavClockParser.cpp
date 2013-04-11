#include "NAV/UbxNavClockParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void ClockParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->clkB = bufferToLong( i0+4 , pbuffer ) ;
  pToData->clkD = bufferToLong( i0+8 , pbuffer );
  pToData->tAcc = bufferToULong( i0+12 , pbuffer );
  pToData->fAcc = bufferToULong( i0+16 , pbuffer );
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
