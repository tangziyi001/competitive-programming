/*
 *	Edmonds Karp's Algorithm
 *	Created by Ziyi Tang
 *	O(V^3 E)
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

int res[MAXN][MAXN]; // Adjacency Matrix for Weighted Directed Graph
int mf; // Max Flow
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
	// Clear
	p.clear();
	FILL(res,0);
	// Setup res, s and t

	// Begin
	mf = 0;
	while(1){
		f = 0;
		vi dist(MAXN,INF);
		dist[s] = 0;
		queue<int> qq;
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
	cout << mf << endl;
	return 0;
}
