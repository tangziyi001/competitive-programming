/*
 *	USACO 2014 March Contest, Silver 1
 *	Created by Ziyi Tang
 *	O(ElogV)
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
#define MAXN 2005

int p[MAXN];
vpi ver;
vector<pair<int, pi> >all; // Undirected Weighted Graph
int n,k;

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
	// Clear
	all.clear();
	ver.clear();
	freopen("irrigation.in","r",stdin);
	freopen("irrigation.out","w",stdout);
	cin >> n >> k; // The number of edges
	REP(i,0,n){
		p[i] = i;
	}
	REP(i,0,n){
		int a,b;
		cin >> a >> b;
		ver.push_back(make_pair(a,b));
	}
	REP(i,0,n-1){
		REP(j,i+1,n){
			pi a = ver[i];
			pi b = ver[j];
			int difx,dify;
			difx = a.first-b.first;
			dify = a.second-b.second;
			all.push_back(make_pair(difx*difx+dify*dify, make_pair(i,j)));
			//cout << difx*difx+dify*dify << endl;
		}
	}
	sort(all.begin(),all.end());
	int total_cost = 0;
	int sz = all.size();
	REP(i,0,sz){
		pair<int,pi> now = all[i];
		if(now.first < k) continue;
		//cout << now.second.first << "s" << now.second.second << endl;
		if(!isSameSet(now.second.first, now.second.second)){
			unionSet(now.second.first, now.second.second);
			total_cost += now.first;
		}
	}
	int flag = 1;
	int now = -1;
	REP(i,0,n){
		if(now == -1)
			now = findParent(i);
		else if(now != findParent(i)){
			flag = 0; break;
		}
	}
	// Output
	if(flag)
		cout << total_cost << endl;
	else
		cout << -1 << endl;
	return 0;
}
