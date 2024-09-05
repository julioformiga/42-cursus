cmake_minimum_required(VERSION 3.30)

project(MiniShell)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_subdirectory(lib/libft)

file(GLOB SRC "src/*.c")
file(GLOB LIBFT_SRC "lib/libft/src/*.c")
file(GLOB LIBFT_PRINTF_SRC "lib/libft/src/ft_printf/*.c")

add_executable(minishell ${SRC} ${LIBFT_SRC} ${LIBFT_PRINTF_SRC})

target_link_libraries(minishell readline)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

add_executable(test_minishell test/test_minishell.cpp)
target_link_libraries(test_minishell gtest gtest_main)
add_test(NAME test_minishell COMMAND test_minishell)
