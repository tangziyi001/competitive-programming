/*
 *	USACO 2014 March Contest, Bronze 3
 *	Coded by Ziyi Tang
 *	
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
#define MAXN 105

char human[MAXN][MAXN];
char cow[MAXN][MAXN];
char mark1[MAXN][MAXN];
char mark2[MAXN][MAXN];
int n;
bool check(int x,int y){
	if(x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}
void dfs1(int i, int j){
	REP(k,0,4){
		int tx = i+dir[k][0];
		int ty = j+dir[k][1];
		if(check(tx,ty) && mark1[tx][ty] == 0 && human[tx][ty] == human[i][j]){
			mark1[tx][ty] = 1;
			dfs1(tx,ty);
		}
	}
}
void dfs2(int i, int j){
	REP(k,0,4){
		int tx = i+dir[k][0];
		int ty = j+dir[k][1];
		if(check(tx,ty) && mark2[tx][ty] == 0 && cow[tx][ty] == cow[i][j]){
			mark2[tx][ty] = 1;
			dfs2(tx,ty);
		}
	}
}
int main(){
	freopen("cowart.in", "r", stdin);
  	freopen("cowart.out", "w", stdout);
	FILL(mark1,0);
	FILL(mark2,0);
	cin >> n;
	REP(i,0,n){
		string line;
		cin >> line;
		REP(j,0,n){
			human[i][j] = line[j];
			cow[i][j] = line[j];
			if(cow[i][j] == 'G')
				cow[i][j] = 'R';
		}
	}
	int cont1 = 0, cont2 = 0;
	REP(i,0,n) REP(j,0,n){
		if(mark1[i][j] == 0){
			cont1++;
			mark1[i][j] = 1;
			dfs1(i,j);
		}
		if(mark2[i][j] == 0){
			cont2++;
			mark2[i][j] = 1;
			dfs2(i,j);
		}
	}
	cout << cont1 << " " << cont2 << endl;
	return 0;
}