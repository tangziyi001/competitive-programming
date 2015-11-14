/*
 *	UVA 11463
 *	Created by Ziyi Tang
 *	Floyd Warshall, find the farest point starting from two point.
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

int grid[105][105];
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		REP(i,0,105) REP(j,0,105){
				if(i == j){
					grid[i][j] = 0;
					continue;
				}
				grid[i][j] = INF;
		}
		int num;
		cin >> num;
		vi tmp;
		int road;
		cin >> road;
		REP(r,0,road){
			int sta,ter;
			cin >> sta >> ter;
			grid[sta][ter] = 1;
			grid[ter][sta] = 1;
		}
		REP(k,0,num) REP(i,0,num) REP(j,0,num){
			if(grid[i][k] == INF || grid[k][j] == INF) continue;
			grid[i][j] = min(grid[i][j], grid[i][k]+grid[k][j]);	
		}
		//Test
		// REP(i,0,num){
		// 	REP(j,0,num){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int x,y;
		cin >> x >> y;
		int maxp = -1;
		REP(i,0,num){
			maxp = max(maxp, grid[x][i]+grid[y][i]);
		}
		printf("Case %d: %d\n",t,maxp);

	}

	return 0;
}
