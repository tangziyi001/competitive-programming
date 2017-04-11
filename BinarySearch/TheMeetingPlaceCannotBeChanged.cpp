/*
 *	Codeforces 782B - The Meeting Place Cannot Be Changed
 *	Created by Ziyi Tang
 *	Binary Search the time
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
vector<long double> all;
vector<long double> v;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		long double tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,n){
		long double tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	long double i = 0, j = 1e9;
	while(fabs(j-i) > 1e-8){
		long double mid = (i+j)/2;
		//cout << mid << endl;
		vector<pair<long double,long double> > vd;
		REP(k,0,n){
			vd.push_back(make_pair(max((long double)0.0, all[k]-mid*v[k]), min((long double)1e9,all[k]+mid*v[k])));
			//cout << all[k] << " " << vd[k].first << " " << vd[k].second << endl;
		}
		long double l = vd[0].first, r = vd[0].second;
		REP(k,1,n){
			l = max(l, vd[k].first);
			r = min(r, vd[k].second);
		}
		if(l > r){
			i = mid;
		} else {
			j = mid;
		}
	}
	printf("%.7Lf", i);
	return 0;
}