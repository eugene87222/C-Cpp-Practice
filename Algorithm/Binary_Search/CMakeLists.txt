cmake_minimum_required(VERSION 3.10.2)

project(Binary_Search)

# Maybe can move to top level CMakeLists.txt in the future
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(IMPLEMENTATION_FILES
    src/Binary_Search_Test.cpp
    src/Binary_Search.cpp
)

set(IMPLEMENTATION_HEADER_FILES
    include/Binary_Search.h
)

add_executable(${PROJECT_NAME}
    ${IMPLEMENTATION_FILES}
    ${IMPLEMENTATION_HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
)