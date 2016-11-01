/*
 *	Dijkstra Template
 *	Created by Ziyi Tang
 *	O(V+E)
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

vvpi all;
priority_queue<pi, vpi, greater<pi> > pq;
int dis[MAXN];
int source = -1;
int n,m;
void init(){
	// Clear
	all.clear();
	REP(i,0,n){
		dis[i] = INF;
	}
	while(!pq.empty()){
		pq.pop();
	}
}
int Dijkstra(int s, int t){
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
	return dis[t];
}
int main(){
	
	cin >> n >> m;
	
	// Initialize
	vpi mtmp;
	all.assign(n,mtmp);
	int sta,ter,cost;
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		all[sta].push_back(make_pair(ter,cost));
	}

	// Source
	cin >> source;
	

	// Test
	// REP(i,0,n){
	// 	cout << dis[i] << endl;
	// }
	


	return 0;
}
