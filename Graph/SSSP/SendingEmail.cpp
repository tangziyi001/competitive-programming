/*
 *	UVA 10986
 *	Created by Ziyi Tang
 *	Basic Dijkstra
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
#define MAXN 20010

vvpi all;
priority_queue<pi, vpi, greater<pi> > pq;
ll dis[MAXN];
int source = -1;

int main(){
	int test;
	cin >> test;
	REP(k,1,test+1){
		int n,m,s,t;
		cin >> n >> m >> s >> t;
		// Clear
		all.clear();
		REP(i,0,n){
			dis[i] = INFL;
		}
		while(!pq.empty()){
			pq.pop();
		}

		// Initialize
		vpi mtmp;
		all.assign(n,mtmp);
		int sta,ter,cost;
		REP(i,0,m){
			cin >> sta >> ter >> cost;
			all[sta].push_back(make_pair(ter,cost));
			all[ter].push_back(make_pair(sta,cost));
		}

		// Source
		pq.push(make_pair(0,s));
		dis[s] = 0;
		
		// Begin
		while(!pq.empty()){
			pi now = pq.top(); pq.pop();
			int d = now.first; 
			int u = now.second;
			if(d > dis[u])
				continue;
			int nsz = all[u].size();
			REP(i,0,nsz){
				pi tmp = all[u][i];
				if(dis[u] + tmp.second < dis[tmp.first]){
					dis[tmp.first] = dis[u] + tmp.second;
					pq.push(make_pair(dis[tmp.first], tmp.first));
				}
			}
		}

		// Test
		// REP(i,0,n){
		// 	cout << dis[i] << endl;
		// }
		if(dis[t] == INFL)
			printf("Case #%d: unreachable\n",k);
		else
			printf("Case #%d: %lld\n", k, dis[t]);
	}
	


	return 0;
}
