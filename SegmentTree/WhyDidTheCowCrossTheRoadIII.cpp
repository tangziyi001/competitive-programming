/*
 *	USACO 2017 February Contest, Gold 3
 *	Created by Ziyi Tang
 *	Binary Index Tree
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
#define MAXN 100010

int ft[MAXN+1];
int sz;
vi all;

struct BITree{
	// Start Index 1
	int n_;
	int bt[MAXN];
	BITree(int n) : n_(n) {
		FILL(bt,0);
	}
	int rsq(int b){
		int sum = 0;
		for(; b; b-=(b&-b)){
			sum+=bt[b];
		}
		return sum;
	}
	int rsq(int a, int b){
		return rsq(b)-rsq(a);
	}
	void update(int i, int val){
		for(; i <= n_; i+=(i&-i)){
			bt[i] += val;
		}
	}
	void clear(){
		FILL(bt,0);
	}
};

map<int,int> mm;
int main(){
	freopen("circlecross.in", "r", stdin);
  	freopen("circlecross.out", "w", stdout);
	int n;
	cin >> n; // Numbers

	// Clear
	all.clear();
	all.assign(2*n,0);

	// Input
	int ttmp;
	REP(i,0,2*n){
		cin >> ttmp;
		all[i] = ttmp;
		if(!mm.count(ttmp)){
			mm[ttmp] = -1;
		} else mm[ttmp] = i;
	}
	BITree st(2*n);
	int cont = 0;
	REP(i,0,2*n){
		int now = all[i];
		int end = mm[now];
		if(end == i) continue;
		cont += st.rsq(i,end);
		//cout << st.rsq(i,end);
		st.update(end,1);
	}
	cout << cont << endl;
	return 0;
}
