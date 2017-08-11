#--------------------------------------------------------
# The CMakeLists.txt for:               pMoosDynamicRID
# Author(s):                            Phil Igoe
#--------------------------------------------------------

FILE(GLOB SRC *.cpp)

ADD_EXECUTABLE(pMoosDynamicRID ${SRC})

TARGET_LINK_LIBRARIES(pMoosDynamicRID
    MOOS
    MOOSGeodesy
    m
    pthread)

