/*
 *	USACO 2015 January Contest, Silver 1
 *	Coded by Ziyi Tang
 *	STL set interval technique
 *	We simply store all "interesting" times (times immediate before/during/after an interval starts and ends) 
 *	in a set and then process the intervals in increasing y values. 
 *	Using set's lower_bound and upper_bound functions we can find the iterator range representing all times within that interval. 
 *	If the interval is non-empty we delete everything in the range and increment the number of seen intervals, 
 *	otherwise the interval is not visible.
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
#include <unordered_set>
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

vector<pair<int,pi> > all;
int n;
set<int> times;
int main(){
	freopen("stampede.in", "r", stdin);
  	freopen("stampede.out", "w", stdout);
  	int a,b,r;
  	cin >> n;
  	REP(i,0,n){
  		cin >> a >> b >> r;
  		all.push_back(make_pair(b, make_pair(r*(0-a-1), r*(0-a))));
  		//cout << all[i].second.first << " " << all[i].second.second << endl;
  		times.insert(r*(0-a));
  		//times.insert(r*(0-a)-1);
  		//times.insert(r*(0-a)+1);
  		times.insert(r*(0-a-1));
  		//times.insert(r*(0-a-1)-1);
  		//times.insert(r*(0-a-1)+1);
  	}
  	sort(all.begin(),all.end());
  	int cont = 0;
  	REP(i,0,n){
  		auto left = times.lower_bound(all[i].second.first);
  		auto right = times.lower_bound(all[i].second.second);
  		if(left != right){
  			cont++;
  			times.erase(left,right);
  		}
  	}
  	cout << cont << endl;
	return 0;
}