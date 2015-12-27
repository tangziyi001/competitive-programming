/*
 *	UVA 11235
 *	Created by Ziyi Tang
 *	Segment Tree: Pack identical numbers into one node with value equals to the amount of that number.
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

vi all;
vi look;
int st[4*MAXN+1];
int n,q;

void build(int p, int L, int R){
	if(L == R){
		st[p] = L;
	}
	else{
		int left = p << 1;
		int right = (p << 1) + 1;
		build(left, L, (L+R)/2);
		build(right, (L+R)/2+1, R);
		int p1 = st[left];
		int p2 = st[right];
		st[p] = (all[p1] >= all[p2]) ? p1 : p2;
	}

}

int rmq(int p, int L, int R, int l, int r){
	if(l > R || r < L)
		return -1;
	if(L >= l && R <= r)
		return st[p];
	int left = p << 1;
	int right = (p << 1) + 1;
	int p1 = rmq(left, L, (L+R)/2, l, r);
	int p2 = rmq(right, (L+R)/2+1, R, l, r);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (all[p1] >= all[p2]) ? p1 : p2;
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
		int p1 = st[left];
		int p2 = st[right];
		st[p] = (all[p1] >= all[p2]) ? p1 : p2;
	}
}

int main(){
	while(cin >> n && n != 0){
		cin >> q;
		// Clear
		all.clear();
		look.clear();
		FILL(st,0);

		// Input
		int ttmp;
		int now = INF;
		int idx = 0;
		REP(i,0,n){
			cin >> ttmp;
			if(now == INF){
				now = ttmp;
				look.push_back(now);
				all.push_back(1);
				continue;
			}
			if(now == ttmp)
				all[idx]++;
			else{
				now = ttmp;
				look.push_back(now);
				all.push_back(1);
				idx++;
			}
		}
		int sz = all.size();

		// Build
		build(1,0,n-1);

		// Query & Test
		int l,r;
		REP(i,0,q){
			cin >> l >> r;
			int p = rmq(1,0,n-1,l-1,r-1);
			cout <<  << endl;
		}
	}
	return 0;
}
