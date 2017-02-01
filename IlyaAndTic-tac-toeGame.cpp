/*
 *	Codeforces 754B - Ilya and tic-tac-toe game
 *	Created by Ziyi Tang
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
typedef vector<vector<char> > vvc;
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[8][2] = {{-1,0},{-1,-1},{0,1},{1,-1},{1,0},{-1,1},{0,-1},{1,1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vector<vector<char> > grid;
bool check(int x, int y){
	if(x >= 0 && x < 4 && y >= 0 && y < 4) return true;
	return false;
}
bool checkWin(int x, int y){
	REP(i,0,8){
		int to = 1;
		REP(t,1,3){
			int tx = x + t*dir[i][0];
			int ty = y + t*dir[i][1];
			if(!check(tx,ty)) to = -1000;
			if(check(tx,ty) && grid[tx][ty] == 'o') {
				to = -1000;
			}
			if(check(tx,ty) && grid[tx][ty] == 'x'){
				to++;
			}
		}
		if(to >= 2){
			return true;
		}
	}
	return false;
}
int main(){
	string line;
	grid.assign(4,vector<char>(4,'.'));
	REP(i,0,4){
		cin >> line;
		REP(j,0,4){
			grid[i][j] = line[j];
		}
	}
	REP(i,0,4) REP(j,0,4){
		if(grid[i][j] == 'x'){
			if(checkWin(i,j)){
				//cout << i << j << endl;
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}