cmake_minimum_required(VERSION 3.25)
project(Poker-XP C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} m)
target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic-errors -Wconversion -Wsign-conversion)
add_subdirectory(src)

configure_file(share/highscores.hsc highscores.hsc COPYONLY)
configure_file(share/Regles\ du\ poker.txt Regles\ du\ poker.txt COPYONLY)