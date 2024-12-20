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

#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Node.h
#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
  T key_;
  Node* left_;
  Node* right_;
  int height_;
  int size_;

  Node(T key)
    : key_(key), left_(nullptr), right_(nullptr), height_(1), size_(1) {}
};
#endif

// Tree.h
#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree {
public:
  virtual bool IsEmpty(Node<T>* node)                              = 0;
  virtual int GetSize(Node<T>* node)                               = 0;
  virtual int GetHeight(Node<T>* node)                             = 0;
  virtual int GetDepth(Node<T>* node, T target)                    = 0;
  virtual Node<T>* FindNode(Node<T>* node, T target)               = 0;
  virtual int Insert(T target)                                     = 0;
  virtual std::pair<int, int> GetAncestor(Node<T>* node, T target) = 0;
  virtual double GetAverage(Node<T>* node)                         = 0;
  virtual int Erase(T target)                                      = 0;
  virtual std::pair<int, int> GetRank(Node<T>* node, T target)     = 0;
  virtual Node<T>* getRoot()                                       = 0;
  virtual ~Tree()                                                  = default;
};

#endif

// AVLTree.h
#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree : public Tree<T> {
public:
  AVLTree() : root_(nullptr) {}
  AVLTree(Node<T>* node) : root_(node) {}
  Node<T>* GetRoot() {
    return this->root_;
  }
  bool IsEmpty(Node<T>* node);
  int GetSize(Node<T>* node);
  int GetHeight(Node<T>* node);
  int GetDepth(Node<T>* node, T target);
  Node<T>* FindNode(Node<T>* node, T target);
  int Insert(T target);
  Node<T>* InsertNode(Node<T>* node, T target);
  T Max(T a, T b);
  void UpdateHeight(Node<T>* node);
  Node<T>* RightRotate(Node<T>* node);
  Node<T>* LeftRotate(Node<T>* node);
  std::pair<int, int> GetAncestor(Node<T>* node, T target);
  Node<T>* GetMin(Node<T>* node);
  Node<T>* GetMax(Node<T>* node);
  double GetAverage(Node<T>* node);
  Node<T>* EraseNode(Node<T>* node, T target);
  int Erase(T target);
  std::pair<int, int> GetRank(Node<T>* node, T target);
  Node<T>* getRoot();

private:
  Node<T>* root_;
  int size = 0;
};

#endif

// AVLTree.cpp

template <typename T>
bool AVLTree<T>::IsEmpty(Node<T>* node) {
  if (node == nullptr) {
    return -1;
  }
  if (node->size_ == 0) {
    return true;
  }
  return false;
}

template <typename T>
int AVLTree<T>::GetSize(Node<T>* node) {
  if (node == nullptr) {
    return -1;
  }
  return node->size_;
}

template <typename T>
int AVLTree<T>::GetHeight(Node<T>* node) {
  if (node == nullptr) {
    return -1;
  }
  return node->height_;
}

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
  return -1;
}

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
  return nullptr;
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
  // FIXFIX
  if (node->height_ == 1) {
    node->left_  = nullptr;
    node->right_ = nullptr;
    node->size_  = 1;
  } else {
    int lsize   = (node->left_ != nullptr) ? node->left_->size_ : 0;
    int rsize   = (node->right_ != nullptr) ? node->right_->size_ : 0;
    node->size_ = lsize + rsize + 1;
  }
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
    return new Node<T>(target);
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
  // cout << "root: " << endl;
  // cout << root_->key_ << endl;
  // cout << "Height: " << endl;
  // cout << FindNode(root_, target)->height_ << endl;
  // cout << "Depth: " << endl;
  // cout << GetDepth(root_, target) << endl;
  return GetDepth(root_, target) + FindNode(root_, target)->height_;
}

