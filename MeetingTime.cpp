/*
 *	USACO 2015 January Contest, Bronze 4
 *	Coded by Ziyi Tang
 *	DFS. Record all possible reaching time for two persons.
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

vvpi a;
vvpi b;
set<int> adistance;
vector<int> bdistance;
int n,m;

void dfsa(int pos, int dis){
	if(pos == n-1){
		adistance.insert(dis);
	}
	else{
		vpi now = a[pos];
		int sz = now.size();
		REP(i,0,sz){
			dfsa(now[i].first,dis+now[i].second);
		}
	}
}
void dfsb(int pos, int dis){
	if(pos == n-1){
		bdistance.push_back(dis);
	}
	else{
		vpi now = b[pos];
		int sz = now.size();
		REP(i,0,sz){
			dfsb(now[i].first,dis+now[i].second);
		}
	}
}
int main(){
	freopen("meeting.in", "r", stdin);
  	freopen("meeting.out", "w", stdout);
	cin >> n >> m;
	vpi ttmp;
	a.assign(n,ttmp);
	b.assign(n,ttmp);
	REP(i,0,m){
		int x,y,ad,bd;
		cin >> x >> y >> ad >> bd;
		a[x-1].push_back(make_pair(y-1,ad));
		b[x-1].push_back(make_pair(y-1,bd));
	}
	dfsa(0,0);
	dfsb(0,0);
	int sz = bdistance.size();
	sort(bdistance.begin(), bdistance.end());
	int re = -1;
	REP(i,0,sz){
		if(adistance.find(bdistance[i]) != adistance.end()){
			re = bdistance[i];
			break;
		}
	}
	if(re == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << re << endl;

	return 0;
}