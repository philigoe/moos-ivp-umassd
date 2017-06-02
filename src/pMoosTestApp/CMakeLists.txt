#--------------------------------------------------------
# The CMakeLists.txt for:               pMoosTestApp
# Author(s):                            Phil
#--------------------------------------------------------

FILE(GLOB SRC *.cpp)

ADD_EXECUTABLE(pMoosTestApp ${SRC})

TARGET_LINK_LIBRARIES(pMoosTestApp
    MOOS
    MOOSGeodesy
    m
    pthread)

