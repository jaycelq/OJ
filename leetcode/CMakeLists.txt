cmake_minimum_required(VERSION 3.2)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ContainerWithMostWater.cpp)
add_executable(leetcode ${SOURCE_FILES})
add_executable(RemoveNthNodeFromEndofList RemoveNthNodeFromEndofList.cpp)
add_executable(ReverseLinkedList ReverseLinkedList.cpp)
add_executable(BinaryTreeZigzagLevelOrderTraversal BinaryTreeZigzagLevelOrderTraversal.cpp)
add_executable(MaximalSquare MaximalSquare.cpp)
add_executable(MaximalRectangle MaximalRectangle.cpp)
add_executable(BasicCalculator BasicCalculator.cpp)