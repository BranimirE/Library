vector<vector<int> > g;
bool mark["MAX_N+K"];
int match["MAX_N+K"];
bool dfs(int left) {
  if (mark[left]) return false;
  mark[left] = true;
  for (int right: g[left])
    if (match[right] == -1 || dfs(match[right])) {
      match[right] = left;
      match[left] = right;
      return true;
    }
  return false;
}
int MCBM(const vector<vector<int> > & _g, int n, int k) {
  g = _g;
  memset(match, -1, sizeof(match));
  while (true) {
    bool fnd = false;
    memset(mark, false, sizeof mark);
    forn (i, n)
      if (match[i] == -1 && !mark[i])
        fnd |= dfs(i);
    if (!fnd)
      break;
  }
  int ans = 0;
  forn (i, n)
    if (match[i] != -1)
      ans++;
  return ans;
}