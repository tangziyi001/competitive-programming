/*
 *	Codeforces 677C - Vanya and Label
 *	Created by Ziyi Tang
 *	Implementation
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

ll look[70];
map<char, int> mm;
int main(){
	REP(i,0,70)
		look[i] = 0LL;
	REP(i,0,64) REP(j,0,64){
		look[i&j]++;
		look[i&j]%=MOD;
		//cout << i << j << " " << (i&j) << " " << look[i&j] << endl;
	}
	REP(i,0,10){
		mm[(char)(i+'0')] = i;
	}
	REP(i,0,26){
		mm[(char)('A'+i)] = i+10;
		mm[(char)('a'+i)] = i+36;
	}
	mm['-'] = 62;
	mm['_'] = 63;
	string line;
	cin >> line;
	int sz = line.size();
	ll re = 1LL;
	REP(i,0,sz){
		int now = mm[line[i]];
		re *= look[now];
		re%=MOD;
	}
	cout << re << endl;

	return 0;
}