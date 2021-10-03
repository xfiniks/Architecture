cmake_minimum_required(VERSION 3.19)
project(Arc_Chernykh C)

set(CMAKE_C_STANDARD 11)

add_executable(Arc_Chernykh main.c shrub.c shrub.h flower.c flower.h plant.c plant.h rnd.c rnd.h tree.c tree.h container.c container.h)