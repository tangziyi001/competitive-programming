/*
 *	CodeForces 191A
 *	Created by Ziyi Tang
 *	dp[i] = max(dp[i-1]+val, val);
 *	val = (all[i] == 0) ? 1 : -1
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

int all[105];
int dp[105];
int main(){
	int n, tmp;
	cin >> n;
	int sum = 0;
	REP(i,0,n){
		cin >> tmp;
		all[i] = tmp;
		sum += tmp;
	}
	dp[0] = (all[0] == 0) ? 1 : -1;
	int maxp = dp[0];
	REP(i,1,n){
		int val = all[i] == 0 ? 1 : -1;
		dp[i] = max(dp[i-1]+val, val);
		maxp = max(maxp, dp[i]);
	}
	cout << sum+maxp << endl;
	return 0;
}

