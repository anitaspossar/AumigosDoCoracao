cmake_minimum_required(VERSION 3.28)
project(ClinicaAumigosdoCoracao C)

set(CMAKE_C_STANDARD 11)

add_executable(ClinicaAumigosdoCoracao app.c
        pacientes.c
        pacientes.h)
