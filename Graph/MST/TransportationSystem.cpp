/*
 *	UVA 11228
 *	Created by Ziyi Tang
 *	MST. Identify two costs
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
#define MAXN 1000100

vi p;
vector<pair<double, pi> >all; // Undirected Weighted Graph
vpi vers;
int m;
int findParent(int i){
	if(p[i] == i)
		return i;
	return p[i] = findParent(p[i]);
}
bool isSameSet(int i, int j){
	int p1 = findParent(i);
	int p2 = findParent(j);
	return p1 == p2;

}
void unionSet(int i, int j){
	if(!isSameSet(i,j))
		p[findParent(i)] = findParent(j);
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		// Clear
		int n,r;
		cin >> n >> r;
		double numroad = 0;
		double numrail = 0;
		int numstate = 1;
		all.clear();
		vers.clear();
		REP(i,0,n){
			int x,y;
			cin >> x >> y;
			vers.push_back(make_pair(x,y));
			for(int j = 0; j < i; j++){
				int tx = vers[j].first;
				int ty = vers[j].second;
				double weight = sqrt((x-tx)*(x-tx)+(y-ty)*(y-ty));
				all.push_back(make_pair(weight,make_pair(i,j)));
			}
		}
		m = all.size();
		p.assign(m+5,0);
		REP(i,0,m){
			p[i] = i;
		}
		sort(all.begin(),all.end());
		double total_cost = 0;
		REP(i,0,m){
			pair<double,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				total_cost += now.first;
				if(now.first > r){
					numstate++;
					numrail+=now.first;
				}
				else{
					numroad+=now.first;
				}

			}
		}
		// Output
		printf("Case #%d: %d %.0lf %.0lf\n", t, numstate, numroad, numrail);
	}

	
	return 0;
}
