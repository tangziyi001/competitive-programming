/*
 *	UVA 437
 *	Created by Ziyi Tang
 *	DFS on DAG with DP
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
#define MAXN 1000
#define MOD 1000000007

vvi all;
vvpi graph;
int dp[120];
int n;

int dfs(int idx){
	if(dp[idx] != -1) return dp[idx];
	vpi now = graph[idx];
	if(now.size() == 0){
		return dp[idx] = all[idx][2];
	} else {
		int maxp = 0;
		int tsz = now.size();
		REP(i,0,tsz){
			maxp = max(maxp, now[i].second + dfs(now[i].first));
		}
		return dp[idx] = maxp;
	}
}
int main(){
	int test = 0;
	while(cin >> n && n != 0){
		test++;
		all.clear();
		graph.clear();
		FILL(dp, -1);
		REP(i,0,n) {
			vi tmp(3,0); // min base1, max base2, height
			int a,b,c;
			cin >> a >> b >> c;
			tmp[0] = min(a,b);
			tmp[1] = max(a,b);
			tmp[2] = c;
			all.push_back(tmp);
			tmp[0] = min(a,c);
			tmp[1] = max(a,c);
			tmp[2] = b;
			all.push_back(tmp);
			tmp[0] = min(b,c);
			tmp[1] = max(b,c);
			tmp[2] = a;
			all.push_back(tmp);
		}
		int sz = all.size();
		graph.assign(sz,vpi(0,make_pair(0,0)));
		REP(i,0,sz){
			vi now = all[i];
			REP(j,0,sz) if(i != j){
				if(now[0] < all[j][0] && now[1] < all[j][1]){
					graph[i].push_back(make_pair(j, now[2]));
				}
			}
		}
		int maxp = 0;
		REP(i,0,sz){
			maxp = max(maxp, dfs(i));
		}
		printf("Case %d: maximum height = %d\n", test, maxp);
	}
	return 0;
}