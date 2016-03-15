/*
 *	USACO 2015 US Open, Silver 3
 *	Coded by Ziyi Tang
 *	DP + Shortest Path
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

vvi all;
int tmpdis[1005];
queue<int> qq;
vpi quality;
int dp[1005];
int n,e;

void computeDis(int pos){
	FILL(tmpdis,-1);
	tmpdis[pos] = 0;
	qq.push(pos);
	while(!qq.empty()){
		int now = qq.front();qq.pop();
		int sz = all[now].size();
		REP(i,0,sz){
			int tmp = all[now][i];
			if(tmpdis[tmp] == -1){
				tmpdis[tmp] = tmpdis[now]+1;
				qq.push(tmp);
			}
		}
	}
}
int main(){
	freopen("buffet.in", "r", stdin);
  	freopen("buffet.out", "w", stdout);
  	cin >> n >> e;
  	FILL(tmpdis, 0);
  	all.assign(n,vector<int>(0,0));
  	int q,d;
  	REP(i,0,n){
  		cin >> q >> d;
  		quality.push_back(make_pair(q,i));
  		REP(j,0,d){
  			int tmp;
  			cin >> tmp;
  			all[i].push_back(tmp-1);
  			all[tmp-1].push_back(i);
  		}
  	}
  	sort(quality.begin(),quality.end());
  	int maxp = 0;
  	REP(i,0,n){
  		int pos = quality[i].second;
  		int qua = quality[i].first;
  		computeDis(pos);
  		dp[i] = qua;
  		if(i){
  			// Pay attention to somewhwere unreachable
  			REP(j,0,i) if(tmpdis[quality[j].second] != -1)
  				dp[i] = max(dp[i], dp[j]+qua-e*tmpdis[quality[j].second]);
  		}
  		maxp = max(maxp, dp[i]);
  	}
  	cout << maxp << endl;
	return 0;
}