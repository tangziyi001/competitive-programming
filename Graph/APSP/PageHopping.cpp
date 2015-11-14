/*
 *	UVA 00821
 *	Created by Ziyi Tang
 *	Basic Floyd-Warshall
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
set<int> nums;
int main(){
	int a,b;
	int cas = 0;
	while(cin >> a >> b && a != 0 && b != 0){
		cas++;
		nums.clear();
		REP(i,0,105){
			REP(j,0,105){
				grid[i][j] = INF;
				if(i == j)
					grid[i][j] = 0;
			}
		}
		grid[a-1][b-1] = 1;
		while(cin >> a >> b && a != 0 && b != 0){
			grid[a-1][b-1] = 1;
			nums.insert(a);
			nums.insert(b);
		}
		REP(k,0,100){
			REP(i,0,100){
				REP(j,0,100){
					if(grid[i][k] == INF || grid[k][j] == INF)
						continue;
					grid[i][j] = min(grid[i][j], grid[i][k]+grid[k][j]);
				}
			}
		}
		ll sum = 0;
		// REP(i,0,10){
		// 	REP(j,0,10){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		REP(i,0,100){
			REP(j,0,100){
				if(grid[i][j]!=INF)
					sum+=grid[i][j];
			}
		}
		int maxp = nums.size();
		printf("Case %d: average length between pages = %.3lf clicks\n", cas, (double)sum/(maxp*maxp-maxp));
	}

	return 0;
}
