#ifndef TREE_H
#define TREE_H

#include "node.h"

template <typename T>
class Tree {
public:
  virtual bool IsEmpty(Node<T>* node)                 = 0;
  virtual int GetSize(Node<T>* node)                  = 0;
  virtual int GetHeight(Node<T>* node)                = 0;
  virtual Node<T>* FindNode(Node<T>* node, T target)  = 0;
  virtual int Insert(T target)                        = 0;
  virtual void GetAncestor(Node<T>* node, T target)   = 0;
  virtual void GetAverage(Node<T>* node)              = 0;
  virtual Node<T>* EraseNode(Node<T>* node, T target) = 0;
  virtual void GetRank(Node<T>* node, T target)       = 0;
  virtual Node<T>* getRoot()                          = 0;
  virtual ~Tree()                                     = default;
};

#endif  // TREE_H