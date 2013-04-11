#include "NAV/UbxNavStatusParser.hpp"

using namespace ublox ;
using namespace ublox::nav ;

void StatusParser::processFrame(  boost::shared_ptr<buffer_t> pbuffer )
{
    pToData->lock() ;
    pToData->clear() ;
    int i0 = HEADER_SIZE ;

    pToData->iTow = bufferToULong(i0,pbuffer);
    pToData->gpsFix = bufferToUChar(i0+4,pbuffer) ;
    pToData->flags = bufferToX1(i0+5,pbuffer) ;
    pToData->fixStat = bufferToX1(i0+6,pbuffer) ;
    pToData->flags2 = bufferToX1(i0+7,pbuffer) ;
    pToData->ttff = bufferToULong(i0+8,pbuffer);
    pToData->msss = bufferToULong(i0+12,pbuffer) ;

    debug() ;
    pToData->unlock() ;

    if ( !this->asNoConnection() )
    {
        doneProcessing() ;
    };
} ;
