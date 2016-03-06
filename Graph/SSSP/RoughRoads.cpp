/*
 *	
 *	Created by Ziyi Tang
 *	Multi-level Floyd Warshall's Algorithm
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

int n,m;
int grid[505][505];
int biggrid[505*2][505*2];
int main(){
	int test = 0;
	while(scanf("%d %d",&n,&m) != EOF){
		test++;
		REP(i,0,n) REP(j,0,n){
			grid[i][j] = INF;
		}
		REP(i,0,2*n) REP(j,0,2*n){
			biggrid[i][j] = INF;
		}
		REP(i,0,m){
			int sta,ter,cost;
			scanf("%d %d %d",&sta,&ter,&cost);
			grid[sta][ter] = cost;
			grid[ter][sta] = cost;
		}
		REP(i,0,n) REP(j,0,n){
			biggrid[i][j+n] = grid[i][j];
			biggrid[i+n][j] = grid[i][j];
		}
		REP(k,0,2*n) REP(i,0,2*n) REP(j,0,2*n){
			if(biggrid[i][k] == INF || biggrid[k][j] == INF) continue;
			biggrid[i][j] = min(biggrid[i][j], biggrid[i][k]+biggrid[k][j]);
		}
		printf("Set #%d\n",test);
		if(biggrid[0][n-1] != INF)
			printf("%d\n",biggrid[0][n-1]);
		else 
			printf("?\n");
		
	}
	return 0;
}

