/*
 *	Segment Tree for RMQ
 *	Created by Ziyi Tang
 *	O(logn)
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
#define MAXN 10005

vi all;
vi ss;
vi dp;
int st[4*MAXN+1];
int n;

int rmq(int p, int L, int R, int l, int r){
	if(l > R || r < L)
		return -1;
	if(L >= l && R <= r)
		return st[p];
	int left = p << 1;
	int right = (p << 1) + 1;
	int p1_idx = rmq(left, L, (L+R)/2, l, r);
	int p2_idx = rmq(right, (L+R)/2+1, R, l, r);
	if(p1_idx == -1) return p2_idx;
	if(p2_idx == -1) return p1_idx;
	return (dp[p1_idx] > dp[p2_idx]) ? dp[p1_idx] : dp[p2_idx];
}

void update(int p, int L, int R, int i){
	if(L == R)
		st[p] = L;
	else{
		int left = p << 1;
		int right = (p << 1) + 1;
		if(i <= (L+R)/2)
			update(left, L, (L+R)/2, i);
		else
			update(right, (L+R)/2+1, R, i);
		int p1_idx = st[left];
		int p2_idx = st[right];
		st[p] = (all[p1_idx] <= all[p2_idx]) ? p1_idx : p2_idx;
	}
}

int main(){
	cin >> n; // Numbers

	// Clear
	all.clear();
	all.assign(n,0);
	dp.assign(n,0);
	FILL(st,0);

	// Input
	int r,h;
	REP(i,0,n){
		cin >> r >> h;
		all[i] = r*r*h;
		ss.push_back(all[i], i);
	}

	// Build
	// build(1,0,n-1);
	sort(ss.begin(),ss.end());

	REP(i,0,n){
		pi now = ss[i];
		int maxp = rmq(0,now.second);
		dp[i] = max(all[i], )
	}

	// Query & Test
	int l,r;
	cin >> l >> r;
	int p = rmq(1,0,n-1,l,r);
	cout << p << " is " << all[p] << endl;
	

	// Update
	int idx,val;
	cin >> idx >> val;
	all[idx] = val;
	update(1,0,n-1,idx);

	// Another Test
	cin >> l >> r;
	p = rmq(1,0,n-1,l,r);
	cout << p << " is " << all[p] << endl;
	return 0;
}
