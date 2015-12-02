/*
 *	UVA 01112
 *	Created by Ziyi Tang
 *	Dijkstra on the ending point
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
#define MAXN 105

vvpi all;
priority_queue<pi, vpi, greater<pi> > pq;
int dis[MAXN];

int main(){
	int test;
	cin >> test;
	REP(i,0,test){
		if(i != 0)
			cout << endl;
		int n,e,t,m;
		cin >> n >> e >> t >> m;
		// Clear
		all.clear();
		REP(i,0,n){
			dis[i] = INF;
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
			// Reverse
			all[ter-1].push_back(make_pair(sta-1,cost));
		}

		// Source
		pq.push(make_pair(0,e-1));
		dis[e-1] = 0;
		
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
		int nums = 0;

		//Test
		REP(i,0,n){
			if(dis[i] <= t)
				nums++;
		}
		cout << nums << endl;
	}


	return 0;
}
