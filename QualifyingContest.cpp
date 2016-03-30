/*
 *	CodeForces 659B - Qualifying Contest
 *	Coded by Ziyi Tang
 *
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

int n,m;
vector<vector<pair<int,string> > > mem;
int main(){
	cin >> n >> m;
	vector<pair<int, string> > ttmp;
	mem.assign(10005, ttmp);
	REP(i,0,n){
		string name;
		int g,c;
		cin >> name >> g >> c;
		mem[g].push_back(make_pair(c, name));
	}
	REP(i,1,m+1){
		vector<pair<int,string> > now = mem[i];
		sort(now.begin(),now.end());
		int sz = now.size();
		if(sz == 2){
			cout << now[0].second << " " <<now[1].second << endl;
		}
		else if(now[sz-2].first > now[sz-3].first){
			cout << now[sz-1].second << " " << now[sz-2].second << endl;
		}
		else
			cout << "?" << endl;
	}
	
	return 0;
}