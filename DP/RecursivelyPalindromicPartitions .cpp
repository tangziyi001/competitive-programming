/*
 *	ICPC NY 2008D
 *	Created by Ziyi Tang
 *	dp[i] += dp[(i-j)/2]; for 0 <= j <= i if i-j is even
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

int dp[10000];
int main(){
	FILL(dp,0);
	dp[0] = 1;
	dp[1] = 1;
	REP(i,2,10000) REP(j,0,i+1) if((i-j)%2 == 0){
		dp[i] += dp[(i-j)/2];
	}
	int n, tmp;
	cin >> n;
	REP(i,1,n+1){
		cin >> tmp;
		printf("%d %d\n",i,dp[tmp]);
	}
	return 0;
}

