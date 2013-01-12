#################################
#   blobtastic CMake Build File   #
#################################

PROJECT(blobtastic)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)

SET(INCLUDE ${blobtastic_SOURCE_DIR}/include)
SET(SRC ${blobtastic_SOURCE_DIR}/src)

INCLUDE_DIRECTORIES(${INCLUDE})

FILE(GLOB INCLUDES ${INCLUDE}/*.h ${INCLUDE}/*.hpp)
FILE(GLOB SOURCES ${SRC}/*.cpp)

IF(WIN32)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../prefix/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../opencv/kiss-prefix/include)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/../prefix/lib)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/../opencv/kiss-prefix/lib)
ENDIF(WIN32)

SET(CMAKE_CXX_FLAGS "-Wall")

IF(APPLE)
	ADD_DEFINITIONS(-arch i386 -arch x86_64 -g)
ELSEIF(WIN32)
	SET(CMAKE_CXX_FLAGS "-Wl,--enable-auto-import")
ELSEIF(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
ENDIF()

SET(LIBRARY_OUTPUT_PATH ${blobtastic_SOURCE_DIR}/lib)

ADD_LIBRARY(blobtastic SHARED ${SOURCES})

IF(WIN32)
TARGET_LINK_LIBRARIES(blobtastic opencv_core249 opencv_highgui249 opencv_imgproc249)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(blobtastic opencv_core opencv_highgui opencv_imgproc)
ENDIF(WIN32)

IF(WIN32)
install(FILES ${INCLUDES} DESTINATION ${blobtastic_SOURCE_DIR}/../prefix/include/blobtastic)
INSTALL(TARGETS blobtastic
	LIBRARY DESTINATION ${blobtastic_SOURCE_DIR}/../prefix/lib
	RUNTIME DESTINATION ${blobtastic_SOURCE_DIR}/../prefix/lib)
ELSE(WIN32)

install(FILES ${INCLUDES} DESTINATION include/blobtastic)
INSTALL(TARGETS blobtastic LIBRARY DESTINATION lib)
ENDIF(WIN32)
add_subdirectory(test)