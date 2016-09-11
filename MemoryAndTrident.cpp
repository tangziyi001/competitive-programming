/*
 *	Codeforces 712B - Memory and Trident
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	string all;
	cin >> all;
	int sz = all.size();
	int hor = 0;
	int ver = 0;
	REP(i,0,sz){
		char now = all[i];
		if(now == 'L') hor++;
		if(now == 'R') hor--;
		if(now == 'U') ver++;
		if(now == 'D') ver--;
	}	
	int re = 0;
	hor = abs(hor);
	ver = abs(ver);
	if((hor%2 == 0 && ver%2 != 0) || (hor%2 != 0 && ver%2 == 0)){
		cout << -1 << endl;
		return 0;
	}
	if(hor%2 == 0 && ver%2 == 0){
		cout << hor/2 + ver/2 << endl;
		return 0;
	}
	else{
		cout << 1 + hor/2 + ver/2 << endl;;
	}
	return 0;
}