#define forn(i, n) for (int i = 0; i < (n); i++)
#define MAXN maximonodos
vector<int> g[MAXN];
vector<pair<int,int> > bridges;
int n;//Nodos
bool vis[MAXN];
int tin[MAXN];
int fup[MAXN];
int tiempo;
void dfs(int u, int padre = -1) {
  vis[u] = true;
  tin[u] = fup[u] = tiempo++;
  for (int to: g[u]) {
    if (to == padre)continue;
    if (vis[to])
      fup[u] = min(fup[u], tin[to]);
    else {
      dfs(to, u);
      fup[u] = min(fup[u], fup[to]);
      if (fup[to] > tin[u])
	  bridges.pb(mp(u, to));
    }
  }
}
void puentes() {
  bridges.clear();
  fill(vis, vis + n, false);
  tiempo = 0;
  forn (i, n)
    if (!vis[i])
      dfs(i);
  for (auto x: bridges)
    printf("%d - %d\n", x.first, x.second);
}
void addEdge(int u, int to) {
  g[u].pb(to);
  g[to].pb(u);
}
int main() {
  n = 5;
  addEdge(1, 0);
  addEdge(0, 2);
  addEdge(2, 1);
  addEdge(0, 3);
  addEdge(3, 4);
  puentes();
  return 0;
}
