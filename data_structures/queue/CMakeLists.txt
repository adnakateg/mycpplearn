set(PROJN queues)

project(${PROJN} VERSION ${PROJECT_VERSION})

set(SRC_LIST 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
)

add_executable(${PROJN} ${SRC_LIST})

target_compile_features(${PROJN} PUBLIC cxx_std_20)

link_directories(
)

set(MY_LINK_LIBRARIES
  gtest
)

target_include_directories(${PROJN} PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/include 
)

target_link_libraries(${PROJN} LINK_PUBLIC ${MY_LINK_LIBRARIES})

