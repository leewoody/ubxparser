#include "NAV/UbxNavVelecefParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void VelecefParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong( i0 , pbuffer );
  pToData->vXecef = bufferToLong( i0+4 , pbuffer );
  pToData->vYecef = bufferToLong( i0+8 , pbuffer );
  pToData->vZecef = bufferToLong( i0+12 , pbuffer );
  pToData->sAcc = bufferToULong( i0+16 , pbuffer );
  debug() ;
  pToData->unlock() ;
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
