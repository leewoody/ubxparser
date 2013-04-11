#include "NAV/UbxNavDefinitions.hpp"

using namespace std ;
using namespace ublox;
using namespace ublox::nav ;

//-------------- AOPSTATUS -----------//
void AopstatusData::clear()
{
   config = 0 ;
   status = 0 ;
   avail = 0 ;
} ;

//-------------- CLOCK ----------------//
void ClockData::clear()
{
   clkB = 0 ;
   clkD = 0 ;
   tAcc = 0 ;
   fAcc = 0 ;
} ;

//-------------- DOP    ---------------//
void DopData::clear()
{
   iTow = 0 ;
   gDOP = 0 ;
   pDOP = 0 ;
   tDOP = 0 ;
   vDOP = 0 ;
   hDOP = 0 ;
   nDOP = 0 ;
   eDOP = 0 ;
};

void DopData::display()
{
   std::cout << "DOP Value (" << timestamp() <<")\n" ;
   std::cout << "GDOP : " << (float)gDOP/100 << "\n" ;
   std::cout << "PDOP : " << (float)pDOP/100 << "\n" ;
   std::cout << "TDOP : " << (float)tDOP/100 << std::endl ;
} ;

//-------------- DGPS -----------------//
void DgpsData::clear()
{
   age = 0 ;
  baseId = 0 ;
  baseHealth = 0 ;
  numCh = 0 ;
  status = 0 ;
  chData.clear() ;
} ;

//-------------- EKFSTATUS ------------//
void EkfstatusData::clear()
{
pulses = 0 ;
period = 0 ;
gyroMean = 0 ;
temperature = 0 ;
direction = 0 ;
calibStatus.reset() ;
pulseScale = 0 ;
gyroBias = 0 ;
gyroScale = 0 ;
accPulseScale= 0 ;
accGyroBias = 0 ;
accGyroScale= 0 ;
measUsed.reset() ;
} ;

//-------------- POSLLH ---------------//
PosllhData::PosllhData() : ublox::BaseData(NAV,POSLLH)
{
  this->clear() ;
} ;

void PosllhData::clear()
{

  this->iTow = 0 ;
  this->longitude = 0 ;
  this->latitude = 0 ;
  this->hElli = 0 ;
  this->hMsl = 0 ;
  this->hAcc = 0 ;
  this->vAcc = 0 ;
} ;

void PosllhData::display()
{
  cout << fixed ;
  cout << "NAV-POSLLH : " ;
  cout << iTow/1000 << "\t" << longitude * 1e-7 << "\t" << latitude * 1e-7 << "\t" << hElli/1000 << "\t" << hAcc/1000 << "\t" << vAcc/1000 << endl ;
} ;

//-------------- POSECEF ---------------//
PosecefData::PosecefData() : ublox::BaseData(NAV,POSECEF)
{
  this->clear() ;
} ;

void PosecefData::clear()
{
  this->iTow = 0 ;
  this->Xecef = 0 ;
  this->Yecef = 0 ;
  this->Zecef = 0 ;
  this->pAcc = 0 ;
} ;

void PosecefData::display()
{
  cout << fixed ;
  cout << "NAV-POSECEF : " ;
  cout << iTow/1000 << "\t" << (double)Xecef/100 << "\t" << (double)Yecef/ 100 << "\t" << (double)Zecef/100 << "\t" << (float)pAcc/100 << endl ;
}

//----------------- SBAS --------------------//
void SbasData::clear()
{
   geo = 0 ;
   mode = 0 ;
   sys = 0 ;
   cnt = 0 ;
   service.reset() ;
   sv.clear();
};

//--------------- SOL -----------------//
SolData::SolData() : ublox::BaseData(NAV,SOL)
{
  this->clear() ;
};

