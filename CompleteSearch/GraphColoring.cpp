/*
 *	UVA 00193
 *	Created by Ziyi Tang
 *	Color vertex one-by-one recursively, either black (if possible) or white.
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

vvi all;
vi re;
int mark[105];
int n,m;
int maxp;
int flag = 0;
void rec(int pos, int num){
	if(pos == n){
		maxp = max(maxp,num);
		return ;
	}
	int sz = all[pos].size();
	int noblack = 0;
	REP(i,0,sz){
		int now = all[pos][i];
		if(mark[now] == 1) noblack = 1;
	}
	if(!noblack){
		mark[pos] = 1;
			rec(pos+1, num+1);
	}
	mark[pos] = 0;
	rec(pos+1, num);
	mark[pos] = -1;
}
void recprint(int pos, int num){
	if(flag == 1) return;
	if(num == maxp && flag == 0){
		flag = 1;
		REP(i,0,num){
			if(i != 0)
				cout << " ";
			cout << re[i]+1;
		}
		cout << endl;
		return;
	}
	if(pos == n){
		return ;
	}
	int sz = all[pos].size();
	int noblack = 0;
	REP(i,0,sz){
		int now = all[pos][i];
		if(mark[now] == 1) noblack = 1;
	}
	if(!noblack){
		mark[pos] = 1;
		re.push_back(pos);
		recprint(pos+1, num+1);
		re.pop_back();
	}
	mark[pos] = 0;
	recprint(pos+1, num);
	mark[pos] = -1;
}

int main(){
	int test;
	cin >> test;
	REP(t,0,test){
		cin >> n >> m;
		maxp = 0;
		flag = 0;
		all.clear();
		re.clear();
		FILL(mark,-1);	
		vi ttmp;
		all.assign(n,ttmp);
		REP(i,0,m){
			int sta, ter;
			cin >> sta >> ter;
			all[sta-1].push_back(ter-1);
			all[ter-1].push_back(sta-1);
		}
		rec(0,0);
		cout << maxp << endl;
		FILL(mark,-1);	
		recprint(0,0);
	}
	return 0;
}
