cmake_minimum_required(VERSION 3.15...4.0)

project(
	tvrender-samples
	VERSION 0.1
	LANGUAGES C
)

find_library(LIBTVR tvrender)

add_executable(
	tvrender-sample-triangle
	src/triangle.c
)
target_link_libraries(tvrender-sample-triangle ${LIBTVR})

