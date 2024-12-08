cmake_minimum_required(VERSION 3.10)
project(gugong2)

set(CMAKE_CXX_STANDARD 17)

# GoogleTest 설정
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 헤더 파일 경로 추가
include_directories(../)

# fixture_test 실행 파일 추가
add_executable(fixture_test fixture_test.cpp ${AVL_TREE_SRC})
target_link_libraries(fixture_test GTest::GTest GTest::Main)

# parameterized_test 실행 파일 추가
add_executable(parameterized_test parameterized_test.cpp ${SET_SRC})
target_link_libraries(parameterized_test GTest::GTest GTest::Main)

# 테스트 등록
add_test(NAME fixture_test COMMAND fixture_test)
add_test(NAME parameterized_test COMMAND parameterized_test)
