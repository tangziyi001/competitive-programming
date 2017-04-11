/*
 *	Codeforces 791E
 *	Created by Ziyi Tang
 *	DP: dp[v][k][x][last letter is V]
 *	Records the min operations for getting a string of length v+k+x
 *	taking first v of V, k of K and x of X
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 80
#define MOD 1000000007

int dp[MAXN][MAXN][MAXN][2]; // V,K,X,last letter is V
int vs[MAXN];
int ks[MAXN];
int xs[MAXN];
vi vidx;
vi kidx;
vi xidx;
int V,K,X;
int n;
string line;
int main(){
	cin >> n;
	cin >> line;
	vs[0] = ks[0] = xs[0] = 0;
	REP(i,0,n){
		vs[i+1] = vs[i];
		ks[i+1] = ks[i];
		xs[i+1] = xs[i];
		if(line[i] == 'V') {
			vs[i+1] += 1;
			vidx.push_back(i);
		}
		else if(line[i] == 'K') {
			ks[i+1] += 1;
			kidx.push_back(i);
		}
		else {
			xs[i+1] += 1;
			xidx.push_back(i);
		}
	}
	V = vs[n];
	K = ks[n];
	X = xs[n];
	FILL(dp,INF);
	dp[0][0][0][0] = dp[0][0][0][1] = 0;
	REP(i,0,V+1){
		REP(j,0,K+1){
			REP(k,0,X+1){
				//cout << i << " " << j << " " << k << endl; 
				if(i > 0){
					int idx = vidx[i-1]; // The idx of the ith v
					dp[i][j][k][1] = dp[i-1][j][k][0] 
						+ max(0, vs[idx]-(i-1)) 
						+ max(0, ks[idx]-j) 
						+ max(0, xs[idx]-k);
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k][1] 
						+ max(0, vs[idx]-(i-1)) 
						+ max(0, ks[idx]-j) 
						+ max(0, xs[idx]-k));
				}
				if(j > 0){
					int idx = kidx[j-1];
					dp[i][j][k][0] = dp[i][j-1][k][0]
						+ max(0, vs[idx]-i)
						+ max(0, ks[idx]-(j-1))
						+ max(0, xs[idx]-k);
				}
				if(k > 0){
					int idx = xidx[k-1];
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j][k-1][0]
						+ max(0, vs[idx]-i)
						+ max(0, ks[idx]-j)
						+ max(0, xs[idx]-(k-1)));
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j][k-1][1]
						+ max(0, vs[idx]-i)
						+ max(0, ks[idx]-j)
						+ max(0, xs[idx]-(k-1)));
				}
				//cout << dp[i][j][k][0] << " " << dp[i][j][k][1] << endl;
			}
		}
	}
	cout << min(dp[V][K][X][0], dp[V][K][X][1]) << endl;
	return 0;
}