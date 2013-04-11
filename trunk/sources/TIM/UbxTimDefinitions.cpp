/*!
 * \file UbxTimDefinitions.cpp
 * \author Clement Fouque
 * \date 05/08/2011
 *
 * Definitions for ublox::tim data structures.
 */

#include "TIM/UbxTimDefinitions.hpp"

using namespace ublox ;
using namespace ublox::tim ;

//---------- SVIN ----------//
void SvinData::clear()
{
    dur = 0 ;
    meanX = 0 ;
    meanY = 0 ;
    meanZ = 0 ;
    meanV = 0 ;
    obs   = 0 ;
    valid = 0 ;
    active= 0 ;
}

//---------- TM2 ----------//
void Tm2Data::clear()
{
    ch = 0 ;
    flags = 0 ;
    count = 0 ;
    wnR = 0 ;
    wnF = 0 ;
    towMsR = 0 ;
    towSubMsR = 0 ;
    towMsF = 0 ;
    towSubMsF = 0 ;
    accEst = 0 ;
};

//----------- TP -----------//
void TpData::clear()
{
    towMS = 0 ;
    towSubMS = 0 ;
    qErr = 0 ;
    week = 0 ;
    flags.reset() ;
};

//--------- VRFY ----------//
void VrfyData::clear()
{
    itow = 0 ;
    frac = 0 ;
    deltaMs = 0 ;
    deltaNs = 0 ;
    wno = 0 ;
    flags = 0 ;
} ;
