/*
 *	UVA 10496
 *	Created by Ziyi Tang
 *	Typical TSP Problem
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

int dp[15][2048];
int mat[15][15];
int sz = 0;
vpi all;

int tsl(int pos, int bm){
	if (bm == (1 << sz) - 1)
		return mat[pos][0];
	if (dp[pos][bm] != -1){

		return dp[pos][bm];
	}
	else{
		int minp = INF;
		for (int i = 0; i < sz; i++){
			if ((bm & (1 << i)) == 0){
				minp = min(minp, mat[pos][i] + tsl(i, bm | (1 << i)));
			}
		}
		return dp[pos][bm] = minp;
	}

}
int main(){
	int test;
	scanf("%d", &test);
	for (int t = 0; t < test; t++){
		all.clear();
		memset(dp,-1,sizeof(dp));
		memset(mat,0,sizeof(mat));
		int x,y;
		scanf("%d %d",&x,&y);
		int sx,sy;
		scanf("%d %d",&sx,&sy);
		all.push_back(make_pair(sx,sy));
		int num;
		scanf("%d",&num);
		for (int k = 0; k < num; k++){
			int tx,ty;
			scanf("%d %d",&tx,&ty);
			all.push_back(make_pair(tx,ty));
		}
		sz = all.size();
		for (int i = 0; i < sz-1; i++){
			for (int j = i+1; j < sz; j++){
				mat[i][j] = abs(all[i].first-all[j].first) + abs(all[i].second-all[j].second);
				mat[j][i] = mat[i][j];
			}
		}

		// for (int i = 0; i < sz; i++){
		// 	for (int j = 0; j < sz; j++){
		// 		cout << mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		int bm = 1;
		int re = tsl(0, bm);
		printf("The shortest path has length %d\n", re);
	}




	return 0;
}
