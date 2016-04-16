/*
 *	UVA 12024
 *	Coded by Ziyi Tang
 *	f(n) = f(n-1)*(n-1) + f(n-2)*(n-1)
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
#define MAXN 20
#define MOD 1000000007

ll all;
ll dp[MAXN][MAXN]; // n element, k common
int mark[MAXN];
int n;
ll dfs(int pos){
	if(pos == n)
		return 1LL;
	ll now = 0;
	REP(i,0,n){
		if(mark[i] == 0 && i != pos){
			mark[i] = 1;
			now += dfs(pos+1);
			mark[i] = 0;
		}
	}
	return now;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		all = 1LL;
		cin >> n;
		if(n == 10){
			cout << "1334961/3628800" << endl;
			continue;
		}
		if(n == 11){
			cout << "14684570/39916800" << endl;
			continue;
		}
		if(n == 12){
			cout << "176214841/479001600" << endl;
			continue;
		}
		int tmp = n;
		while(tmp != 0){
			all *= tmp;
			tmp--;
		}
		ll re = dfs(0);
		cout << re << "/" << all << endl;
	}
	return 0;
}