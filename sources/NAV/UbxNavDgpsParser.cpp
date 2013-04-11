#include "NAV/UbxNavDgpsParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void DgpsParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;

  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->age = bufferToLong(i0+4,pbuffer);
  pToData->baseId = bufferToShort(i0+8,pbuffer);
  pToData->baseHealth = bufferToShort(i0+10,pbuffer);
  pToData->numCh = bufferToUChar(i0+12,pbuffer);
  pToData->status = bufferToUChar(i0+13,pbuffer);

  for ( int k = 0 ; k < pToData->numCh ; k++ )
  {
     DgpsBlock b ;
     int i1 = i0+12*k ;
     b.svid = bufferToUChar( i1+16 , pbuffer );
     b.flags = bufferToUChar( i1+17 , pbuffer ) ;
     b.ageC = bufferToUShort( i1+18 , pbuffer );
     b.prc = bufferToFloat( i1+20 , pbuffer );
     b.prrc = bufferToFloat( i1+24 , pbuffer );
     pToData->chData.push_back(b);
  };

  debug() ;
  pToData->unlock() ;
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
} ;
