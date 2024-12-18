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
#ifndef SET_H
#define SET_H

#include <iostream>
#include "avl_tree.h"
#include "tree.h"

template <typename T>
class Set {
private:
  std::unique_ptr<Tree<T>> tree;

public:
  Set(Tree<T>* treeImpl) : tree(treeImpl) {}
  bool IsEmpty();
  int GetSize();
  int GetHeight();
  int FindNode(T target);
  int Insert(T target);
  // return pair<K , key_sum>
  std::pair<int, int> GetAncestor(T target);
  double GetAverage(T target);
  int Erase(T target);
  // return pair<K, rank>
  std::pair<int, int> GetRank(T target);
};

#endif  // SET_H