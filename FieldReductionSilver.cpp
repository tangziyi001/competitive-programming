/*
 *	USACO 2016 US Open Contest, Silver 1
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
vpi myleft;
vpi mybottom;
int n;

ll check(set<int> now){
	int l = INF, r = -1, t = -1, b = INF;
	REP(i,0,n){
		if(now.find(i) != now.end()) continue;
		l = min(l, all[i].first);
		r = max(r, all[i].first);
		t = max(t, all[i].second);
		b = min(b, all[i].second);
	}
	return (ll)(r-l)*(ll)(t-b);
}
int main(){
	freopen("reduce.in", "r", stdin);
  	freopen("reduce.out", "w", stdout);
  	cin >> n;
  	REP(i,0,n){
  		int a,b;
  		cin >> a >> b;
  		all.push_back(make_pair(a,b));
  		myleft.push_back(make_pair(a,i));
  		mybottom.push_back(make_pair(b,i));
  	}
  	sort(myleft.begin(),myleft.end());
  	sort(mybottom.begin(),mybottom.end());
  	int lsz = myleft.size();
  	int bsz = mybottom.size();

  	ll minp = INFL;
  	for(int l = 0; l <= 3; l++)
  	for(int r = 0; r <= 3-l; r++)
  	for(int t = 0; t <= 3-l-r; t++){
  		int b = 3-l-r-t;
  		//cout << l << r << t << b << endl;
  		set<int> now;
  		for(int ll = 0; ll < l; ll++)
  			now.insert(myleft[ll].second);
  		for(int rr = lsz-1; rr >= lsz-r; rr--)
  			now.insert(myleft[rr].second);
  		for(int bb = 0; bb < b; bb++)
  			now.insert(mybottom[bb].second);
  		for(int tt = bsz-1; tt >= bsz-t; tt--)
  			now.insert(mybottom[tt].second);
  		// REP(i,0,3){
  		// 	cout << now[i] << " ";
  		// }
  		// cout << endl;
  		minp = min(minp, check(now));
  	}
  	cout << minp << endl;
	return 0;
}