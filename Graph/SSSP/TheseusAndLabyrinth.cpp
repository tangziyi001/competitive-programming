/*
 *	CodeForces 676D
 *	Created by Ziyi Tang
 *	BFS, Heavy Implementation
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
#define MAXN 1000
#define MOD 1000000007

int mark[1005][1005][4];
int all[1005][1005][4];
queue<pair<pi, int> > qq;
int n,m;
void fill(){
	REP(i,0,n){
		string line;
		cin >> line;
		REP(j,0,m){
			char now;
			now = line[j];
			if(now == '+')
				all[i][j][0] = 15;
			if(now == '-')
				all[i][j][0] = 5;
			if(now == '|')
				all[i][j][0] = 10;
			if(now == '^')
				all[i][j][0] = 8;
			if(now == '>')
				all[i][j][0] = 4;
			if(now == '<')
				all[i][j][0] = 1;
			if(now == 'v')
				all[i][j][0] = 2;
			if(now == 'L')
				all[i][j][0] = 14;
			if(now == 'R')
				all[i][j][0] = 11;
			if(now == 'U')
				all[i][j][0] = 7;
			if(now == 'D')
				all[i][j][0] = 13;
		}
	}
	
	REP(k,1,4){
		REP(i,0,n){
			REP(j,0,m){
				all[i][j][k] = ((all[i][j][k-1] & 1) != 0) ? 
					(all[i][j][k-1] >> 1) | (1 << 3) : 
					(all[i][j][k-1] >> 1);
			}
		}
	}
}
int check(int x,int y,int tx,int ty,int dr,int i){
	if(tx < 0 || tx >= n || ty < 0 || ty >= m)
		return false;
	int dir1 = i;
	int dir2 = (i+2)%4;
	if((all[x][y][dr] & (1 << (3-dir1))) != 0 && (all[tx][ty][dr] & (1 << (3-dir2))) != 0)
		return true;
	return false;
}
int main(){
	cin >> n >> m;
	FILL(all,0);
	fill();
	int stax,stay,terx,tery;
	cin >> stax >> stay >> terx >> tery;
	stax--;stay--;terx--;tery--;
	FILL(mark,-1);
	mark[stax][stay][0] = 0;
	qq.push(make_pair(pi(stax,stay), 0));
	while(!qq.empty()){
		auto now = qq.front();qq.pop();
		int x = now.first.first;
		int y = now.first.second;
		int dr = now.second;
		int num = mark[x][y][dr];
		//cout << x << " " << y << " " << dr << " " << num << endl;

		// Rotate CW
		int nxtdr = (dr+1)%4;
		if(mark[x][y][nxtdr] == -1 || mark[x][y][nxtdr] > num+1){
			mark[x][y][nxtdr] = num+1;
			qq.push(make_pair(pi(x,y), nxtdr));
		}

		// Move
		REP(i,0,4){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if(!check(x,y,tx,ty,dr,i) || (mark[tx][ty][dr] != -1 && mark[tx][ty][dr] <= num+1))
				continue;
			mark[tx][ty][dr] = num+1;
			qq.push(make_pair(pi(tx,ty), dr));
		}
	}
	int re = INF;
	REP(i,0,4){
		if(mark[terx][tery][i] != -1)
			re = min(re, mark[terx][tery][i]);
	}
	if(re != INF)
		cout << re << endl;
	else
		cout << -1 << endl;
	
	return 0;
}