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
#define MAXN 100

int v,e;
ll fw[MAXN][MAXN];
int main(){
	cin >> v >> e;
	
	// No Self Loop 
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			fw[i][j] = i == j ? 0 : INFL;
		}
	}
	// Fill in the Adj Matrix
	for (int i = 0; i < e; i++){
		ll a,b,c;
		cin >> a >> b >> c;
		fw[a][b] = c;
	}
	for (int k = 0; k < v; k++){
		for (int i = 0; i < v; i++){
			for (int j = 0; j < v; j++){
				if (fw[i][k] == INFL || fw[k][j] == INFL)
					continue;
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}
	return 0;
}
