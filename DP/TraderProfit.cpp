/*
 *	Goldman Sachs CodeSprint 3
 *	Created by Ziyi Tang
 *	Stock Buying DP
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
typedef vector<double> vd;
typedef vector<vd> vvd;
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ((x) > EPS)
#define MAXN 1000
#define MOD 1000000007

int dp[40][15];
vi all;
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		int k,n;
		cin >> k >> n;
		REP(i,0,n){
			int tmp; cin >> tmp;
			all.push_back(tmp);
		}
		FILL(dp,0);
		REP(j,1,k+1){
			REP(i,1,n+1){
				dp[i][j] = dp[i-1][j];
				REP(s,0,i){
					dp[i][j] = max(dp[i][j], all[i-1]-all[s]+dp[s][j-1]);
				}
			}
		}
		cout << dp[n][k] << endl;
	}
	return 0;
}