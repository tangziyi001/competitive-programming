/*
 *	UVA 00929
 *	Created by Ziyi Tang
 *	Basic Dijkstra
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
typedef pair<int,pi> pip;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1005

priority_queue<pip, vector<pip>, greater<pip> > pq;
int dis[MAXN][MAXN];
int grid[MAXN][MAXN];
int source = -1;
int n,m;

int check(int i, int j){
	if(i >= 0 && j >= 0 && i < n && j < m)
		return true;
	return false;
}
int main(){

	int cas;
	cin >> cas;
	REP(t,0,cas){
		cin >> n >> m;
		REP(i,0,n){
			REP(j,0,m){
				int tmp;
				cin >> tmp;
				grid[i][j] = tmp;
				dis[i][j] = INF;
			}
		}
		while(!pq.empty()){
			pq.pop();
		}

		// Source
		pq.push(make_pair(0,make_pair(0,0)));
		dis[0][0] = grid[0][0];
		
		// Begin
		while(!pq.empty()){
			pip now = pq.top(); pq.pop();
			int d = now.first; 
			pi u = now.second;
			int nx = u.first;
			int ny = u.second;
			if(d > dis[nx][ny])
				continue;
			REP(i,0,4){
				int tx = nx + dir[i][0];
				int ty = ny + dir[i][1];
				if(check(tx,ty) && dis[nx][ny] + grid[tx][ty] < dis[tx][ty]){
					dis[tx][ty] = dis[nx][ny] + grid[tx][ty];
					pq.push(make_pair(dis[tx][ty], make_pair(tx,ty)));
				}
			}
		}

		//Test
		// REP(i,0,n){
		// 	REP(j,0,m){
		// 		cout << dis[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << dis[n-1][m-1] << endl;
	}
	return 0;
}
