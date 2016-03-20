/*
 *	UVA 10397
 *	Coded by Ziyi Tang
 *	Basic MST
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
#define MAXN 755

vpi all;
vector<pair<double,pi> > edges;
int p[MAXN];
int findRep(int i){
	if(p[i] == i) return i;
	else return p[i] = findRep(p[i]);
}
bool isSameSet(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	int pi = findRep(i);
	int pj = findRep(j);
	if(pi != pj)
		p[pi] = pj;
}
double computeDis(int i, int j){
	int dif1 = abs(all[i].first-all[j].first);
	int dif2 = abs(all[i].second-all[j].second);
	double w = sqrt(dif1*dif1+dif2*dif2);
	return w;
}
int main(){
	int n,m;
	while(scanf("%d",&n) != EOF){
		all.clear();
		REP(i,0,MAXN){
			p[i] = i;
		}
		edges.clear();
		int a,b;
		REP(i,0,n){
			cin >> a >> b;
			all.push_back(make_pair(a,b));
		}
		REP(i,0,n-1){
			REP(j,i+1,n){
				double w = computeDis(i,j);
				edges.push_back(make_pair(w, make_pair(i,j)));
			}
		}
		cin >> m;
		double re = 0.0;
		REP(i,0,m){
			int a,b;
			cin >> a >> b;
			unionSet(a-1,b-1);
		}
		int sz = edges.size();
		sort(edges.begin(),edges.end());
		REP(i,0,sz){
			int a = edges[i].second.first;
			int b = edges[i].second.second;
			if(!isSameSet(a,b)){
				re += edges[i].first;
				unionSet(a,b);
			}
		}
		printf("%.2lf\n",re);
	}

	return 0;
}

