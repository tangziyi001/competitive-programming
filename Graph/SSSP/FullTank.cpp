/*
 *	Nordic Collegiate Programming Contest 2007
 *	Created by Ziyi Tang
 *	2D Dijkstra. Use a dp table to keep track of the current place and current gas remained
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
#define MAXN 1005
#define MOD 1000000007

vi p;
vvpi all;
int n,m;
int dp[MAXN][105]; // Idx, Gas Remained
struct State{
	int idx, gas;
	State() : idx(0), gas(0) {}
	State(int idx_, int gas_) : idx(idx_), gas(gas_) {}
	bool operator < (const State& tmp) const {
		if(gas == tmp.gas)
			return idx < tmp.idx;
		return gas < tmp.gas;
	}
};
priority_queue<pair<int,State> > pq;
int main(){
	cin >> n >> m;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	all.assign(n,vpi(0,make_pair(0,0)));
	REP(i,0,m){
		int sta, ter, cost;
		cin >> sta >> ter >> cost;
		all[sta].push_back(make_pair(ter,cost));
		all[ter].push_back(make_pair(sta,cost));
	}
	int q;
	cin >> q;
	REP(i,0,q){
		int c,s,e;
		cin >> c >> s >> e;
		FILL(dp, INF);
		pq.push(make_pair(0, State(s,0)));
		dp[s][0] = 0;
		while(!pq.empty()){
			State now = pq.top().second;
			int cost = -pq.top().first;
			//cout << now.idx << " " << now.gas << " " << cost << endl;
			pq.pop();
			if(cost > dp[now.idx][now.gas]) continue;
			// Add one gas
			if(now.gas < c){
				if(dp[now.idx][now.gas+1] > cost+p[now.idx]){
					dp[now.idx][now.gas+1] = cost+p[now.idx];
					pq.push(make_pair(-(cost+p[now.idx]), State(now.idx ,now.gas+1)));
				}
			}
			// Go to next reachable place
			int tsz = all[now.idx].size();
			REP(i,0,tsz){
				int nxtDis = all[now.idx][i].second;
				if(now.gas >= nxtDis){
					if(dp[all[now.idx][i].first][now.gas-nxtDis] > cost){
						dp[all[now.idx][i].first][now.gas-nxtDis] = cost;
						pq.push(make_pair(-cost, State(all[now.idx][i].first, now.gas-nxtDis)));
					}
				}
			}
		}
		if(dp[e][0] >= INF)
			cout << "impossible" << endl;
		else
			cout << dp[e][0] << endl;
	}
	return 0;
}