// Parentheses
#include <bits/stdc++.h>

using namespace std;

char str[1000000];

int solve() {
  stack<char> s;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') s.push(str[i]);
    else if (str[i] == ')') {
      if (s.empty()) return 0;
      if (s.top() == '(') s.pop();
      else return 0;
    } else if (str[i] == ']') {
      if (s.empty()) return 0;
      if (s.top() == '[') s.pop();
      else return 0;
    } else if (str[i] == '}') {
      if (s.empty()) return 0;
      if (s.top() == '{') s.pop();
      else return 0;
    }
  }
  return s.empty() ? 1 : 0;
}

int main(int argc, char const *argv[]) {
  scanf("%s", str);
  cout << solve();
  return 0;
}
