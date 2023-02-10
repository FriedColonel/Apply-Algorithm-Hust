#include <bits/stdc++.h>

using namespace std;

string str;
string matching;
int matchingCnt = 0;
int last[256];

void input() {
  getline(cin, matching);
  getline(cin, str);
}

void computeLast() {
  for (int i = 0; i < 256; i++) last[i] = 0;

  for (int i = matching.size() - 1; i >= 0; i--) {
    if (last[matching[i]] == 0) {
      last[matching[i]] = i;
    }
  }
}

unsigned long long hashCode(string s, int start, int end) {
  unsigned long long hash = 0;
  for (int i = start; i <= end; i++) {
    hash = (hash * 31 + s[i]) % 1000000000;
  }
  return hash;
}

void rabinKarp() {
  int s = 0;
  int N = str.length();
  int M = matching.length();
  unsigned long long hash = hashCode(matching, 0, M - 1);
  unsigned long long strHash = hashCode(str, 0, M - 1);

  while(s <= N - M) {
    if (hash == strHash) {
      matchingCnt++;
      s += M;
    } else {
      s++;
    }
    strHash = hashCode(str, s, s + M - 1);
  }
}

void boyerMoore() {
  computeLast();
  int s = 0;
  int N = str.length();
  int M = matching.length();

  while(s <= N - M) {
    int j = M - 1;
    while (j >= 0 && matching[j] == str[s + j]) j--;
    if (j < 0) {
      matchingCnt++;
      s += M;
    } else {
      s += max(1, j - last[str[s + j]]);
    }
  }
}

int main(int argc, char const *argv[]) {
  input();
  // boyerMoore();
  rabinKarp();
  cout << matchingCnt << endl;
  return 0;
}
