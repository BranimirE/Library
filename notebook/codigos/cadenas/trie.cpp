#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

struct trie {
  map<char, trie> sig;
  bool final;//Podria ser int si es que hay repetidos
  trie() {final = false;}
  void insert(const string &s, int pos = 0) {
    if (pos < sz(s)) sig[s[pos]].insert(s, pos + 1);
    else final = true;
  }
  void insert2(const string &s) {
    trie *cur = this;
    for (char c: s)
      cur = &(cur->sig[c]); //Antes de esto podemos !(cur->sig).count(c)
    (cur->final) = true;
  }
  bool find(const string &s, int pos = 0) {
    if (pos == sz(s)) return final;
    if (sig.count(s[pos]))
      return sig[s[pos]].find(s, pos + 1);
    return false;
  }
  void print(string s = "") {
    if (final)cout << "\"" << s << "\"" << endl;
    for (auto &e: sig)
      e.second.print(s + e.first);
  }
};

char cad[100];
int main() {
  int n;
  cin >> n;
  trie t;
  while (n--) {
    cin >> cad;
    t.insert2(cad);
  }
  t.print();
  cin >> n;
  while (n--) {
    cin >> cad;
    cout << t.find(cad) << endl;
  }
  return 0;
}
