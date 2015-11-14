/*
 *	UVA 11080
 *	Created by Ziyi Tang
 *	Multiple Connected Graph. Find less-used color after Bipartite for each CC (only if that color has been used).
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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


vvi all;
int col[210];
queue<int> que;
int main(){
	int test;
	cin >> test;
	while(test--){
		bool bc = true;
		all.clear();
		FILL(col,-1);
		while(!que.empty()){
			que.pop();
		}
		int v,e;
		cin >> v >> e;
		vi tmp;
		all.assign(v,tmp);
		int sum = 0;
		
		REP(i,0,e){
			int sta,ter;
			cin >> sta >> ter;
			all[sta].push_back(ter);
			all[ter].push_back(sta);
		}
		REP(i,0,v){
			int sum1 = 0;
			int sum0 = 0;
			if(col[i] == -1){
				col[i] = 0;
				que.push(i);
				while(!que.empty()){
					int now = que.front();que.pop();
					int sz = all[now].size();
					if(col[now] == 0){
						sum0++;
					}
					else{
						sum1++;
					}
					REP(j,0,sz){
						int tmp = all[now][j];
						if(col[tmp] == -1){
							col[tmp] = 1-col[now];
							que.push(tmp);
						}
						else if(col[tmp] == col[now]){
							bc = false;
							break;
						}
					}
					if(bc == false){
						break;
					}
				}
				if(bc == false){
					break;
				}
				if(sum1 != 0 && sum0 != 0)
					sum += min(sum1,sum0);
				else{
					sum += 1;
				}
			}
		}
		if(bc == false){
			cout << -1 << endl;
		}
		else{
			cout << sum << endl;
		}

	}

	return 0;
}
