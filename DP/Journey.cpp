/*
 *	Codeforces 721C
 *	Created by Ziyi Tang
 *	DP to DAG. Find minimum time for each state dp[i][j] (reach i by passing j vertices).
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
const int INF = 1e9+3;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 5010
#define MOD 1000000007

vvpi all;
vvpi rev;
int dp[MAXN][MAXN];
int re[MAXN][MAXN];
int n,m,T;
int rec(int now, int pass){
	if(now == 0 && pass == 0) return dp[now][pass] = 0;
	else if(pass == 0) return INF;
	if(dp[now][pass] != -1) return dp[now][pass];  
	int minp = INF;
	int tsz = rev[now].size();
	REP(i,0,tsz){
		int nxt = rev[now][i].first;
		int time = rev[now][i].second;
		int nxt_time = time+rec(nxt, pass-1);
		if(minp > nxt_time){
			minp = nxt_time;
			re[now][pass] = nxt;
		}
		
	}
	return dp[now][pass] = minp;
}
int main(){
	cin >> n >> m >> T;
	all.assign(n, vpi(0,pi(0,0)));
	rev.assign(n, vpi(0,pi(0,0)));
	FILL(dp,-1);
	FILL(re,-1);
	REP(i,0,m){
		int sta, ter, tmp;
		cin >> sta >> ter >> tmp;
		all[sta-1].push_back(make_pair(ter-1, tmp));
		rev[ter-1].push_back(make_pair(sta-1, tmp));
	}
	REP(i,0,n){
		rec(n-1,i);
	}
	int maxp = 0;
	REP(i,0,n){
		if(dp[n-1][i] <= T){
			maxp = max(maxp, i);
		}
	}
	cout << maxp+1 << endl;
	vi res;
	int tmp = n-1;
	int pass = maxp;
	while(tmp != 0){
		res.push_back(tmp+1);
		int nxt = re[tmp][pass];
		// cout << tmp << " " << nxt << endl;
		pass--;
		tmp = nxt;
	}
	res.push_back(1);
	for(int i = res.size()-1; i >= 0; i--){
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}