void SolData::clear()
{
//    PosecefData::clear();
  this->vXecef = 0 ;
  this->vYecef = 0 ;
  this->vZecef = 0 ;
  this->sAcc = 0 ;
  this->Xecef = 0 ;
  this->Yecef = 0 ;
  this->Zecef = 0 ;
  this->pAcc = 0 ;
  week = 0 ;
  gpsFix = 0;
  flags.reset() ;
  pdop = 0 ;
} ;

void SolData::display()
{
  cout << fixed ;
  cout << "\nNAV-SOL : " ;
  cout << "iTow : " << (int)week << ":" << (double)iTow/1000 << "\tPDOP : " << (float)pdop << endl ;
  cout << "POS : " << (double)Xecef/100 << "\t" << (double)Yecef/ 100 << "\t" << (double)Zecef/100 << "\t" << (float)pAcc/100 << endl ;
  cout << "VEL : " << (float)vXecef/100 << "\t" << (float)vYecef/100 << "\t" << (float)vZecef/100 << "\t" << (float)sAcc/100 << endl ;
};

//-------------- STATUS --------------//
void StatusData::clear()
{
   gpsFix = 0 ;
   flags.reset() ;
   fixStat.reset() ;
   flags2.reset() ;
   ttff = 0 ;
   msss = 0 ;
} ;

//-------------- SVINFO --------------//
SvinfoData::SvinfoData() : ublox::BaseData(NAV,SVINFO)
{
  this->clear();
};

void SvinfoData::clear()
{
  iTow = 0;
  numCh = 0 ;
  globalFlags = 0 ;
  chData.clear();
};

void SvinfoData::display()
{
  cout << fixed << "NAV-SVINFO : " ;
  cout << "Tow : " << (double)iTow/1000 << "\t Nchan : " << (int)numCh << "\n" ;
  for ( int k = 0 ; k < numCh ; k++ )
    {
      cout << (int)chData[k].chId << "\t" << (int)chData[k].svId ;
      cout << "\t" << (double)chData[k].prRes/100 ;
      cout << "\t" << (int)chData[k].elev << ":" << (int)chData[k].azim << "\n" ;
    }
  cout << endl ;
} ;

//----------------- TIMEGPS -----------------//
void TimegpsData::clear()
{
   fTow = 0 ;
   leapS = 0 ;
   valid.reset() ;
   tAcc = 0 ;
} ;


//----------------- TIMEUTC -----------------//
void TimeutcData::clear()
{
   iTow = 0 ;
   tAcc = 0 ;
   nano = 0 ;
   year = 0 ;
   month = 0 ;
   day = 0 ;
   hour = 0 ;
   min = 0 ;
   sec = 0 ;
   valid.reset() ;
}

//-------------- VELECEF ---------------//
VelecefData::VelecefData() : ublox::BaseData(NAV,VELECEF)
{
  this->clear() ;
} ;

void VelecefData::clear()
{
  this->iTow = 0 ;
  this->vXecef = 0 ;
  this->vYecef = 0 ;
  this->vZecef = 0 ;
  this->sAcc = 0 ;
} ;

void VelecefData::display()
{
  cout << fixed ;
  cout << "NAV-VELECEF : " ;
  cout << iTow << "\t" << (float)vXecef/100 << "\t" << (float)vYecef/100 << "\t" << (float)vZecef/100 << "\t" << (float)sAcc/100 << endl ;
}

//-------------- VELNED ---------------//
VelnedData::VelnedData() : ublox::BaseData(NAV,VELNED)
{
  this->clear() ;
} ;

void VelnedData::clear()
{
  iTow = 0 ;
  week = 0 ;
  velN = 0 ;
  velE = 0 ;
  velD = 0 ;
  speed = 0 ;
  gSpeed = 0 ;
  heading = 0 ;
  sAcc = 0 ;
  cAcc = 0 ;
} ;

void VelnedData::display()
{
  cout << fixed ;
  cout << "NAV-VELECEF : " ;
  cout << iTow << "\t" << (float)gSpeed/100 << "\t" << (float)heading*1e-5 << endl ;
}