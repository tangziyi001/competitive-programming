/*
 *	UVA 11137
 *	Created by Ziyi Tang
 *	CoinChange (Count) DP
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

int all[22];
ll dp[22][10005];
ll rec(int now, int val){
	if(val == 0) return 1;
	if(now == 22) return 0;
	if(val < 0) return 0;
	if(dp[now][val] != -1) return dp[now][val];
	ll ways = 0;
	ways = rec(now+1, val) + rec(now, val-all[now]);
	return dp[now][val] = ways;
}
int main(){
	REP(i,0,22) REP(j,0,10005) dp[i][j] = -1;
	REP(i,1,22){
		all[i] = i*i*i;
	}
	int n;
	while(cin >> n){
		cout << rec(1,n) << endl;
		// REP(i,0,22){
		// 	cout << all[i] << endl;
		// }
	}

	return 0;
}

