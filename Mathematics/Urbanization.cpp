/*
 *	Codeforces 735B - Urbanization
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

vector<ll> all;
int main(){
	ll n,n1,n2;
	cin >> n >> n1 >> n2;
	REP(i,0,n){
		ll tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	sort(all.begin(), all.end());
	if(n1 > n2) swap(n1,n2);
	double sum = 0.0;
	double tmp = 0.0;
	REP(i,0,n1){
		tmp += all[n-1-i];
	}
	sum += tmp/n1;
	tmp = 0;
	REP(i,0,n2){
		tmp += all[n-1-n1-i];
	}
	sum += tmp/n2;
	printf("%.7f\n", sum);
	return 0;
}