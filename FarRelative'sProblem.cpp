/*
 *	CodeForces 343B
 *	Created by Ziyi Tang
 *	Interval Endpoints Comparison
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

vector<pair<pi, char> > all;
int main(){
	int n;
	cin >> n;
	char m;
	int a,b;
	REP(i,0,n){
		cin >> m >> a >> b;
		all.push_back(make_pair(make_pair(b,a),m));
	}
	sort(all.begin(),all.end());
	// REP(i,0,n){
	// 	cout << all[i].first.second << " " << all[i].first.first << endl;
	// }
	int maxp = -1;
	REP(i,0,n){
		int cont = 0;
		int male = 0;
		int female = 0;
		pair<pi,char> now = all[i];
		int end = (now.first).first;
		int start = (now.first).second;
		if(now.second == 'F') female++;
		else male++;
		REP(j,i+1,n){
			pair<pi,char> tmp = all[j];
			int tstart = tmp.first.second;
			int tend = tmp.first.first;
			if(tstart <= end){
				cont++;
				if(tmp.second == 'F') female++;
				else male++;
			}
		}
		maxp = max(maxp, min(male,female)*2);
	}
	cout << maxp << endl;
	return 0;
}

