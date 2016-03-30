/*
 *	USACO 2014 US Open, Silver 2
 *	Coded by Ziyi Tang
 *	Dijkstra finding the shortest path from the end point to every other points.
 *	Keep track of the parent of each vertex
 *	Use BFS to traverse and update the minimum number until reaching the end point.
 *
 *	A nicer way is to rebuild the graph based on the original graph: 
 *	If dist[tmp] - dist[now] is equal to the actual edge length of edge (a,b), 
 *	then edge (a,b) is on a shortest path to N, and our GPS will not complain on this edge. 
 *	Otherwise, we add +1 to the length of (a,b) in G.
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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

vvpi ori;
vvpi all1;
vvpi all2;
vi dist1;
vi dist2;
vi par1;
vi par2;
priority_queue<pi> pq; 
vi res;
int n,m;

void dijkstra(vvpi& all, vi& dist, vi& p){
	int s = n-1, t = 0;
	dist[s] = 0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		pi now = pq.top();pq.pop();
		int d = -now.first;
		int pos = now.second;
		if(d > dist[pos]) continue;
		int sz = all[pos].size();
		REP(i,0,sz){
			int tmp = all[pos][i].first;
			int dis = all[pos][i].second;
			if(dist[pos] + dis < dist[tmp]){
				dist[tmp] = dis + dist[pos];
				p[tmp] = pos;
				pq.push(make_pair(-dist[tmp], tmp));
			}
		}
	}
	// REP(i,0,n)
	// cout << dist[i] << " ";
	// cout << endl;
	// REP(i,0,n)
	// cout << p[i] << " ";
	// cout << endl;

}
void bfs(){
	res[0] = 0;
	queue<int> qq;
	qq.push(0);
	while(!qq.empty()){
		int now = qq.front();qq.pop();
		int sz = ori[now].size();
		int a = par1[now];
		int b = par2[now];
		REP(i,0,sz){
			int tmp = ori[now][i].first;
			if(tmp == a && tmp == b){
				if(res[now] < res[tmp]){
					res[tmp] = res[now];
					qq.push(tmp);
				}
			}
			else if(tmp == a || tmp == b){
				if(res[now]+1 < res[tmp]){
					res[tmp] = res[now]+1;
					qq.push(tmp);
				}
			}
			else{
				if(res[now]+2 < res[tmp]){
					res[tmp] = res[now]+2;
					qq.push(tmp);
				}
			}
		}
	}
}
int main(){
	freopen("gpsduel.in", "r", stdin);
  	freopen("gpsduel.out", "w", stdout);
	cin >> n >> m;
	dist1.assign(n,INF);
	dist2.assign(n,INF);
	res.assign(n,INF);
	par1.assign(n,-1);
	par2.assign(n,-1);
	vpi ttmp(0,make_pair(0,0));
	all1.assign(n,ttmp);
	all2.assign(n,ttmp);
	ori.assign(n,ttmp);

	REP(i,0,m){
		int sta,ter,c1,c2;
		cin >> sta >> ter >> c1 >> c2;
		ori[sta-1].push_back(make_pair(ter-1, 1));
		all1[ter-1].push_back(make_pair(sta-1, c1));
		all2[ter-1].push_back(make_pair(sta-1, c2));
		//cout << sta << ter << endl;
	}
	dijkstra(all1,dist1,par1);
	dijkstra(all2,dist2,par2);

	bfs();
	cout << res[n-1] << endl;
	return 0;
}
