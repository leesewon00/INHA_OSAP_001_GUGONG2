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

#include "avl_tree.h"

// node를 root로 가지는 트리가 비어있는지 여부 반환
template <typename T>
bool AVLTree<T>::IsEmpty(Node<T>* node) {
  if (node == nullptr) {
    return -1;  // 찾지 못한 경우 -1 반환
  }
  if (node->size_ == 0) {
    return true;
  }
  return false;
}

// node를 root로 가지는 트리의 원소 수 반환
template <typename T>
int AVLTree<T>::GetSize(Node<T>* node) {
  if (node == nullptr) {
    return -1;  // 찾지 못한 경우 -1 반환
  }
  return node->size_;
}

// node를 root로 가지는 트리의 높이 반환
template <typename T>
int AVLTree<T>::GetHeight(Node<T>* node) {
  if (node == nullptr) {
    return -1;  // 찾지 못한 경우 -1 반환
  }
  return node->height_;
}

// node를 root로 가지는 트리에서 target 노드의 깊이 반환
template <typename T>
int AVLTree<T>::GetDepth(Node<T>* node, T target) {
  int depth        = 0;
  Node<T>* current = node;

  while (current != nullptr) {
    if (current->key_ == target) {
      return depth;
    }
    if (current->key_ > target) {
      current = current->left_;
    } else {
      current = current->right_;
    }
    depth++;
  }
  return -1;  // 찾지 못한 경우 -1 반환
}

// node를 root로 가지는 트리에서 target 노드의 포인터 반환
template <typename T>
Node<T>* AVLTree<T>::FindNode(Node<T>* node, T target) {
  while (node != nullptr) {
    if (node->key_ == target) {
      return node;
    }
    if (node->key_ > target) {
      node = node->left_;
    } else {
      node = node->right_;
    }
  }
  return nullptr;  // 찾지 못한 경우 nullptr 반환
}

template <typename T>
T AVLTree<T>::Max(T a, T b) {
  return (a > b) ? a : b;
}

template <typename T>
void AVLTree<T>::UpdateHeight(Node<T>* node) {
  int left_height  = GetHeight(node->left_);
  left_height      = (left_height == -1) ? 0 : left_height;
  int right_height = GetHeight(node->right_);
  right_height     = (right_height == -1) ? 0 : right_height;
  // height update
  node->height_ = 1 + Max(left_height, right_height);
}

template <typename T>
Node<T>* AVLTree<T>::RightRotate(Node<T>* node) {
  Node<T>* left_child       = node->left_;
  Node<T>* left_right_child = left_child->right_;

  left_child->right_ = node;
  node->left_        = left_right_child;

  UpdateHeight(node);
  UpdateHeight(left_child);

  return left_child;
}

template <typename T>
Node<T>* AVLTree<T>::LeftRotate(Node<T>* node) {
  Node<T>* right_child      = node->right_;
  Node<T>* right_left_child = right_child->left_;

  right_child->left_ = node;
  node->right_       = right_left_child;

  UpdateHeight(node);
  UpdateHeight(right_child);

  return right_child;
}

template <typename T>
Node<T>* AVLTree<T>::InsertNode(Node<T>* node, T target) {
  // 노드가 자기 자리를 찾았을 경우
  if (node == nullptr) {
    return new Node(target);
  }  // BST order에 따라 자리 탐색
  if (target < node->key_) {
    node->left_ = InsertNode(node->left_, target);
  } else if (target > node->key_) {
    node->right_ = InsertNode(node->right_, target);
  }

  // target node의 모든 Ancestor의 height를 update
  UpdateHeight(node);

  // get balance factor in specific node
  int left_height  = GetHeight(node->left_);
  left_height      = (left_height == -1) ? 0 : left_height;
  int right_height = GetHeight(node->right_);
  right_height     = (right_height == -1) ? 0 : right_height;
  int bf           = left_height - right_height;

  // LL case
  if (bf > 1 && target < node->left_->key_) {
    return RightRotate(node);
  }  // RR case
  if (bf < -1 && target > node->right_->key_) {
    return LeftRotate(node);
  }  // LR case
  if (bf > 1 && target > node->left_->key_) {
    node->left_ = LeftRotate(node->left_);
    return RightRotate(node);
  }  // RL case
  if (bf < -1 && target < node->right_->key_) {
    node->right_ = RightRotate(node->right_);
    return LeftRotate(node);
  }
  return node;
}

template <typename T>
int AVLTree<T>::Insert(T target) {
  root_ = InsertNode(root_, target);
  // 문제 조건의 깊이와 높이의 합을 리턴
  return GetDepth(root_, target) + FindNode(root_, target)->height_;
}

// target의 높이, 깊이의 합 출력 , target의 부모 ~ 루트 경로의 노드들의 key값의
// 합 출력
template <typename T>
void AVLTree<T>::GetAncestor(Node<T>* node, T target) {
  Node<T>* target_node = FindNode(node, target);

  int depth  = GetDepth(node, target);
  int height = GetHeight(target_node);
  int K      = depth + height;

  int key_sum      = 0;
  Node<T>* current = node;  // root start
  while (current != nullptr) {
    if (current->key_ == target) {
      break;
    }
    key_sum += current->key_;
    if (target < current->key_) {
      current = current->left_;
    } else {
      current = current->right_;
    }
  }
  std::cout << K << " " << key_sum << '\n';
}

template <typename T>
Node<T>* AVLTree<T>::GetMin(Node<T>* node) {
  while (node != nullptr && node->left_ != nullptr) {
    node = node->left_;
  }
  return node;
}

template <typename T>
Node<T>* AVLTree<T>::GetMax(Node<T>* node) {
  while (node != nullptr && node->right_ != nullptr) {
    node = node->right_;
  }
  return node;
}

template <typename T>
void AVLTree<T>::GetAverage(Node<T>* node) {
  Node<T>* min_node = GetMin(node);
  Node<T>* max_node = GetMax(node);

  T min_key      = min_node->key_;
  T max_key      = max_node->key_;
  double average = ((double)min_key + (double)max_key) / 2.0;

  std::cout << average << '\n';
}

template <typename T>
Node<T>* AVLTree<T>::getRoot() {
  return root_;
}

template <typename T>
void AVLTree<T>::GetRank(Node<T>* node, T target) {
  int depth        = 0;
  int rank         = 0;
  Node<T>* current = node;

  while (current != nullptr) {
    if (current->key_ == target) {
      rank += (current->left_ != nullptr ? current->left_->size_ : 0) + 1;
      int height = current->height_;
      int K      = depth + height;
      std::cout << K << " " << rank << '\n';
      return;
    }

    if (target < current->key_) {
      current = current->left_;
    } else {
      rank += (current->left_ != nullptr ? current->left_->size_ : 0) + 1;
      current = current->right_;
    }
    depth++;
  }
}