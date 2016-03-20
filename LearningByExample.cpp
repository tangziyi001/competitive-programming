/*
 *	USACO 2014 December Contest, Bronze 4
 *	Coded by Ziyi Tang
 *	Interval Manipulation
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
ll re = 0ll;
int main(){
	freopen("learning.in", "r", stdin);
  	freopen("learning.out", "w", stdout);
  	int a,b,n;
  	cin >> n >> a >> b;
  	REP(i,0,n){
  		string com;
  		int w;
  		cin >> com >> w;
  		int tmp = 0;
  		if(com == "S") tmp = 1;
  		all.push_back(make_pair(w, tmp));
  	}
  	all.push_back(make_pair(INF,0));
  	all.push_back(make_pair(-INF,0));
  	sort(all.begin(), all.end());
  	int sz = all.size();
  	REP(i,0,sz-1){
  		pi now = all[i];
  		pi nxt = all[i+1];
  		int m = (now.first+nxt.first)/2;
  		if(now.second == 1){
  			int s = max(now.first+1, a);
  			int e = min(m, b);
  			if(e >= s)
  				re += (e-s+1);
  		}
  		if(nxt.second == 1){
  			int s = max(m+1, a);
  			int e = min(nxt.first, b);
  			if(e >= s)
  				re += (e-s+1);
  		}
  		if(now.second == 0 && nxt.second == 1 && a <= m && m <= b && (now.first%2 == nxt.first%2))
  			re++;
  	}
  	cout << re << endl;
	return 0;
}