cmake_minimum_required(VERSION 3.28)
project(cpp_module_03)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(claptrap0
        ex00/main.cpp
        ex00/ClapTrap.cpp
        ex00/ClapTrap.hpp)
