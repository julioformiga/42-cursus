cmake_minimum_required(VERSION 3.30)

project(MiniShell)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SRC "src/*.c")
file(GLOB LIBFT_SRC "lib/libft/src/*.c")
file(GLOB LIBFT_PRINTF_SRC "lib/libft/src/ft_printf/*.c")

add_executable(minishell ${SRC} ${LIBFT_SRC} ${LIBFT_PRINTF_SRC})

target_link_libraries(minishell readline)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
set(BUILD_GMOCK OFF)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

add_executable(test_minishell test/test_minishell.cpp)
target_link_libraries(test_minishell gtest gtest_main)
add_test(NAME TestMinishell COMMAND test_minishell)
