#include "NAV/UbxNavDopParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void DopParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->gDOP = bufferToUShort(i0+4,pbuffer);
  pToData->pDOP = bufferToUShort(i0+6,pbuffer);
  pToData->tDOP = bufferToUShort(i0+8,pbuffer);
  pToData->vDOP = bufferToUShort(i0+10,pbuffer);
  pToData->hDOP = bufferToUShort(i0+12,pbuffer);
  pToData->nDOP = bufferToUShort(i0+14,pbuffer);
  pToData->eDOP = bufferToUShort(i0+16,pbuffer);
  
  debug() ;
  pToData->unlock() ;
  
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
