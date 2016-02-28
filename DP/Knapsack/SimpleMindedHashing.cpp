/*
 *	
 *	Created by Ziyi Tang
 *	3D DP
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

int dp[30][30][400]; // dp[pos][count][sum]
int l,s;
int main(){
	FILL(dp,0);
	int cas = 0;
	dp[0][0][0] = 1;
	REP(i,1,27) REP(j,0,i+1) REP(k,0,400) {
		dp[i][j][k] = dp[i-1][j][k];
		if(j > 0 && k >= i)
			dp[i][j][k] += dp[i-1][j-1][k-i];
	}
	while(cin >> l >> s && l != 0 && s != 0){
		cas++;
		if(l > 26)
			printf("Case %d: %d\n", cas, 0);
		else{
			int re = dp[26][l][s];
			printf("Case %d: %d\n", cas, re);
		}
	}
	return 0;
}

