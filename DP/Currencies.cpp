/*
 *	Goldman Sachs CodeSprint 5
 *	Created by Ziyi Tang
 *	Divide & Conquer DP with log(a*b) = log(a+b) for multiplication comparison
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
typedef vector<double> vd;
typedef vector<vd> vvd;
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ((x) > EPS)
#define MAXN 30
#define MOD 1000000007

int grid[MAXN][MAXN];
map<vi,pair<double,ll> > dp;
int n, x,s,f,m;
pair<double,ll> bi(int m, int s, int f){
	vi tmp;
	tmp.push_back(m);
	tmp.push_back(s);
	tmp.push_back(f);
	double maxp = 0.0;
	ll maxv = 0LL;
	if(dp.count(tmp)) return dp[tmp];
	if(m == 1){
		return dp[tmp] = make_pair(log(grid[s][f]), grid[s][f]);
	} else if(m&1){
		REP(i,0,n){
			pair<double,ll> left = bi(m/2, s, i);
			pair<double,ll> right = bi(m/2+1, i, f);
			if(left.first+right.first > maxp){
				maxp = left.first+right.first;
				maxv = (left.second%MOD*right.second%MOD)%MOD;
			}
			left = bi(m/2+1, s, i);
			right = bi(m/2, i, f);
			if(left.first+right.first > maxp){
				maxp = left.first+right.first;
				maxv = (left.second%MOD*right.second%MOD)%MOD;
			}
		}
	} else {
		REP(i,0,n){
			pair<double,ll> left = bi(m/2, s, i);
			pair<double,ll> right = bi(m/2, i, f);
			if(left.first+right.first > maxp){
				maxp = left.first+right.first;
				maxv = (left.second%MOD*right.second%MOD)%MOD;
			}
		}
	}
	return dp[tmp] = make_pair(maxp, maxv);
}
int main(){
	cin >> n >> x >> s >> f >> m;
	FILL(grid,0);
	REP(i,0,n){
		REP(j,0,n){
			int tmp; cin >> tmp;
			grid[i][j] = tmp;
		}
	}
	ll re = x*bi(m,s,f).second%MOD;
	cout << re << endl;
	return 0;
}