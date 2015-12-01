/*
 *	UVA 11101
 *	Created by Ziyi Tang
 *	Multi-Sources BFS
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 2050

int grid[MAXN][MAXN];
set<pi> mark;
queue<pi> que;
int n1,n2;
int l,r,t,b;

int check(int x, int y){
	if(x >= l && x <= r && y >= t && y <= b)
		return true;
	return false;
}
int main(){
	while(cin >> n1 && n1 != 0){
		FILL(grid,-1);
		while(!que.empty()){
				que.pop();
		}
		int minp = INF;
		l = MAXN-1;
		r = 0;
		t = MAXN-1;
		b = 0;
		mark.clear();
		REP(i,0,n1){
			int x,y;
			cin >> x >> y;
			que.push(make_pair(x,y));
			grid[x][y] = 0;
			if(x < l)
				l = x;
			if(x > r)
				r = x;
			if(y < t)
				t = y;
			if(y > b)
				b = y;
		}
		int n2;
		cin >> n2;
		REP(i,0,n2){
			int x,y;
			cin >> x >> y;
			mark.insert(make_pair(x,y));
			if(x < l)
				l = x;
			if(x > r)
				r = x;
			if(y < t)
				t = y;
			if(y > b)
				b = y;
		}

			
		while(!que.empty()){
			pi now = que.front(); que.pop();
			int tx = now.first;
			int ty = now.second;
			REP(j,0,4){
				int dx = tx+dir[j][0];
				int dy = ty+dir[j][1];
				if(check(dx,dy) && grid[dx][dy] == -1){
					grid[dx][dy] = grid[tx][ty] + 1;
					que.push(make_pair(dx,dy));
				}
				if(mark.find(make_pair(dx,dy)) != mark.end()){
					minp = min(minp, grid[dx][dy]);
					break;
				}
			}
			if(minp != INF)
				break;
		}
		// REP(i,l,r+1){
		// 	REP(j,t,b+1){
		// 		cout << grid[i][j] << " ";
		// 	}
		// cout << endl;
		// }
		// cout << endl;
		cout << minp << endl;
		
	}
	return 0;
}
