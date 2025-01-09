cmake_minimum_required(VERSION 3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.25)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_SKIP_RPATH ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(CppTraining VERSION 1.0
                    DESCRIPTION "Cpp Training Project"
                    LANGUAGES CXX)


set(PROJN proj)


set(SRC_LIST 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJN} ${SRC_LIST})

target_compile_features(${PROJN} PUBLIC cxx_std_20)

link_directories(
)

set(MY_LINK_LIBRARIES
  gtest
)

target_include_directories(${PROJN} PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/dsa/
)

target_link_libraries(${PROJN} LINK_PUBLIC ${MY_LINK_LIBRARIES})

