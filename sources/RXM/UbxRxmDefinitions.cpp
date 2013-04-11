#include "RXM/UbxRxmDefinitions.hpp"

using namespace ublox::rxm ;

//-------- RXM-EPH --------//
void EphData::clear()
{
    svid = 0 ;
    how = 0 ;
    for ( int k = 0 ; k < 8 ; k++ )
    {
        sf1d[k] = 0 ;
        sf2d[k] = 0 ;
        sf3d[k] = 0 ;
    }
};

//-------- RXM-ALM --------//
void AlmData::clear()
{
    svid = 0 ;
    almWeek = 0 ;
    for ( int k = 0 ; k < 8 ; k++ )
        dwrd[k] = 0 ;
} ;

//-------- RXM-PMREQ --------//
void PmreqData::clear()
{
    duration = 0 ;
    flags.reset() ;
} ;

//-------- RXM-RAW --------//
void RawData::clear()
{
    iTow = 0 ;
    week = 0 ;
    numSV = 0 ;
    meas.clear() ;
} ;

void RawData::display()
{
    using namespace std ;
    cout << fixed << "RXM-RAW : " ;
    cout << (int)week << ":" << (float)iTow/1000 << "\t Nb SV :" << (int)numSV << "\n" ;
    for ( int k = 0 ; k < numSV ; k++ )
    {
        cout << (int)meas[k].svId << "\t" ;
        cout << meas[k].L1 << "\t" ;
        cout << meas[k].C1 << "\t" ;
        cout << meas[k].D1 << "\t" ;
        cout << (int)meas[k].snr << "\t" ;
        cout << (int)meas[k].QualIndic <<"\n" ;
    }
    cout << endl ;
}

//---------- RXM-SFRB ----------------//
void SfrbData::clear()
{
    dwrds.clear() ;
};

//---------- RXM-SVSI ----------------//
void SvsiData::clear()
{
    iTow = 0 ;
    week = 0 ;
    numSV = 0 ;
    numVis = 0 ;
    svInfos.clear() ;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0;
