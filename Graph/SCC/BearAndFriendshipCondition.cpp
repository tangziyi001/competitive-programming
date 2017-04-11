/*
 *	Codeforces 791B
 *	Created by Ziyi Tang
 *	Check SCC
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 200000
#define MOD 1000000007

vvi all;
int mark[MAXN];
set<int> ss;
int dfs(int now){
	ss.insert(now);
	int tsz = all[now].size();
	int cont = 0;
	REP(i,0,tsz){
		int nxt = all[now][i];
		if(!mark[nxt]){
			mark[nxt] = 1;
			cont += dfs(nxt);
		}
	}
	return 1+cont;
}
int main(){
	int n,m;
	cin >> n >> m;
	all.assign(n,vi(0,0));
	REP(i,0,m){
		int a,b;
		cin >> a >> b;
		all[a-1].push_back(b-1);
		all[b-1].push_back(a-1);
	}
	int flag = 1;
	int cont = 0;
	FILL(mark,0);
	REP(i,0,n){
		if(!mark[i]) {
			mark[i] = 1;
			cont = dfs(i);
		}
		//cout << cont << endl;
		for(auto it = ss.begin(); it != ss.end(); it++){
			int now = *it;
			if(all[now].size() != cont-1){
				flag = 0;
				break;
			}
		}
		ss.clear();
	}
	if(flag){
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}
	return 0;
}