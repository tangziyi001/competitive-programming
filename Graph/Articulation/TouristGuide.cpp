/*
 *	UVA 10199
 *	Created by Ziyi Tang
 *	Basic Articulation Point
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

vvi all; //Unweighted Undirected Graph
map<string,int> strint;
vector<string> intstr;
int root;
int children;
int p[MAXN];
int nums[MAXN];
int lows[MAXN];
int counter;
int re[MAXN]; // Articulation Points will be set to 1
vpi edges; // Record Articulation Edges
void arti(int now){
	lows[now] = nums[now] = counter;
	counter++;
	int sz = all[now].size();
	REP(i,0,sz){
		int tmp = all[now][i];
		if(nums[tmp] == -1){
			p[tmp] = now;
			if (root == now)
				children++;
			arti(tmp);
			if(lows[tmp] >= nums[now]){
				re[now] = 1;
			}
			if(lows[tmp] > nums[now]){
				edges.push_back(make_pair(now,tmp));
			}
			lows[now] = min(lows[now],lows[tmp]);
		}
		else if(p[now] != tmp){
			lows[now] = min(lows[now], nums[tmp]);
		}
	}
}
int main(){
	int n,m; //vertices, edges
	int test = 0;
	while(cin >> n && n != 0){
		test++;
		// Clear
		FILL(nums,-1);
		FILL(lows,0);
		FILL(re,0);
		edges.clear();
		all.clear();
		vi tmp;
		all.assign(n,tmp);
		counter = 0;
		strint.clear();
		intstr.clear();
		REP(i,0,n){
			string now;
			cin >> now;
			strint[now] = i;
			intstr.push_back(now);
		}
		cin >> m;
		REP(i,0,m){
			string sta,ter;
			cin >> sta >> ter;
			all[strint[sta]].push_back(strint[ter]);
			all[strint[ter]].push_back(strint[sta]);
		}

		// Begin
		REP(i,0,n){
			if(nums[i] == -1){
				root = i;
				children = 0;
				arti(i);
				re[root] = (children > 1);
			}
		}
		
		// Test
		vector<string> tre;
		REP(i,0,n){
			if(re[i]) tre.push_back(intstr[i]);
		}
		sort(tre.begin(),tre.end());
		int sz = tre.size();
		if(test!=1) printf("\n");
		printf("City map #%d: %d camera(s) found\n",test,sz);
		REP(i,0,sz){
			printf("%s\n",tre[i].c_str());
		}
	}
	return 0;
}
