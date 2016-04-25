/*
 *	UVA 10739
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *
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
#define MAXN 1005
#define MOD 1000000007

int dp[MAXN][MAXN];
string line;
int sz;
int dpdp(int sta, int ter){
	if(sta > ter) return 0;
	if(dp[sta][ter] != -1) return dp[sta][ter];
	if(line[sta] == line[ter])
		return dp[sta][ter] = dpdp(sta+1, ter-1);
	else{
		int minp = min(dpdp(sta+1, ter-1), dpdp(sta+1, ter));
		return dp[sta][ter] = 1 + min(minp, dpdp(sta, ter-1));
	}
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		FILL(dp,-1);
		cin >> line;
		sz = line.size();
		int re = dpdp(0,sz-1);
		printf("Case %d: %d\n",t,re);
	}
	return 0;
}