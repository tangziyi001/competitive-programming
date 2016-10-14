/*
 *	POJ 2352
 *	Created by Ziyi Tang
 *	Use BIT to keep track of 2D range frequency
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
#define MAXN 32100
#define MOD 1000000007

struct BST{
	int n_;
	int bt[MAXN+1];
	// starting from 1
	BST(int n){
		n_ = n;
		FILL(bt, 0);
	}
	int rsq(int idx){
		int re = 0;
		for(; idx; idx-=(idx&-idx)){
			re += bt[idx];
		}
		return re;
	}
	void update(int idx, int val){
		for(; idx <= n_; idx+=(idx&-idx)){
			bt[idx] += val;
		}
	}
};
vector<pi> all;
vi re(MAXN, 0);
int main(){
	int n;
	scanf("%d", &n);
	BST xx = BST(MAXN);
	REP(i,0,n){
		int x,y;
		scanf("%d %d", &x, &y);
		x++;y++;
		all.push_back(make_pair(x,y));
	}
	REP(i,0,n){
		pi now = all[i];
		int X = xx.rsq(now.first);
		re[X]++;
		xx.update(now.first, 1);
	}
	REP(i,0,n){
		printf("%d\n", re[i]);
	}
	return 0;
}