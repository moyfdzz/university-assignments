cmake_minimum_required(VERSION 3.9)
project(Proyecto3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto3 main.cpp Fecha.h Reserva.h Material.h Libro.h Disco.h Software.h)

configure_file(Reserva.txt Reserva.txt COPYONLY)
configure_file(Material.txt Material.txt COPYONLY)