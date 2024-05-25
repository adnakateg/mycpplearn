set(PROJN stack)
project(${PROJN} VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE cppSource "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE incSource "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

set(SRC_LIST ${cppSource})
set(INC_LIST ${incSource})

message("Cpplist = ${SRC_LIST}")
message("Inclist = ${INC_LIST}")

add_library(${PROJN} ${SRC_LIST})

target_include_directories(${PROJN} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


