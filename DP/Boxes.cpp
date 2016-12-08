/*
 *	UVA 11003
 *	Created by Ziyi Tang
 *	DP
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
#define MAXN 1000
#define MOD 1000000007

int n;
vi weight;
vi limit;
int dp[1005][5000];

int rec(int idx, int l){
	if(dp[idx][l] != -1) return dp[idx][l];
	if(idx == n) return 0;
	int maxp = 0;
	if(l - weight[idx] >= 0){
		maxp = max(maxp, 1+rec(idx+1, min(limit[idx],l-weight[idx])));
	}
	maxp = max(maxp, rec(idx+1, l));
	return dp[idx][l] = maxp;
}
int main(){
	while(cin >> n && n != 0){
		weight.clear();
		limit.clear();
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			weight.push_back(tmp);
			cin >> tmp;
			limit.push_back(tmp);
		}
		FILL(dp,-1);
		int re = rec(0,5000);
		cout << re << endl;
	}
	return 0;
}