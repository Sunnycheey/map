cmake_minimum_required(VERSION 3.24)
project(Map)

set(CMAKE_CXX_STANDARD 11)

add_executable(Map main.cpp storage/Map.cpp storage/Map.h storage/HashMap.cpp storage/HashMap.h storage/List.cpp storage/List.h storage/LinkedList.cpp storage/LinkedList.h storage/HashFunc.cpp storage/HashFunc.h storage/KvData.cpp storage/KvData.h storage/StdHashFunc.cpp storage/StdHashFunc.h)
