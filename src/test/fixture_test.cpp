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

// SetTestFixture 클래스는 테스트를 위한 공통된 설정을 제공하는 Fixture
class SetTestFixture : public ::testing::Test {
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

// GetSize 메소드 검증 : 루트가 null이 아닌 경우
TEST_F(SetTestFixture, GetSizeValidRootCase) {
  ASSERT_EQ(3, set_t.GetSize());
}

// GetSize 메소드 검증 : 루트가 null인 경우
TEST_F(SetTestFixture, GetSizeInvalidRootCase) {
  set_t = new AVLTree<int>();
  ASSERT_EQ(-1, set_t.GetSize());
}

// IsEmpty 메소드 검증 : set이 비어있는 경우
TEST_F(SetTestFixture, IsEmptyEmptyCase) {
  set_t = new AVLTree<int>();
  ASSERT_EQ(true, set_t.IsEmpty());
}

// IsEmpty 메소드 검증 : set이 비어있지 않은 경우
TEST_F(SetTestFixture, IsEmptyNotEmptyCase) {
  ASSERT_EQ(false, set_t.IsEmpty());
}

// GetHeight 메소드 검증 : 루트가 null이 아닌 경우
TEST_F(SetTestFixture, GetHeightValidRootCase) {
  ASSERT_EQ(2, set_t.GetHeight());
}

// GetHeight 메소드 검증 : 루트가 null인 경우
TEST_F(SetTestFixture, GetHeightTestInvalidRootCase) {
  set_t = new AVLTree<int>();
  ASSERT_EQ(-1, set_t.GetHeight());
}

// FindNode 메소드 검증 : set에 존재하는 Target 값이 들어올 때
TEST_F(SetTestFixture, FindNodeValidTargetCase) {
  int height = 2;
  int depth  = 0;
  ASSERT_EQ(height + depth, set_t.FindNode(2));
}

// FindNode 메소드 검증 : set 존재하지 않는 Target 값이 들어올 때
TEST_F(SetTestFixture, FindNodeInvalidTargetCase) {
  ASSERT_EQ(0, set_t.FindNode(-1));
}

// GetAverage 메소드 검증 : set에 존재하는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetAverageValidTargetCase) {
  ASSERT_EQ(3, set_t.GetAverage(3));
}

// GetAverage 메소드 검증 : set에 존재하지 않는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetAverageInvalidTargetCase) {
  ASSERT_EQ(-1, set_t.GetAverage(-1));
}

// GetAncestor 메소드 검증 : set에 존재하는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetAncestorValidTargetCase) {
  std::pair<int, int> returnValue = set_t.GetAncestor(2);
  ASSERT_EQ(std::make_pair(2, 3), returnValue);
}

// GetAncestor 메소드 검증 : root 값이 들어온 경우
TEST_F(SetTestFixture, GetAncestorRootTargetCase) {
  ASSERT_EQ(std::make_pair(2, 0), set_t.GetAncestor(3));
}

// GetAncestor 메소드 검증 : set에 존재하지 않는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetAncestorInvalidTargetCase) {
  ASSERT_EQ(std::make_pair(-1, -1), set_t.GetAncestor(-1));
}

// GetRank 메소드 검증 : set에 존재하는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetRankValidTargetCase) {
  ASSERT_EQ(std::make_pair(2, 3), set_t.GetRank(4));
}

// GetRank 메소드 검증 : set에 존재하지 않는 Target 값이 들어올 때
TEST_F(SetTestFixture, GetRankInvalidTargetCase) {
  ASSERT_EQ(std::make_pair(-1, -1), set_t.GetRank(100));
}