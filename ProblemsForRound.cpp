/*
 *	673B - Problems for Round
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

vpi all;
int main(){
	int n,m;
	cin >> n >> m;
	REP(i,0,m){
		int a,b;
		cin >> a >> b;
		all.push_back(make_pair(min(a,b), max(a,b)));
	}
	sort(all.begin(), all.end());
	int sta = 1,ter = n;
	REP(j,0,m){
		if(all[j].first > sta)
			sta = all[j].first;
		if(all[j].second < ter)
			ter = all[j].second;
	}
	if(sta >= ter)
		cout << 0 << endl;
	else
		cout << ter-sta << endl;

	return 0;
}