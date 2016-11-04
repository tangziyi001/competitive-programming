/*
 *	UVA 10927
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

struct point{
	ll x,y;
	point(){x=y=0LL;}
	point(ll x_, ll y_) : x(x_), y(y_) {}
	bool operator < (const point& tmp) const {
		return x*x+y*y < tmp.x*tmp.x+tmp.y*tmp.y;
	}
};
ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}
map<string, ll> mm; // Slope, Height
vpi rem;
vector<pair<point, ll> > all;
int main(){
	int n;
	int t = 0;
	while(cin >> n && n != 0){
		t++;
		mm.clear();
		all.clear();
		rem.clear();
		REP(i,0,n){
			ll x,y,h;
			scanf("%lld %lld %lld", &x, &y, &h);
			all.push_back(make_pair(point(x,y), h));
		}
		sort(all.begin(), all.end());
		REP(i,0,n){
			point now = all[i].first;
			ll h = all[i].second;
			ll ggcd = gcd(now.x, now.y);
			string key = to_string(now.x/ggcd)+'/'+to_string(now.y/ggcd);
			key+='-';
			if(now.x >= 0) key+='1';
			if(now.y >= 0) key+='2';
			if(mm.count(key)){
				if(mm[key] >= h) rem.push_back(make_pair(now.x, now.y));
				else mm[key] = h;
			} else mm[key] = h;
		}
		printf("Data set %d:\n", t);
		if(rem.size() == 0){
			printf("All the lights are visible.\n");
		} else {
			printf("Some lights are not visible:\n");
			sort(rem.begin(), rem.end());
			REP(i,0,rem.size()){
				printf("x = %d, y = %d", rem[i].first, rem[i].second);
				if(i != rem.size()-1) printf(";\n");
				else printf(".\n");
			}
		}
	}
	return 0;
}
