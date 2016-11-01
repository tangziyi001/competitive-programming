/*
 *  POJ 3686
 *  Created by Ziyi Tang
 *  MCMF
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
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 2600
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

int main(){
    int test; cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        MCMF<> mcmf(n+m*n+2);
        REP(i,0,n){
            // Source to Toys
            mcmf.AddEdge(0,i+1,1,0);
            // Toys to n potential slots of each workshop 
            REP(j,0,m){
                int tmp;
                cin >> tmp;
                REP(k,0,n)
                    mcmf.AddEdge(i+1,n+1+j*n+k,1,tmp*(k+1));
            }
        }
        // n potential slots of each workshop to Sink
        REP(i,0,m) REP(j,0,n){
            mcmf.AddEdge(n+1+i*n+j, n+m*n+1, 1, 0);
        }
        ll ans = mcmf.Get(0,n+m*n+1).second;
        printf("%.6f\n", 1.0*ans/n+1e-9);
    }
    return 0;
}
