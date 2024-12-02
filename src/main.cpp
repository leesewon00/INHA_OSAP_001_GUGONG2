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
        cout << set_t.GetSize() << '\n';
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
        cout << set_t.GetAverage(a) << '\n';
      } else if (s == "Empty") {
      } else if (s == "Rank") {
        int a;
        cin >> a;
        pair<int, int> p = set_t.GetRank(a);
        if (p.first == -1 && p.second == -1) {
          cout << "0\n";
        } else {
          cout << p.first << " " << p.second << "\n";
        }
      }
    }
  }
  return 0;
}