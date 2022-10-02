cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris
        src/main.cpp
        src/gameLogic/Block.h src/gameLogic/Block.cpp
        src/gameLogic/Factory/ColoredBlockFactory.h src/gameLogic/Factory/ColoredBlockFactory.cpp
        src/gameLogic/Factory/ColorFactory.h src/gameLogic/Factory/ColorFactory.cpp
        src/gameLogic/Factory/BlockFactory.h src/gameLogic/Factory/BlockFactory.cpp
        src/GameConstants.h
        src/gameLogic/GameState.h src/gameLogic/GameState.cpp
        src/Render.h src/Render.cpp
        src/smfl/UserInput.h src/smfl/UserInput.cpp
        src/smfl/Visualization.h src/smfl/Visualization.cpp
        src/gameLogic/Matrix.h src/gameLogic/Matrix.cpp
        )


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