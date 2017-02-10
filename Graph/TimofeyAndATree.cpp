/*
 *	Codeforces 764C
 *	Created by Ziyi Tang
 *	DFS to find two candidate roots, then check if either candidate root is valid.
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

vvi all;
vi col;
int can1 = -1;
int can2 = -1;
void dfs1(int now, int p){
	int tsz = all[now].size();
	REP(i,0,tsz){
		int nxt = all[now][i];
		if(nxt == p) continue;
		if(col[nxt] != col[now]){
			can1 = now;
			can2 = nxt;
			return ;
		} else dfs1(nxt, now);
	}
}
bool dfs2(int now, int p, int ori){
	int tsz = all[now].size();
	bool flag = true;
	REP(i,0,tsz){
		int nxt = all[now][i];
		if(nxt == p) continue;
		if(ori == 0 && col[nxt] != col[now]){
			return false;
		} else flag &= dfs2(nxt, now, 0);
	}
	return flag;
}
int main(){
	int n;
	cin >> n;
	all.assign(n,vi(0,0));
	REP(i,0,n-1){
		int a,b;
		scanf("%d %d", &a, &b);
		all[a-1].push_back(b-1);
		all[b-1].push_back(a-1);
	}
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		col.push_back(tmp);
	}
	dfs1(0, -1);
	if(can1 == -1 && can2 == -1){
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}
	bool is1 = dfs2(can1,-1,1);
	bool is2 = dfs2(can2,-1,1);
	if(is1){
		cout << "YES" << endl;
		cout << can1+1 << endl;
	} else if(is2){
		cout << "YES" << endl;
		cout << can2+1 << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}