/*
 *	UVA 11396
 *	Created by Ziyi Tang
 *	
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
queue<int> que;
int col[305];
int main(){
	int n;
	while(cin >> n && n != 0){
		bool bc = true;
		while(!que.empty()){
			que.pop();
		}
		FILL(col,-1);
		all.clear();
		vi tmp;
		all.assign(n+1,tmp);
		int sta,ter;
		while(cin >> sta >> ter && sta != 0 && ter != 0){
			all[sta].push_back(ter);
			all[ter].push_back(sta);
		}
		REP(i,1,n+1){
			if(col[i] == -1){
				col[i] = 0;
				que.push(i);
				while(!que.empty()){
					int now = que.front();que.pop();
					int sz = all[now].size();
					REP(j,0,sz){
						int nxt = all[now][j];
						if(col[nxt] == -1){
							col[nxt] = 1-col[now];
							que.push(nxt);
						}
						else if(col[nxt] == col[now]){
							bc = false;
							break;
						}

					}
					if(bc == false){
						break;
					}
				}
			}
		}
		if(bc == false){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}

	}

	return 0;
}
