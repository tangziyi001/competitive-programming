/*
 *	CodeForces 332B
 *	Created by Ziyi Tang
 *	Sliding Window DP
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
#define MAXN 200010

int n,k;
ll sum[MAXN];
ll dp[MAXN];
ll f[MAXN];
int main(){
	cin >> n >> k;
	sum[0] = 0L;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		if(i == 0) sum[i+1] = tmp;
		else sum[i+1] = (tmp+sum[i]);
	}
	int fi,si;
	ll maxp = -INFL;
	for(int i = 1+k; i <= n-k+1; i++){
		if(i == k+1) {
			dp[i] = sum[i-1]-sum[i-k-1];
			f[i] = 1;
			fi = 1;
		}
		else{
			if(sum[i-1]-sum[i-k-1] > dp[i-1]){
				dp[i] = sum[i-1]-sum[i-k-1];
				f[i] = i-k;
			}
			else{
				dp[i] = dp[i-1];
				f[i] = f[i-1];
			}
		}
		if(maxp < dp[i] + sum[i+k-1]-sum[i-1]){
			maxp = dp[i] + sum[i+k-1]-sum[i-1];
			fi = f[i];
			si = i;
		}
	}
	cout << fi << " " << si << endl;
	return 0;
}
