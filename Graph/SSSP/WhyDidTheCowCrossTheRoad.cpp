/*
 *	USACO 2017 February Contest, Gold 1
 *	Coded by Ziyi Tang
 *	Multi-state Dijkstra Algorithm
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
const int INF = (int)0x3f3f3f;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 105

int dis[MAXN][MAXN][3];
int grid[MAXN][MAXN];
vvpi all;
priority_queue<pair<int, vector<int> > > qq;
int n,m;
bool check(int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < n);
}

int main(){
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	FILL(dis,INF);
  cin >> n >> m;
	REP(i,0,n){
		REP(j,0,n){
			int tmp;
			cin >> tmp;
      grid[i][j] = tmp;
		}
	}
  vi source;
  source.push_back(0);
  source.push_back(0);
  source.push_back(0);
  qq.push(make_pair(0, source));
  dis[0][0][0] = 0;
  while(!qq.empty()){
    int d = -qq.top().first;
    int x = (qq.top().second)[0];
    int y = (qq.top().second)[1];
    int r = (qq.top().second)[2];
    qq.pop();
    if(d > dis[x][y][r]) continue ;
    REP(i,0,4) {
      int tx = x + dir[i][0];
      int ty = y + dir[i][1];
      if(!check(tx,ty)) continue;
      int tr = (r+1)%3;
      int off = (tr != 0) ? m : m+grid[tx][ty];
      if(d + off < dis[tx][ty][tr]){
        dis[tx][ty][tr] = d + off;
        vi tmp;
        tmp.push_back(tx); tmp.push_back(ty); tmp.push_back(tr);
        qq.push(make_pair(-(d+off), tmp));
      }
    }
  }
  int re = dis[n-1][n-1][0];
  re = min(re, dis[n-1][n-1][1]);
  re = min(re, dis[n-1][n-1][2]);
  cout << re << endl;
	return 0;
}