#include <bits/stdc++.h>

using namespace std;

const int NODO_SOURCE = 1;
const int MIRAR_EN_EL_STATEMENT = 500010;
const long long INFINITO = (1LL)<<(58LL);

//----------------------------------------------------------

const int MAXN = MIRAR_EN_EL_STATEMENT;
const long long inf = INFINITO;//o sum de todos los arcos  + 1
//cuidado con overflow en la relajacion
int n;
vector<pair<int,long long> > g[MAXN];
long long d[MAXN];
/*Complejidad: O((V + E)*Log(V))
  Si el grafo es demasiado denso (E = V^2)
  => O( V^2 Log(V) ) conviene usar la version
  sin heap O(V^2) */
void dijkstra(int ini) {
  int u, v; long long du, cost;
  priority_queue<pair<long long,int> > q;
  fill(d, d + n + 1, inf);
  d[ini] = 0;
  q.push({-d[ini], ini});
  while (!q.empty()) {
    tie(du, u) = q.top(); du = -du;
    q.pop();
    if (du > d[u]) continue;
    for (auto e: g[u]) {
      tie(v, cost) = e;
      if (du + cost < d[v]) {
        d[v] = du + cost;
        q.push({-d[v], v});
      }
    }
  }
  //return vector<long long>(d, d + n + 1);
}
//----------------------------------------------------------

int main() {
  //Leer grafo...
  dijkstra(NODO_SOURCE);
  return 0;
}
