cmake_minimum_required(VERSION 3.10.0)
project(kalkulator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build as a Windows GUI application (no console)
add_executable(kalkulator WIN32 main.cpp)

if(MSVC)
	target_compile_options(kalkulator PRIVATE /W4 /permissive-)
else()
	target_compile_options(kalkulator PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Link common Windows libraries used for GUI drawing
if(WIN32)
	target_link_libraries(kalkulator PRIVATE user32 gdi32 comctl32)
endif()

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
