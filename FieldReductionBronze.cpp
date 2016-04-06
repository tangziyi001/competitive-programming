/*
 *	USACO 2016 US Open Contest, Bronze 3
 *	Coded by Ziyi Tang
 *	Brute Force
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
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vpi all;
int main(){
	freopen("reduce.in", "r", stdin);
  	freopen("reduce.out", "w", stdout);
  	int n;
  	cin >> n;
  	REP(i,0,n){
  		int x,y;
  		cin >> x >> y;
  		all.push_back(make_pair(x,y));
  	}
  	int left = INF;
  	int idl = -1;
  	int right = -1;
  	int idr = -1;
  	int top = -1;
  	int idt = -1;
  	int bottom = INF;
  	int idb = -1;
  	REP(i,0,n){
  		pi now = all[i];
  		if(now.first < left){
  			left = now.first;
  			idl = i;
  		}
  		if(now.first > right){
  			right = now.first;
  			idr = i;
  		}
  		if(now.second > top){
  			top = now.second;
  			idt = i;
  		}
  		if(now.second < bottom){
  			bottom = now.second;
  			idb = i;
  		}
  	}
  	// REP(i,0,n){
  	// 	pi now = all[i];
  	// 	if(now.first == left || now.first == right || now.second == top || now.second == bottom) 
  	// }
  	int de[4] = {idl,idr,idt,idb};
  	ll minp = INFL;
  	REP(k,0,4){
  		int l = INF, r = -1, t = -1, b = INF;
  		REP(i,0,n){
  			if(i == de[k]) continue;
  			pi now = all[i];
  			if(now.first < l) l = now.first;
  			if(now.first > r) r = now.first;
  			if(now.second > t) t = now.second;
  			if(now.second < b) b = now.second;
  		}
  		minp = min(minp, ((ll)(r-l))*((ll)(t-b)));
  	}
  	cout << minp << endl;
	return 0;
}