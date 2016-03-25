/*
 *	Edmonds Karp's Algorithm for Network Flow Problem
 *	Created by Ziyi Tang
 *	Basic Network Flow. Notice that there may be more than one edges
 *	between two vertices
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

int res[MAXN][MAXN]; // Adjacency Matrix
ll mf; // Max Flow
int f, s, t;
vi p; // BFS Spanning Tree

void augment(int v, int minEdge){
	if(v == s){
		f = minEdge;
		return ;
	}
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main(){

	// Setup res, s and t
	int n,m;
	int test = 0;
	while(cin >> n && n != 0){
		p.clear();
		FILL(res,0);
		cin >> s >> t >> m;
		s--;t--;
		test++;
		REP(i,0,m){
			int sta,ter,cost;
			cin >> sta >> ter >> cost;
			res[sta-1][ter-1] += cost; // Notice that two vertices may have multiple edges
			res[ter-1][sta-1] += cost;
		}
		// Begin
		mf = 0LL;
		while(1){
			f = 0;
			// Create the spanning path
			vi dist(MAXN,INF);
			queue<int> qq;
			dist[s] = 0;
			qq.push(s);
			p.assign(MAXN, -1);
			while(!qq.empty()){
				int u = qq.front();qq.pop();
				if(u == t) break; // Stop if reaching the sink t
				for(int v = 0; v < MAXN; v++){
					if(res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						qq.push(v); 
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if(f == 0) break;
			mf+=f;
		}
		printf("Network %d\n", test);
		printf("The bandwidth is %lld.\n", mf);
		printf("\n");
	}
	return 0;
}
