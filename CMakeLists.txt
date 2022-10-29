cmake_minimum_required(VERSION 3.13)

project(
	Shoutout_from_Fetchcontent
	VERSION 1.0
	LANGUAGES CXX
	DESCRIPTION "This shouts out ;)"
	HOMEPAGE_URL "http://vorlesung.nabla-b.engineering"
)

include(FetchContent)

find_package(CLI11 2 QUIET)
if(NOT CLI11_FOUND)
	fetchcontent_declare(
		CLI11
		GIT_REPOSITORY https://github.com/CLIUtils/CLI11
		GIT_TAG main
	)
	fetchcontent_makeavailable(CLI11)
endif()

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} CLI11::CLI11)
