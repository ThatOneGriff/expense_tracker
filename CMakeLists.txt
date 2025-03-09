cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(expense_tracker VERSION 1.0 LANGUAGES CXX)

# libraries
set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(include/nlohmann_json)

# headers
add_library(helper STATIC helper.hpp)
set_property(TARGET helper PROPERTY LINKER_LANGUAGE CXX)


add_executable(expense_tracker main.cpp)
target_link_libraries(expense_tracker PRIVATE nlohmann_json::nlohmann_json helper)
set_property(TARGET expense_tracker PROPERTY CXX_STANDARD 17)