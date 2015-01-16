#include <bits/stdc++.h>

using namespace std;

struct TwoSat {
  void dfs1(vector<vector<int> > &graph, vector<bool> &used, vector<int> &order, int u) {
    used[u] = true;
    for (int v: graph[u])
      if (!used[v])
	dfs1(graph, used, order, v);
    order.push_back(u);
  }
  void dfs2(vector<vector<int> > &reverseGraph, vector<int> &comp, int u, int color) {
    comp[u] = color;
    for (int v: reverseGraph[u])
      if (comp[v] == -1)
	dfs2(reverseGraph, comp, v, color);
  }
  vector<bool> solve2Sat(vector<vector<int> > graph) {
    int n = graph.size();

    vector<bool> used(n, false);
    vector<int> order;
    for (int i = 0; i < n; ++i)
      if (!used[i])
	dfs1(graph, used, order, i);
    
    vector<vector<int> > reverseGraph(n);
    for (int i = 0; i < n; i++)
      for (int j: graph[i])
		reverseGraph[j].push_back(i);
    
    vector<int> comp(n, -1);
    
    for (int i = n - 1, color = 0; i >= 0; i--) {
      int u = order[i];
      if (comp[u] == -1)
		dfs2(reverseGraph, comp, u, color++);
    }
    for (int i = 0; i < n; ++i)
      if (comp[i] == comp[i ^ 1])
		return vector<bool>();//No hay solucion
    vector<bool> res(n / 2);
    for (int i = 0; i < n; i += 2)
    	res[i / 2] = comp[i] > comp[i ^ 1];
    return res;
  }
} ts;

int main() {
  int n = 6;
  vector<vector<int> > g(n);
  // x or y
  // !x -> y  and  !y -> x
  //
  // (a || b) && (b || !c)
  // !a => b
  // !b => a
  // !b => !c
  // c => b
  int a = 0, na = 1, b = 2, nb = 3, c = 4, nc = 5;
  g[na].push_back(b);
  g[nb].push_back(a);
  g[nb].push_back(nc);
  g[c].push_back(b);
  
  vector<bool> solution = ts.solve2Sat(g);
  if (solution.size() == 0)
  	cout << "No hay solucion" << endl;
  else {
  	for (bool e: solution)
    	cout << e;
   	cout << endl;
  }
  return 0;
}
