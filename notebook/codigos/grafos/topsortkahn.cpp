#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

#define MAXN MAXIMOID
int n;
vector<int> g[MAXN];
int gradoin[MAXN];
//El grafo debe ser un DAG!!!
vector<int> topsort() {
  vector<int> ts;
  queue<int> q;
  //Los nodos estan numerados: [1, n]
  for (int i = 1; i <= n; i++)
    if (gradoin[i] == 0)
      q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ts.pb(u);
    for (int v: g[u]) {
      gradoin[v]--;
      if (gradoin[v] == 0)
	q.push(v);
    }
  }
  return ts;
}
int main() {
  n = 5;
  fill(gradoin + 1, gradoin + 1 + n, 0);
  g[1].pb(2); gradoin[2]++;
  g[2].pb(3); gradoin[3]++;
  g[4].pb(3); gradoin[3]++;
  g[5].pb(1); gradoin[1]++;
  vector<int> ans = topsort();
  for (int node: ans)
    cout << node << " ";
  cout << endl;
  return 0;
}
