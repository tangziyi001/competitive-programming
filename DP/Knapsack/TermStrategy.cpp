/*
 *	
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

int dp[15][105];
int all[15][105];
int n,m;
int rec(int pos, int tm){
	if(tm < 0) return -INF;
	if(tm == 0 && pos != n) return -INF;
	if(dp[pos][tm] != -1) return dp[pos][tm];
	if(pos == n) return 0;
	int maxp = -INF;
	REP(i,1,m+1){
		if(all[pos][i-1] < 5) continue;
		maxp = max(maxp, all[pos][i-1]+rec(pos+1, tm-i));
	}
	return dp[pos][tm] = maxp;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		FILL(dp,-1);
		FILL(all,-1);
		cin >> n >> m;
		REP(i,0,n){
			REP(j,0,m){
				int tmp;
				cin >> tmp;
				all[i][j] = tmp;
			}
		}
		int maxp = rec(0,m);
		if(maxp > 0)
			printf("Maximal possible average mark - %.2f.\n", (double)maxp/n+1e-7);
		else
			printf("Peter, you shouldn\'t have played billiard that much.\n");
	}
	return 0;
}

