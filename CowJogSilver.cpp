/*
 *	USACO 2014 December Contest, Silver 3
 *	Coded by Ziyi Tang
 *	Scan from the last cow to the first cow, Compute how far away each cow can run and check
 *	if it can reach the next cow.
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vector<pll> all;
int main(){
	freopen("cowjog.in", "r", stdin);
  	freopen("cowjog.out", "w", stdout);
  	int n,t;
  	cin >> n >> t;
  	REP(i,0,n){
  		ll pos,v;
  		cin >> pos >> v;
  		all.push_back(make_pair(pos,v));
  	}
  	ll tmp = all[n-1].first + all[n-1].second*t;
  	int cont = 1;
  	for(int i = n-2; i >= 0; i--){
  		ll far = all[i].first + all[i].second*t;
  		if(far < tmp){
  			cont++; tmp = far;
  		}
  	}
  	cout << cont << endl;
	return 0;
}