/*
 *	The 2nd ProgNova Multi-University Programming Contest D
 *	Created by Ziyi Tang
 *	BFS
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 105
#define MOD 1000000007
int n,m,k;
struct state{
	int x,y,mana;
	state(int x_,int y_,int mana_) : x(x_), y(y_), mana(mana_) {}
};
char grid[MAXN][MAXN];
int mark[MAXN][MAXN][MAXN];
queue<pair<state, int> >qq;

bool check(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int eval(int x, int y){
	if(grid[x][y] == '.' || grid[x][y] == 'G') return 1;
	if(grid[x][y] == 'F') return 2;
	if(grid[x][y] == 'M') return 3;
	else return 0;
}
int main(){
	cin >> n >> m >> k;
	string line;
	FILL(mark,-1);
	int sx = 0, tx = 0;
	int sy = 0, ty = 0;
	REP(i,0,n){
		cin >> line;
		REP(j,0,m){
			grid[i][j] = line[j];
			if(grid[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if(grid[i][j] == 'G'){
				tx = i;
				ty = j;
			}
		}
	}
	qq.push(make_pair(state(sx,sy,k), 1));
	mark[sx][sy][k] = 1;
	while(!qq.empty()){
		state now = qq.front().first;
		int step = qq.front().second;
		//if(step > 10000) continue;
		//cout << now.x << " " << now.y << " " << now.mana << " " << step << endl;
		qq.pop();
		REP(i,0,4){
			int nx = now.x + dir[i][0];
			int ny = now.y + dir[i][1];
			if(check(nx,ny) && grid[nx][ny] != '#'){
				//cout << nx << ny << endl;
				int val = eval(nx,ny);
				//cout << mark[nx][ny][now.mana-val] << endl;
				if(val > now.mana) continue;
				if(mark[nx][ny][now.mana-val] == -1){
					mark[nx][ny][now.mana-val] = step;
					qq.push(make_pair(state(nx,ny,now.mana-val), step));
				}
			}
		}
		if(now.mana != k){
			state tmp = now;
			tmp.mana = k;
			if(mark[tmp.x][tmp.y][tmp.mana] == -1){
				mark[tmp.x][tmp.y][tmp.mana] = step+1;
				qq.push(make_pair(tmp, step+1));
			}
		}
	}
	int minp = INF;
	REP(i,0,k+1) if(mark[tx][ty][i] != -1){
		minp = min(minp, mark[tx][ty][i]);
	}
	if(minp == INF){
		cout << -1 << endl;
	}
	else cout << minp << endl;
	return 0;
}