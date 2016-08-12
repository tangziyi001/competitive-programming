/*
 *	Codeforces 706C
 *	Created by Ziyi Tang
 *	Simple DP
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
const long long INFL = (long long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 100010
#define MOD 1000000007

vector<ll> cc;
vector<string> all;
vector<string> rev;
ll dp[MAXN][2];
int main(){
	REP(i,0,MAXN){
		dp[i][0] = INFL;
		dp[i][1] = INFL;
	}
	int n;
	cin >> n;
	REP(i,0,n){
		ll tmp;
		cin >> tmp;
		cc.push_back(tmp);
	}
	REP(i,0,n){
		string tmp;
		cin >> tmp;
		all.push_back(tmp);
		reverse(tmp.begin(), tmp.end());
		rev.push_back(tmp);
	}
	dp[0][0] = 0;
	dp[0][1] = cc[0];
	REP(i,1,n){
		if(all[i] >= all[i-1] && dp[i-1][0] != INFL){
			dp[i][0] = min(dp[i][0], dp[i-1][0]);
		}
		if(all[i] >= rev[i-1] && dp[i-1][1] != INFL){
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		}
		if(rev[i] >= all[i-1] && dp[i-1][0] != INFL){
			dp[i][1] = min(dp[i][1], dp[i-1][0] + cc[i]);
		}
		if(rev[i] >= rev[i-1] && dp[i-1][1] != INFL){
			dp[i][1] = min(dp[i][1], dp[i-1][1] + cc[i]);
		}
	}
	ll re = min(dp[n-1][0], dp[n-1][1]);
	if(re != INFL){
		cout << re << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}