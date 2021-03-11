cmake_minimum_required(VERSION 3.15)
project(units_compare
  LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# set restrictive compilation warnings
include(warnings)
set_warnings()

# add project code
add_subdirectory(src)
