cmake_minimum_required(VERSION 3.20)
project(lab_booking CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(lab_booking STATIC
    src/admin.cpp
    src/booking.cpp
    src/equipment.cpp
    src/student.cpp
    src/user.cpp
)
target_include_directories(lab_booking PUBLIC include)

if(MSVC)
    target_compile_options(lab_booking PRIVATE /W4)
else()
    target_compile_options(lab_booking PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(demo src/demo.cpp)
target_link_libraries(demo PRIVATE lab_booking)

add_executable(scenario_diagram scenarios/diagram.cpp)
target_link_libraries(scenario_diagram PRIVATE lab_booking)
