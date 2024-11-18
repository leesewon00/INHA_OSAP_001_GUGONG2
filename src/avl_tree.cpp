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
T max(T a, T b) {
  return (a > b) a : b;
}

template <typename T>
void updateHeight(Node<T>* node) {
  int leftHeight  = GetHeight(node->left_);
  leftHeight      = (leftHeight == -1) ? 0 : leftHeight;
  int rightHeight = GetHeight(node->right_);
  rightHeight     = (rightHeight == -1) ? 0 : rightHeight;
  // height update
  node->height_ = 1 + max(leftHeight, rightHeight);
}

template <typename T>
Node<T>* rightRotate(Node<T>* node) {
  Node<T>* leftChild      = node->left_;
  Node<T>* leftRightChild = leftChild->right_;

  leftChild->right_ = node;
  node->left_       = leftRightChild;

  updateHeight(node);
  updateHeight(leftChild);

  return leftChild;
}

template <typename T>
Node<T>* leftRotate(Node<T>* node) {
  Node<T>* rightChild     = node->right_;
  Node<T>* rightLeftChild = rightChild->left_;

  rightChild->left = node;
  node->right_     = rightLeftChild;

  updateHeight(node);
  updateHeight(rightChild);

  return rightChild;
}

template <typename T>
Node<T>* InsertNode(Node<T>* node, T target) {
  // Insert 특정상 node에는 root 고정. target 에 Insert Node 정보가 들어감.
  if (node == nullptr) {
    // TODO
    // Node 생성자 만들고 new Node return;
  }
  if (target < node->key_) {
    node->left = InsertNode(node->left_, target);
  } else if (target > node->key_) {
    node->right_ = InsertNode(node->right_, target)
  } else {
    // TODO
    // 중복된 값이 insert 되는 경우
  }

  updateHeight(node);

  // get balance factor in specific node
  int bf = leftHeight - rightHeight;

  if (bf > 1 && target < node->left_->key_) {
    return rightRotate(node);
  }
  if (bf < -1 && target > node->right_->key_) {
    return leftRotate(node);
  }
  if (bf > 1 && target > node->left_->key_) {
    node->left_ = leftRotate(node->left_);
    return rightRotate(node);
  }
  if (bf < -1 && target < node->right_->key_) {
    node->right_ = rightRotate(node->right_);
    return leftRotate(node);
  }
  return node;
}

template <typename T>
int AVLTree<T>::insert(T target) {
  root_ = InsertNode(root_, target);
  return GetDepth(root_, target) + FindNode(root_, target)->height_;
}