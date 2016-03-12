/*
 *	Code Jam to IO 2016 for Women C
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
#define MOD 1000000007
ll dp[505][2];
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		REP(i,0,505) REP(j,0,2){
			dp[i][j] = 0;
		}
		dp[0][0] = 1;
		int c,v,l;
		cin >> c >> v >> l;
		REP(i,1,l+1){
				dp[i][1] = c*dp[i-1][0]%MOD;
				dp[i][1] %= MOD;
				dp[i][0] = v*dp[i-1][0]%MOD + v*dp[i-1][1]%MOD;
				dp[i][0] %= MOD;
		}
		printf("Case #%d: %lld\n",t,dp[l][0]);
	}
	return 0;
}

