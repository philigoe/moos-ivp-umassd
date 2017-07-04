#--------------------------------------------------------
# The CMakeLists.txt for:               pMoosCoordinateConsumer
# Author(s):                            Phil Igoe
#--------------------------------------------------------

FILE(GLOB SRC *.cpp)

ADD_EXECUTABLE(pMoosCoordinateConsumer ${SRC})

TARGET_LINK_LIBRARIES(pMoosCoordinateConsumer
    MOOS
    MOOSGeodesy
    m
    pthread)

