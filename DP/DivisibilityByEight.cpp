/*
 *	CodeForces 550C
 *	Created by Ziyi Tang
 *	DP on modulo
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

int dp[200][20];
pi look[200][20];
int main(){
	string line;
	cin >> line;
	int sz = line.size();
	FILL(dp,0);
	REP(i,0,sz){
		int now = line[i]-'0';
		dp[i][now%8] = 1;
		look[i][now%8] = pi(i,-1);å
	}
	REP(i,0,sz-1) REP(j,i+1,sz) REP(k,0,8) if(dp[i][k] == 1){
			dp[j][(2*k+(line[j]-'0')%8)%8] |= 1;
			look[j][(2*k+(line[j]-'0')%8)%8] = make_pair(i,k);
	}
	REP(i,0,sz){
		if(dp[i][0]){
			cout << "YES" << endl;
			pi now = look[i][0];
			string re = "";
			re += line[i];
			while(now.second != -1){
				re += line[now.first];
				now = look[now.first][now.second];
			}
			reverse(re.begin(), re.end());
			int idx = 0;
			while(re[idx] == '0' && idx != re.size()-1)
				idx++;
			cout << re.substr(idx) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}