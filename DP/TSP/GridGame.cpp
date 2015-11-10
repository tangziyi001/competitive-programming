/*
 *	UVA 11553
 *	Created by Ziyi Tang
 *	Double TSP
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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


int grid[10][10];
int dp[1 << 9][1 << 9];
int n;
int tsp(int r, int c){
	if (r == (1 << n) - 1) return 0;
	if (dp[r][c] != INF) return dp[r][c];
	int maxp = -INF;
	REP(i,0,n){
		if ((r & (1 << i)) == 0){
			int minp = INF;
			REP(j,0,n){
 				if ((c & (1 << j)) == 0){
					minp = min(minp, grid[i][j] + tsp(r | (1 << i), c | (1 << j)));
				}
			}
			maxp = max(maxp,minp);
		}
	}
	return dp[r][c] = maxp;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		REP(i,0,1 << 9) REP(j,0, 1 << 9){
			dp[i][j] = INF;
		}
		cin >> n;
		REP(i,0,n) REP(j,0,n){
			int tmp;
			cin >> tmp;
			grid[i][j] = tmp;
		}
		int re = tsp(0,0);
		cout << re << endl;

	}

	return 0;
}
