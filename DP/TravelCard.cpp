/*
 *	Codeforces 756B - Travel Card
 *	Created by Ziyi Tang
 *	DP with binary search
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 100005
#define MOD 1000000007

vi all;
int dp[MAXN];
int main(){
	int n;
	cin >> n;
	all.push_back(-INF);
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	dp[0] = 0;
	int now = 0;
	int off = 0;
	REP(i,1,n+1){
		dp[i] = dp[i-1]+20;
		int pre = distance(all.begin(),upper_bound(all.begin(),all.end(),all[i]-90))-1;
		dp[i] = min(dp[i], 50+dp[pre]);
		pre = distance(all.begin(),upper_bound(all.begin(),all.end(),all[i]-1440))-1;
		dp[i] = min(dp[i], 120+dp[pre]);
		off = max(0,dp[i]-now);
		now = max(now,dp[i]);
		cout << off << endl;
	}
	return 0;
}