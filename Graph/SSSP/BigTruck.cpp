/*
 *	2016 ICPC North American Qualifier Contest
 *	Created by Ziyi Tang
 *	Dijkstra with Multiple Weights
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 105
#define MOD 1000000007

int n,m;
vi p;
vvpi all;
struct Edge {
	int dis, num;
	Edge(){}
	Edge(int d_, int n_) : dis(d_), num(n_) {}
	bool operator < (const Edge& tmp) const {
		if(dis == tmp.dis)
			return num < tmp.num;
		return dis > tmp.dis;
	}
};
vector<Edge> dp;
priority_queue<pair<Edge, int> > qq;
int main(){
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	dp.assign(n, Edge(INF,-1));
	all.assign(n,vpi(0,pi(0,0)));
	cin >> m;
	REP(i,0,m){
		int sta,ter,dis;
		cin >> sta >> ter >> dis;
		sta--;ter--;
		all[sta].push_back(make_pair(ter, dis));
		all[ter].push_back(make_pair(sta, dis));
	}
	dp[0] = Edge(0,p[0]);
	qq.push(make_pair(Edge(0,p[0]), 0));
	while(!qq.empty()){
		Edge now = qq.top().first;
		int idx = qq.top().second;
		qq.pop();
		int tsz = all[idx].size();
		if(now < dp[idx]) continue;
		REP(i,0,tsz){
			int nxt = all[idx][i].first;
			int dis = all[idx][i].second;
			if(dp[nxt] < Edge(now.dis+dis, now.num+p[nxt])){
				dp[nxt] = Edge(now.dis+dis, now.num+p[nxt]);
				qq.push(make_pair(Edge(now.dis+dis, now.num+p[nxt]), nxt));
			}
		}
	}
	if(dp[n-1].dis != INF)
		cout << dp[n-1].dis << " " << dp[n-1].num << endl;
	else cout << "impossible" << endl;
	return 0;
}