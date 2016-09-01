/*
 *	Codeforces 711C - Coloring Trees
 *	Created by Ziyi Tang
 *	3D DP
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 105
#define MOD 1000000007

ll dp[MAXN][MAXN][MAXN];
vi all;
vvi price;
int main(){
	REP(i,0,MAXN) REP(j,0,MAXN) REP(k,0,MAXN){
		dp[i][j][k] = INFL;
	}
	int n,m,k;
	cin >> n >> m >> k;
	REP(i,0,n){
		ll tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,n){
		vi tmp;
		REP(j,0,m){
			ll cost;
			cin >> cost;
			tmp.push_back(cost);
		}
		price.push_back(tmp);
	}

	// The color for the first one
	if(all[0] == 0){
		REP(j,0,m){
			dp[0][j][0] = price[0][j];
		}
	} else {
		dp[0][all[0]-1][0] = 0LL;
	}

	// DP
	REP(i,1,n){
		REP(j,0,m){
			REP(g,0,k){
				// If this is colored, then only that coloring is allowed,
				// and without cost
				if(all[i] != 0 && j != all[i]-1)
					continue;
				if(all[i] != 0 && j == all[i]-1){
					REP(t,0,m){
						if(t == j) {
							dp[i][j][g] = min(dp[i][j][g], dp[i-1][t][g]);
						} else {
							if(g > 0)
								dp[i][j][g] = min(dp[i][j][g], dp[i-1][t][g-1]);
						}
					}
				} else {
					REP(t,0,m){
						if(t == j) {
							dp[i][j][g] = min(dp[i][j][g], price[i][j] + dp[i-1][t][g]);
						} else {
							if(g > 0)
								dp[i][j][g] = min(dp[i][j][g], price[i][j] + dp[i-1][t][g-1]);
						}
					}
				}
			}
		}
	}
	ll minp = INFL;
	REP(j,0,m){
		minp = min(minp, dp[n-1][j][k-1]);
	}
	if(minp == INFL){
		cout << -1 << endl;
	} else {
		cout << minp << endl;
	}
	return 0;
}