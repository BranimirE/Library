#include <bits/stdc++.h>

using namespace std;

struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 100010;
vector<int> g[MAXN];
int ID[MAXN];
int cnt[MAXN];
int contar(int u, int parent) {
  if (ID[u] != -1) return cnt[u] = 0;
  cnt[u] = 1;
  for (int v: g[u])
    if (v != parent)
      cnt[u] += contar(v, u);
  return cnt[u];
}
int get_centroid(int u, int parent, int size) {
  for (int v: g[u])
    if (v != parent)
      if (cnt[v] > (size / 2))
        return get_centroid(v, u, size);
  return u;
} 
void dfs(int u, int id) {
  contar(u, -1);
  int centroid = get_centroid(u, -1, cnt[u]);
  ID[centroid] = id;
  for (int v: g[centroid])
    if (ID[v] == -1)
      dfs(v, id + 1);
}

int main() {
  int n;//No es necesario
  g[0].pb(1); g[1].pb(0);
  g[2].pb(1); g[1].pb(2);
  g[3].pb(1); g[1].pb(3);
  g[5].pb(6); g[6].pb(5);
  g[4].pb(5); g[5].pb(4);
  g[1].pb(4); g[4].pb(1);

  g[7].pb(4); g[4].pb(7);
  g[7].pb(8); g[8].pb(7);

  g[8].pb(9); g[9].pb(8);
  g[8].pb(12); g[12].pb(8);

  g[9].pb(10); g[10].pb(9);
  g[9].pb(11); g[11].pb(9);
  
  g[12].pb(13); g[13].pb(12);
  g[12].pb(14); g[14].pb(12);

  n = 15;

  
  memset(ID, -1, sizeof(ID));//No olvidar esta linea
  //el arbol es conexo
  //iniciar con "dfs(nodoqueexiste, 0)"
  dfs(0, 0);

  /*
    Esta implementación halla el centroide y elimina el centroide
    y halla el centroide de los subarboles(recursivamente)
    Complejidad: O(N Log(N))

    Si solo se quiere el centroide del arbol
    solo llamar a la funcion "get_centroid" una sola vez
    "get_centroid(nodoqueexiste, -1, contar(u, -1))"
    No olvidar el "contar(u, -1)" para preprocesar tamaños
    
   */
  return 0;
}
