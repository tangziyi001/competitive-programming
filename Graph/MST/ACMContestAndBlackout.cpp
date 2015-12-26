/*
 *	UVA 10060
 *	Created by Ziyi Tang
 *	Second MST. Check Connectivity
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

int p[MAXN];
vector<pair<int, pi> >all; // Undirected Weighted Graph
int n,m;

int findParent(int i){
	if(p[i] == i)
		return i;
	return p[i] = findParent(p[i]);
}
bool isSameSet(int i, int j){
	int p1 = findParent(i);
	int p2 = findParent(j);
	return p1 == p2;

}
void unionSet(int i, int j){
	if(!isSameSet(i,j))
		p[findParent(i)] = findParent(j);
}
int main(){
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m; // The number of edges
		// Clear
		all.clear();
		REP(i,0,n){
			p[i] = i;
		}

		// Input Edge Cost
		int u,v,w;
		REP(i,0,m){
			cin >> u >> v >> w;
			all.push_back(make_pair(w, make_pair(u-1,v-1)));
		}
		sort(all.begin(),all.end());
		int total_cost = 0;
		vector<int> routes;
		REP(i,0,m){
			pair<int,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				total_cost += now.first;
				routes.push_back(i);
			}
		}
		int minp = INF;
		int sz = routes.size();
		REP(i,0,sz){
			int second_cost = 0;
			int exlu = routes[i];
			REP(k,0,n){
				p[k] = k;
			}	
			REP(j,0,m){
				if(j == exlu)
					continue;
				pair<int,pi> now = all[j];
				if(!isSameSet(now.second.first, now.second.second)){
					unionSet(now.second.first, now.second.second);
					second_cost += now.first;
				}
			}
			int count = findParent(0);
			int flag = 1;

			// Check Connectivity
			REP(i,0,n){
				if(count != findParent(i)){
					flag = 0;
					break;
				}
			}
			if(flag == 1)
				minp = min(minp,second_cost);
		}

	// Output
	cout << total_cost << " " << minp << endl;
	}
	
	return 0;
}
