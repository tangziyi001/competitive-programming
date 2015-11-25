/*
 *	UVA 00314
 *	Created by Ziyi Tang
 *	BFS with x*y*direction states
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
typedef pair<pi, int> ppi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 55

int grid[MAXN][MAXN][4];
int obs[MAXN][MAXN];
int r,c;
queue<ppi> que;
pi sta, ter;
int check(int x, int y){
	if(x > 0 && x < r && y > 0 && y < c && obs[x][y] == 0 && obs[x-1][y] == 0 && obs[x-1][y-1] == 0 && obs[x][y-1] == 0)
		return true;
	return false;
}
int main(){
	while(cin >> r >> c && r != 0 && c != 0){
		while(!que.empty()){
			que.pop();
		}
		FILL(grid,-1);
		REP(i,0,r){
			REP(j,0,c){
				int tmp;
				cin >> tmp;
				obs[i][j] = tmp;
			}
		}
		int x,y;
		cin >> x >> y;
		sta = make_pair(x,y);
		cin >> x >> y;
		ter = make_pair(x,y);
		string com;
		cin >> com;
		int direc = -1;
		if(com == "south")
			direc = 2;
		if(com == "north")
			direc = 0;
		if(com == "west")
			direc = 3;
		if(com == "east")
			direc = 1;
		ppi ini = make_pair(sta, direc);
		grid[sta.first][sta.second][direc] = 0;
		que.push(ini);
		int re = -1;
		while(!que.empty()){
			ppi now = que.front(); que.pop();
			if(now.first == ter){
				re = grid[now.first.first][now.first.second][now.second];
				break;
			}
			int x = now.first.first;
			int y = now.first.second;
			int direc = now.second;
			int right = (direc+1+4)%4;
			int left = (direc-1+4)%4;
			if(grid[x][y][left] == -1){
				grid[x][y][left] = grid[x][y][direc]+1;
				que.push(make_pair(make_pair(x,y),left));

			}
			if(grid[x][y][right] == -1){
				grid[x][y][right] = grid[x][y][direc]+1;
				que.push(make_pair(make_pair(x,y),right));
			}
			REP(i,1,4){
				int tx = x + i*dir[direc][0];
				int ty = y + i*dir[direc][1];
				if(check(tx,ty)){
					if(grid[tx][ty][direc] == -1){
						grid[tx][ty][direc] = grid[x][y][direc]+1;
						que.push(make_pair(make_pair(tx,ty),direc));
					}
				}
				else{
					break;
				}
			}
		}

		// REP(k,0,4){
		// REP(i,0,r){
		// 	REP(j,0,c){
		// 		cout << grid[i][j][k] << " ";
		// 	}
		// 	cout << endl;
		// }
		// }
		cout << re << endl;

	}

	return 0;
}
