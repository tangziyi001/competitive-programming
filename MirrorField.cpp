/*
 *	USACO 2014 February Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	Simulation
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
#define MAXN 1005

char all[MAXN][MAXN];
int n,m;
int check(int prev_dir, int x, int y){
	//cout << x << y << endl;
	if(x < 0 || y < 0 || x == n || y == m)
		return 0;
	int maxp = 0;
	if(all[x][y] == '/'){
		if(prev_dir == 0)
			maxp = 1 + max(maxp, check(1, x, y+1));
		else if(prev_dir == 1)
			maxp = 1 + max(maxp, check(0, x-1, y));
		else if(prev_dir == 2)
			maxp = 1 + max(maxp, check(3, x, y-1));
		else
			maxp = 1 + max(maxp, check(2, x+1, y));

	}else{
		if(prev_dir == 0)
			maxp = 1 + max(maxp, check(3, x, y-1));
		else if(prev_dir == 1)
			maxp = 1 + max(maxp, check(2, x+1, y));
		else if(prev_dir == 2)
			maxp = 1 + max(maxp, check(1, x, y+1));
		else
			maxp = 1 + max(maxp, check(0, x-1, y));
	}
	return maxp;
}
int main(){
	freopen("mirror.in", "r", stdin);
  	freopen("mirror.out", "w", stdout);
  	cin >> n >> m;
  	REP(i,0,n){
		string line;
		cin >> line;
		REP(j,0,m){
			all[i][j] = line[j];
		}
  	}
  	int maxp = -1;
  	REP(i,0,n){
  		maxp = max(maxp, check(1, i, 0));
  		maxp = max(maxp, check(3, i, m-1));
  	}
  	REP(j,0,m){
  		maxp = max(maxp, check(2, 0, j));
  		maxp = max(maxp, check(0, n-1, j));
  	}
  	cout << maxp << endl;
	return 0;
}