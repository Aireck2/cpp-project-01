cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(my_app
  src/main.cpp
  src/Incidente.cpp
  src/Validacion.cpp
)

target_include_directories(my_app PRIVATE include)
