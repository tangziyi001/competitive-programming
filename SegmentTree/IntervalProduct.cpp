/*
 *	UVA 12532
 *	Created by Ziyi Tang
 *	Use Segment Tree to record the sign of each interval
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
#define MAXN 100005

vi all;
int st[4*MAXN+1];
int n,m;

void build(int p, int L, int R){
	if(L == R){
		if(all[L] > 0) st[p] = 1;
		else if(all[L] < 0) st[p] = -1;
		else st[p] = 0;
	}
	else{
		int left = p << 1;
		int right = (p << 1) + 1;
		build(left, L, (L+R)/2);
		build(right, (L+R)/2+1, R);
		int sign = st[left] * st[right];
		if(sign > 0) st[p] = 1;
		else if(sign < 0) st[p] = -1;
		else st[p] = 0;
	}

}

int rmq(int p, int L, int R, int l, int r){
	if(l > R || r < L)
		return 1;
	if(L >= l && R <= r)
		return st[p];
	int left = p << 1;
	int right = (p << 1) + 1;
	int sign = rmq(left, L, (L+R)/2, l, r)*rmq(right, (L+R)/2+1, R, l, r);
	if(sign > 0) return 1;
	else if(sign < 0) return -1;
	else return 0;
}

void update(int p, int L, int R, int i){
	if(L == R){
		if(all[i] > 0) st[p] = 1;
		else if(all[i] < 0) st[p] = -1;
		else st[p] = 0;
	}
	else{
		int left = p << 1;
		int right = (p << 1) + 1;
		if(i <= (L+R)/2)
			update(left, L, (L+R)/2, i);
		else
			update(right, (L+R)/2+1, R, i);
		int sign = st[left] * st[right];
		if(sign > 0) st[p] = 1;
		else if(sign < 0) st[p] = -1;
		else st[p] = 0;
	}
}

int main(){
	while(cin >> n >> m){
		// Clear
		all.clear();
		FILL(st,0);

		// Input
		int ttmp;
		REP(i,0,n){
			cin >> ttmp;
			all.push_back(ttmp);
		}

		// Build
		build(1,0,n-1);

		// Query & Test
		REP(i,0,m){
			char s;
			int l,r;
			cin >> s >> l >> r;
			if(s == 'C'){
				all[l-1] = r;
				update(1,0,n-1,l-1);
			}
			else{
				int p = rmq(1,0,n-1,l-1,r-1);
				if(p > 0) cout << "+";
				else if(p < 0) cout << "-";
				else cout << "0";
			}
		}
		cout << endl;
	}
	
	return 0;
}
