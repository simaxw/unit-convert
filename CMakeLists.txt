cmake_minimum_required(VERSION 3.30.0)

set(TARGET_NAME unitconvert)

project(${TARGET_NAME} VERSION 1.1 LANGUAGES CXX)
configure_file(config.h.in config.h)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(
  Qt6 COMPONENTS Core Core5Compat Widgets Network Xml Qml
)

add_executable(
  ${TARGET_NAME}
  src/about.cpp
  src/about.hpp
  src/app.cpp
  src/ccore.cpp
  src/ccore.hpp
  src/help.cpp
  src/help.hpp
  src/main.cpp
  src/main.hpp
  src/menufactory.cpp
  src/menufactory.hpp
  src/parser.cpp
  src/parser.hpp
  src/settings.cpp
  src/settings.hpp
  src/unit.cpp
  src/unit.hpp
)

target_compile_options(
  ${TARGET_NAME}
  PRIVATE
  -Wall
  -Wextra
  -pedantic
  -Werror
)

target_include_directories(
  ${TARGET_NAME}
  PUBLIC
  "${PROJECT_BINARY_DIR}"
)

target_link_libraries(
  ${TARGET_NAME}
  Qt6::Core
  Qt6::Core5Compat
  Qt6::Widgets
  Qt6::Network
  Qt6::Xml
  Qt6::Qml
)
