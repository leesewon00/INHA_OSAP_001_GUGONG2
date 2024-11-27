#include <avl_tree.h>
#include <set.h>
#include <avl_tree.cpp>
#include <iostream>
#include <set.cpp>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  AVLTree<int>* avlTree = new AVLTree<int>();

  Set<int> set_t(avlTree);

  cout << "Hello, World!\n";

  return 0;
}