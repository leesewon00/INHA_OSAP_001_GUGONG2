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
bool Set<T>::IsEmpty(Node<T>* node) {
  return tree->IsEmpty(node);
}

template <typename T>
int Set<T>::GetSize(Node<T>* node) {
  return tree->GetSize(node);
}

template <typename T>
int Set<T>::GetHeight(Node<T>* node) {
  return tree->GetHeight(node);
}

template <typename T>
Node<T>* Set<T>::FindNode(T target) {
  return tree->FindNode(tree->getRoot(), target);
}

template <typename T>
int Insert(T target) {}

template <typename T>
std::pair<int, int> Set<T>::GetAncestor(T target) {
  return tree->GetAncestor(tree->getRoot(), target);
}

template <typename T>
double Set<T>::GetAverage(T target) {
  Node<T>* targetNode = tree->FindNode(tree->getRoot(), target);
  return tree->GetAverage(targetNode);
}

template <typename T>
void EraseNode(Node<T>* node, T target) {}

template <typename T>
std::pair<int, int> Set<T>::GetRank(T target) {
  return tree->GetRank(tree->getRoot(), target);
}