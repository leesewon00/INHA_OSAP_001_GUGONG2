// MIT License

// Copyright(c) 2024 GUGONG2

//     Permission is hereby granted,
//     free of charge,
//     to any person obtaining a copy of this software and associated
//     documentation files(the "Software"), to deal in the Software without
//     restriction, including without limitation the rights to use, copy,
//     modify, merge, publish
//     ,
//     distribute, sublicense, and / or sell copies of the Software,
//     and to permit persons to whom the Software is furnished to do so,
//     subject to the following conditions :

//     The above copyright notice and this permission notice shall be included
//     in all copies or substantial portions of the Software.

//     THE SOFTWARE IS PROVIDED "AS IS",
//     WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//     INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
//     THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//     OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//     OTHER DEALINGS IN THE SOFTWARE.
//
//     2024.12 GUGONG2

#include <gtest/gtest.h>
#include "../avl_tree.cpp"
#include "../set.cpp"

// SetTestFixture 클래스는 <int,int> 형태의 파라미터 테스트를 위한 공통된 설정을
// 제공하는 Fixture
class SetTestFixture : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
  Set<int> set_t;

public:
  SetTestFixture() : set_t(new AVLTree<int>()) {}

  // 각 테스트 실행 전 호출되어 set init
  void SetUp() override {
    //      3
    //     /  \
    //    2    4
    set_t.Insert(2);
    set_t.Insert(3);
    set_t.Insert(4);
  }
};

// FindNode 메서드에서 여러 가지 입력 값을 테스트하기 위한 테스트 인스턴스
INSTANTIATE_TEST_CASE_P(FindNodeParamSet, SetTestFixture,
                        testing::Values(std::make_tuple(2, 2),
                                        std::make_tuple(3, 2),
                                        std::make_tuple(4, 2)));

// FindNode 메서드 여러 가지 입력으로 테스트
TEST_P(SetTestFixture, FindNodeParamSet) {
  std::tuple<int, int> tuple = GetParam();

  int param          = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  int is_inside = set_t.FindNode(param);
  ASSERT_EQ(expected_value, is_inside);
}

// SetTestFixture 클래스는 <int,pair<int,int>> 형태의 파라미터 테스트를 위한
// 공통된 설정을 제공하는 Fixture
class GetRankTestFixture
  : public ::testing::TestWithParam<std::tuple<int, std::pair<int, int>>> {
protected:
  Set<int> set_t;

public:
  GetRankTestFixture() : set_t(new AVLTree<int>()) {}
  void SetUp() override {
    set_t.Insert(2);
    set_t.Insert(3);
    set_t.Insert(4);
  }
};
// 테스트 오라클
INSTANTIATE_TEST_CASE_P(
    GetRankParamSet, GetRankTestFixture,
    testing::Values(std::make_tuple(2, std::make_pair(2, 1)),
                    std::make_tuple(3, std::make_pair(2, 2)),
                    std::make_tuple(4, std::make_pair(2, 3)),
                    std::make_tuple(5, std::make_pair(-1, -1))));

TEST_P(GetRankTestFixture, GetRankParamSet) {
  std::tuple<int, std::pair<int, int>> tuple = GetParam();

  int param                          = std::get<0>(tuple);
  std::pair<int, int> expected_value = std::get<1>(tuple);

  auto KandRank = set_t.GetRank(param);
  ASSERT_EQ(expected_value, KandRank);
}

// Insert Test를 위한 Fixture
class InsertTestFixture
  : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
  Set<int> set_t;

public:
  InsertTestFixture() : set_t(new AVLTree<int>()) {}

  // 각 테스트 실행 전 호출되어 set init
  void SetUp() override {
    set_t.Insert(2);
    set_t.Insert(3);
    set_t.Insert(4);
  }
};

// INSERT 테스트 오라클
INSTANTIATE_TEST_CASE_P(GetInsertParamSet, InsertTestFixture,
                        testing::Values(std::make_tuple(5, 3),
                                        std::make_tuple(6, 3),
                                        std::make_tuple(7, 3)));
TEST_P(InsertTestFixture, GetInsertParamSet) {
  std::tuple<int, int> tuple = GetParam();

  int param          = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  int InsertValue = set_t.Insert(param);
  ASSERT_EQ(expected_value, InsertValue);
}

// Erase Test를 위한 Fixture
class EraseTestFixture : public ::testing::TestWithParam<std::tuple<int, int>> {
protected:
  Set<int> set_t;

public:
  EraseTestFixture() : set_t(new AVLTree<int>()) {}

  // 각 테스트 실행 전 호출되어 set init
  void SetUp() override {
    set_t.Insert(2);
    set_t.Insert(3);
    set_t.Insert(4);
  }
};

// Erase 테스트 오라클
INSTANTIATE_TEST_CASE_P(GetEraseParamSet, EraseTestFixture,
                        testing::Values(std::make_tuple(4, 2),
                                        std::make_tuple(3, 2),
                                        std::make_tuple(5, 0)));
TEST_P(EraseTestFixture, GetEraseParamSet) {
  std::tuple<int, int> tuple = GetParam();

  int param          = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  int EraseValue = set_t.Erase(param);
  ASSERT_EQ(expected_value, EraseValue);
}