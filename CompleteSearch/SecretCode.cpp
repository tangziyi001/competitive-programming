/*
 *	USACO 2014 February Contest, Silver
 *	Created by Ziyi Tang
 *	Recursion with memo
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
#define MOD 2014

map<string, ll> mm;
ll check(string ss);
ll cc(string now){
	ll sum = 0LL;
	int sz = now.size();
	int mid = sz/2;
	if((sz&1) == 0) mid--;
	REP(i,1,mid+1){
		string part = now.substr(0,i);
		string rem = now.substr(i,sz-i);
		if(part == now.substr(i,i)){
			sum += 1 + check(rem);
			sum %= MOD;
		}
		if(part == now.substr(sz-i,i)){
			sum += 1 + check(rem);
			sum %= MOD;
		}
	}
	return sum;
}
ll check(string now){
	ll sum = 0LL;
	int sz = now.size();
	if(sz == 2)
		return 0;
	if(mm.find(now) != mm.end())
		return mm[now];
	int mid = sz/2;
	sum += cc(now);
	sum %= MOD;
	reverse(now.begin(), now.end());
	sum += cc(now);
	sum %= MOD;
	reverse(now.begin(), now.end());
	return mm[now] = sum;
}
int main(){
	freopen("scode.in", "r", stdin);
  	freopen("scode.out", "w", stdout);
	string now;
	cin >> now;
	ll re = check(now);
	cout << re%MOD << endl;
	return 0;
}