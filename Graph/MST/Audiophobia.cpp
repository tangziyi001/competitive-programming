/*
 *	UVA 10048
 *	Created by Ziyi Tang
 *	Minimax the graph by Kruskal and do tree traversal
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
vvpi tree;
int m,n,q;
vi mark;
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

int dfs(int sta, int ter){
	if(sta == ter)
		return 0;
	mark[sta] = 1;
	int sz = tree[sta].size();
	int maxp = -INF;
	REP(i,0,sz){
		pi tmp = tree[sta][i];
		if(mark[tmp.first] == 0){
			int can = dfs(tmp.first,ter);
			if(can == -INF) continue;
			maxp = max(can, tmp.second);
		}
	}
	return maxp;
}
int main(){
	int test = 0;
	while(cin >> n >> m >> q && (n!=0||m!=0||q!=0)){ // The number of edges
		test++;
		if(test > 1)
			cout << endl;
		// Clear
		tree.clear();
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
		vpi ttmp;
		tree.assign(n,ttmp);
		REP(i,0,m){
			pair<int,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				//cout << now.second.first << " " << now.second.second << " " << now.first << endl;
				tree[now.second.first].push_back(make_pair(now.second.second,now.first));
				tree[now.second.second].push_back(make_pair(now.second.first,now.first));
				total_cost += now.first;
			}
		}
		printf("Case #%d\n",test);
		REP(i,0,q){
			int sta,ter,maxp;
			cin >> sta >> ter;
			if(!isSameSet(sta-1,ter-1))
				cout << "no path" << endl;
			else{
				maxp = -INF;
				mark.assign(n,0);
				maxp = dfs(sta-1,ter-1);
				cout << maxp << endl;
			}
		}
		// Output
		
	}
	return 0;
}

