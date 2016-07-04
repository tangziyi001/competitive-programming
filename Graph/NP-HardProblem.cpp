/*
 *	Codeforces 687A - NP-Hard Problem
 *	Created by Ziyi Tang
 *	Bi-coloring
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
#define MOD 1000000007

vvi all;
int mark[100005];


int main(){
	int n,m;
	cin >> n >> m;
	FILL(mark,-1);
	all.assign(n,vi(0,0));
	REP(i,0,m){
		int a,b;
		cin >> a >> b;
		a--;b--;
		all[a].push_back(b);
		all[b].push_back(a);
	}
	bool flag = 1;
	queue<int> qq;
	REP(i,0,n){
		if(mark[i] == -1){
			mark[i] = 0;
			qq.push(i);
			while(!qq.empty()){
				int now = qq.front();qq.pop();
				int sz = all[now].size();
				REP(k,0,sz){
					int nxt = all[now][k];
					if(mark[nxt] == mark[now]){
						flag = 0;
						break;
					}
					else if(mark[nxt] == -1){
						mark[nxt] = 1-mark[now];
						qq.push(nxt);
					}
				}
				if(flag == 0) break;
			}
		}
		if(flag == 0) break;
	}
	if(!flag)
		cout << -1 << endl;
	else{
		vi aa,bb;
		REP(i,0,n){
			if(mark[i] == 0) aa.push_back(i+1);
			else if(mark[i] == 1) bb.push_back(i+1);
		}
		int sza = aa.size();
		int szb = bb.size();
		cout << sza << endl;
		REP(i,0,sza){
			if(i != 0) cout << " ";
			cout << aa[i];
		}
		cout << endl;
		cout << szb << endl;
		REP(i,0,szb){
			if(i != 0) cout << " ";
			cout << bb[i];
		}
		cout << endl;
	}
	return 0;
}