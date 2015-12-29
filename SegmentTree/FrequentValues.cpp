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
#define MAXN 100005

vi cont;
vi value;
vi num;
vi Left;
vi Right;
vi all;
int st[4*MAXN+1];
int n,q;

void build(int p, int L, int R){
	if(L == R){
		st[p] = cont[L];
	}
	else{
		int left = p << 1;
		int right = (p << 1) + 1;
		build(left, L, (L+R)/2);
		build(right, (L+R)/2+1, R);
		int p1 = st[left];
		int p2 = st[right];
		st[p] = (p1 >= p2) ? p1 : p2;
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
	return (p1 >= p2) ? p1 : p2;
}


int main(){
	while(cin >> n && n != 0){
		cin >> q;
		// Clear
		cont.clear();
		value.clear();
		num.clear();
		Left.clear();
		Right.clear();
		all.clear();
		FILL(st,0);

		// Input
		int ttmp;
		int now = INF;
		int idx = 0;
		int tleft = 0;
		int tright = n-1;
		REP(i,0,n){
			cin >> ttmp;
			all.push_back(ttmp);
			if(now == INF){
				now = ttmp;
				value.push_back(now);
				cont.push_back(1);
				num.push_back(idx);
				Left.push_back(tleft);
				continue;
			}
			if(now == ttmp){
				cont[idx]++;	
			}
			else{
				now = ttmp;
				value.push_back(now);
				cont.push_back(1);
				idx++;
				tleft = i;
			}
			num.push_back(idx);
			Left.push_back(tleft);
		}
		now = num[n-1];
		Right.assign(n,0);
		Right[n-1] = n-1;
		tright = n-1;
		for(int i = n-2; i >= 0; i--){
			if(num[i] != now){
				now = num[i];
				tright = i;
			}
			Right[i] = tright;
		}

		// Test
		// REP(i,0,value.size()){
		// 	cout << value[i] << " ";
		// }
		// cout << endl;
		// REP(i,0,cont.size()){
		// 	cout << cont[i] << " ";
		// }
		// cout << endl;
		// REP(i,0,num.size()){
		// 	cout << num[i] << " ";
		// }
		// cout << endl;
		// REP(i,0,Left.size()){
		// 	cout << Left[i] << " ";
		// }
		// cout << endl;
		// REP(i,0,Left.size()){
		// 	cout << Right[i] << " ";
		// }
		// cout << endl;
		// REP(i,0,all.size()){
		// 	cout << all[i] << " ";
		// }
		// Build
		int sz = cont.size();
		build(1,0,sz-1);

		// Query & Test
		int l,r;
		REP(i,0,q){
			cin >> l >> r;
			l--;r--;
			int re;
			if(all[l] == all[r]){
				re = r - l + 1;
			}
			else{
				int maxp = -INF;
				maxp = max(Right[l] - l + 1, r - Left[r] + 1);
				if(num[l] + 1 <= num[r] - 1)
					maxp = max(maxp, rmq(1,0,sz-1, num[l] + 1, num[r] - 1));
				re = maxp;
			}
			cout << re << endl;
		}
	}
	return 0;
}
