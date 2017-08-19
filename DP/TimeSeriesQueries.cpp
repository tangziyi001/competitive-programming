/*
 *	Goldman Sachs CodeSprint 4
 *	Created by Ziyi Tang
 *	Binary Search
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
typedef vector<double> vd;
typedef vector<vd> vvd;
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ((x) > EPS)
#define MAXN 100010
#define MOD 1000000007

vi allp;
vi allt;
vpi all1;
vpi all2;
int mint[MAXN];
int maxp[MAXN];
int main(){
	int n,q;
	FILL(mint, INF);
	FILL(maxp, 0);
	cin >> n >> q;
	REP(i,0,n){
		int t;
		cin >> t;
		allt.push_back(t);
	}
	REP(i,0,n){
		int p;
		cin >> p;
		allp.push_back(p);
	}
	REP(i,0,n){
		all1.push_back(make_pair(allp[i], allt[i]));
		all2.push_back(make_pair(allt[i], allp[i]));
	}
	sort(all1.begin(), all1.end());
	sort(all2.begin(), all2.end());
	mint[n-1] = all1[n-1].second;
	maxp[n-1] = all2[n-1].second;
	for(int i = n-2; i >= 0; i--){
		mint[i] = min(all1[i].second, mint[i+1]);
		maxp[i] = max(all2[i].second, maxp[i+1]);
	}
	REP(qq,0,q){
		int a,v; cin >> a >> v;
		if(a == 1){
			auto it = lower_bound(all1.begin(), all1.end(), make_pair(v, -1));
			int idx = it-all1.begin();
			if(idx < n){
				cout << mint[idx] << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			auto it = lower_bound(all2.begin(), all2.end(), make_pair(v, -1));
			int idx = it-all2.begin();
			if(idx < n){
				cout << maxp[idx] << endl;
			} else 
				cout << -1 << endl;
		}
	}
	return 0;
}