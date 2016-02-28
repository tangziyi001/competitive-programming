/*
 *	
 *	Created by Ziyi Tang
 *	Traverse from 0 to other nodes. Remove each node and traverse it again.
 *  If a node can be reached before but cannot be reached after, then the node
 *	removed is a dominator of that node.
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

int all[105][105];
int before[105];
int after[105];
int re[105][105];
int n;
void dfs1(int now){
	before[now] = 1;
	re[0][now] = 1;
	REP(i,0,n){
		if(all[now][i] == 1 && before[i] == 0)
			dfs1(i);
	}
}
void dfs2(int now, int rem){
	after[now] = 1;
	REP(i,0,n){
		if(i != rem && all[now][i] == 1 && after[i] == 0)
			dfs2(i, rem);
	}
}
string printB(int n){
	string ttmp = "";
	ttmp += '+';
	for(int i = 0; i < 2*n-1; i++) ttmp+='-';
	ttmp += '+';
	return ttmp;
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		FILL(re,0);
		FILL(all,0);
		FILL(before,0);
		cin >> n;
		REP(i,0,n){
			REP(j,0,n){
				int tmp;
				cin >> tmp;
				all[i][j] = tmp;
			}
		}
		dfs1(0);
		REP(i,1,n){
			FILL(after,0);
			dfs2(0,i);
			REP(j,0,n){
				if(before[j] == 1 && after[j] == 0){
					re[i][j] = 1;
				}
			}
		}
		string line = printB(n);
		printf("Case %d:\n", t);
		printf("%s\n",line.c_str());
		REP(i,0,n){
			REP(j,0,n){
				if(j == 0)
					printf("|");
				char now = 'N';
				if(re[i][j] == 1) now = 'Y';
				printf("%c|", now);
			}
			printf("\n%s\n",line.c_str());
		}
	}
	return 0;
}

