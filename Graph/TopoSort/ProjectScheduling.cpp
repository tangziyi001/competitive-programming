/*
 *	UVA 00452
 *	Created by Ziyi Tang
 *	DAG: Topo Sort and DP
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
#define MAXN 60

int val[26];
int dp[26];
vvi rev;
vvi all;
int dg[26];
int app[26];
vi ord;
int main(){
	
	int test;
	string ff;
	cin >> test;
	getchar();
	getline(cin,ff);
	REP(t,0,test){
		// Clear
		rev.assign(26,vi(0,0));
		all.assign(26,vi(0,0));
		FILL(dg,0);
		FILL(dp,0);
		FILL(app,0);
		ord.clear();
		FILL(val,0);
		// Initialize
		string line;
		while(getline(cin,line)){
			if(line == "") break;
			//cout << line << endl;
			char now;
			int cost;
			string rest;
			stringstream ss(line);
			ss >> now >> cost >> rest;
			val[now-'A'] = cost;
			int sz = rest.size();
			dg[(int)now-'A']=sz;
			REP(i,0,sz){
				char tmp = rest[i];
				//cout << tmp-'A' << " " << now-'A' << endl;
				all[tmp-'A'].push_back(now-'A');
				rev[now-'A'].push_back(tmp-'A');
				app[now-'A'] = 1;
				app[tmp-'A'] = 1;
			}
		}
		queue<int> qq;
		REP(i,0,26) if(app[i]){
			if(dg[i] == 0)
				qq.push(i);
		}
		while(!qq.empty()){
			int now = qq.front();qq.pop();
			ord.push_back(now);
			int sz = all[now].size();
			REP(i,0,sz){
				int tmp = all[now][i];
				dg[tmp]--;
				if(dg[tmp] == 0) qq.push(tmp);
			}
		}
		int sz = ord.size();
		REP(i,0,sz){
			int maxp = 0;
			int now = ord[i];
			int ssz = rev[now].size();
			REP(j,0,ssz){
				int tmp = rev[now][j];
				maxp = max(maxp, dp[tmp]);
			}
			dp[now] = maxp+val[now];
		}
		// REP(i,0,sz)
		// 	cout << ord[i] << " ";
		// cout << endl;

		if(t != 0) cout << endl;
		int maxp = 0;
		REP(i,0,26){
			maxp = max(maxp, dp[i]);
		}
		cout << maxp << endl;
	}
	return 0;
}
