cmake_minimum_required(VERSION 3.5)
project(state-space)

find_package(Eigen3 REQUIRED)
include_directories(
  include
  ${EIGEN3_INCLUDE_DIRS}
)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
add_library(${PROJECT_NAME} ${SRC})

add_executable(${PROJECT_NAME}_test ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME}_test
  ${PROJECT_NAME}  
)