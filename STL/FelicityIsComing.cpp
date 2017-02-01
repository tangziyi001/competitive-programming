/*
 *	Codeforces 757C - Felicity is Coming!
 *	Created by Ziyi Tang
 *
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
#define MAXN 1000
#define MOD 1000000007

vvi all;
int mark[MAXN];
ll fac[1000005];
map<vi,ll> mm;
int main(){
	FILL(mark,0);
	int n,m;
	cin >> n >> m;
	fac[0] = 1;
	REP(i,1,1000001){
		fac[i] = (i*fac[i-1])%MOD;
	}
	all.assign(m,vi(0,0));
	REP(i,0,n){
		int num;
		scanf("%d", &num);
		REP(j,0,num){
			int tmp;
			scanf("%d", &tmp);
			tmp--;
			all[tmp].push_back(i);
		}
	}
	REP(i,0,m){
		sort(all[i].begin(), all[i].end());
		mm[all[i]]++;
	}

	ll re = 1;
	for(auto it = mm.begin(); it != mm.end(); it++){
		re *= fac[it->second];
		re %= MOD;
	}
	cout << re << endl;
	return 0;
}