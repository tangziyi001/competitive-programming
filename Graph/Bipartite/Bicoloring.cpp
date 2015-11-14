/*
 *	UVA 10004
 *	Created by Ziyi Tang
 *	Basic Bipartite Check
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
int col[205];
int main(){
	int num;
	while(cin >> num && num != 0){
		FILL(col,-1);
		all.clear();
		vi tmp;
		all.assign(num,tmp);
		int edge;
		cin >> edge;
		bool isbc = true;
		REP(i,0,edge){
			int sta,ter;
			cin >> sta >> ter;
			all[sta].push_back(ter);
		}
		while(!que.empty()){
			que.pop();
		}
		col[0] = 0;
		que.push(0);
		while(!que.empty()){
			int now = que.front();que.pop();
			int sz = all[now].size();
			REP(i,0,sz){
				int nxt = all[now][i];
				if(col[nxt] == -1){
					col[nxt] = 1-col[now];
					que.push(nxt);
				}
				else if(col[nxt] == 1-col[now]){
					continue;
				}
				else if(col[nxt] == col[now]){
					isbc = false;
					break;
				}
			}
			if(isbc == false){
				break;
			}
		}
		if(isbc == false){
			cout << "NOT BICOLORABLE." << endl;
		}
		else{
			cout << "BICOLORABLE." << endl;
		}

	}

	return 0;
}
