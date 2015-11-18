/*
 *	UVA 00247
 *	Created by Ziyi Tang
 *	Print SCC by Tarjan
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
#define MAXN 30

vvi all; // Unweighted Directed Graph
int nums[MAXN];
int lows[MAXN];
int mark[MAXN];
vi member; // The members within a SCC
vi head; // The root of each SCC
int counter;
int numSCC; // The number of SCCs
map<string,int> strint;
string intstr[MAXN];

void tarjan(int now){
	mark[now] = 1;
	lows[now] = nums[now] = counter++;
	member.push_back(now);
	int sz = all[now].size();
	REP(i,0,sz){
		int tmp = all[now][i];
		if(nums[tmp] == -1)
			tarjan(tmp);
		if(mark[tmp])
			lows[now] = min(lows[now],lows[tmp]);
	}
	if(nums[now] == lows[now]){
		head.push_back(now);
		numSCC++;
		while(1){
			int nxt = member.back(); member.pop_back();
			cout << intstr[nxt]; // Print members
			mark[nxt] = 0;
			if(now == nxt)
				break;
			printf(", ");
		}
		printf("\n");
	}
}
int main(){
	int n,m;
	int cas = 0;
	// n vertices and m edges
	while(cin >> n >> m && (n != 0 || m != 0)){
		// Clear
		cas++;
		FILL(nums,-1);
		FILL(lows, 0);
		FILL(mark,0);
		head.clear();
		all.clear();
		counter = 0;
		numSCC = 0;
		vi tmp;
		all.assign(n,tmp);
		// Input
		strint.clear();
		string sta,ter;
		int cc = 0;
		REP(i,0,m){
			cin >> sta >> ter;
			if(strint.find(sta) == strint.end()){
				strint[sta] = cc;
				intstr[cc] = sta;
				cc++;
			}
			if(strint.find(ter) == strint.end()){
				strint[ter] = cc;
				intstr[cc] = ter;
				cc++;
			}

			all[strint[sta]].push_back(strint[ter]);
		}

		// Begin
		if(cas != 1)
			cout << endl;
		printf("Calling circles for data set %d:\n", cas);
		REP(i,0,n){
			if(nums[i] == -1){
				tarjan(i);
			}
		}
	}
	// Test

	return 0;
}
