/*
 *	673C - Bear and Colors
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
#define MAXN 5005
#define MOD 1000000007

vi all;
vi re;
vi A;
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
			st[p] = (A[p1_idx] >= A[p2_idx]) ? p1_idx : p2_idx;
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
		return (A[p1_idx] >= A[p2_idx]) ? p1_idx : p2_idx;
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
			st[p] = (A[p1_idx] >= A[p2_idx]) ? p1_idx : p2_idx;
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
int main(){
	int n;
	cin >> n;
	re.assign(n,0);
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp-1);
	}
	REP(i,0,n){
		A.assign(n,0);
		SegmentTree st(A);
		REP(j,i,n){
			int now = all[j];
			A[now]++;
			st.update(now,A[now]);
			int maxp = st.rmq(0,n-1);
			re[maxp]++;
		}
	}
	REP(i,0,n){
		if(i != 0) cout << " ";
		cout << re[i]; 
	}
	cout << endl;
	return 0;
}