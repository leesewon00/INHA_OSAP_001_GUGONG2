#ifndef TREE_H
#define TREE_H

#include <utility>
#include "node.h"

template <typename T>
class Tree {
public:
  virtual bool IsEmpty(Node<T>* node)                 = 0;
  virtual int GetSize(Node<T>* node)                  = 0;
  virtual int GetHeight(Node<T>* node)                = 0;
  virtual Node<T>* FindNode(Node<T>* node, T target)  = 0;
  virtual int Insert(T target)                        = 0;
  virtual std::pair<int, int> GetAncestor(Node<T>* node,
                                          T target)   = 0;  //<K, key_sum>
  virtual double GetAverage(Node<T>* node)            = 0;
  virtual Node<T>* EraseNode(Node<T>* node, T target) = 0;
  virtual std::pair<int, int> GetRank(Node<T>* node, T target) = 0;
  virtual Node<T>* getRoot()                                   = 0;
  virtual ~Tree()                                              = default;
};

#endif  // TREE_H