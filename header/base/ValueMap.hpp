#ifndef __UBLOX_VALUE_MAP__
#define __UBLOX_VALUE_MAP__

#include <map>
#include "base/UbxDatatype.hpp"
#include "base/Exceptions.hpp"

namespace ublox
{

/*!
 * MapData according to the Message  ID
 */
template <typename T> class ValueMap : public std::map<MSG_ID,T>
{

  public :
    void set( const MSG_ID & id , T val ) ;
    T get( const MSG_ID & id ) ;
};

template <typename T > void ValueMap<T>::set( const MSG_ID & id , T val )
{
  std::pair<MSG_ID,T> p( id , val ) ;
  this->insert(p);
};

template <typename T> T ValueMap<T>::get( const MSG_ID & id )
{
  typename ValueMap<T>::iterator it ;
  it = this->find( id );
  if ( it == this->end() ) throw ( ublox::UnsetValue() );
  else return it->second ;
};

};

#endif