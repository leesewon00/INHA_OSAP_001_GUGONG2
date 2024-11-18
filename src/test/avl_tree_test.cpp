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
//     2024.11 GUGONG2

#include <gtest/gtest.h>
#include "../avl_tree.cpp"

// AVLTreeTest 클래스는 테스트를 위한 공통된 설정을 제공하는 Fixture
class AVLTreeTest : public ::testing::Test {
protected:
  Node<int>* left;
  Node<int>* right;
  Node<int>* root;
  AVLTree<int> tree;

  // 각 테스트 실행 전 호출되어 트리 설정
  void SetUp() override {
    //      10
    //     /  \
    //    6   12
    left  = new Node<int>{6, nullptr, nullptr, 1, 1};
    right = new Node<int>{12, nullptr, nullptr, 1, 1};
    root  = new Node<int>{10, left, right, 2, 3};
    tree  = AVLTree<int>(root);
  }

  // 각 테스트 종료 후 호출되어 메모리를 해제
  void TearDown() override {
    delete left;
    delete right;
    delete root;
  }
};

// IsEmpty 메소드 검증 : 트리가 비어있지 않은 경우
TEST_F(AVLTreeTest, IsEmptyTest_NotEmptyCase) {
  EXPECT_EQ(false, tree.IsEmpty(tree.GetRoot()));
}

// IsEmpty 메소드 검증 : 트리가 비어있는 경우
TEST_F(AVLTreeTest, IsEmptyTest_EmptyCase) {
  EXPECT_EQ(true, tree.IsEmpty(nullptr));
}

// GetSize 메소드 검증 : 루트가 null이 아닌 경우
TEST_F(AVLTreeTest, GetSizeTest_ValidRoot) {
  EXPECT_EQ(3, tree.GetSize(tree.GetRoot()));
}

// GetSize 메소드 검증 : 루트가 null인 경우
TEST_F(AVLTreeTest, GetSizeTest_InvalidRoot) {
  EXPECT_EQ(-1, tree.GetSize(nullptr));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}