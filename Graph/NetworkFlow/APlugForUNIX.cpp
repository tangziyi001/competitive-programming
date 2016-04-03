/*
 *	UVA 753
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
#define MAXN 1000

int res[MAXN][MAXN]; // Adjacency Matrix for Weighted Directed Graph
int mf; // Max Flow
int f, s, t;
vi p; // BFS Spanning Tree
map<string,int> strint;
vi sta;
vi ter;
vpi ada;
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
	int test;
	cin >> test;
	REP(cas,0,test){
		// Clear
		p.clear();
		FILL(res,0);
		strint.clear();
		sta.clear();
		ter.clear();
		ada.clear();
		int n,m;
		int idx = 0;
		cin >> n;
		REP(i,0,n){
			string tmp;
			cin >> tmp;
			//cout << tmp << " " << idx << endl;
			if(strint.find(tmp) == strint.end())
				strint[tmp] = idx++;
			ter.push_back(strint[tmp]);
		}
		cin >> m;
		REP(i,0,m){
			string name,type;
			cin >> name >> type;
			if(strint.find(type) == strint.end())
				strint[type] = idx++;
			sta.push_back(strint[type]);
		}
		int k;
		cin >> k;
		REP(i,0,k){
			string a,b;
			cin >> a >> b;
			if(strint.find(a) == strint.end())
				strint[a] = idx++;
			if(strint.find(b) == strint.end())
				strint[b] = idx++;
			ada.push_back(make_pair(strint[a],strint[b]));
		}
		int sz = idx;
		REP(i,0,m){
			res[0][sta[i]+1] += 1; //start->plug
			res[sta[i]+1][sta[i]+1+sz] += 1;
		}
		REP(i,0,n){
			res[sz+ter[i]+1][2*sz+1] += 1; // receptacle->end
		}
		REP(i,0,k){
			res[ada[i].first+sz+1][ada[i].second+1+sz] = INF; //adapter->adapter
		}
		s = 0;
		t = 2*sz+1;
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
	if(cas != 0) cout << endl;
	cout << m-mf << endl;
}	
	return 0;
}
