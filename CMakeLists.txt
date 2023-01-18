cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-g -O2")

project(UniPD_BatagliaNavale)

include_directories(include)

add_library(${PROJECT_NAME}
	src/Battleship.cpp
	src/Submarine.cpp
	src/Support.cpp
	src/Unit.cpp
	src/Position.cpp
	src/Entity.cpp
	src/Controller.cpp
	src/ComputerVSComputer.cpp
	src/PlayerVSComputer.cpp
	src/Replay.cpp
	src/Helper.cpp
	src/Game.cpp
)

add_executable(battaglia_navale 
	src/main.cpp
	)

add_executable(replay
	src/mainReplay.cpp
	)

target_link_libraries(battaglia_navale ${PROJECT_NAME})
target_link_libraries(replay ${PROJECT_NAME})