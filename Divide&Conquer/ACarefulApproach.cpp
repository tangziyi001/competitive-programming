/*
 *	UVA 1079 World Final 2009A
 *	Created by Ziyi Tang
 *	Divide & Conquer to find the result. Greedy to check the outcome.
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

vpi all;
int p[10];
int n;
bool check(double t){
	double now = all[p[0]].first;
	now+=t;
	REP(i,1,n){
		if(all[p[i]].second < now)
			return false;
		if(all[p[i]].first > now)
			now = all[p[i]].first;
		now+=t;
	}
	return true;
}
int main(){
	int cas = 0;
	while(cin >> n && n != 0){
		cas++;
		all.clear();
		REP(i,0,n){
			p[i] = i;
		}

		REP(i,0,n){
			int a,b;
			cin >> a >> b;
			all.push_back(make_pair(a*60,b*60));
		}
		double re = -1;
		do{
			double l = 0;
			double r = 1440*60;
			while(fabs(l-r) > 1e-7){
				double mid = (l+r)/2;
				if(check(mid)) l = mid;
				else r = mid;
			}
			re = max(re,l);
		}while(next_permutation(p,p+n));
		int r = round(re);
		printf("Case %d: %d:%02d\n", cas, r/60, r%60);
	}
	return 0;
}

