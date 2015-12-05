/*
 *	
 *	Created by Ziyi Tang
 *	
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
#define MAXN 105

int grid[MAXN][MAXN];
int row[MAXN];
int col[MAXN];
int main(){
	int n;
	FILL(grid,0);
	FILL(row,0);
	FILL(col,0);
	while(cin >> n && n != 0){
		int tmp;
		int row_odd = 0;
		int rid = -1;
		int cid = -1;
		int col_odd = 0;
		REP(i,0,n){
			int sum = 0;
			REP(j,0,n){
				cin >> tmp;
				grid[i][j] = tmp;
				sum += tmp;
			}
			if(sum%2 != 0){
				row_odd++;
				rid = i;
			}
		}

		REP(j,0,n){
			int sum = 0;
			REP(i,0,n){
				sum += grid[i][j];
			}
			if(sum%2 != 0){
				col_odd++;
				cid = j;
			}
		}
		if(row_odd == 0 && col_odd == 0){
			cout << "OK" << endl;
		}
		else if(row_odd == 1 && col_odd == 1){
			printf("Change bit (%d,%d)\n", rid,cid);
		}
		else{
			cout << "Corrupt" << endl;
		}
	}
	return 0;
}
