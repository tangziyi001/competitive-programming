/*
 *	Codeforces 650A
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
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

map<int,int> rr;
map<int,int> cc;
map<pair<int,int>, int> ss;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int a,b;
		cin >> a >> b;
		rr[a]++;
		cc[b]++;
		ss[make_pair(a,b)]++;
	}
	ll sum = 0LL;
	for(auto it = rr.begin(); it != rr.end(); it++){
		ll num = it->second;
		sum += (ll)(num*(num-1))/2;
	}
	for(auto it = cc.begin(); it != cc.end(); it++){
		ll num = it->second;
		sum += (ll)(num*(num-1))/2;
	}
	for(auto it = ss.begin(); it != ss.end(); it++){
		ll num = it->second;
		sum -= (ll)(num*(num-1))/2;
	}
	cout << sum << endl;
	return 0;
}