cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

#-------------------------------------------------------------------------------
# User configuration
#-------------------------------------------------------------------------------
# Set Arduino sketchbook directory
if(WIN32)
    set(SKETCHBOOK_DIR  C:/Users/$ENV{USERNAME}/Documents/Arduino)
elseif(UNIX)
    set(SKETCHBOOK_DIR  $ENV{HOME}/Arduino)
endif()

# Configure one sketch
set(SKETCH examples/LCDKeypadShield/LCDKeypadShield.ino)

# Configure board, default Arduino UNO
set(BOARD       uno)

# Configure serial port:
if(WIN32)
    set(SERIAL_PORT     COM1)
elseif(UNIX)
    set(SERIAL_PORT     /dev/ttyUSB0)
endif()

#-------------------------------------------------------------------------------
# Project configuation
#-------------------------------------------------------------------------------
# Project name
set(PROJECT_NAME        ErriezLCDKeypadShield)

# Set library directory
set(LIB_SRC_DIR         ${SKETCHBOOK_DIR}/libraries/${PROJECT_NAME}/src)

# Configure project
project(${PROJECT_NAME})

# Configure include directories
include_directories(${LIB_SRC_DIR})

# Generate library
generate_arduino_library(
        ${PROJECT_NAME}Lib
        SRCS
            ${LIB_SRC_DIR}/LCDKeypadShield.cpp
        HDRS
            ${LIB_SRC_DIR}/LCDKeypadShield.h
)

# Configure project
set(${CMAKE_PROJECT_NAME}_SKETCH    ${SKETCH})
set(${CMAKE_PROJECT_NAME}_LIBS      ${PROJECT_NAME}Lib)
set(${CMAKE_PROJECT_NAME}_BOARD     ${BOARD})
set(${CMAKE_PROJECT_NAME}_PORT      ${SERIAL_PORT})
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
