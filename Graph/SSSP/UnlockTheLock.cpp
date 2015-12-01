/*
 *	UVA 12160 
 *	Created by Ziyi Tang
 *	BFS
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
#define MAXN 10005

int all[MAXN];
vi adder;
queue<int> que;
int main(){
	int sta,ter,n;
	int test = 0;
	while(cin >> sta >> ter >> n && (sta != 0 || ter != 0 || n != 0)){
		test++;
		int minp = INF;
		while(!que.empty())
			que.pop();
		FILL(all,-1);
		adder.clear();

		REP(i,0,n){
			int tmp;
			cin >> tmp;
			adder.push_back(tmp);
		}
		all[sta] = 0;
		que.push(sta);
		while(!que.empty()){
			int now = que.front();que.pop();
			REP(i,0,n){
				int tmp = (now + adder[i])%10000;
				if(all[tmp] == -1){
					all[tmp] = all[now] + 1;
					que.push(tmp);
				}
				if(tmp == ter){
					minp = min(minp, all[tmp]);
					break;
				}
			}
			if(minp != INF)
				break;
		}
		if(minp == INF)
			printf("Case %d: Permanently Locked\n", test);
		else
			printf("Case %d: %d\n", test, minp);
	}

	return 0;
}
