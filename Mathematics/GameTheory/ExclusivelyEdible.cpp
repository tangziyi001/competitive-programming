/*
 *	UVA 11311
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Game Theory with DFS and Memo
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
#define MAXN 55
#define MOD 1000000007

int m,n,r,c;
int dp[MAXN][MAXN][MAXN][MAXN];
int dfs(int top, int bot, int left, int right){
	// cout << top << " " << bot << " " << left << " " << right << endl;
	// cout << r << c << endl;
	if(dp[top][bot][left][right] != -1) return dp[top][bot][left][right];
	if(top == bot && left == right)
		return 0;
	int flag = 0;
	REP(i,left+1,c+1){
		flag |= dfs(top, bot, i, right);
	}
	REP(i,c,right){
		flag |= dfs(top, bot, left, i);
	}
	REP(i,top+1,r+1){
		flag |= dfs(i, bot, left, right);
	}
	REP(i,r,bot){
		flag |= dfs(top, i, left, right);
	}
	return dp[top][bot][left][right] = flag^1;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		FILL(dp,-1);
		cin >> m >> n >> r >> c;
		if(dfs(0,m-1,0,n-1))
			cout << "Hansel" << endl;
		else
			cout << "Gretel" << endl;

	}
	return 0;
}