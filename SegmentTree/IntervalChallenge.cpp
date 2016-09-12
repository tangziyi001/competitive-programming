/*
 *	SPOJ INTERVA2
 *	Created by Ziyi Tang
 *	Sort all intervals according to the right end point, and then the left point.
 *	Loop over the intervals and use BITree to keep track of how many left end point
 *	is smaller. 
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
#define MAXN 200010
#define MOD 1000000007

int re[MAXN];
struct node{
	int x,y;
	int idx_;
	int tx;
} all[MAXN];
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
	void update(int i, int val){
		for(; i <= n_; i+=(i&-i)){
			bt[i] += val;
		}
	}
	void clear(){
		FILL(bt,0);
	}
};
int compy(node aa, node bb){
	if(aa.y == bb.y)
		return aa.x < bb.x;
	return aa.y > bb.y;
}
int compx(node aa, node bb){
	return aa.x < bb.x;
}
int main(){
	BITree bit = BITree(MAXN);
	int n;
	while(scanf("%d", &n) != EOF && n != 0){
		FILL(re,0);
		bit.clear();
		REP(i,0,n){
			int a,b;
			scanf("%d %d",&a,&b);
			all[i].x = a;
			all[i].y = b;
			all[i].idx_ = i;
		}
		sort(all, all+n, compx);
		int now = 1;
		all[0].tx = now;
		REP(i,1,n){
			if(all[i].x == all[i-1].x){
				all[i].tx = all[i-1].tx;
			} else {
				all[i].tx = ++now;
			}
		}
		sort(all, all+n, compy);
		REP(i,0,n){
			if(i != 0 && all[i].x == all[i-1].x && all[i].y == all[i-1].y){
				re[all[i].idx_] = re[all[i-1].idx_];
				bit.update(all[i].tx, 1);
				continue;
			}
			re[all[i].idx_] = bit.rsq(all[i].tx);
			bit.update(all[i].tx, 1);
		}
		REP(i,0,n){
			if(i != 0) printf(" ");
			printf("%d", re[i]);
		}
		printf("\n");
	}
	return 0;
}