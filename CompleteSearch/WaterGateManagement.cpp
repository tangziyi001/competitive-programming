/*
 *	UVA 12346
 *	Created by Ziyi Tang
 *	Enumerate all sets of gates and check if works
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

vpi all;
int main(){
	int n,m;
	cin >> n;
	REP(i,0,n){
		int a,b;
		cin >> a >> b;
		all.push_back(make_pair(a,b));
	}
	cin >> m;
	REP(j,0,m){
		int v,t;
		cin >> v >> t;
		ll bit = 0LL;
		ll minCost = INFL;
		while(bit < (1<<n)){
			ll curCost = 0LL;
			ll curVol = 0LL;
			REP(i,0,n){
				if(bit&(1<<i)){
					curCost += all[i].second;
					curVol += all[i].first*t;
				}
			}
			if(curVol >= v){
				minCost = min(minCost, curCost);
			}
			bit++;
		}
		if(minCost == INFL){
			printf("Case %d: IMPOSSIBLE\n", j+1);
		} else {
			printf("Case %d: %lld\n", j+1, minCost);
		}
	}
	return 0;
}