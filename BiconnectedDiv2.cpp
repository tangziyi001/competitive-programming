/*
 *	Topcoder SRM 693 2
 *	Created by Ziyi Tang
 *	Observation
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

class BiconnectedDiv2 {
public:
	int minimize(vector <int>, vector <int>);
};

int BiconnectedDiv2::minimize(vector <int> w1, vector <int> w2) {
	int sz1 = w1.size();
	int sz2 = w2.size();
	vi can;
	int sum1 = 0;
	sum1 += w1[0];
	sum1 += w1[sz1-1];
	REP(i,0,sz2){
		sum1 += w2[i];
	}
	if(sz1 == 2) return sum1;
	REP(i,1,sz1-1){
		if(w1[i] < 0) sum1 += w1[i];
	}
	return sum1;
}
