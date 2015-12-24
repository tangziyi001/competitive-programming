/*
 *	UVA 10557
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vvpi all;
vvpi all2;
int dis[105];
int seen[105];
int reach[105];

void DFS(int ter){
	//cout << "DFS" << ter << endl;
	reach[ter] = 1;
	int sz = all2[ter].size();
	REP(i,0,sz){
		pi tmp = all2[ter][i];
		if(reach[tmp.first] == 0){
			DFS(tmp.first);
		}
	}
}
bool dfs(int sta,int ter){
	//cout << sta << "sta" <<endl;
	seen[sta] = 1;
	if(sta == ter && dis[sta] > 0)
		return true;
	if(dis[sta] <= 0)
		return false;
	int sz = all[sta].size();
	REP(i,0,sz){
		pi tmp = all[sta][i];
		if(seen[tmp.first] == 0){
			dis[tmp.first] = dis[sta] + tmp.second;
			if(dfs(tmp.first,ter))
				return true;
		}
		else if(dis[tmp.first] < dis[sta] + tmp.second && reach[tmp.first] == 1)
			return true;
	} 
	return false;
}
int main(){
	int nums;
	while(cin >> nums && nums != -1){
		all2.clear();
		all.clear();
		vpi ttmp;
		all.assign(nums,ttmp);
		all2.assign(nums,ttmp);
		REP(i,0,nums){
			dis[i] = -INF;
		}
		FILL(reach,0);
		FILL(seen,0);
		dis[0] = 100;
		int ter,cost;
		REP(i,0,nums){
			cin >> cost >> ter;
			int next;
			REP(j,0,ter){
				cin >> next;
				all[i].push_back(make_pair(next-1,cost));
				all2[next-1].push_back(make_pair(i,cost));
			}
		}
		DFS(nums-1);
		bool re = dfs(0,nums-1);
		if(re)
			cout << "winnable" << endl;
		else
			cout << "hopeless" << endl;


	}
	return 0;
}
