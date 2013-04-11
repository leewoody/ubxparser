#ifndef __UBLOX_UBX_CFG_DEFINITIONS__
#define __UBLOX_UBX_CFG_DEFINITIONS__

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 CFG = 0x06 ;

namespace cfg
{
const I1 ANT 	= 0x13 ;
const I1 CFG 	= 0x09 ;
const I1 DAT 	= 0x06 ;
const I1 EKF 	= 0x12 ;
const I1 ESFGWT = 0x29 ;
const I1 FXN 	= 0x0E ;
const I1 INF   	= 0x02 ;
const I1 ITFM  	= 0x39 ;
const I1 MSG   	= 0x01 ;
const I1 NAV5  	= 0x24 ;
const I1 NAVX5 	= 0x23 ;
const I1 NMEA  	= 0x17 ;
const I1 NVS   	= 0x22 ;
const I1 PM2   	= 0x3B ;
const I1 PM    	= 0x32 ;
const I1 PRT   	= 0x00 ;
const I1 RATE  	= 0x08 ;
const I1 RINV  	= 0x34 ;
const I1 RST   	= 0x04 ;
const I1 RXM   	= 0x11 ;
const I1 SBAS  	= 0x16 ;
const I1 TMODE2	= 0x3D ;
const I1 TMODE 	= 0x1D ;
const I1 TP5 	= 0x31 ;
const I1 TP 	= 0x07 ;
const I1 USB 	= 0x1B ;

enum RX_PORT
{
    ALL = -1 ,
    I2C = 0 ,
    UART1 = 1 ,
    UART2 = 2 ,
    SERIAL = 3 ,
    SPI = 4
} ;

enum TIME_REF
{
    UTC_TIME = 0 ,
    GPS_TIME = 1 ,
    LOCAL_TIME = 2
} ;

enum DYN_MODEL
{
    PORTABLE = 0 ,
    STATIONARY = 2 ,
    PEDESTRIAN = 3 ,
    AUTOMOTIVE = 4 ,
    SEA = 5 ,
    AIRBORNE_1G = 6 ,
    AIRBORNE_2G = 7,
    AIRBORNE_4G = 8
} ;

enum FIX_MODE
{
    TWOD_ONLY = 1,
    THREED_ONLY = 2,
    AUTO = 3
} ;

enum SBAS_SYSTEM
{
    AUTO_SCAN ,
    WAAS ,
    EGNOS ,
    MSAS ,
    GAGAN ,
    OTHER
} ;

class AntData ;
class CfgData ;
class DatData ;
class EkfData ;
class EsfgwtData ;
class FxnData ;
class InfData ;
class ItfmData ;

/*!
 * \brief Message configuration
 */
class MsgData : public ublox::BaseData
{
public :
    MsgData() : ublox::BaseData(ublox::CFG,ublox::cfg::MSG) {
        this->clear();
    };
    void clear() ;
    U1 msgClass ;
    U1 msgID ;
    U1 rate ;
    U1 rates[6] ;
} ;

/*!
 * \brief Navigation engine configuration
 */
class Nav5Data : public ublox::BaseData
{
public :
    Nav5Data() : ublox::BaseData(ublox::CFG,ublox::cfg::NAV5) {
        this->clear() ;
    };
    void clear() ;
    X2 mask ;
    DYN_MODEL dynModel ;
    FIX_MODE fixMode ;
    I4 fixedAlt ;
    U4 fixedAltVar ;
    I1 minElev ;
    I1 drLimit ;
    U2 pDop ;
    U2 tDop ;
    U2 pAcc ;
    U2 tAcc ;
    U1 staticHoldThres ;
    U1 dgpsTimeOut ;
};


class Navx5Data ;
class NmeaData ;
class NvsData ;
class Pm2Data ;
class PmData ;
class PrtData ;

/*!
 * \brief Measurement/Navigation rate
 */
class RateData : public ublox::BaseData
{
public :
    RateData() : ublox::BaseData(ublox::CFG,ublox::cfg::RATE) {
        this->clear() ;
    };
    void clear() ;
    U2 measRate ;
    U2 navRate ;
    U2 timeRef ;
};


class RinvData ;
class RstData ;
class RxmData ;

/*!
 * \brief SBAS Configuration data
 */
class SbasData : public ublox::BaseData
{
public :
    SbasData() : ublox::BaseData(ublox::CFG,ublox::cfg::SBAS) {
        this->clear() ;
    };
    void clear() ;
    void setEnabled( const bool & b );
    void setTestmode( const bool & b );
    void setServices( const bool & ranging , const bool & sbas_corr , const bool & integrity ) ;
    void setSystem( cfg::SBAS_SYSTEM system ) ;

    X1 mode ;
    X1 usage ;
    U1 maxSbas ;
    X1 scanmode2 ;
    X4 scanmode1 ;
};


class Tmode2Data ;
class TmodeData ;
class Tp5Data ;
class TpData ;
class UsbData ;

} ;
} ;

#endif
