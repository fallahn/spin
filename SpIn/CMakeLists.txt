project(spin)
cmake_minimum_required(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
SET(SPIN_STATIC_SFML FALSE CACHE BOOL "Choose whether SFML is linked statically or not.")
SET(SPIN_STATIC_RUNTIME FALSE CACHE BOOL "Use statically linked standard/runtime libraries? This option must match the one used for SFML.")


if(CMAKE_COMPILER_IS_GNUCXX)
  if(xygine_example_STATIC_RUNTIME)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y -static")
  else()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y")
  endif()
endif()

SET (CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG_ -DOP_TEST")
SET (CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")

if(SPIN_STATIC_SFML)
  SET(SFML_STATIC_LIBRARIES TRUE)
endif()

if(WIN32)
  find_package(SFML 2 REQUIRED graphics window audio system network main)
else()
  find_package(SFML 2 REQUIRED graphics window audio system network)
endif()

if(UNIX)
  find_package(X11 REQUIRED)
endif()

find_package(OpenGL REQUIRED)

include_directories(
  ${OPENGL_INCLUDE_DIRECTORIES}
  ${SFML_INCLUDE_DIR} 
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/../I8080/include)

if(X11_FOUND)
  include_directories(${X11_INCLUDE_DIRS})
endif()

SET(I8080_DIR ${CMAKE_SOURCE_DIR}/../I8080/src)
include(${I8080_DIR}/CMakeLists.txt)

SET(SPIN_DIR ${CMAKE_SOURCE_DIR}/src)
include(${SPIN_DIR}/CMakeLists.txt)

if(WIN32)
  add_executable(spin WIN32 ${SPIN_SRC} ${I8080_SRC})
else()
  add_executable(spin ${SPIN_SRC} ${I8080_SRC})
endif()

target_link_libraries(spin
  ${SFML_LIBRARIES}
  ${SFML_DEPENDENCIES}
  ${OPENGL_LIBRARIES})

if(UNIX)
  target_link_libraries(spin
    ${X11_LIBRARIES})
endif()

#install executable
install(TARGETS spin
  RUNTIME DESTINATION .)

#install game data
install(DIRECTORY assets
  DESTINATION .)

#install the OpenAL DLL
if(WIN32)
  install(FILES ${SFML_INCLUDE_DIR}/../bin/openal32.dll
    DESTINATION .)
endif()
