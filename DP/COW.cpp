/*
 *	USACO 2015 February Contest, Bronze 2
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
#define MAXN 1000

ll dp[100005][3];
string line;
int n;
int main(){
	freopen("cow.in", "r", stdin);
  	freopen("cow.out", "w", stdout);
  	cin >> n >> line;
  	REP(i,0,3){
  		dp[0][i] = 0;
  	}
  	REP(i,1,n+1){
  		REP(j,0,3)
  			dp[i][j] = dp[i-1][j];
  		if(line[i-1] == 'C')
  			dp[i][0] += 1;
  		if(line[i-1] == 'O')
  			dp[i][1] += dp[i][0];
  		if(line[i-1] == 'W')
  			dp[i][2] += dp[i][1];
  	}
  	cout << dp[n][2] << endl;
	return 0;
}