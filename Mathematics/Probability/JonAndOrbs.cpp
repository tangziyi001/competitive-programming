/*
 *	Codeforces 768D - Jon and Orbs
 *	Created by Ziyi Tang
 *	DP of Coupon Collection Problem
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1005
#define MAXD 10000
#define MOD 1000000007
#define EPS 1e-7

double dp[MAXD][MAXN]; // days, distinct num
int main(){
	int k,q;
	cin >> k >> q;
	REP(i,0,MAXD) REP(j,0,MAXN) dp[i][j] = 0LL;
	dp[0][0] = 1.0;
	REP(i,1,MAXD){
		REP(j,0,k+1){
			dp[i][j] = j*dp[i-1][j]/k;
			if(j > 0)
				dp[i][j] += (k-j+1)*dp[i-1][j-1]/k;
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	REP(t,0,q){
		int p;
		cin >> p;
		REP(i,0,MAXD){
			if(dp[i][k]>(p-EPS)/2000.0){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}