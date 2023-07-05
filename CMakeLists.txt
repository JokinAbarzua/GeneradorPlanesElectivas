cmake_minimum_required(VERSION 3.12)
project(diasElectivas)

# Configuración de compilación
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Archivos fuente
set(SOURCES
    diasElectivas.cpp
    Horario.cpp
    Materia.cpp
)

# Agregar ejecutable
add_executable(diasElectivas ${SOURCES})
