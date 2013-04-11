#include "NAV/UbxNavAopstatusParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void AopstatusParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->config = bufferToChar(i0+4,pbuffer);
  pToData->status = bufferToChar(i0+5,pbuffer);
  pToData->avail = bufferToULong(i0+8,pbuffer) ;
  debug() ;
  pToData->unlock() ;

  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
