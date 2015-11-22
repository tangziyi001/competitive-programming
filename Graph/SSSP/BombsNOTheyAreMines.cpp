/*
 *	UVA 10653
 *	Created by Ziyi Tang
 *	BFS SSSP
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
#define MAXN 1005

int grid[MAXN][MAXN];
int r,c;
queue<pi> que;
bool check(int tr, int tc){
	if(tr >= 0 && tr < r && tc >= 0 && tc < c)
		return true;
	return false;
}
int main(){
	int	rows;
	while(cin >> r >> c && r != 0 && c != 0){
		while(!que.empty()){
			que.pop();
		}
		FILL(grid,-1);
		cin >> rows;
		REP(i,0,rows){
			int tr,tn;
			cin >> tr >> tn;
			REP(i,0,tn){
				int tc;
				cin >> tc;
				grid[tr][tc] = -2;
			}
		}
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		grid[x][y] = 0;
		pi sta = make_pair(x,y);
		que.push(sta);
		while(!que.empty()){
			pi now = que.front();que.pop();
			int tr = now.first;
			int tc = now.second;
			REP(i,0,4){
				int dr = tr+dir[i][0];
				int dc = tc+dir[i][1];
				if(check(dr,dc) && grid[dr][dc] == -1){
					grid[dr][dc] = grid[tr][tc] + 1;
					que.push(make_pair(dr,dc));
				}
			}
		}
		// REP(i,0,r){
		// 	REP(j,0,c){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << grid[a][b] << endl;

	}
	return 0;
}
