/*
 *	UVA 11621
 *	Created by Ziyi Tang
 *	Use a table to record all 2^i*3^j combinations
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

ll dp[35][35];
int main(){
	dp[0][0] = 1L;
	REP(i,1,33){
		dp[0][i] = dp[0][i-1]*2;
	}
	REP(i,1,33){
		REP(j,0,33){
			dp[i][j] = dp[i-1][j]*3;
		}
	}
	ll tmp;
	while(cin >> tmp && tmp != 0){
		ll minp = INFL;
		REP(i,0,33){
			REP(j,0,33){
				if(dp[i][j] >= tmp && dp[i][j] < minp) minp = dp[i][j];
			}
		}
		cout << minp << endl;
	}
	return 0;
}
