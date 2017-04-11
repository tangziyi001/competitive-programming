/*
 *	HackerRank University CodeSprint 2 E 
 *	Created by Ziyi Tang
 *  Combinatorics and DP
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
typedef vector<vvi> vvvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1300
#define MOD 1000000007

vi all;
vector<int> vv;
ll fac[MAXN];
ll C[MAXN][MAXN];
vvvi dp;
ll rec(int idx, int rem, int rem_v){
    if(dp[idx][rem][rem_v] != -1) return dp[idx][rem][rem_v];
    if(idx == vv.size()){
        return 1LL;
    }
    if(rem_v == 0 && idx+1 < vv.size()) return rec(idx+1, rem, vv[idx+1]);
    else if(rem_v == 0) return 1LL;
    ll rre = 0;
    int now = rem_v;
    int rows = min(now, rem);
    
    // Rows used
    REP(i,1, rows+1){
        // Choose which slots will be used
        ll re = C[rem][i];
        re %= MOD;
        re *= fac[i];
        re %= MOD;
        // Check the number of remaining slots
        re *= rec(idx, i, now-i);
        re %= MOD;
        rre +=re;
        rre %= MOD;
    }
    return dp[idx][rem][rem_v] = rre%MOD;
}
void comb(){
    REP(i,0,MAXN) REP(j,0,MAXN)  C[i][j] = 0LL;
	C[0][0] = 1LL;
	REP(i,1,MAXN) REP(j,0,i+1){
		C[i][j] = C[i-1][j];
		if(j >= 1){
			C[i][j] += C[i-1][j-1];
        }
        C[i][j] %= MOD;
	}
}
int main(){
    fac[0] = 1LL;
    REP(i,1,MAXN){
        fac[i] = (i*fac[i-1])%MOD;
    }
    comb();
	int n;
    cin >> n;
    REP(i,0,n){
        int tmp; cin >> tmp;
        all.push_back(tmp);
    }
    int tmp = 0;
    int cont = 0;
    REP(i,0,n){
        int now = all[i];
        if(now > tmp){
            cont++;
        } else {
            vv.push_back(cont);
            cont = 1;
        }
        tmp = now;
    }
    vv.push_back(cont);
    int maxp = *max_element(vv.begin(), vv.end());
    int vn = vv.size();
    dp.assign(vn+5, (vvi(vv[0]+5, vi(maxp+5,-1))));
    ll rre = 0;
    int idx = 0;
    int now = vv[idx];
    REP(j,1,now+1){
        ll re = 1;
        re *= rec(idx, j, now-j);
        re %= MOD;
        rre += re;
        rre %= MOD;
    }
    cout << rre << endl;
	return 0;
}