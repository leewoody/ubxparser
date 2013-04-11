#include "NAV/UbxNavPosllhParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void PosllhParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->longitude = bufferToLong(i0+4,pbuffer) ;
  pToData->latitude = bufferToLong(i0+8,pbuffer) ;
  pToData->hElli = bufferToLong( i0+12 , pbuffer );
  pToData->hMsl = bufferToLong( i0+16 , pbuffer );
  pToData->hAcc = bufferToULong( i0+20 , pbuffer );
  pToData->vAcc = bufferToLong( i0+24 , pbuffer );
  debug() ;
  pToData->unlock() ;
  
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
