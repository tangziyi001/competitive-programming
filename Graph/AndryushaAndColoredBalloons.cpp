/*
 *	Codeforces 782C - Andryusha and Colored Balloons
 *	Created by Ziyi Tang
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 200050
#define MOD 1000000007

int all[MAXN];
int col[MAXN];
int maxp = 0;
vvi tree;
vi re;
void dfs(int now, int p, int& c){
	int tsz = tree[now].size();
	set<int> ss;
	REP(i,0,tsz){
		int nxt = tree[now][i];
		if(nxt == p) continue;
		while(c == col[now] || (p >= 0 && c == col[p])){
			c++;
			c%=maxp;
		}
		col[nxt] = c; //cout << "col" << c << endl;
		ss.insert(c);
	}
	REP(i,0,tsz){
		int nxt = tree[now][i];
		if(nxt == p) continue;
		dfs(nxt, now, c);
	}
}
int main(){
	int n;
	cin >> n;
	FILL(all,0);
	FILL(col,-1);
	tree.assign(n,vi(0,0));
	REP(i,0,n-1){
		int a,b;
		cin >> a >> b;
		all[a-1]++;
		all[b-1]++;
		tree[a-1].push_back(b-1);
		tree[b-1].push_back(a-1);
	}
	REP(i,0,n){
		maxp = max(all[i],maxp);
	}
	cout << maxp+1 << endl;
	maxp+=1;
	int c = 0;
	col[0] = c;
	dfs(0,-1,c);
	REP(i,0,n){
		cout << col[i]+1 << " ";
	}
	cout << endl;
	return 0;
}