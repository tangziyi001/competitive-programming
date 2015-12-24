/*
 *	UVA 10449
 *	Created by Ziyi Tang
 *	Bellman Ford - Mark Vertices along Negative Cycle by BFS/DFS
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

vi weight;
vvpi all;
int nega[205];
int dis[205];
int seen[205];
void mark(int now){
	int sz = all[now].size();
	seen[now] = 1;
	REP(i,0,sz){
		pi tmp = all[now][i];
		nega[tmp.first] = 1;
		if(seen[tmp.first] == 0)
			mark(tmp.first);
	}
}
int main(){
	int test = 0;
	int n;
	while(cin >> n){
		weight.clear();
		FILL(nega,0);
		FILL(seen,0);
		REP(i,0,n){
			dis[i] = INF;
		}
		all.clear();
		vpi ttmp;
		all.assign(n,ttmp);
		test++;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			weight.push_back(tmp);
		}
		int e;
		cin >> e;
		REP(i,0,e){
			int sta,ter;
			cin >> sta >> ter;
			int diff = weight[ter-1]-weight[sta-1];
			all[sta-1].push_back(make_pair(ter-1, diff*diff*diff));
		}

		// Bellman Ford
		dis[0] = 0;
		REP(i,0,n-1){
			REP(j,0,n){
				int sz = all[j].size();
				REP(k,0,sz){
					pi now = all[j][k];
					dis[now.first] = min(dis[now.first], dis[j] + now.second);
				}
			}
		}

		// Negative Cycles
		REP(i,0,n){
			int sz = all[i].size();
			REP(j,0,sz){
				pi tmp = all[i][j];
				if(dis[tmp.first] > dis[i] + tmp.second){
					nega[tmp.first] = 1;
					mark(tmp.first);
				}
					
			}
		}
		int num;
		cin >> num;
		int des;
		printf("Set #%d\n",test);
		REP(i,0,num){
			cin >> des;
			int re = dis[des-1];
			if(re < 3 || re > (int)1E8 || nega[des-1] == 1)
				printf("?\n");
			else
				printf("%d\n", dis[des-1]);
				
		}

	}
	return 0;
}
