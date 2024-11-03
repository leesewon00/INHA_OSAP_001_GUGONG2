cmake_minimum_required(VERSION 3.10)
project(gugong2)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest 설정
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 헤더 파일 경로 추가
include_directories(../)

# AVL Tree 소스 파일 추가
set(AVL_TREE_SRC
    ../avl_tree.cpp
)

# Set 소스 파일 추가
set(SET_SRC
    ../set.cpp
)

# AVL Tree 테스트 실행 파일 추가
add_executable(avl_tree_test avl_tree_test.cpp ${AVL_TREE_SRC})
target_link_libraries(avl_tree_test GTest::GTest GTest::Main)

# Set 테스트 실행 파일 추가
add_executable(set_test set_test.cpp ${SET_SRC})
target_link_libraries(set_test GTest::GTest GTest::Main)

# 테스트 등록
add_test(NAME avl_tree_test COMMAND avl_tree_test)
add_test(NAME set_test COMMAND set_test)
