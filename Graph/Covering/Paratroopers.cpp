/*
 *	POJ 3308
 *	Created by Ziyi Tang
 *	Minimum Vertex Cover => Min Cut Problem
 *	Create bipartite graph. One side are rows and another side are cols.
 * 	Connect two side if there is a paratrooper on an intersection.
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

double res[MAXN][MAXN]; // Adjacency Matrix for Weighted Directed Graph
double f;
int s, t;
vi p; // BFS Spanning Tree

void augment(int v, double minEdge){
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
void init(int s_, int t_){
	// Clear
	p.clear();
	REP(i,0,MAXN) REP(j,0,MAXN) res[i][j] = 0.0;
	s = s_; t = t_;
}

double run(){
	// Begin
	double mf = 0;
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
	return mf;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		int m,n,l;
		cin >> m >> n >> l;
		init(0,m+n+1);
		REP(i,0,m){
			double tmp;
			cin >> tmp;
			res[0][i+1] = log(tmp);
		}
		REP(i,0,n){
			double tmp;
			cin >> tmp;
			res[i+1+m][n+m+1] = log(tmp);
		}
		REP(i,0,l){
			int a,b;
			cin >> a >> b;
			a--;b--;
			res[1+a][m+1+b] = INF;
		}
		double mf = run();
		printf("%.4f\n", exp(mf));
	}
	return 0;
}
