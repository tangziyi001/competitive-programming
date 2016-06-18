/*
 *	Codeforces 682A — Alyona and Numbers
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vector<ll> ns;
vector<ll> ms;
int main(){
	int n,m;
	ns.assign(5,0LL);
	ms.assign(5,0LL);
	cin >> n >> m;
	REP(i,1,n+1){
		ns[i%5]++;
	}
	REP(i,1,m+1){
		ms[i%5]++;
	}
	ll re = 0LL;
	re += (ns[0]*ms[0]);
	re += (ns[1]*ms[4]);
	re += (ns[2]*ms[3]);
	re += (ns[3]*ms[2]);
	re += (ns[4]*ms[1]);
	cout << re << endl;
	return 0;
}