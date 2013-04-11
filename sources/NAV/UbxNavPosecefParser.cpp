#include "NAV/UbxNavPosecefParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void PosecefParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
  pToData->lock() ;
//    std::cout << "nav::PosecefParser -> processing data" << std::endl ;
  pToData->clear() ;
  int i0 = HEADER_SIZE ;
  pToData->iTow = bufferToULong(i0,pbuffer);
  pToData->Xecef = bufferToLong(i0+4,pbuffer);
  pToData->Yecef = bufferToLong(i0+8,pbuffer);
  pToData->Zecef = bufferToLong(i0+12,pbuffer);
  pToData->pAcc = bufferToULong(i0+16,pbuffer);
  debug() ;
  pToData->unlock() ;
  
  if ( !this->asNoConnection() )
  {
     doneProcessing() ;
  };
//    std::cout << "nav::PosecefParser -> done" << std::endl ;
} ;
