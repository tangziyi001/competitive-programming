/*
 *	USACO 2016 US Open Contest, Silver 2
 *	Coded by Ziyi Tang
 *	Sliding window DP and Binary Search
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
#define MAXN 50005

int n,k;
vi all;
int dp[MAXN];
int dp2[MAXN];
int main(){
	FILL(dp,0);
	FILL(dp2,0);
	freopen("diamond.in", "r", stdin);
  	freopen("diamond.out", "w", stdout);
  	cin >> n >> k;
  	REP(i,0,n){
  		int tmp;
  		cin >> tmp;
  		all.push_back(tmp);
  	}
  	sort(all.begin(),all.end());
  	REP(i,0,n){
  		int now = all[i];
  		auto it = upper_bound(all.begin(),all.end(),now+k);
  		int j = it-all.begin();
  		//cout << now << " " << *it << " " << j-i << endl;
  		dp[i] = j-i;
  	}
  	dp2[n-1] = dp[n-1];
  	for(int i = n-1; i > 0; i--){
  		dp2[i-1] = max(dp[i-1],dp2[i]);
  	}
  	int maxp = 0;
  	REP(i,0,n-1){
  		maxp = max(maxp, dp[i]+dp2[i+dp[i]]);
  	}
  	cout << maxp << endl;
	return 0;
}