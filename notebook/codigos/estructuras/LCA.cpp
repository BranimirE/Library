// La cantidad maxima de vertices n debe ser menor que 2^(LVL-1).
#define LVL 15
#define MAXN (1<<LVL)

int d[MAXN];

bool fcmp(int a,int b) {
  return d[a] < d[b];
}

int vec[LVL][MAXN];
int mn(int i, int j) { // intervalo [i,j)
  int p = 31 - __builtin_clz(j-i);
  return min(vec[p][i],vec[p][j-(1<<p)],fcmp);
}
void mn_init(int n) {
  int mp = 31-__builtin_clz(n);
  forn(p, mp) forn(x, n-(1<<p)) vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)],fcmp);
}

vector<int> t[MAXN]; // Tree
int pos[MAXN];
int id, pp;

void dfs(int x) {
  d[x] = id++;
  vec[0][pos[x] = pp++] = x;
  forall(y,t[x])
    if (d[*y] == -1) {
      dfs(*y);
      vec[0][pp++] = x;
    }
}

void lcaInit(int n,int raiz) {
  id = pp = 0;
  memset(d,-1,sizeof(d));
  dfs(raiz);
  mn_init(2*n-1);
}

int lca(int i,int j) {
  int a = pos[i], b = pos[j];
  if (a > b) swap(a,b);
  return mn(a,b+1);
}
