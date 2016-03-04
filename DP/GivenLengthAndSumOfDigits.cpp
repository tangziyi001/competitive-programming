/*
 *	CodeForces 277C
 *	Created by Ziyi Tang
 *	dp[i][j][0] = dp[i-1][j-k][0]+(char)('0'+k)
 *	i is the length of the number, and j is the sum of all numbers.
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

string dp[105][905][2];
int main(){
	int m,s;
	cin >> m >> s;
	REP(i,0,105) REP(j,0,905) REP(k,0,2){
		dp[i][j][k] = "-1";
	}
	dp[0][0][0] = dp[0][0][1] = "";
	REP(i,1,m+1) REP(j,1,s+1){
		int flag = 1;
		REP(k,0,10){
			if(j >= k && dp[i-1][j-k][0] != "-1" && flag){
				flag = 0;
				dp[i][j][0] = dp[i-1][j-k][0]+(char)('0'+k);
			}
			if(j >= k && dp[i-1][j-k][1] != "-1")
				dp[i][j][1] = dp[i-1][j-k][1]+(char)('0'+k);
		}
	}
	if(m == 1 && s == 0){
		printf("%d %d\n",0,0);
	}
	else if(dp[m][s][0] != "-1" && dp[m][s][1] != "-1")
		printf("%s %s\n",dp[m][s][1].c_str(),dp[m][s][0].c_str());
	else
		printf("%d %d\n",-1,-1);
	return 0;
}

