/*
 *	TopCoder SRM 585 500
 *	Created by Ziyi Tang
 *	DP: Decreasing order order placement with combinatorics.
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

class LISNumber {
public:
	int count(vector <int>, int);
};
ll C[1300][1300];
ll dp[40][1300];
ll rec(vector <int>& cardsnum, int idx, int k, int K, int S){
	if(idx == 0 && k == 0) {
		return 1;
	}
	else if(idx == 0 || k <= -1) return 0;
	if(dp[idx][k] != -1) return dp[idx][k];
	int filled = K-k; // Number of decreaising gaps already filled
	int noeff = filled+1; // Add the front position
	int eff = S+1-noeff; // Number of non-decreasing gap positions
	int s = cardsnum[idx-1];
	ll re = 0LL;
	for(int i = 0; i <= s; i++){
		for(int j = 0; j+i <= s; j++){
			int eq = s - i - j;
			re += (((C[noeff][i] * C[eff][j] % MOD) * C[i+j+eq-1][eq]) % MOD * rec(cardsnum, idx-1, k-eq-j, K, S+s)) % MOD;
			re %= MOD;
		}
	}
	return dp[idx][k] = re%MOD;
}
int LISNumber::count(vector <int> cardsnum, int K) {
	REP(i,0,1300) REP(j,0,1300) C[i][j] = 0LL;
	REP(i,0,40) REP(j,0,1300) dp[i][j] = -1LL;
	C[0][0] = 1LL;
	REP(i,1,1300){
		REP(j,0,1300){
			C[i][j] += C[i-1][j]%MOD;
			C[i][j] %= MOD;
			if(j >= 1)
				C[i][j] += C[i-1][j-1]%MOD;
			C[i][j] %= MOD;
		}
	}
	int n = cardsnum.size();
	ll re = rec(cardsnum, n, K-1, K-1, 0);
	return re;
}


//Powered by [KawigiEdit] 2.0!