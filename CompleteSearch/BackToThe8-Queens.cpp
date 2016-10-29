/*
 *	UVA 11085
 *	Created by Ziyi Tang
 *	Backtracking
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 2000
#define MOD 1000000007

vi all;
set<int> dia1;
set<int> dia2;
int rec(int col, int bm){
	//if(dp[col][bm] != -1) return dp[col][bm];
	if(col == 8) return 0;
	int minp = INF;
	REP(i,0,8){
		if((bm & (1 << i)) == 0 && dia1.count(col+i) == 0 && dia2.count(col-i) == 0){
			int dis = (all[col] == i) ? 0 : 1;
			//cout << col << " " << i << endl;
			dia1.insert(col+i);
			dia2.insert(col-i);
			minp = min(minp, dis + rec(col+1, bm | (1 << i)));
			dia1.erase(col+i);
			dia2.erase(col-i);
		}
	}
	return minp;
}
int main(){
	int tmp = 0;
	int test = 0;
	while(cin >> tmp){
		test++;
		all.clear();
		dia1.clear();
		dia2.clear();
		all.push_back(tmp-1);
		int bm = 0;
		REP(i,0,7){
			cin >> tmp;
			all.push_back(tmp-1);
		}
		printf("Case %d: %d\n", test, rec(0, bm));
	}
	return 0;
}