struct BipartiteMatch {
  bool edge[MAXN][MAXN];
  int nX, nY;
 
  void init(int _nX, int _nY) {
    nX = _nX;
    nY = _nY;
    memset(edge, false, sizeof edge);
  }
 
  void addMatch(int x, int y) {
    edge[x][y] = true;
  }
 
  int linkY[MAXN];
  bool visited[MAXN];
  bool dfs(int x) {
    if (visited[x])
      return false;
    visited[x] = true;
    for (int y = 0; y < nY; ++y) {
      if (edge[x][y] && (linkY[y] == -1 || dfs(linkY[y])))
        return linkY[y] = x, true;
    }
    return false;
  }
  int calcMaxMatch() {
    memset(linkY, -1, sizeof linkY);
    int cnt = 0;
    for (int x = 0; x < nX; ++x) {
      memset(visited, false, sizeof visited);
      if (dfs(x))
        ++cnt;
    }
    return cnt;
  }
};