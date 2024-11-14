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
