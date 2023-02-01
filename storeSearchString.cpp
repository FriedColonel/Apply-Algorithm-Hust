// solve Store & Search String
#include <bits/stdc++.h>

using namespace std;

set<string> db;

int main(int argc, char const *argv[]) {
  string x;
  cin >> x;
  while(x != "*") {
    db.insert(x);
    cin >> x;
  }
  string option;
  cin >> option;
  while(option != "***") {
    cin >> x;
    if (db.find(x) != db.end()) {
      if (option == "find") cout << 1 << endl;
      else cout << 0 << endl;
    } else {
      if (option == "find") cout << 0 << endl;
      else {
        cout << 1 << endl;
        db.insert(x);
      }
    }
    cin >> option;
  }

  return 0;
}
