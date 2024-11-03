cmake_minimum_required(VERSION 3.10)
project(gugong2)

set(CMAKE_CXX_STANDARD 17)

# 현재 디렉토리의 헤더 파일 포함
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# AVL Tree 및 Set 라이브러리 추가
add_library(avl_tree avl_tree.cpp)
add_library(set set.cpp)

# 메인 실행 파일 추가
add_executable(main main.cpp)

# 메인 파일에 필요한 라이브러리 링크
target_link_libraries(main avl_tree set)