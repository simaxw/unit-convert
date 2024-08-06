cmake_minimum_required(VERSION 3.30.0)

set(TARGET_NAME unitconvert)

project(${TARGET_NAME} VERSION 2.2.0 LANGUAGES CXX)
configure_file(config.h.in config.h)

set(CMAKE_AUTOMOC ON)

find_package(
  Qt6 COMPONENTS Core Widgets Xml Qml
)

set(PROJECT_SOURCES
  src/main.cpp
  src/convert.cpp
  src/convert.hpp
  src/parser.cpp
  src/parser.hpp
  src/unit.cpp
  src/unit.hpp
  src/ccore.cpp
  src/ccore.hpp
  src/about.cpp
  src/about.hpp
  src/help.cpp
  src/help.hpp
  src/menufactory.cpp
  src/menufactory.hpp
  src/settings.cpp
  src/settings.hpp
)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  enable_language("RC")
  set (WIN32_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/res/convert.rc)
  add_executable(${TARGET_NAME} WIN32
    ${PROJECT_SOURCES}
    ${WIN32_RESOURCES}
  )
else()
  add_executable(
    ${TARGET_NAME}
    ${PROJECT_SOURCES}
  )
endif()

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
  Qt6::Widgets
  Qt6::Xml
  Qt6::Qml
)

set(QRC_FILE ${PROJECT_SOURCE_DIR}/res/main.qrc)
set(RESOURCE_BINARY ${CMAKE_CURRENT_BINARY_DIR}/data.rcc)

add_custom_command(
  OUTPUT ${RESOURCE_BINARY}
  COMMAND rcc -o ${RESOURCE_BINARY} --binary --compress 9 ${QRC_FILE}
  DEPENDS ${QRC_FILE}
  COMMENT "Generating binary resource file"
)

add_custom_target(ResourceTarget ALL DEPENDS ${RESOURCE_BINARY})
add_dependencies(${TARGET_NAME} ResourceTarget)
