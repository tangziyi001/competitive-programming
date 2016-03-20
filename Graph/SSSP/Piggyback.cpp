/*
 *	USACO 2014 December Contest, Silver 1
 *	Coded by Ziyi Tang
 *	Shortest Path in Two Directions
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
#define MAXN 40005

int b,e,p,n,m;
int A[MAXN];
int B[MAXN];
int P[MAXN];
vvi all;
queue<int> qq;
int main(){
	FILL(A, -1);
	FILL(B, -1);
	FILL(P, -1);
	freopen("piggyback.in", "r", stdin);
  	freopen("piggyback.out", "w", stdout);
  	cin >> b >> e >> p >> n >> m;
  	all.assign(n,vi(0,0));
  	A[0] = 0;
	B[1] = 0;
	P[n-1] = 0;
  	REP(i,0,m){
  		int sta,ter;
  		cin >> sta >> ter;
  		all[sta-1].push_back(ter-1);
  		all[ter-1].push_back(sta-1);
  	}
  	qq.push(0);
  	while(!qq.empty()){
  		int now = qq.front();qq.pop();
  		int sz = all[now].size();
  		REP(i,0,sz){
  			int tmp = all[now][i];
  			if(A[tmp] == -1){
  				A[tmp] = A[now] + 1;
  				qq.push(tmp);
  			}
  		}
  	}
  	qq.push(1);
  	while(!qq.empty()){
  		int now = qq.front();qq.pop();
  		int sz = all[now].size();
  		REP(i,0,sz){
  			int tmp = all[now][i];
  			if(B[tmp] == -1){
  				B[tmp] = B[now] + 1;
  				qq.push(tmp);
  			}
  		}
  	}
  	qq.push(n-1);
  	while(!qq.empty()){
  		int now = qq.front();qq.pop();
  		int sz = all[now].size();
  		REP(i,0,sz){
  			int tmp = all[now][i];
  			if(P[tmp] == -1){
  				P[tmp] = P[now] + 1;
  				qq.push(tmp);
  			}
  		}
  	}
  	int minp = INF;
  	REP(i,0,n) if(A[i] != -1 && B[i] != -1 && P[i] != -1){
  		// cout << i << endl;
  		// cout << A[i] << " " << B[i] << " " << P[i] << endl;
  		minp = min(minp, b*A[i]+e*B[i]+p*P[i]);
  	}
  	cout << minp << endl;
	return 0;
}