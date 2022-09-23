cmake_minimum_required(VERSION 3.21)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers main.cpp srcs/vector.hpp srcs/stack.hpp srcs/iterator_utils/iterator_traits.hpp srcs/utils/enable_if.hpp srcs/utils/is_integral.hpp srcs/utils/equal.hpp)
