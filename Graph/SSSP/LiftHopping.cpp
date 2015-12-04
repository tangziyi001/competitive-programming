/*
 *	UVA 10801
 *	Created by Ziyi Tang
 *	Find shortest paths to each vertex by each elevator. 
 *	Then run Dijkstra on that graph with 60 seconds extra cost.
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

int all[MAXN][MAXN];
vi ele;
vi ter;
priority_queue<pi, vpi, greater<pi> > pq;
int dis[MAXN];
int main(){
	int n,k;
	while(cin >> n >> k){
		// Clear
		ele.clear();
		REP(i,0,MAXN){
			dis[i] = INF;
			REP(j,0,MAXN){
				all[i][j] = INF;
			}
		}
		while(!pq.empty()){
			pq.pop();
		}
		getchar();
		// Initialize
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			ele.push_back(tmp);
		}
		getchar();
		REP(i,0,n){
			ter.clear();
			string line;
			getline(cin,line);
			stringstream ss(line);
			int tmp1 = -1;
			while(ss >> tmp1){
				ter.push_back(tmp1);
			}
			int sz = ter.size();
			REP(j,0,sz-1){
				REP(k,j+1,sz){
					int cost = (ter[k]-ter[j])*ele[i];
					all[ter[j]][ter[k]] = min(all[ter[j]][ter[k]], cost);
					all[ter[k]][ter[j]] = min(all[ter[k]][ter[j]], cost);
					//cout << cost << endl;
				}
			}
		}

		// Source
		pq.push(make_pair(0,0));
		dis[0] = 0;
		
		// Begin
		while(!pq.empty()){
			pi now = pq.top(); pq.pop();
			int d = now.first; 
			int u = now.second;
			if(d > dis[u])
				continue;
			//cout << d << endl;
			REP(i,0,MAXN){
				if(all[u][i] == INF)
					continue;
				else{
					if(dis[u] + all[u][i] + 60 < dis[i]){
						dis[i] = dis[u] + all[u][i] + 60;
						pq.push(make_pair(dis[i], i));
					}
				}
				
			}
		}
		if(0 == k){
			cout << 0 << endl;
		}
		else if(dis[k] == INF){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << dis[k]-60 << endl;
		}
		//Test
		// REP(i,0,MAXN){
		// 	cout << dis[i] << endl;
		// }
	}

	return 0;
}
