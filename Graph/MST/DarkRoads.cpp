/*
 *	UVA 11631
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
#define MAXN 200010

int p[MAXN];
vector<pair<int, pi> >all; // Undirected Weighted Graph
int m,n;
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
	while(cin >> n >> m && m != 0 && n != 0){
		// Clear
		int ori_cost = 0;
		all.clear();
		REP(i,0,m){
			p[i] = i;
		}
		// Input Edge Cost
		int u,v,w;
		REP(i,0,m){
			cin >> u >> v >> w;
			ori_cost += w;
			all.push_back(make_pair(w, make_pair(u,v)));
		}
		sort(all.begin(),all.end());
		int total_cost = 0;
		REP(i,0,m){
			pair<int,pi> now = all[i];
			if(!isSameSet(now.second.first, now.second.second)){
				unionSet(now.second.first, now.second.second);
				total_cost += now.first;
			}
		}

		// Output
		cout << ori_cost-total_cost << endl;
	}
	return 0;
}
