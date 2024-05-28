cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add the executable for the main project
add_executable(Lists src/main.cpp src/SortedLinkedList.cpp src/UnsortedLinkedList.cpp)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executables
# add_executable(SortedLinkedList_tests tests/SortedLinkedList_tests.cpp)
# target_link_libraries(SortedLinkedList_tests ${GTEST_LIBRARIES} pthread)

add_executable(ListFindTest tests/ListFindTest.cpp src/SortedLinkedList.cpp src/UnsortedLinkedList.cpp)
target_link_libraries(ListFindTest ${GTEST_LIBRARIES} pthread)

# # Add tests to CTest
add_test(NAME ListFindTest COMMAND ListFindTest)
# add_test(NAME UnSortedLinkedList_tests COMMAND UnSortedLinkedList_tests)
