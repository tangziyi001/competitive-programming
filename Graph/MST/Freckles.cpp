/*
 *	UVA 10034
 *	Created by Ziyi Tang
 *	MST
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

int p[MAXN];
vector<pair<double, pi> >all; // Undirected Weighted Graph
int n,m;
vector<pair<double, double> > dots;

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
	REP(t,0,test){
		if(t != 0)
			printf("\n");
		cin >> n;
		dots.clear();
		// Clear
		all.clear();
		REP(i,0,n){
			p[i] = i;
		}
		REP(i,0,n){
			double a,b;
			cin >> a >> b;
			dots.push_back(make_pair(a,b));
		}
		REP(i,0,n-1){
			REP(j,i,n){
				double difx = dots[j].first-dots[i].first;
				double dify = dots[j].second-dots[i].second;
				double d = sqrt(difx*difx+dify*dify);
				all.push_back(make_pair(d, make_pair(i,j)));
			}
		}
		sort(all.begin(),all.end());
		double total_cost = 0.0;
		m = all.size();
		REP(i,0,m){
			pair<double,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				total_cost += now.first;
			}
		}
		// Output
		printf("%.2lf\n",total_cost);
	}	
	return 0;
}
