# CMakeList.txt : CMake project for Eigen After Basic Math, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_package(Eigen3 CONFIG REQUIRED)
# Add source to this project's executable.
add_executable (main "Eigen After Basic Math.cpp" "Eigen After Basic Math.h")
target_link_libraries(main PRIVATE Eigen3::Eigen)

# TODO: Add tests and install targets if needed.
