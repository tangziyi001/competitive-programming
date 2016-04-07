/*
 *	USACO 2014 March Contest, Silver 3
 *	Coded by Ziyi Tang
 *	DP + Simulation
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
#define MAXN 100005

int dp[MAXN];
vi bre;
vi voi;
int n,b;
int main(){
	freopen("mooomoo.in", "r", stdin);
  	freopen("mooomoo.out", "w", stdout);
	cin >> n >> b;
	REP(i,0,b){
		int tmp;
		cin >> tmp;
		bre.push_back(tmp);
	}
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		voi.push_back(tmp);
	}
	REP(i,0,MAXN)
		dp[i] = INF;
	dp[0] = 0;
	REP(i,1,MAXN){
		int minp = INF;
		REP(j,0,b) if(i >= bre[j]){
			minp = min(minp, dp[i-bre[j]]);
		}
		dp[i] = minp == INF ? INF : 1 + minp;
	}
	int cont;
	int flag = 1;
	int carry = 0;
	REP(i,0,n){
		int rem = voi[i]-carry;
		carry = max(0,voi[i]-1);
		if(dp[rem] == INF || rem < 0){
			flag = 0;
			break;
		}
		cont += dp[rem];
		//cout << dp[rem] << endl;
	}
	if(flag)
		cout << cont << endl;
	else
		cout << -1 << endl;
	return 0;
}