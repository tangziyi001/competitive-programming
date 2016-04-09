/*
 *	UVA 10759
 *	Coded by Ziyi Tang
 *	DP to compute all possible ways
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
typedef unsigned long long ll;
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

ll dp[25][155];
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}
ll power(ll base, ll n){
	if(n == 0LL) return 1LL;
	//if(n == 1LL) return base;
	ll tmp = power(base,n/2);
	ll now = tmp*tmp;
	if(n&1){
		now = base*now;
	}
	return now;
}
int main(){
	int n,x;
	dp[0][0] = 1LL;
	REP(i,1,25){
		REP(j,0,155){
			REP(k,1,7) if(j >= k){
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	while(cin >> n >> x && (n != 0 || x != 0)){
		// REP(i,0,10){
		// 	REP(j,0,10)
		// 		cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		ll mypow = power(6,n);
		ll sum = 0LL;
		//cout << dp[n][x] << endl;
		REP(j,0,x){
			//cout << dp[n][j] << endl;
			sum += dp[n][j];
		}
		//cout << mypow << " " << mypow-sum << endl;
		ll gcdd = gcd(mypow,mypow-sum);
		 if((mypow-sum) % mypow == 0)
			cout << (mypow-sum)/mypow<< endl;
		else cout << (mypow-sum)/gcdd << "/" << mypow/gcdd << endl;
	}	
	return 0;
}