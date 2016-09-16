/*
 *	CodeForces 368B
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

vi all;
vi mm;
int re[100005];
set<int> ss;
int main(){
	int n,m;
	cin >> n >> m;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,m){
		int tmp;
		cin >> tmp;
		mm.push_back(tmp);
	}
	for(int i = n-1; i >= 0; i--){
		ss.insert(all[i]);
		re[i] = ss.size();
	}
	REP(i,0,m){
		cout << re[mm[i]-1] << endl;
	}
	return 0;
}