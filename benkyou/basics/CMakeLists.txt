set(PROJN basics)
project(${PROJN} VERSION ${PROJECT_VERSION})

file(GLOB_RECURSE cppSource "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE incSource "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

set(SRC_LIST ${cppSource})
set(INC_LIST ${incSource})

message("Cpplist = ${SRC_LIST}")
message("Inclist = ${INC_LIST}")

add_executable(${PROJN} ${SRC_LIST})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
add_test(benktests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJN})
target_include_directories(${PROJN} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJN} -lgtest)

