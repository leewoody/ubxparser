#include "CFG/UbxCfgDefinitions.hpp"

using namespace ublox ;

void cfg::MsgData::clear()
{
    msgClass = 0 ;
    msgID = 0 ;
    rate = 0 ;
    for ( unsigned int k = 0 ; k < 6 ; k++ ) rates[k] = 0 ;
} ;

void cfg::RateData::clear()
{
    measRate = 0 ;
    navRate = 0 ;
    timeRef = 0 ;
} ;

void cfg::Nav5Data::clear()
{
    mask.reset() ;
    dynModel = PORTABLE ;
    fixMode = AUTO ;
    fixedAlt = 0 ;
    fixedAltVar = 0 ;
    minElev = 0 ;
    drLimit = 0 ;
    pDop = 0 ;
    tDop = 0 ;
    pAcc = 0 ;
    tAcc = 0 ;
    staticHoldThres = 0 ;
    dgpsTimeOut = 0 ;
}

void cfg::SbasData::clear()
{
    mode.reset() ;
    usage.reset() ;
    maxSbas = 0 ;
    scanmode2.reset() ;
    scanmode1.reset() ;
} ;

void cfg::SbasData::setEnabled( const bool & b )
{
    mode[0] = b ;
};

void cfg::SbasData::setTestmode( const bool & b )
{
    mode[1] = b ;
};

void cfg::SbasData::setServices( const bool & ranging , const bool & sbas_corr , const bool & integrity )
{
    usage[0] = ranging ;
    usage[1] = sbas_corr ;
    usage[2] = integrity ;
};

void cfg::SbasData::setSystem( cfg::SBAS_SYSTEM system )
{
    scanmode1.reset() ;
    scanmode2.reset() ;

    if ( system == WAAS )
    {
        scanmode1[2] = true ;
        scanmode1[13] = true ;
        scanmode1[14] = true ;
        scanmode1[15] = true ;
        scanmode1[18] = true ;
    }
    else if ( system == EGNOS )
    {
        scanmode1[0] = true ;
        scanmode1[4] = true ;
        scanmode1[6] = true ;
        scanmode1[11] = true ;
    }
    else if ( system == MSAS )
    {
        scanmode1[9] = true ;
        scanmode1[17] = true ;
    }
    else if ( system == GAGAN )
    {
        scanmode1[7] = true ;
        scanmode1[8] = true ;
    }

};
