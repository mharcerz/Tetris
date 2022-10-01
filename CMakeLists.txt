cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris
        src/Field.cpp
        src/Field.h
        src/main.cpp)


include_directories(src headers c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(tetris ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()