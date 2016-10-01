/*
 *	Codeforces 721C - Journey
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vvpi all;
queue<int> qq;
int n;
int dp[5005][5005];
int maxp = 0;
vi re;
set<pair<int,int> > imp;
int dfs(int now, vector<int>& tmp, int t, int num){
	if(t < 0) return 0;
	if(t <= dp[now][num]) {
		return 0;
	}
	else {
		//cout << now << " " << num << " " << t << " " << dp[now][num] << endl;
		dp[now][num] = t;
	}
	if(imp.find(make_pair(now,t)) != imp.end()){
		return 0;
	}
	if(now == n-1){
		if(num > maxp){
			re = tmp;
			maxp = num;
		}
		return 1;
	}
	int tsz = all[now].size();
	int flag = 0;
	REP(i,0,tsz){
		int ttmp = all[now][i].first;
		tmp.push_back(ttmp);
		flag |= dfs(ttmp, tmp, t-all[now][i].second, num+1);
		tmp.pop_back();
	}
	if(flag == 0) imp.insert(make_pair(now,t));
	return flag;
}
int main(){
	int m,T;
	cin >> n >> m >> T;
	all.assign(n,vpi(0,make_pair(0,0)));
	REP(i,0,m){
		int sta,ter,c;
		cin >> sta >> ter >> c;
		if(c <= T)
			all[sta-1].push_back(make_pair(ter-1,c));
	}
	REP(i,0,5005) REP(j,0,5005) {
		dp[i][j] = -1;
	}
	vector<int> tmp(0,0);
	tmp.push_back(0);
	dfs(0, tmp, T, 1);
	cout << maxp << endl;
	REP(i,0,maxp){
		if(i) cout << " ";
		cout << re[i]+1;
	}
	cout << endl;
	return 0;
}