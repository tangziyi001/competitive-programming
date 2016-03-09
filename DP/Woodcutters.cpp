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
vpi all;
int dp[100005][3];
int main(){
	FILL(dp,-1);
	int n;
	cin >> n;
	int a,b;
	all.push_back(make_pair(-INF,0));
	REP(i,1,n+1){
		cin >> a >> b;
		all.push_back(make_pair(a,b));
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	REP(i,1,n+1){
		dp[i][0] = (dp[i-1][0] != -1) ? max(dp[i-1][0], dp[i][0]) : dp[i][0];
		dp[i][0] = (dp[i-1][1] != -1) ? max(dp[i-1][1], dp[i][0]) : dp[i][0];
		dp[i][2] = (dp[i-1][0] != -1) ? max(1 + dp[i-1][0], dp[i][2]) : dp[i][2];
		dp[i][2] = (dp[i-1][1] != -1) ? max(1 + dp[i-1][1], dp[i][2]) : dp[i][2];
		if(all[i].first - all[i].second > all[i-1].first){
			dp[i][1] = (dp[i-1][0] != -1) ? max(1 + dp[i-1][0], dp[i][1]) : dp[i][1];
			dp[i][1] = (dp[i-1][1] != -1) ? max(1 + dp[i-1][1], dp[i][1]) : dp[i][1];
		}
		if(all[i].first > all[i-1].first + all[i-1].second){
			dp[i][0] = (dp[i-1][2] != -1) ? max(dp[i-1][2], dp[i][0]) : dp[i][0];
			dp[i][2] = (dp[i-1][2] != -1) ? max(1 + dp[i-1][2], dp[i][2]) : dp[i][2];
		}
		if(all[i].first - all[i].second > all[i-1].first + all[i-1].second){
			dp[i][1] = (dp[i-1][2] != -1) ? max(1 + dp[i-1][2], dp[i][1]) : dp[i][1];
		}
	}
	int maxp = 0;
	maxp = max(maxp, dp[n][0]);
	maxp = max(maxp, dp[n][1]);
	maxp = max(maxp, dp[n][2]);
	cout << maxp << endl;
	return 0;
}