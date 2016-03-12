/*
 *	USACO 2015 December Contest, Silver 1
 *	Created by Ziyi Tang
 *	DFS with post order re-traversal
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

int n,m;
int grid[105][105];
vector<vector<vector<pi> > > swi;
int check(int x,int y){
	if(x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}
void dfs(int i, int j){
	vpi tmp = swi[i][j];
	int sz = tmp.size();
	//cout << i << j << endl;
	REP(k,0,sz){
		if(grid[tmp[k].first][tmp[k].second] == -1){
			grid[tmp[k].first][tmp[k].second] = 0;
			REP(h,0,4){
				int tx = tmp[k].first + dir[h][0];
				int ty = tmp[k].second + dir[h][1];
				//cout << tx << " " << ty << endl;
				if(check(tx,ty) && grid[tx][ty] == 1){
					grid[tmp[k].first][tmp[k].second] = 1;
					dfs(tmp[k].first,tmp[k].second);
					break;
				}
			}
		}
	}
	REP(k,0,4){
		int tx = i + dir[k][0];
		int ty = j + dir[k][1];
		if(check(tx,ty) && grid[tx][ty] == 0){
			grid[tx][ty] = 1;
			dfs(tx,ty);
		}
	}
}
int main(){
	FILL(grid,-1);
	ifstream ifile("lightson.in");
	ifile >> n >> m;
	vpi ttmp;
	vvpi tttmp(n,ttmp);
	swi.assign(n,tttmp);
	REP(i,0,m){
		int sx,sy,tx,ty;
		ifile >> sx >> sy >> tx >> ty;
		swi[sx-1][sy-1].push_back(make_pair(tx-1,ty-1));
	}
	ifile.close();
	grid[0][0] = 1;
	dfs(0,0);

	int cont = 0;
	REP(i,0,n) REP(j,0,n){
		if(grid[i][j] == 1 || grid[i][j] == 0)
			cont++;
	}
	// REP(i,0,n){
	// 	REP(j,0,n){
	// 		cout << grid[i][j] << " "; 
	// 	}
	// 	cout << endl;
	// }
	cout << cont << endl;
	ofstream ofile("lightson.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}