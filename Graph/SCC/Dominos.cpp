/*
 *	UVA 11504
 *	Created by Ziyi Tang
 *	Count the number of 0 degree node within Tarjan-contract Graph.
 *  NOTE: The "lows" is not the lead of each node, the "lead" is.
 *  Reduce the "degree" of the next vertex when the currect vertex has the
 *  same lead as the next vertex. A SCC has 0 degree if all of its members has
 *  0 "degree".
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
#define MAXN 100010

vvi all; // Unweighted Directed Graph
int nums[MAXN];
int lows[MAXN];
int mark[MAXN];
int deg[MAXN];
int flag[MAXN];
int root[MAXN];
vi member; // The members within a SCC
vi head; // The root of each SCC
int counter;
int numSCC; // The number of SCCs
int re;
void tarjan(int now){
	mark[now] = 1;
	lows[now] = nums[now] = root[now] = counter++;
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
			root[nxt] = now;
			//printf("%d ",nxt); // Print members
			mark[nxt] = 0;
			int nsz = all[nxt].size();
			REP(i,0,nsz){
				int tmp = all[nxt][i];
				if(root[tmp] == root[nxt]){
					deg[tmp]--;
				}
			}
			if(now == nxt)
				break;
		}
		//if(member.size() == 0)
			
		//printf("\n");
	}
}
int main(){
	int test;
	cin >> test;
	while(test--){
		int n,m;
		// n vertices and m edges
		cin >> n >> m;

		// Clear
		re = 0;
		FILL(nums,-1);
		FILL(lows, 0);
		FILL(mark,0);
		FILL(deg,0);
		FILL(flag,0);
		FILL(root,0);
		head.clear();
		all.clear();
		vi tmp;
		all.assign(n,tmp);
		counter = 0;
		numSCC = 0;

		// Input
		int sta,ter;
		REP(i,0,m){
			cin >> sta >> ter;
			deg[ter-1]++;
			all[sta-1].push_back(ter-1);
		}

		// Begin
		REP(i,0,n){
			if(nums[i] == -1){
				tarjan(i);
			}
		}
		
		REP(i,0,n){
			//cout << i << " " << deg[i] << " " << root[i] << endl;
			if(deg[i] != 0)
				flag[root[i]] = -1;
		}
		int sz = head.size();
		REP(i,0,sz){
			if(flag[head[i]] == 0)
				re++;
		}
		
		cout << re << endl;
		// Test
	}
	return 0;
}
