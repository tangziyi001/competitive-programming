/*
 *	Codeforces 721B - Passwords
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

vector<string> all;
int main(){
	int n,k;
	cin >> n >> k;
	string right;
	REP(i,0,n){
		string line;
		cin >> line;
		all.push_back(line);
	}
	cin >> right;
	int sz = right.size();
	int countS = 0;
	int countN = 0;
	REP(i,0,n){
		int tsz = all[i].size();
		if(tsz < sz)
			countS++;
		else if(tsz == sz)
			countN++;
	}
	int minp = countS + 1;
	int maxp = countS + countN;
	minp += 5*((minp-1)/k);
	maxp += 5*((maxp-1)/k);
	cout << minp << " " << maxp << endl;
	return 0;
}