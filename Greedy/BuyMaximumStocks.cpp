/*
 *	Goldman Sachs CodeSprint 2
 *	Created by Ziyi Tang
 *	Greedy Sort
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
typedef pair<ll,ll> pi;
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
#define MAXN 1000
#define MOD 1000000007

vpi all;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		ll tmp; cin >> tmp;
		all.push_back(make_pair(tmp, (ll)i+1));
	}
	ll k; cin >> k;
	sort(all.begin(), all.end());
	ll total = 0LL;
	ll rem = k;
	REP(i,0,n){
		ll num = min(all[i].second, rem/all[i].first);
		total += num;
		rem -= num*all[i].first;
	}
	cout << total << endl;
	return 0;
}