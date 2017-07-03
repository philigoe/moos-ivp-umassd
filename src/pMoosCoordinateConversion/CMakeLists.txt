#--------------------------------------------------------
# The CMakeLists.txt for:               pMoosCoordinateConversion
# Author(s):                            Phil Igoe
#--------------------------------------------------------

FILE(GLOB SRC *.cpp)

ADD_EXECUTABLE(pMoosCoordinateConversion ${SRC})

TARGET_LINK_LIBRARIES(pMoosCoordinateConversion
    MOOS
    MOOSGeodesy
    m
    pthread)

