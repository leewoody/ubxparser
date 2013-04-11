/*!
 * \file UbxBaseData.hpp
 * \author Clément Fouque
 * \date 27-07-2011
 * \version 2
 *
 * This file defines the base class for all data structure
 *
 */

#ifndef __UBLOX_BASE_DATA__
#define __UBLOX_BASE_DATA__

/**
 * \file UbxBaseData.hpp
 * \author Clément fouque
 * \date 25/05/2011
 * \version 1.0
 *
 * \brief Abstract class to handle UBX data structure
 *
 * This files contains an abstract class definition to be used as a basis
 * for all data structure coming from an UBX message.
 *
 * */

#include <boost/thread/mutex.hpp>
#include "base/UbxDatatype.hpp"

namespace ublox
{
//! \class BaseData
//! \brief Virtual class for data class
//! This abstract class should be inherited by class that describes
//! ublox messages. \n

class BaseData
{
public :
  //! Constructor
  //! Takes MSG_CLASS and MSG_ID as argument
  BaseData( const char & cl , const char & id)
      : iTow(0) ,
      week(0) ,
      mut()
  {
    msg_clss = cl ;
    msg_id = id ;
    mut.unlock();
  } ;

  //! Overloaded copy constructor
  BaseData( const BaseData & base ) :  mut()
  {
//     base.lock() ;
    msg_clss = base.msg_clss ;
    msg_id = base.msg_id ;
    iTow = base.iTow ;
    week = base.week ;
  } ;

  //! Default Destructor
  ~BaseData() {} ;

  //! Class of the message
  char msg_clss ;

  //! ID of the message
  char msg_id ;

  //! GPS Timestamp of the MSG (ms)
  U4 iTow ;

  //! GPS Week of the MSG
  U2 week ;

  //! returns the timestamp of the msg
  inline double timestamp()
  {
    return 1e-3 * static_cast<double>(this->iTow) ;
  } ;

  //! Display data as a human-readable format (for debugging purpose)
  virtual void display() {} ;

  //! \brief Abstract member function to reset class members
  //! This abstract member function must be reimplemented by classes
  //! that inherits from ublox::BaseData.
  virtual void clear() = 0 ;

  //! lock the mutex
  void lock()
  {
    mut.lock();
  }

  //! Try to acquire the lock without blocking.
  bool try_lock()
  {
    return mut.try_lock();
  }

  //! Release the lock.
  void unlock()
  {
    mut.unlock();
  }



private :
  //! a mutex to allow concurential access to data.
  boost::mutex mut ;

} ;

/*!
 * \brief Empty data structure used for convenience
 */
class NullData : public BaseData
{
public :
  NullData() : BaseData(0,0) {};
  void clear() {};
} ;

} ;

#endif
