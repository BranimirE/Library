#include <bits/stdc++.h>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << endl;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()

#define MAXN MAXIMOIDNODOS
int n;
vector<int> g[MAXN];
bool vis[MAXN];
vector<int> ts;
void dfs(int u) {
  vis[u] = true;
  for (int v: g[u])
    if (!vis[v])
      dfs(v);
  ts.pb(u);
}
vector<int> topsort() {
  ts.clear();
  fill(vis + 1, vis + 1, n);
  for (int i = 1; i <= n; i++) // Los nodos numerados de 1 a n
    if (!vis[i])
      dfs(i);
  return vector<int>(ts.rbegin(), ts.rend());
}
int main() {
  n = 5;
  g[1].pb(2);
  g[2].pb(3);
  g[4].pb(3);
  g[5].pb(1);
  vector<int> ans = topsort();
  for (int i = 0; i < sz(ans) ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
