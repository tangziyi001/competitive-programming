/*
 *		CodeForces 115A
 *      Created by Ziyi Tang
 *		Basic DFS
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

int n;
vvi all;
int mark[2005];
int dfs(int now){
	if(mark[now] != -1) return mark[now];
	if(all[now].size() == 0){
		return 1;
	}
	int maxp = 0;
	int sz = all[now].size();
	REP(i,0,sz){
		maxp = max(maxp, 1 + dfs(all[now][i]));
	}
	return mark[now] = maxp;

}
int main(){
		cin >> n;
		vi tmp;
		all.assign(n,tmp);
		FILL(mark,-1);
		REP(i,0,n){
			int ttmp;
			cin >> ttmp;
			if(ttmp == -1) continue;
			all[ttmp-1].push_back(i);
		}
		int maxp = 0;
		REP(i,0,n){
			if(mark[i] == -1){
				maxp = max(maxp, dfs(i));
			}
		}
		cout << maxp << endl;
        return 0;
}