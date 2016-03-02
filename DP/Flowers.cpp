/*
 *	CodeForces 474D
 *	Created by Ziyi Tang
 *	dp[i] denotes how many distinct combinations of two letters with length i.
 *	dp[i] = dp[i-1] if this letter is R.
 *	dp[i] += dp[i-k] if this letter is W and i >= k, 
 *	because we must fix the previous k-1 letters to W.
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
#define MAXN 100005
#define MOD 1000000007

int t,k;
ll dp[MAXN];
ll sum[MAXN];
int main(){
	cin >> t >> k;
	dp[0] = 1;
	FILL(sum,0);
	REP(i,1,100002){
		dp[i] = dp[i-1];
		if(i >= k){
			dp[i] += dp[i-k];
		}
		dp[i]%=MOD;
	}
	REP(i,0,100001){
		sum[i+1] += sum[i] + dp[i];
		sum[i+1]%=MOD;
	}
	ll a,b;
	REP(i,0,t){
		cin >> a >> b;
		ll re = sum[b+1]-sum[a];
		if(re < 0) re+=MOD;
		cout << re << endl;
	}
	return 0;
}

