/*
 *	USACO 2017 February Contest, Gold 2
 *	Coded by Ziyi Tang
 *	DP
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
#define MAXN 1005

int dp[MAXN][MAXN];
int main(){
	freopen("nocross.in", "r", stdin);
  	freopen("nocross.out", "w", stdout);
  	vi a,b;
  	int n;
  	cin >> n;
  	int tmp;
  	REP(i,0,n){
  		cin >> tmp;
  		a.push_back(tmp);
  	}
  	REP(i,0,n){
  		cin >> tmp;
  		b.push_back(tmp);
  	}
  	dp[0][0] = 0;
  	REP(i,0,n+1) REP(j,0,n+1){
  		int maxp = 0;
  		if(i > 0){
  			maxp = max(maxp, dp[i-1][j]);
  		}
  		if(j > 0){
  			maxp = max(maxp, dp[i][j-1]);
  		}
  		if(i > 0 && j > 0 && abs(a[i-1]-b[j-1]) <= 4){
  			maxp = max(maxp, 1+dp[i-1][j-1]);
  		}
  		dp[i][j] = maxp;
  	}
  	cout << dp[n][n] << endl;
	return 0;
}