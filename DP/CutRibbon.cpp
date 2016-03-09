/*
 *	CodeForces 189A
 *	Created by Ziyi Tang
 *	Count Max Number of Coin Change
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

int dp[4005];
int sz[3];
int main(){
	int n;
	FILL(dp, -1);
	dp[0] = 0;
	cin >> n >> sz[0] >> sz[1] >> sz[2];
	REP(i,1,n+1){
		REP(j,0,3){
			if(i >= sz[j] && dp[i-sz[j]] != -1)
				dp[i] = max(dp[i], 1 + dp[i-sz[j]]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}

