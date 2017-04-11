/*
 *	Google Code Jam Qualification Round 2017 C
 *	Created by Ziyi Tang
 *	Use map to store intervals
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
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18+10;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

map<ll,ll> mm;
int main(){
	int T;
	cin >> T;
	REP(t,1,T+1){
		mm.clear();
		ll n,k;
		cin >> n >> k;
		mm[-n] = 1;
		ll minp = n;
		ll maxp = n;
		while(k > 0){
			ll now = -mm.begin()->first;
			ll time = mm.begin()->second;
			mm.erase(mm.begin());
			if(now&1){
				mm[-(now-1)/2] += time*2;
				minp = min(minp, (now-1)/2);
				maxp = min(maxp, (now-1)/2);
			}
			else{
				mm[-(now-1)/2] += time;
				mm[-(now)/2] += time;
				minp = min(minp, (now-1)/2);
				maxp = min(maxp, now/2);
			}
			// cout << maxp << " " << minp << endl;
			k-=time;
		}
		printf("Case #%d: %lld %lld\n", t, maxp,minp);
	}
	return 0;
}