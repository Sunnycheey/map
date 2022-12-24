cmake_minimum_required(VERSION 3.24)
project(Map)

set(CMAKE_CXX_STANDARD 11)

add_executable(Map main.cpp Map.cpp Map.h HashMap.cpp HashMap.h List.cpp List.h LinkedList.cpp LinkedList.h HashFunc.cpp HashFunc.h KvData.cpp KvData.h StdHashFunc.cpp StdHashFunc.h)
