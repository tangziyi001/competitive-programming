/*
 *	Codeforces 522A - Reposts
 *	Created by Ziyi Tang
 *  DFS to find the max path
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
#define MAXN 1000
#define MOD 1000000007

map<string,int> mm;
vvi all;
int dfs(int now){
	int tsz = all[now].size();
	int sum = 0;
	REP(i,0,tsz){
		int nxt = all[now][i];
		sum = max(sum, dfs(nxt));
	}
	return 1+sum;
}
string low(string now){
	string re;
	REP(i,0,now.size()){
		char a = now[i];
		if(a >= 'A' && a <= 'Z'){
			a = (char)(a-'A'+'a');
		}
		re += a;
	}
	return re;
}
int main(){
	int n;
	cin >> n;
	int idx = 0;
	all.assign(500,vi(0,0));
	mm["polycarp"]=idx++;
	REP(i,0,n){
		string a,r,b;
		cin >> a >> r >> b;
		a = low(a);
		b = low(b);
		//cout << a << " " << b << endl;
		if(!mm.count(a)){
			mm[a] = idx++;
		}
		if(!mm.count(b)){
			mm[b] = idx++;
		}
		all[mm[b]].push_back(mm[a]);
	}
	int re = dfs(0);
	cout << re << endl;
	return 0;
}