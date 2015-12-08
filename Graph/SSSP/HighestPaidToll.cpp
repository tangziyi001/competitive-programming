/*
 *	UVA 10247
 *	Created by Ziyi Tang
 *	Dijkstra on both source and destination. 
 *	Find the maximum cost(u,v) for each edge (u,v)
 *	that satisfies dis[u] + dis_rev[v] + cost(u,v) <= p
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
#define MAXN 10005

vvpi all;
vvpi all_rev;
vector<pair<pi, int> > edges;
priority_queue<pi, vpi, greater<pi> > pq;
int dis[MAXN];
int dis_rev[MAXN];
int source = -1;

int main(){

	int test;
	cin >> test;
	REP(tt,0,test){
		// Clear
		int n,m,s,t,p;
		cin >> n >> m >> s >> t >> p;
		vpi ttmp;
		all_rev.clear();
		all.clear();
		edges.clear();
		all_rev.assign(n,ttmp);
		all.assign(n,ttmp);
		REP(i,0,n){
			dis[i] = INF;
			dis_rev[i] = INF;
		}
		REP(i,0,m){
			int u,v,c;
			cin >> u >> v >> c;
			edges.push_back(make_pair(make_pair(u-1,v-1),c));
			all[u-1].push_back(make_pair(v-1,c));
			all_rev[v-1].push_back(make_pair(u-1,c));
		}

		// First
		pq.push(make_pair(0,s-1));
		dis[s-1] = 0;
		
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

		// Second
		pq.push(make_pair(0,t-1));
		dis_rev[t-1] = 0;
		
		// Begin
		while(!pq.empty()){
			pi now = pq.top(); pq.pop();
			int d = now.first; 
			int u = now.second;
			if(d > dis_rev[u])
				continue;
			int nsz = all_rev[u].size();
			REP(i,0,nsz){
				pi tmp = all_rev[u][i];
				if(dis_rev[u] + tmp.second < dis_rev[tmp.first]){
					dis_rev[tmp.first] = dis_rev[u] + tmp.second;
					pq.push(make_pair(dis_rev[tmp.first], tmp.first));
				}
			}
		}

		int maxp = -1;
		int sz = edges.size();
		REP(i,0,sz){
			int u = edges[i].first.first;
			int v = edges[i].first.second;
			//cout << dis[u] << " " << dis_rev[v] << " " << edges[i].second << endl;
			if(dis[u] + dis_rev[v] + edges[i].second <= p){
				maxp = max(maxp,edges[i].second);
			}
		}
		cout << maxp << endl;
		// Test
		// REP(i,0,n){
		// 	cout << dis[i] << endl;
		// }
	}


	return 0;
}
