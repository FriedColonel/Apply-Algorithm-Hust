#include <bits/stdc++.h>

using namespace std;

string p1, p2;
string text;

int main(int argc, char const *argv[])
{
  getline(cin, p1);
  getline(cin, p2);
  getline(cin, text);
  text = regex_replace(text, regex("\\b" + p1 + "\\b"), p2);
  cout << text;
  return 0;
}
