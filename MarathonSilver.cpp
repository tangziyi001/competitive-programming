/*
 *	USACO 2014 December Contest, Silver 2
 *	Coded by Ziyi Tang
 *	DP: Add one point to the route until we have n-k points.
 *	dp[i][j]: When we have i points and the second last point is j, store the minimum distance.
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

vpi all;
int dp[505][505]; // N-K,N
int compute(int i, int j){
	return abs(all[i].first-all[j].first) + abs(all[i].second-all[j].second);
}
int main(){
	freopen("marathon.in", "r", stdin);
  	freopen("marathon.out", "w", stdout);
  	int n,k;
  	cin >> n >> k;
  	REP(i,0,n){
  		int a,b;
  		cin >> a >> b;
  		all.push_back(make_pair(a,b));
  	}
  	REP(i,0,505) REP(j,0,505){
  		dp[i][j] = INF;
  	}
  	dp[2][0] = compute(0,n-1);
  	REP(i,3,n-k+1){ // The number of points
  		REP(j,1,n-1){ // End point
  			REP(h,0,j){ // Previous points
  				dp[i][j] = min(dp[i][j], dp[i-1][h] + compute(h,j) + compute(j,n-1) - compute(h,n-1));
  			}
  		}
  	}
  	int re = INF;
  	REP(i,0,n){
  		re = min(re, dp[n-k][i]);
  	}
  	cout << re << endl;
	return 0;
}