/*
 *	Codeforces 343A - Rational Resistance
 *	Created by Ziyi Tang
 *	Oberve the euclidian algorithm
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

int main(){
	ll a,b;
	cin >> a >> b;
	ll cont = 0;
	while(a != 0 && b != 0){
		ll maxp = max(a,b);
		ll minp = min(a,b);
		ll fac = maxp/minp;
		maxp = maxp-fac*minp;
		cont += fac;
		a = maxp; b = minp;
	}
	cout << cont << endl;
	return 0;
}