#include "NAV/UbxNavTimeutcParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void TimeutcParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->tAcc = bufferToULong(i0+4,pbuffer) ;
   pToData->nano = bufferToLong(i0+8,pbuffer) ;
   pToData->year = bufferToUShort(i0+12,pbuffer) ;
   pToData->month = bufferToUChar(i0+14,pbuffer) ;
   pToData->day = bufferToUChar(i0+15,pbuffer) ;
   pToData->hour = bufferToUChar(i0+16,pbuffer) ;
   pToData->min = bufferToUChar(i0+17,pbuffer) ;
   pToData->sec = bufferToUChar(i0+18,pbuffer) ;
   pToData->valid = bufferToX1(i0+19,pbuffer) ;
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
