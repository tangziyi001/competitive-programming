/*
 *	Google Code Jam 2016 Online Qualification Round 4
 *	Coded by Ziyi Tang， CS480 S16 Algorithmic Problem Solving, New York University
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
typedef unsigned long long ll;
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
#define MAXN 110000

vector<ll> all;
int k,c,s;
ll sz;
int vsz;
int ff;
ll power(ll base, ll p){
	if(p == 0) return 1LL;
	ll tmp = power(base,p/2);
	tmp = tmp*tmp;
	if(p&1)
		tmp*=base;
	return tmp;
}
ll expand(ll cur){
	ll re = cur;
	REP(t,2,c+1){
		ll now = 0LL;
		int length = power(k,t-1);
		REP(i,0,length){
			if(re & (1 << i)){
				ll tmp = (1 << k) - 1;
				now |= (tmp << (k*i));
			}else{
				now |= (cur << (k*i));
			}
		}
		re = now;
		bitset<12> b(re);
		//cout << b << endl;
	}
	return re;
}


int main(){
	int test;
	cin >> test;
	REP(cas,1,test+1){
		cin >> k >> c >> s;
		if(k == 1){
			printf("Case #%d: %d\n",cas, 1);
			continue;
		}
		// int group = sz/k;
		// all.clear();
		// ff = 0;
		// REP(i,0,k){
		// 	ll cur = 0LL;
		// 	cur |= (1 << i);
		// 	bitset<10> now(cur);
		// 	//cout << now << endl;
		// 	ll tmp = expand(cur);
		// 	all.push_back(tmp);
		// 	bitset<81> now2(tmp);
		// 	cout << now2 << endl;
		// }
		// vsz = all.size();

		sz = power(k,c);
		//cout << sz << endl;
		ll dis = (sz-1)/(k-1);
		printf("Case #%d:", cas);
			ll now = 1;
			REP(i,0,k){
				cout << " " << now;
				now+=dis;
			}
			cout << endl;
		
	}
	return 0;
}