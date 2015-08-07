#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 1000000000;//Cuidado con el overflow en la relajacion
const int MAXN = 1000;

int n, m;
//Ya que el algoritmo igual queda O(V^2)
//Es mas facil usar una matriz de adyaciencia
int v[MAXN], d[MAXN], G[MAXN][MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      G[i][j] = INF;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u][v] = w;
  }
  memset(v, 0, sizeof(v));
  for(int i = 0; i < n; i++) d[i] = (i==0 ? 0 : INF);
  for(int i = 0; i < n; i++) {
    int x = -1, m = INF;
    for(int y = 0; y < n; y++)
      if(!v[y] && d[y]<=m) m = d[x=y];
    if (x == -1) break;
    v[x] = 1;
    for(int y = 0; y < n; y++) d[y] = min(d[y], d[x] + G[x][y]);
  }
  for(int i = 0; i < n; i++)
    printf("%d\n", d[i]);
  return 0;
}
