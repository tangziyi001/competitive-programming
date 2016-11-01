/*
 *	Tarjan Algorithm for Strong Connected Component
 *	Created by Ziyi Tang
 *  NOTE: The "lows" is not the lead of each node, the "lead" is.
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

int n,m; // n vertices and m edges
vvi all; // Unweighted Directed Graph
int nums[MAXN];
int lows[MAXN];
int mark[MAXN];
int lead[MAXN]; // The lead of each node from SCC
vi member; // The members
vi head; // The leads of each SCC
int counter;
int numSCC; // The number of SCCs

void tarjan(int now){
	mark[now] = 1;
	lows[now] = nums[now] = counter++;
	member.push_back(now);
	int sz = all[now].size();
	REP(i,0,sz){
		int tmp = all[now][i];
		if(nums[tmp] == -1)
			tarjan(tmp);
		if(mark[tmp]) // If marked, update the lows
			lows[now] = min(lows[now],lows[tmp]);
	}
	// After Recursion
	if(nums[now] == lows[now]){
		head.push_back(now);
		numSCC++;
		while(1){
			int nxt = member.back(); member.pop_back();
			lead[nxt] = now;
			printf("%d ",nxt); // Print members
			mark[nxt] = 0;
			if(now == nxt)
				break;
		}
		printf("\n");
	}
}
void init(){
	// Clear
	FILL(nums,-1);
	FILL(lows, 0);
	FILL(mark,0);
	FILL(lead,-1);
	head.clear();
	all.clear();
	vi tmp;
	all.assign(n,tmp);
	counter = 0;
	numSCC = 0;
}

void Tarjan(){
	// Begin
	REP(i,0,n){
		if(nums[i] == -1){
			tarjan(i);
		}
	}
}
int main(){
	
	cin >> n >> m;
	init();
	// Input
	int sta,ter;
	REP(i,0,m){
		cin >> sta >> ter;
		all[sta].push_back(ter);
	}
	Tarjan();
	return 0;
}
