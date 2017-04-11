/*
 *	Codeforces 553A
 *	Created by Ziyi Tang
 *	DP with Combination
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
#define MAXN 1010
#define MOD 1000000007
vi all;
int sum[MAXN];
ll C[MAXN][MAXN];
ll dp[MAXN];

ll power(ll b, ll p){
	if(p == 0) return 1;
	ll tmp = power(b,p/2);
	tmp *= tmp;
	tmp %= MOD;
	if(p&1){
		return (b*tmp)%MOD;
	}else{
		return tmp;
	}
}
int main(){
	FILL(C,0);
	C[0][0] = 1;
	REP(i,1,MAXN){
		REP(j,0,MAXN){
			C[i][j] = C[i-1][j]%MOD;
			if(j > 0){
				C[i][j] += C[i-1][j-1];
				C[i][j] %= MOD;
			}
		}
	}
	int n;
	cin >> n;
	ll re = 1LL;
	sum[0] = 0;
	dp[0] = 1;
	REP(i,0,n){
		int tmp; cin >> tmp;
		all.push_back(tmp);
		sum[i+1] = (sum[i] + tmp);
	}
	if(n == 1){
		cout << re << endl;
		return 0;
	}
	REP(i,1,n){
		dp[i] = (dp[i-1]*C[sum[i]+1+all[i]-1-1][sum[i]+1-1])%MOD;
	}
	cout << dp[n-1] << endl;
	return 0;
}