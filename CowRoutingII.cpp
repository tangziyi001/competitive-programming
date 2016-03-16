/*
 *	USACO 2015 January Contest, Bronze 2
 *	Coded by Ziyi Tang
 *	Start from two ends and find the shortest path.
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
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vector<pair<int, vector<int> > > all;
int disa[10005];
int disb[10005];
int main(){
	freopen("cowroute.in", "r", stdin);
  	freopen("cowroute.out", "w", stdout);
  	FILL(disa,-1);
  	FILL(disb,-1);
  	int a,b,n;
  	cin >> a >> b >> n;
  	REP(i,0,n){
  		int w,d;
  		cin >> w >> d;
  		all.push_back(make_pair(w, vector<int>(0,0)));
  		REP(j,0,d){
  			int tmp;
  			cin >> tmp;
  			all[i].second.push_back(tmp);
  		}
  	}
  	// Notice that taking one subway is permitted.
  	disa[a] = 0;
  	disb[b] = 0;
  	REP(i,0,n){
  		vi now = all[i].second;
  		int sz = now.size();
  		int flag = 0;
  		REP(j,0,sz){
  			if(now[j] == a){
  				flag = 1;continue;
  			}
  			if(flag)
  				disa[now[j]] = (disa[now[j]] == -1) ? all[i].first : min(disa[now[j]],all[i].first);
  		}
  		flag = 0;
  		for(int j = sz-1; j >= 0; j--){
  			if(now[j] == b){
  				flag = 1;continue;
  			}
  			if(flag)
  				disb[now[j]] = (disb[now[j]] == -1) ? all[i].first : min(disb[now[j]],all[i].first);
  		}
  	}
  	int minp = INF;
	REP(i,1,10001){
		if(disa[i] != -1 && disb[i] != -1)
			minp = min(minp, disa[i]+disb[i]);
	}
	if(minp == INF)
		cout << -1 << endl;
	else
		cout << minp << endl;
	return 0;
}