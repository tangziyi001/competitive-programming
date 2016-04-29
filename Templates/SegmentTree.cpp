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
#define MAXN 1000


struct SegmentTree{
	vi A;
	int n;
	vi st;
	void build(int p, int L, int R){
		if(L == R){
			st[p] = L;
		}
		else{
			int left = p << 1;
			int right = (p << 1) + 1;
			build(left, L, (L+R)/2);
			build(right, (L+R)/2+1, R);
			int p1_idx = st[left];
			int p2_idx = st[right];
			st[p] = (A[p1_idx] <= A[p2_idx]) ? p1_idx : p2_idx;
		}
	}

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
		return (A[p1_idx] <= A[p2_idx]) ? p1_idx : p2_idx;
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
			st[p] = (A[p1_idx] <= A[p2_idx]) ? p1_idx : p2_idx;
		}
	}
	
	SegmentTree(vi &_A){
		A = _A;
		n = A.size();
		st.assign(4*n,0);
		build(1,0,n-1);
	}
	int rmq(int l, int r){
		return rmq(1,0,n-1,l,r);
	}
	void update(int idx, int val){
		A[idx] = val;
		update(1,0,n-1,idx);
	}
};

vi all;
int main(){
	int n;
	cin >> n; // Numbers

	// Clear
	all.clear();
	all.assign(n,0);

	// Input
	int ttmp;
	REP(i,0,n){
		cin >> ttmp;
		all[i] = ttmp;
	}

	SegmentTree st(all);

	// Test
	int l,r;
	int i,v;
	cin >> i >> v;
	all[i] = v; // Must change the original array
	st.update(i,v);
	while(cin >> l >> r){
		int p = st.rmq(l,r);
		cout << p << " is " << all[p] << endl;
	}
	return 0;
}
