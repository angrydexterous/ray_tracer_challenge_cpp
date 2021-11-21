cmake_minimum_required(VERSION 3.2)
project(primatives C CXX)

set(SOURCE_FILES
    tuple.h
    tuple.cpp
)

add_library(primatives SHARED STATIC ${SOURCE_FILES})

install(TARGETS primatives DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})
install(FILES tuple.h math.h DESTINATION ${DIVISIBLE_INSTALL_INCLUDE_DIR})
