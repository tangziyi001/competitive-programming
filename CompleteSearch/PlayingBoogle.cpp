/*
 *	UVA 11283
 *	Created by Ziyi Tang
 *	DFS Search. Pay attention to the boundary base case.
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
const int dir[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

char all[4][4];
int scores[9] = {0,0,0,1,1,2,3,5,11};
bool check(int x, int y){
	if(x >= 0 && x < 4 && y >= 0 && y < 4)
		return true;
	return false;
}
int dfs(int idx, string line, int x, int y){
	if(idx == line.size()) return 1;
	if(!check(x,y) || all[x][y] == '#') return 0;
	if(line[idx] == all[x][y]){
		int flag = 0;
		char now = all[x][y];
		all[x][y] = '#';
		REP(i,0,8){
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			flag |= dfs(idx+1, line, tx, ty);
			if(flag) break;
		}
		all[x][y] = now;
		return flag;
	} else return 0;
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		REP(i,0,4){
			string line;
			cin >> line;
			REP(j,0,4){
				all[i][j] = line[j];
			}
		}
		int q;
		cin >> q;
		int re = 0;
		REP(k,0,q){
			string line;
			cin >> line;
			bool tmp = 0;
			REP(i,0,4) REP(j,0,4){
				tmp |= dfs(0, line, i, j);
			}
			if(tmp)
				re += line.size() < 9 ? scores[line.size()] : 11;
		}
		printf("Score for Boggle game #%d: %d\n", t, re);
	}
	return 0;
}