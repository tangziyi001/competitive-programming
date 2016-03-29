/*
 *	UVA 10480
 *	Created by Ziyi Tang
 *	Min Cut Problem. Trace the cut edges by take zero edges from the 
 *	residue graph and check if the two end points are in different set.
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
#define MAXN 55

int res[MAXN][MAXN]; // Adjacency Matrix for Weighted Directed Graph
int ori[MAXN][MAXN];
int mf; // Max Flow
int f, s, t;
int n,m;
vi p; // BFS Spanning Tree
vector<pi> edges;
int group[MAXN];
int pass[MAXN];
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

void dfs(int pos){
	pass[pos] = 0;
	group[pos] = 1;
	REP(i,0,n){
		if(pos != i && pass[i] == -1 && ori[pos][i] != -1 && res[pos][i] != 0){
			dfs(i);
		}
	}
}
int main(){
	while(cin >> n >> m && ((n!=0) || (m!=0))){
		// Clear
		p.clear();
		edges.clear();
		FILL(res,0);
		FILL(pass,-1);
		FILL(ori,-1);
		FILL(group,0);
		// Setup res, s and t
		REP(i,0,m){
			int sta,ter,cost;
			cin >> sta >> ter >> cost;
			ori[sta-1][ter-1] = cost;
			ori[ter-1][sta-1] = cost;
			res[sta-1][ter-1] = cost;
			res[ter-1][sta-1] = cost;
		}
		s = 0;
		t = 1;
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
		dfs(0);
		REP(i,0,n) REP(j,0,n){
			if(ori[i][j] != -1 && res[i][j] == 0 && (group[i] != group[j]))
				edges.push_back(make_pair(i,j));
		}
		int sz = edges.size();
		REP(i,0,sz){
			cout << edges[i].first+1 << " " << edges[i].second+1 << endl;
		}
		cout << endl;
	}
	return 0;
}
