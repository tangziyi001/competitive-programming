/*
 *	UVA 11489
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Game Theory DP. dp[sum][number of remained]
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
#define MAXN 10005
#define MOD 1000000007

int dp[MAXN][1000];
string n;
int sz;
int dfs(int now, int sum, int num){
	if(dp[sum][num] != -1) return dp[sum][num];
	int flag = 0;
	int mmod = 0;
	REP(i,0,sz) if(n[i] != '#'){
		int tmp = (int)(n[i]-'0');
		int rem = sum - tmp;
		n[i] = '#';
		if(rem == 0) return dp[sum][num] = 1;
		if(rem % 3 == 0){
			mmod = 1;
			flag |= dfs(now^1, rem, num-1);
		}
		n[i] = (char)(tmp+'0');
	}
	if(!mmod) return dp[sum][num] = 0;
	if(flag) return dp[sum][num] = 0;
	else return dp[sum][num] = 1;

}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		FILL(dp, -1);
		int sum = 0;
		cin >> n;
		//cout << n << endl;
		sz = n.size();
		REP(i,0,sz){
			sum += n[i]-'0';
		}
		int re = dfs(0, sum, sz);
		printf("Case %d: ",t);
		if(re) cout << "S" << endl;
		else cout << "T" << endl;
	}
	return 0;
}