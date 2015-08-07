#include <bits/stdc++.h>

using namespace std;

#define MAX 505
//cuidado con el overflow
#define oo (1LL<<58LL)

int n;
vector<pair<int,long long int> > g[MAX];
bool ciclo[MAX];//ciclo negativo
long long int d[MAX];//dist
bool v[MAX];//visitado
void dfs(int i) {
  v[i] = true;
  d[i] = -1;//NO CALCULABLE
  for(int j = 0; j < g[i].size(); j++)
    if(!v[g[i][j].first])
      dfs(g[i][j].first);
}

//Complejidad: O(V * E), E = V^2 =>  O(V^3)
void bellmanford(int ini) {
  //fill(d + 1, d + 1 + n, oo);
  //----------------------------------------------------------
  for(int i = 1; i <= n; i++)d[i] = oo, ciclo[i] = false;
  d[ini] = 0LL;
  //Podemos salir si antes de V-1 pasos ya no se actualiza d
  for(int i = 0; i < n-1; i++)//V - 1 pasos
    for(int u = 1; u <= n; u++)
      if(d[u] != oo) // Nos aseguramos que ya existe un camino hasta u
        for(int j = 0; j < g[u].size(); j++) {
          pair<int,long long int> v = g[u][j];
          d[v.first] = min(d[v.first], d[u] + v.second);//por que INF + (pesonegativo) es menor que INF
        }
  //verificamos y marcamos todos los nodos que pertenecen a un ciclo negativo
  for(int u = 1; u <= n; u++)
    for(int j = 0; j < g[u].size(); j++) {
      pair<int,int> v = g[u][j];
      if(d[v.first] > d[u] + v.second)
        ciclo[u] = ciclo[v.first] = true;//Ciclo negativo return -1
    }
  //---------------------------------------------------------
  //Todos los nodos accesibles desde un nodo con ciclo negativo tambien tienen distancia NO CALCULABLE
  memset(v, false, sizeof(v));
  for(int i = 1; i <= n; i++)
    if(ciclo[i] && !v[i])
      dfs(i);
}

int main() {
  //llenar grafo
  bellmanford(1);
  return 0;
}
