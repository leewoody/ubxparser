# Find UbxParser library
# defines :
# UbxParser_INCLUDE_DIR
# UbxParser_LIBRARIES

# locate the path of headers
INCLUDE(FindPackageHandleStandardArgs)
FIND_PATH( UbxParser_INCLUDE_DIR NAMES UbxDefinitions.hpp PATH_SUFFIXES UbxParser )
FIND_LIBRARY( UbxParser_LIBRARY NAMES UbxParser libUbxParser )
FIND_PACKAGE_HANDLE_STANDARD_ARGS( UbxParser DEFAULT_MSG UbxParser_LIBRARY UbxParser_INCLUDE_DIR )

# MESSAGE( STATUS "UbxParser_INCLUDE_DIR : ${UbxParser_INCLUDE_DIR}" )
# MESSAGE( STATUS "UbxParser_LIBRARY : ${UbxParser_LIBRARY}" )

# IF( UbxParser_FOUND )
# 	MESSAGE( STATUS "UbxParser Found" )
    SET( UbxParser_LIBRARIES ${UbxParser_LIBRARY} )
    SET( UbxParser_INCLUDE_DIRS ${UbxParser_INCLUDE_DIR} )
    MESSAGE( STATUS "UbxParser_INCLUDE_DIR : ${UbxParser_INCLUDE_DIR}" )
    MESSAGE( STATUS "UbxParser_LIBRARY : ${UbxParser_LIBRARY}" )
# ENDIF( UbxParser_FOUND )

MARK_AS_ADVANCED( UbxParser_INCLUDE_DIR UbxParser_LIBRARY )


