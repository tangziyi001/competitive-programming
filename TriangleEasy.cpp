/*
 *	Topcoder SRM 693 1
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

class TriangleEasy {
public:
	int find(int, vector <int>, vector <int>);
};


int TriangleEasy::find(int n, vector <int> x, vector <int> y) {
	vvi all;
	set<pi> ss;
	int sz = x.size();
	all.assign(n,vi(0,0));
	REP(i,0,sz){
		int a = x[i];
		int b = y[i];
		all[a].push_back(b);
		all[b].push_back(a);
		ss.insert(make_pair(a,b));
	}
	int minp = 3;
	REP(i,0,n){
		if(all[i].size() >= 2)
			minp = min(minp, 1);
		if(all[i].size() >= 1)
			minp = min(minp, 2);
		int ssz = all[i].size();
		REP(j,0,ssz-1){
			REP(k,j+1,ssz){
				int sta = all[i][j];
				int ter = all[i][k];
				if(ss.find(make_pair(sta,ter)) != ss.end() || ss.find(make_pair(ter,sta)) != ss.end())
					minp = min(minp, 0);
			}
			if(minp == 0) break;
		}
	}
	return minp;
}
