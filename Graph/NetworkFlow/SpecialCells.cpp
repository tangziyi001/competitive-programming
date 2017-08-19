/*
 *	Topcoder 612 Div1 450
 *	Created by Ziyi Tang
 *	MCMF
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
#define MOD 1000000007

template <class Flow = ll, class Cost = ll> 
struct MCMF {
    
    struct Edge {
        int u, v;
        Flow cap, flow;
        Cost cost;
    };
    
    vector<Edge> edges;
    vector<vector<int> > adjlist;
    vector<int> p;
    vector<Cost> dist;
    vector<Flow> pushed;
    
    MCMF(int N) {
        adjlist.resize(N);
        p.resize(N);
        dist.resize(N);
        pushed.resize(N);
    }
    
    void AddEdge(int u, int v, Flow cap, Cost cost) {
        Edge f = { u, v, cap, 0, cost }, b = { v, u, 0, 0, -cost };
        adjlist[u].push_back((int) edges.size()); edges.push_back(f);
        adjlist[v].push_back((int) edges.size()); edges.push_back(b);
    }
    
    bool Dijkstra(int s, int t) {
        fill(p.begin(), p.end(), -1);
        fill(dist.begin(), dist.end(), INF); 
        dist[s] = 0;
        pushed[s] = INF;
        priority_queue<pair<Cost, int> > q; q.push(make_pair(0, s));
        while (!q.empty()) {
            pair<Cost, int> front = q.top(); q.pop();
            Cost d = -front.first; int u = front.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < (int) adjlist[u].size(); i++) {
                int id = adjlist[u][i], to = edges[id].v;
                Cost cost = edges[id].cost;
                if (dist[u] + cost < dist[to] && edges[id].flow < edges[id].cap) {
                    dist[to] = dist[u] + cost;
                    p[to] = id;
                    pushed[to] = min(pushed[u], edges[id].cap - edges[id].flow);
                    q.push(make_pair(-dist[to], to));
                }
            }
        }
        if (p[t] == -1) return false;
        for (int k = p[t]; k != -1; k = p[edges[k].u]) {
            edges[k].flow += pushed[t];
            edges[k^1].flow -= pushed[t];
        }
        return true;
    }
    
    pair<Flow, Cost> Get(int s, int t) {
        for (int i = 0; i < (int) edges.size(); i++)
            edges[i].flow = 0;
        int totalFlow = 0; int totalCost = 0;
        while (Dijkstra(s, t)) {
            totalFlow += pushed[t];
            totalCost += dist[t] * pushed[t];
        }
        return make_pair(totalFlow, totalCost);
    }
};

class SpecialCells {
public:
	int guess(vector <int>, vector <int>);
};

int SpecialCells::guess(vector <int> x, vector <int> y) {
	int n = x.size();
	map<int,int> mmx;
	map<int,int> mmy;
	set<pi> ss;
	REP(i,0,n){
		mmx[x[i]]++;
		ss.insert(make_pair(x[i],y[i]));
	}
	REP(i,0,n){
		mmy[y[i]]++;
	}
	vi all;
	for(auto it = mmx.begin();it != mmx.end(); it++){
		all.push_back(it->first);
	}
	for(auto it = mmy.begin();it != mmy.end(); it++){
		all.push_back(it->first);
	}
	int m = mmx.size()+mmy.size();
	MCMF<ll,ll> mf(m+2);
	for(int i = 0; i < mmx.size(); i++){
		mf.AddEdge(m,i,mmx[all[i]],0);
		for(int j = 0; j < mmy.size(); j++){
			ll cost = 0;
			if(ss.count(make_pair(all[i],all[mmx.size()+j]))) cost = 1;
			mf.AddEdge(i, mmx.size()+j, 1, cost);
		}
	}
	for(int j = 0; j < mmy.size(); j++){
		mf.AddEdge(mmx.size()+j, m+1, mmy[all[mmx.size()+j]], 0);
	}
	return mf.Get(m,m+1).second;
}


//Powered by [KawigiEdit] 2.0!
