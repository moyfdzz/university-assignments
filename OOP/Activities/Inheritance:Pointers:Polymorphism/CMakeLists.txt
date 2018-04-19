cmake_minimum_required(VERSION 3.9)
project(ActividadAnimal)

set(CMAKE_CXX_STANDARD 11)

add_executable(ActividadAnimal main.cpp Animal.h Perro.h Gato.h)

configure_file(Animal.h Animal.h COPYONLY)
configure_file(Perro.h Perro.h COPYONLY)
configure_file(Gato.h Gato.h COPYONLY)