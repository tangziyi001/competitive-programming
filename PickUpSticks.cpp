/*
 *	
 *	Coded by Ziyi Tang
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

int deg[1000005];
vi re;
vvi all;
int main(){
	int n,m;
	while(cin >> n >> m && (n!=0 || m!=0)){
		FILL(deg,0);
		re.clear();
		all.clear();
		all.assign(n,vi(0,0));
		REP(i,0,m){
			int sta,ter;
			cin >> sta >> ter;
			all[sta-1].push_back(ter-1);
			deg[ter-1]++;
		}
		queue<int> qq;
		REP(i,0,n){
			if(deg[i] == 0){
				qq.push(i);
				re.push_back(i);
			}
		}
		while(!qq.empty()){
			int now = qq.front();qq.pop();
			int sz = all[now].size();
			REP(i,0,sz){
				int tmp = all[now][i];
				deg[tmp]--;
				if(deg[tmp] == 0){
					re.push_back(tmp);
					qq.push(tmp);
				}
			}
		}
		if(re.size() == n){
			int sz = re.size();
			REP(i,0,sz){
				cout << re[i]+1 << endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;


	}
	return 0;
}