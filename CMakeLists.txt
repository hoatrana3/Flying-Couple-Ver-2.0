cmake_minimum_required(VERSION 3.2)
project(SFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Cpp/Audio.cpp Header/Audio.h Header/Background.h Cpp/Background.cpp Header/Character.h Cpp/Character.cpp Header/ControlGame.h Cpp/ControlGame.cpp Header/LoadAnimation.h Cpp/LoadAnimation.cpp Header/Screen.h Cpp/Screen.cpp Header/Gameproject.h Cpp/Gameproject.cpp)
add_executable(SFML ${SOURCE_FILES} Cpp/Audio.cpp Header/Audio.h Header/Background.h Cpp/Background.cpp Header/Character.h Cpp/Character.cpp Header/ControlGame.h Cpp/ControlGame.cpp Header/LoadAnimation.h Cpp/LoadAnimation.cpp Header/Screen.h Cpp/Screen.cpp Header/Gameproject.h Cpp/Gameproject.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-build-release")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML ${SFML_LIBRARIES})
endif()