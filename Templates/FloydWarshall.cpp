/*
 *	Floyd Warshall’s algorithm
 *	Created by Ziyi Tang
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
#define INF (int)1E9
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
#define MAXN 1000

//v vertices and e edges
int v,e;
int grid[MAXN][MAXN];
int p[MAXN][MAXN];

void printPath(int i, int j){
	if (i != j) 
		printPath(i, p[i][j]);
	printf(" %d", j); 
}
int main(){
	cin >> v >> e;
	
	// Clear (No self loop)
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			grid[i][j] = (i == j) ? 0 : INF;
			p[i][j] = i;
		}
	}
	// Input the Adj Matrix
	for (int i = 0; i < e; i++){
		int x,y,c;
		cin >> x >> y >> c;
		grid[x][y] = c;
	}

	// Begin
	for (int k = 0; k < v; k++){
		for (int i = 0; i < v; i++){
			for (int j = 0; j < v; j++){
				if (grid[i][k] == INF || grid[k][j] == INF)
					continue;
				if(grid[i][k] + grid[k][j] < grid[i][j]){
					grid[i][j] =  grid[i][k] + grid[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}

	// Print Path
	cin >> a >> b;
	printPath(a,b);
	return 0;
}
