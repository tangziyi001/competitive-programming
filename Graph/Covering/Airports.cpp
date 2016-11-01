/*
 *	2015 Southeast USA Regionals Division 1
 *	Created by Ziyi Tang
 *	Minimum Edge Covering => Bipartite Match
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 505
#define MOD 1000000007

int n,m;
int ins[MAXN];
int adj[MAXN][MAXN];
int direct[MAXN][MAXN];
vvi all;

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

int main(){
	scanf("%d %d", &n, &m);
	REP(i,0,n){
		scanf("%d", &ins[i]);
	}
	FILL(adj, INF);
	FILL(direct, INF);
	REP(i,0,n) REP(j,0,n){
		int tmp;
		scanf("%d", &tmp);
		adj[i][j] = tmp + ins[j];
		direct[i][j] = tmp + ins[j];
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(adj[i][k] == INF || adj[k][j] == INF) continue;
		if(adj[i][k] + adj[k][j] < adj[i][j]){
			adj[i][j] = adj[i][k] + adj[k][j];
		}
	}
	all.assign(m,vi(3,0)); // Start, End, Start Time
	REP(i,0,m){
		scanf("%d %d %d", &all[i][0], &all[i][1], &all[i][2]);
	}
	BipartiteMatch bm;
	bm.init(m,m);
	// Pair up each two flights
	REP(i,0,m) REP(j,0,m) if(i != j){
		int is = all[i][0]-1;
		int it = all[i][1]-1;
		int itime = all[i][2];
		int js = all[j][0]-1;
		int jt = all[j][1]-1;
		int jtime = all[j][2];
		int time = itime + direct[is][it];
		if(it != js){
			time += adj[it][js];
		}
		if(time <= jtime) bm.addMatch(i,j);
	}
	cout << m-bm.calcMaxMatch() << endl;
	return 0;
}