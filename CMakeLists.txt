cmake_minimum_required(VERSION 3.1)
project(DominosOptimizer VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(lib/SQLiteCpp)
file(GLOB SOURCES "src/*.cpp")

add_executable(DominosOptimizer ${SOURCES})

target_link_libraries(DominosOptimizer 
	SQLiteCpp
	sqlite3
	pthread
	dl
)
