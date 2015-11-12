/*
 *	UVA 10305
 *	Created by Ziyi Tang
 *	Topological Sort with Tarjan's Algorithm. There may be 0 constrains for order.
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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


int n,m;
vvi all;
vi re;
int mark[105];
void dfs(int idx){
	mark[idx] = 1;
	int sz = all[idx].size();
	REP(i,0,sz){
		if(mark[all[idx][i]] == 0)
			dfs(all[idx][i]);
	}
	re.push_back(idx);
}
int main(){
	while(cin >> n >> m && (m != 0 || n != 0)){
		FILL(mark,0);
		all.clear();
		re.clear();
		vi tmp;
		all.assign(n+1,tmp);
		REP(i,0,m){
			int sta,ter;
			cin >> sta >> ter;
			all[sta].push_back(ter);
		}
		REP(i,1,n+1){
			if(mark[i] == 0)
				dfs(i);
		}
		reverse(re.begin(),re.end());
		REP(i,0,n){
			if (i != 0)
				cout << " ";
			cout << re[i];
		}
		cout << endl;
	}

	return 0;
}
