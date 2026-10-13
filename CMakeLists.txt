cmake_minimum_required(VERSION 3.12)

project(Practica02 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opciones de compilacion segun el compilador
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(NOT DEFINED CPACK_PACKAGE_NAME)
    set(CPACK_SOURCE_GENERATOR ZIP)
    include(CPack)
endif()

add_library(Tragaperras Tragaperras.cpp)

add_library(Poker
    Poker.cpp
    Jugador.cpp
    Mano.cpp
    Carta.cpp
)

add_library(Blackjack
    Blackjack.cpp
    Carta.cpp
)

add_library(Ruleta Ruleta.cpp)

add_executable(Casino Casino.cpp)

target_link_libraries(Casino
    Tragaperras
    Poker
    Blackjack
    Ruleta
)

target_include_directories(Casino PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_features(Casino PRIVATE cxx_std_17)
