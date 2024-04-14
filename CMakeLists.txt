cmake_minimum_required(VERSION 3.10.2)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(tetris
        src/main.cpp
        src/gameLogic/BlockOnBoard.h src/gameLogic/BlockOnBoard.cpp
        src/gameLogic/Factory/ColoredBlockFactory.h src/gameLogic/Factory/ColoredBlockFactory.cpp
        src/gameLogic/Factory/ColorFactory.h src/gameLogic/Factory/ColorFactory.cpp
        src/gameLogic/Factory/BlockFactory.h src/gameLogic/Factory/BlockFactory.cpp
        src/GameConstants.h
        src/gameLogic/GameState.h src/gameLogic/GameState.cpp
        src/sfml/UserInput.h src/sfml/UserInput.cpp
        src/sfml/Visualization.h src/sfml/Visualization.cpp
        src/gameLogic/BoolMatrix.h
        src/gameLogic/GameBoard.h src/gameLogic/GameBoard.cpp
        src/gameLogic/BlockPattern.h src/gameLogic/BlockPattern.cpp
        src/gameLogic/BlockWithColor.h src/gameLogic/BlockWithColor.cpp
        src/gameLogic/Run.h src/gameLogic/Run.cpp
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
