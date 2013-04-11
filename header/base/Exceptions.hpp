#ifndef __UBLOX_PARSER_EXCEPTIONS__
#define __UBLOX_PARSER_EXCEPTIONS__

#include <exception>

namespace ublox
{

  class UnknowParser : public std::exception
  {
  public :
    const char * what()
    {
      return "Unknow Parser" ;
    };
  } ;

  class UnknowData : public std::exception
  {
  public :
    const char * what()
    {
      return "Data type unknown" ;
    };
  };

  class UnsetValue : public std::exception
  {
  public :
    const char * what()
    {
      return "Unset Value" ;
    };
  };

} ;

#endif