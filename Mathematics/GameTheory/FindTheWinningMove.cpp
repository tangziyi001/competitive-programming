/*
 *	UVA 10111
 *	Coded by Ziyi Tang
 *
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
#define MAXN 4
#define MOD 1000000007

char grid[MAXN][MAXN];
int rex,rey;
map<string, int> rec;
int checkFull(){
	REP(i,0,4) REP(j,0,4){
		if(grid[i][j] == '.')
			return false;
	}
	return true;
}
int checkAll(int now){
	cout << "check" << endl;
	char tmp = now == 0 ? 'x' : 'o';
	REP(i,0,4){
		int j = 0;
		if(grid[i][j] != tmp) continue;
		for(; j < 3; j++){
			if(grid[i][j] != grid[i][j+1]){
				break;
			}
		}
		if(j == 3) return 1;
	}
	REP(i,0,4){
		int j = 0;
		if(grid[i][j] != tmp) continue;
		for(; j < 3; j++){
			if(grid[j][i] != grid[j+1][i]){
				break;
			}
		}
		if(j == 3) return 1;
	}
	int i = 0;
	for(; i < 3; i++){
		if(grid[i][i] != tmp) break;
		if(grid[i][i] != grid[i+1][i+1])
			break;
	}
	if(i == 3) return 1;
	i = 2;
	for(; i >= 0; i--){
		if(grid[i][i] != tmp) break;
		if(grid[i][i] != grid[i+1][i+1])
			break;
	}
	if(i == -1) return 1;
	if(tmp == 1 && checkFull())
		return 1;
	return 0;
}
int dfs(int now, int x, int y){
	REP(i,0,4){
		REP(j,0,4){
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
	string tmp;
	REP(i,0,4) REP(j,0,4)
		tmp += grid[i][j];

	// Check from memo
	if(rec.find(tmp) != rec.end()){
		cout << "find" << endl;
		return rec[tmp] == now;
	}
	if(checkAll(1-now)){
		cout << "win" << 1-now << endl;
		rec[tmp] = 1-now;
		return 0;
	}

	int flag = 0;
	REP(i,0,4) REP(j,0,4) if(grid[i][j] == '.') {
		grid[i][j] = now == 0 ? 'x' : 'o';
		flag |= dfs(1-now, i, j);
		grid[i][j] = '.';
	}
	if(flag){
		rec[tmp] = 1-now;
		return 0;
	}
	rec[tmp] = now;
	return 1;
}
int main(){
	char l;
	while(cin >> l && l != '$'){
		string line;
		rec.clear();
		rex = 100;
		rey = 100;
		REP(i,0,4){
			cin >> line;
			REP(j,0,4)
				grid[i][j] = line[j];
		}
		string tmp;
		REP(i,0,4) REP(j,0,4)
			tmp += grid[i][j];
		REP(i,0,4){
			REP(j,0,4) if(grid[i][j] == '.'){
				grid[i][j] = 'x';
				int flag = 0;
				dfs(1,i,j);
				if(rec.find(tmp) != rec.end() && rec[tmp] == 0){
					rex = i; rey = j;
					break;
				}
				grid[i][j] = '.';
			}
			if(rex != 100 && rey != 100) break;
		}
		cout << rex << " " << rey << endl;
	}
	return 0;
}