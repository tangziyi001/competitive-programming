/*
 *	UVA 10369
 *	Created by Ziyi Tang
 *	Minimum Spanning Forest
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
vpi vers;
int n,m,s;

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
	REP(i,0,test){
		cin >> s >> n; // The number of edges

		// Clear
		all.clear();
		vers.clear();
		REP(i,0,n){
			p[i] = i;
		}

		// Create Edges
		REP(i,0,n){
			int x,y;
			cin >> x >> y;
			vers.push_back(make_pair(x,y));
			REP(j,0,i){
				pi tmp = vers[j];
				int tx = tmp.first;
				int ty = tmp.second;
				double len = sqrt((tx-x)*(tx-x)+(ty-y)*(ty-y));
				all.push_back(make_pair(len, make_pair(i,j)));
			}
		}
		m = all.size();
		int rem = n;
		sort(all.begin(),all.end());
		double now_cost = 0;
		REP(i,0,m){
			if(rem == s)
				break;
			pair<double,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				now_cost = now.first;
				rem--;
			}
			
		}
		// Output
		printf("%.2lf\n",now_cost);
	}
	
	return 0;
}
