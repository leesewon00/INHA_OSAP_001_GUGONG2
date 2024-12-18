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
#include <set.h>

template <typename T>
bool Set<T>::IsEmpty() {
  return tree->IsEmpty(tree->getRoot());
}

template <typename T>
int Set<T>::GetSize() {
  return tree->GetSize(tree->getRoot());
}

template <typename T>
int Set<T>::GetHeight() {
  return tree->GetHeight(tree->getRoot());
}

template <typename T>
int Set<T>::FindNode(T target) {
  if (tree->FindNode(tree->getRoot(), target) == nullptr) {
    return 0;
  }
  Node<T>* n = tree->FindNode(tree->getRoot(), target);
  return n->height_ + tree->GetDepth(tree->getRoot(), target);
}

template <typename T>
int Set<T>::Insert(T target) {
  return tree->Insert(target);
}

template <typename T>
std::pair<int, int> Set<T>::GetAncestor(T target) {
  return tree->GetAncestor(tree->getRoot(), target);
}

template <typename T>
int Set<T>::GetAverage(T target) {
  Node<T>* targetNode = tree->FindNode(tree->getRoot(), target);
  if (targetNode == nullptr) {
    return -1;
  }
  return tree->GetAverage(targetNode);
}

template <typename T>
int Set<T>::Erase(T target) {
  return tree->Erase(target);
}

template <typename T>
std::pair<int, int> Set<T>::GetRank(T target) {
  return tree->GetRank(tree->getRoot(), target);
}