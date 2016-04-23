/*
 *	UVA 11151
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
#define MAXN 1000
#define MOD 1000000007

string now;
int dp[1005][1005];
int dpdp(int sta, int ter){
	if(sta > ter){
		return 0;
	}
	//cout << sta << " " << ter << endl;
	if(dp[sta][ter] != -1)
		return dp[sta][ter];
	else{
		int maxp = 0;
		if(now[sta] == now[ter] && sta == ter){
			maxp = 1 + dpdp(sta+1,ter-1);
		}
		else if(now[sta] == now[ter]){
			maxp = 2 + dpdp(sta+1,ter-1);
		}
		else{
			maxp = max(dpdp(sta,ter-1), dpdp(sta+1, ter));
		}
		//cout << maxp << endl;
		return dp[sta][ter] = maxp;
	}
}
int main(){
	int test;
	cin >> test;
	getchar();
	while(test--){
		FILL(dp,-1);
		getline(cin,now);
		if(now == ""){
			cout << 0 << endl;
			continue;
		}
		int sz = now.size();
		int maxp = dpdp(0,sz-1);
		cout << maxp << endl;
	}
	return 0;
}