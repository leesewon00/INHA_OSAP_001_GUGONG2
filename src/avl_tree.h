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

#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"

template <typename T>
class AVLTree {
public:
  // 기본 생성자
  AVLTree() : root_(nullptr) {}
  // node를 root로 가지는 AVLTree 생성자
  AVLTree(Node<T>* node) : root_(node) {}
  // AVLTree의 root 반환
  Node<T>* GetRoot() {
    return this->root_;
  }
  // node를 root로 가지는 트리가 비어있는지 여부 반환
  bool IsEmpty(Node<T>* node);
  // node를 root로 가지는 트리의 원소 수 반환
  int GetSize(Node<T>* node);
  // node를 root로 가지는 트리의 높이 반환
  int GetHeight(Node<T>* node);
  // node를 root로 가지는 트리에서 target 노드의 깊이 반환
  int GetDepth(Node<T>* node, T target);
  // node를 root로 가지는 트리에서 target 노드 포인터 반환
  Node<T>* FindNode(Node<T>* node, T target);
  // node를 root로 가지는 트리에 새로운 target 노드를 삽입하고
  // 깊이와 높이의 합 반환
  int InsertNode(Node<T>* node, T target);
  // node를 root로 가지는 트리에 target 노드의 깊이와 높이의 합,
  // target 노드의 부모로부터 root까지 경로의 노드들의 key 값들의 합을 공백으로
  // 구분하여 출력
  void GetAncestor(Node<T>* node, T target);
  // node를 root로 가지는 트리에서 노드들의 key 값의 최솟값(a)와 최댓값(b)의
  // 산술평균((a + b)/2) 을 출력
  void GetAverage(Node<T>* node);
  // node를 root로 가지는 트리에서 target 노드의 깊이와 높이의 합,
  // 순위(rank)를 공백으로 구분하여 출력
  void GetRank(Node<T>* node, T target);
  // node를 root로 가지는 트리에서 target 노드의 깊이와 높이의 합을 출력하고
  // 해당 노드를 삭제
  void EraseNode(Node<T>* node, T target);

private:
  Node<T>* root_;
};
#endif