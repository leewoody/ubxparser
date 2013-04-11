#ifndef __UBLOX_UBX_TIM_DEFINITIONS__
#define __UBLOX_UBX_TIM_DEFINITIONS__

#include "base/UbxBaseData.hpp"
#include "base/UbxDatatype.hpp"

namespace ublox
{

const I1 TIM = 0x0D ;

namespace tim
{
const I1 SVIN = 0x04 ;
const I1 TM2 = 0x03 ;
const I1 TP = 0x01 ;
const I1 VRFY = 0x06 ;

/*!
 * \brief Survey-in data
 * This message contains information about survey-in parameters.
 * For details about the Time Mode, see section Time Mode Configuration.
 * \warning This message is only supported on timing receivers
 */
class SvinData : public BaseData
{
public :
    SvinData() : ublox::BaseData( TIM , tim::SVIN )
    {
        this->clear() ;
    };
    void clear() ;
    U4 dur ;      //!< Passed survey-in observation time (s)
    I4 meanX ;    //!< Current survey-in mean position ECEF X coordinate (cm)
    I4 meanY ;    //!< Current survey-in mean position ECEF Y coordinate (cm)
    I4 meanZ ;    //!< Current survey-in mean position ECEF Z coordinate (cm)
    U4 meanV ;    //!< Current survey-in mean position 3D variance (mm^2)
    U4 obs   ;    //!< Observations used during survey-in
    U1 valid ;    //!< Survey-in position validity flag
    U1 active;    //!< Survey-in in progress flag
};

/*!
 * \brief Time mark data
 * This message contains information for high precision time stamping / pulse counting.
 * The delay figures and timebase given in CFG-TP are also applied to the time
 * results output in this message.
 */
class Tm2Data : public ublox::BaseData
{
public :
    Tm2Data() : ublox::BaseData( TIM , TM2 )
    {
        this->clear() ;
    }
    void clear() ;
    U1 ch ;            //!< marker channel 0 or 1
    X1 flags ;         //!< Bitmask (see graphic below)
    U2 count ;         //!< rising edge counter.
    U2 wnR ;           //!< week number of last rising edge
    U2 wnF ;           //!< week number of last falling edge
    U4 towMsR ;        //!< tow of rising edge
    U4 towSubMsR ;     //!< millisecond fraction of tow of rising edge in nanoseconds
    U4 towMsF ;        //!< tow of falling edge
    U4 towSubMsF ;     //!< millisecond fraction of tow of falling edge in nanoseconds
    U4 accEst ;        //!< Accuracy estimate
};

/*!
 * \brief TimePulse data
 * This message contains information for high precision timing.
 *\warning contents are correct only if the timepulse is set to one pulse per second.
 */
class TpData : public ublox::BaseData
{
public :
    TpData() : ublox::BaseData(TIM,TP)
    {
        this->clear();
    };
    void clear() ;
    U4 towMS ;    //!< Timepulse time of week according to time base
    U4 towSubMS ; //!< Submillisecond part of TOWMS (scaling = 2^-32 )
    I4 qErr ;     //!< Quantization error of timepulse.
    U2 week ;     //!< Timepulse week number according to time base
    X1 flags ;    //!< bitmask (see graphic below)
};

/*!
 * \brief Sourced Time Verification
 * This message contains verification information about previous time received
 * via AID-INI or from RTC
 */
class VrfyData : public ublox::BaseData
{
public :
    VrfyData() : ublox::BaseData(TIM,VRFY)
    {
        this->clear() ;
    };
    void clear() ;
    I4 itow ;    //!< integer millisecond tow received by source
    I4 frac ;    //!< sub-millisecond part of tow
    I4 deltaMs ; //!< integer milliseconds of delta time (current time minus sourced time)
    I4 deltaNs ; //!< sub-millisecond part of delta time
    U2 wno ;     //!< week number
    X1 flags ;   //!< information flags (see graphic below)
};

} ;
} ;

#endif
