/*
 *	
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
#define MAXN 9

char all[9][9];
char col[2] = {'O','X'};
bool check(int x, int y){
	if(x >= 0 && x < 9 && y >= 0 && y < 9)
		return true;
	return false;
}
int dfs(int x, int y, int color, int bound){
	int sum = 1;
	REP(i,0,4){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(check(tx,ty)){
			if(all[tx][ty] == col[1-color]){
				sum = -INF;
			}
			if(all[tx][ty] == '.'){
				all[tx][ty] = '#';
				int tmp = dfs(tx,ty,color,bound);
				if(tmp < 0) sum = -INF;
				else sum += tmp;
			}
		}
	}
	return sum >= 0 ? sum : -INF;
}
int main(){
	int n;
	cin >> n;
	REP(t,0,n){
		int w = 0;
		int b = 0;
		int bt = 0;
		int wt = 0;
		REP(i,0,9){
			string line;
			cin >> line;
			REP(j,0,9){
				all[i][j] = line[j];
				if(line[j] == 'X') b++;
				if(line[j] == 'O') w++; 
			}
		}
		REP(i,0,9) REP(j,0,9){
			if(all[i][j] == 'O'){
				REP(k,0,4){
					int tx = i + dir[k][0];
					int ty = j + dir[k][1];
					if(check(tx,ty) && all[tx][ty] == '.'){
						all[tx][ty] = '#';
						int sum = dfs(tx,ty,0,0);
						if(sum >= 0)
							wt += sum;
					}
				}
			}
			if(all[i][j] == 'X'){
				REP(k,0,4){
					int tx = i + dir[k][0];
					int ty = j + dir[k][1];
					if(check(tx,ty) && all[tx][ty] == '.'){
						all[tx][ty] = '#';
						int sum = dfs(tx,ty,1,0);
						if(sum >= 0)
							bt += sum;
					}
				}
			}
		}
		printf("Black %d White %d\n",bt+b,wt+w);
	}
	return 0;
}

