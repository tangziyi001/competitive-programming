/*
 *	Bellman Ford’s algorithm
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

int dis[MAXN];
vvpi all;
int main(){
	int n,m;
	cin >> n >> m;

	// Clear
	all.clear();
	REP(i,0,n){
		dis[i] = INF;
	}
	vpi ttmp;
	all.assign(n,ttmp);

	// Initialize
	int sta,ter,cost;
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		all[sta].push_back(make_pair(ter,cost));
	}

	// Begin
	REP(i,0,n-1){
		REP(j,0,n){
			int sz = all[j].size();
			REP(k,0,sz){
				pi tmp = all[j][k];
				dis[tmp.first] = min(dis[tmp.first], dis[j] + tmp.second);
			}
		}
	}

	// Check Negative Cycle
	bool nega = false; // True if there is any negative cycle
	REP(i,0,n){
		int sz = all[i].size();
		REP(j,0,sz){
			pi tmp = all[i][j];
			if (dis[tmp.first] > dis[i] + tmp.second){
				nega = true; break;
			}
		}
	}

	return 0;
}
