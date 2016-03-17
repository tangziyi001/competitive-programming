/*
 *	USACO 2015 January Contest, Silver 2
 *	Coded by Ziyi Tang
 *	Dijkstra with pair
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1005

pll dis[MAXN];
priority_queue<pair<pll,int> > qq;
pll all[MAXN][MAXN];
int main(){
	freopen("cowroute.in", "r", stdin);
  	freopen("cowroute.out", "w", stdout);
  	ll a,b,n;
  	cin >> a >> b >> n;
  	vpi ttmp;
  	REP(i,0,MAXN) REP(j,0,MAXN){
  		all[i][j] = make_pair(INFL, INFL);
  	}
  	REP(i,0,MAXN){
  		dis[i] = make_pair(INFL, INFL);
  	}
  	REP(i,0,n){
  		ll w,d;
  		cin >> w >> d;
  		vi routes;
  		REP(j,0,d){
  			int tmp;
  			cin >> tmp;
  			routes.push_back(tmp-1);
  		}
  		REP(j,0,d-1){
  			REP(k,j,d){
  				int x = routes[j];
  				int y = routes[k];
  				if(j == k)
  					all[x][y] = make_pair(0,0);
  				else all[x][y] = min(all[x][y], make_pair((ll)w, (ll)(k-j)));
  			}
  		}
  	}
  	dis[a-1] = make_pair(0LL, 0LL);
  	qq.push(make_pair(make_pair(-dis[a-1].first, -dis[a-1].second), a-1));
  	while(!qq.empty()){
  		pair<pll,int> now = qq.top();qq.pop();
  		if(make_pair(-now.first.first, -now.first.second) < dis[now.second]) continue;
  		REP(i,0,MAXN){
  			pll tmp = make_pair(all[now.second][i].first + dis[now.second].first, all[now.second][i].second + dis[now.second].second);
  			if(tmp  < dis[i]){
  				dis[i] = tmp;
  				qq.push(make_pair(make_pair(-dis[i].first, -dis[i].second), i));
  			}
  		}
  	}
  	if(dis[b-1].first != INFL || dis[b-1].second != INFL)
  		cout << dis[b-1].first << " " << dis[b-1].second << endl;
  	else
  		cout << -1 << " " << -1 << endl;
	return 0;
}