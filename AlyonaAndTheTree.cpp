/*
 *	Codeforces 682C — Alyona and the Tree
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

int n;
vector<ll> all;
vector<ll> maxp;

vvpi tree;
int dfs(int now, int p){
	int sz = tree[now].size();
	int re = 0;
	REP(i,0,sz){
		int nxt = tree[now][i].first;
		if(nxt == p) continue;
		int w = tree[now][i].second;
		ll num_nxt = all[nxt];
		ll max_nxt = max((ll)w, (ll)w + maxp[now]);
		if(num_nxt < max_nxt)
			continue;
		maxp[nxt] = max_nxt;
		re += dfs(nxt,now);
	}
	return 1 + re;
}
int main(){
	int n;
	cin >> n;
	tree.assign(n,vpi(0,pi(0,0)));
	maxp.assign(n,0LL);
	REP(i,0,n){
		ll tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,1,n){
		int nxt,v;
		cin >> nxt >> v;
		nxt--;
		tree[i].push_back(pi(nxt,v));
		tree[nxt].push_back(pi(i,v));
	}
	int re = dfs(0,-1);
	// REP(i,0,n)
	// 	cout << maxp[i] << " " << minp[i] << endl;
	cout << n-re << endl;
	return 0;
}