// target의 높이, 깊이의 합 출력 , target의 부모 ~ 루트 경로의 노드들의 key값의
// 합 출력
template <typename T>
std::pair<int, int> AVLTree<T>::GetAncestor(Node<T>* node, T target) {
  Node<T>* target_node = FindNode(node, target);
  if (target_node == nullptr) {
    return std::make_pair(-1, -1);
  }

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
  //   return {K, key_sum};
  return make_pair(K, key_sum);
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
double AVLTree<T>::GetAverage(Node<T>* node) {
  Node<T>* min_node = GetMin(node);
  Node<T>* max_node = GetMax(node);

  T min_key      = min_node->key_;
  T max_key      = max_node->key_;
  double average = ((double)min_key + (double)max_key) / 2.0;

  return average;
}

template <typename T>
Node<T>* AVLTree<T>::getRoot() {
  return root_;
}

template <typename T>
int AVLTree<T>::Erase(T target) {
  Node<T>* node = FindNode(root_, target);
  if (node == nullptr)
    return 0;
  else {
    int ret = GetDepth(root_, target) + FindNode(root_, target)->height_;
    root_   = EraseNode(root_, target);
    // if (root_ != nullptr) std::cout << "root : " << root_->key_ << endl;
    return ret;
  }
}

template <typename T>
Node<T>* AVLTree<T>::EraseNode(Node<T>* node, T target) {
  if (node == nullptr) return node;
  if (target < node->key_)
    node->left_ = EraseNode(node->left_, target);
  else if (target > node->key_)
    node->right_ = EraseNode(node->right_, target);
  else {
    if (node->left_ == nullptr || node->right_ == nullptr) {
      Node<T>* tmp = node->left_ ? node->left_ : node->right_;
      if (tmp == nullptr) {
        tmp  = node;
        node = nullptr;
      } else {
        *node = *tmp;
      }
      delete tmp;
    } else {
      Node<T>* cur = node->right_;
      while (cur->left_ != nullptr) {
        cur = cur->left_;
      }
      node->key_   = cur->key_;
      node->right_ = EraseNode(node->right_, cur->key_);
    }
  }
  if (node == nullptr) {
    return node;
  }

  UpdateHeight(node);

  int bf = getBf(node);
  if (bf > 1 && getBf(node->left_) >= 0) return RightRotate(node);
  if (bf > 1 && getBf(node->left_) < 0) {
    node->left_ = LeftRotate(node->left_);
    return RightRotate(node);
  }
  if (bf < -1 && getBf(node->right_) <= 0) return LeftRotate(node);
  if (bf < -1 && getBf(node->right_) > 0) {
    node->right_ = RightRotate(node->right_);
    return LeftRotate(node);
  }

  return node;
}
template <typename T>
int getBf(Node<T>* node) {
  if (node == nullptr) return 0;
  int lh = node->left_ != nullptr ? node->left_->height_ : 0;
  int rh = node->right_ != nullptr ? node->right_->height_ : 0;
  return lh - rh;
}

template <typename T>
std::pair<int, int> AVLTree<T>::GetRank(Node<T>* node, T target) {
  int depth        = 0;
  int rank         = 0;
  Node<T>* current = node;

  while (current != nullptr) {
    if (current->key_ == target) {
      rank += (current->left_ != nullptr ? current->left_->size_ : 0) + 1;
      int height = current->height_;
      int K      = depth + height;
      //   return {K, rank};  // return K, rank
      return make_pair(K, rank);
    }

    if (target < current->key_) {
      current = current->left_;
    } else {
      rank += (current->left_ != nullptr ? current->left_->size_ : 0) + 1;
      current = current->right_;
    }
    depth++;
  }
  return std::make_pair(-1, -1);  // error case , 없는 값이 들어온 경우
}

// Set.h
#ifndef SET_H
#define SET_H

template <typename T>
class Set {
private:
  Tree<T>* tree;

public:
  Set(Tree<T>* treeImpl) : tree(treeImpl) {}
  bool IsEmpty() {
    return tree->IsEmpty(tree->getRoot());
  }
  int GetSize() {
    return tree->GetSize(tree->getRoot());
  }
  int GetHeight() {
    return tree->GetHeight(tree->getRoot());
  }
  int FindNode(T target) {
    if (tree->FindNode(tree->getRoot(), target) == nullptr) {
      return 0;
    }
    Node<T>* n = tree->FindNode(tree->getRoot(), target);
    return n->height_ + tree->GetDepth(tree->getRoot(), target);
  }
  int Insert(T target) {
    return tree->Insert(target);
  }
  std::pair<int, int> GetAncestor(T target) {
    return tree->GetAncestor(tree->getRoot(), target);
  }
  double GetAverage(T target) {
    Node<T>* targetNode = tree->FindNode(tree->getRoot(), target);
    if (targetNode == nullptr) {
      return -1.0;
    }
    return tree->GetAverage(targetNode);
  }
  int Erase(T target) {
    return tree->Erase(target);
  }
  std::pair<int, int> GetRank(T target) {
    return tree->GetRank(tree->getRoot(), target);
  }
  ~Set() {
    delete tree;
  }
};

#endif

// Main program
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int Q;
    cin >> Q;
    AVLTree<int>* avlTree = new AVLTree<int>();
    Set<int> set_t(avlTree);
    while (Q--) {
      string s;
      cin >> s;
      if (s == "Height") {
        cout << set_t.GetHeight() << '\n';
      } else if (s == "Size") {
        int s = set_t.GetSize();
        if (s != -1)
          cout << set_t.GetSize() << '\n';
        else
          cout << 0 << '\n';
      } else if (s == "Find") {
        int a;
        cin >> a;
        cout << set_t.FindNode(a) << '\n';
      } else if (s == "Insert") {
        int a;
        cin >> a;
        cout << set_t.Insert(a) << '\n';
      } else if (s == "Ancestor") {
        int a;
        cin >> a;
        pair<int, int> p = set_t.GetAncestor(a);
        if (p.first == -1 && p.second == -1) {
          cout << "0\n";
        } else {
          cout << p.first << " " << p.second << "\n";
        }
      } else if (s == "Average") {
        int a;
        cin >> a;
        cout << (int)set_t.GetAverage(a) << '\n';
      } else if (s == "Empty") {
        cout << set_t.IsEmpty() << '\n';
      } else if (s == "Rank") {
        int a;
        cin >> a;
        pair<int, int> p = set_t.GetRank(a);
        if (p.first == -1 && p.second == -1) {
          cout << "0\n";
        } else {
          cout << p.first << " " << p.second << "\n";
        }
      } else if (s == "Erase") {
        int a;
        cin >> a;
        cout << set_t.Erase(a) << '\n';
      }
    }
  }
  return 0;
}
