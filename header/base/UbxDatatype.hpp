#ifndef __UBLOX_DATATYPE__
#define __UBLOX_DATATYPE__

#include <bitset>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>

namespace ublox
{
   // Type of message fields
typedef unsigned char U1 ;
typedef unsigned short U2 ;
typedef unsigned long U4 ;
typedef char I1 ;
typedef short I2 ;
typedef long I4 ;
typedef float R4 ;
typedef double R8 ;
typedef std::bitset<8> X1 ;
typedef std::bitset<16> X2 ;
typedef std::bitset<32> X4 ;

typedef char buffer_v ;
typedef std::vector<buffer_v> buffer_t ;
typedef boost::signals2::signal<void ()> signal_t ;
typedef signal_t::slot_type slot_t ;
typedef unsigned short MSG_ID ;

class BaseData ;
typedef boost::shared_ptr<BaseData> datas_p ;

class ParserBase ;
typedef boost::shared_ptr<ParserBase> parsers_p ;

};

#endif

