/*
 *	Articulation Template
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

vvi all; //Unweighted Undirected Graph
int root;
int children;
int p[MAXN];
int nums[MAXN];
int lows[MAXN];
int counter;
int re[MAXN]; // Articulation Points will be set to 1
vpi edges; // Record Articulation Edges
void arti(int now){
	lows[now] = nums[now] = counter;
	counter++;
	int sz = all[now].size();
	REP(i,0,sz){
		int tmp = all[now][i];
		if(nums[tmp] == -1){
			p[tmp] = now;
			if (root == now)
				children++;
			arti(tmp);
			if(lows[tmp] >= nums[now]){
				re[now] = 1;
			}
			if(lows[tmp] > nums[now]){
				edges.push_back(make_pair(now,tmp));
			}
			lows[now] = min(lows[now],lows[tmp]);
		}
		else if(p[now] != tmp){
			lows[now] = min(lows[now], nums[tmp]);
		}
	}
}
int main(){
	int n,m; //vertices, edges
	cin >> n >> m;

	// Clear
	FILL(nums,-1);
	FILL(lows,0);
	FILL(re,0);
	edges.clear();
	all.clear();
	vi tmp;
	all.assign(n,tmp);
	counter = 0;


	// Input n vertices and m edges
	REP(i,0,m){
		int sta,ter;
		cin >> sta >> ter;
		all[sta].push_back(ter);
		all[ter].push_back(sta);
	}

	// Begin
	REP(i,0,n){
		if(nums[i] == -1){
			root = i;
			children = 0;
			arti(i);
			re[root] = (children > 1);
		}
	}
	
	// Test
	REP(i,0,n){
		cout << re[i] << endl;
	}
	return 0;
}
