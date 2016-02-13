/*
 *	POJ 2559
 *	Created by Ziyi Tang
 *	单调栈
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

stack<pll> all;
int main(){
	ll n;
	ll tmp;
	while(scanf("%lld",&n) && n != 0){
		ll maxp = 0;
		REP(i,0,n){
			scanf("%lld",&tmp);
			if(all.empty()){
				all.push(make_pair((ll)tmp, 1));
				continue;
			}
			while(!all.empty() && tmp < all.top().first){
				pll now = all.top();all.pop();
				ll length = now.second;
				maxp = max(maxp, now.first*length);
				if(all.empty()){
					all.push(make_pair((ll)tmp, length));
					break;
				}
				now = all.top();all.pop();
				now.second += length;
				//cout << now.first << " " << now.second << endl;
				all.push(now);
			}
			if(tmp == all.top().first){
				pll now = all.top();all.pop();
				now.second+=1;
				all.push(now);
			}
			else{
				all.push(make_pair((ll)tmp, 1));
			}
		}
		while(!all.empty()){
			pll now = all.top();all.pop();
			maxp = max(maxp, now.first*now.second);
			ll length = now.second;
			if(all.empty()) break;
			now = all.top();all.pop();
			now.second += length;
			all.push(now);
		}
		cout << maxp << endl;
	}
	return 0;
}
