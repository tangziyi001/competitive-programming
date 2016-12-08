/*
 *	TopCoder SRM 588 2
 *	Created by Ziyi Tang
 *	dp[bitmask][num of white keys assigned red]
 *  For each state, assign white keys to red.
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
#define MAXN 15
#define MOD 1000000007

class KeyDungeonDiv1 {
public:
	int maxKeys(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>);
};
int dp[(1<<12)][150]; // bm, w
int n;
vector<int> dr, dg, rr, rg, rw, ks;
int rec(int bm, int wtor){
	if(dp[bm][wtor] != -1) return dp[bm][wtor];
	int r = ks[0], g = ks[1], w = ks[2];
	// Retrieve num of originally red/green keys
	for(int i = 0; i < n; i++){
		if((bm&(1<<i)) != 0){
			r = r - dr[i] + rr[i];
			g = g - dg[i] + rg[i];
			w = w + rw[i];
		}
	}
	// Add white keys
	r += wtor;
	g += w-wtor;
	int maxp = r+g;
	for(int k = 0; k < n; k++){
		int newW = rw[k];
		if((bm & (1<<k)) == 0 && r >= dr[k] && g >= dg[k]){
			for(int i = 0; i <= newW; i++){
				// Assign new white keys
				maxp = max(maxp, rec(bm|(1<<k), wtor+i));
			}
		}
	}
	return dp[bm][wtor] = maxp;
}
int KeyDungeonDiv1::maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) {
	FILL(dp,-1);
	dr = doorR; dg = doorG; rr = roomR; rg = roomG; rw = roomW; ks = keys;
	n = doorR.size();
	int maxp = 0;
	for(int i = 0; i <= keys[2]; i++)
		maxp = max(maxp, rec(0, i));
	return maxp;
}


//Powered by [KawigiEdit] 2.0!