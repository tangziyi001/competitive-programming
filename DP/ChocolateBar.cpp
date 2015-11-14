/*
 *	CodeForces 598E
 *	Created by Ziyi Tang
 *	Dynamic Programming
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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


int dp[35][35][55];
int rec(int i, int j, int k){
	if(k == 0 || i*j == k)
		return 0;
	if(k > i*j)
		return INF;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	int minp = INF;
	REP(tk,0,k+1){
		// Divide what I want into two part
		int rk = k - tk;
		// Everytime I can either horizontally cut the chocolate or vertically cut the chocolate
		REP(ti,1,i){
			minp = min(minp, j*j + rec(ti,j,tk) + rec(i-ti,j,rk));
		}
		REP(tj,1,j){
			minp = min(minp, i*i + rec(tj,i,tk) + rec(j-tj,i,rk));
		}
	}
	return dp[i][j][k] = minp;

}
int main(){
	FILL(dp,-1);
	REP(i,1,31) REP(j,1,31) REP(k,1,51){
		rec(i,j,50);
	}
	int cas;
	int n,m,k;
	cin >> cas;
	REP(i,0,cas){
		cin >> n >> m >> k;
		cout << rec(n,m,k) << endl;
	}

	return 0;
}
