cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

project(UniPD_BatagliaNavale)

include_directories(include)

add_library(${PROJECT_NAME}
	src/Battleship.cpp
	src/Submarine.cpp
	src/Support.cpp
	src/Unit.cpp
	src/Grid.cpp
	src/Game.cpp
	src/Pc_vs_pc.cpp
	src/Pc_vs_player.cpp
	src/Replay.cpp
)

add_executable(main 
	src/main.cpp
	)

add_executable(mainReplay
	src/mainReplay.cpp
	)

target_link_libraries(main ${PROJECT_NAME})
target_link_libraries(mainReplay ${PROJECT_NAME})
