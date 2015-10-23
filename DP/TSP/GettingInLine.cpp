/*
 *	UVA 216
 *	Created by Ziyi Tang
 *	Bitmask in TSP problem, track the next step, multiple starting point
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

double mat[10][10];
double dp[10][1024];
int pt[10][1024];
vpi all;
int num;

double tsp(int pos, int path){
	if (path == (1 << num) - 1){
		return 0;
	}
	if (dp[pos][path] != -1){
		return dp[pos][path];
	}
	else{
		double minp = INF;
		int minnxt;
		for (int i = 0; i < num; i++){
			if ((path & (1 << i)) == 0){
				double tmp = mat[pos][i]+tsp(i, path | (1 << i));
				if (minp > tmp){
					minp = tmp;
					minnxt = i;
				}
			}
		}
		pt[pos][path] = minnxt;
	 	return dp[pos][path] = minp;
	}
}
int main(){
	int count = 0;
	while (scanf("%d", &num) && num != 0){
		count++;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				mat[i][j] = 0;
			}
		}
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 1024; j++){
				dp[i][j] = -1;
			}
		}
		all.clear();
		

		for (int t = 0; t < num; t++){
			int x,y;
			scanf("%d %d", &x, &y);
			all.push_back(make_pair(x,y));
		}
		for (int i = 0; i < num-1; i++){
			for (int j = i+1; j < num; j++){
				mat[i][j] = 16.0 + sqrt((double)(all[i].first-all[j].first)*(all[i].first-all[j].first)
							 + (double)(all[i].second-all[j].second)*(all[i].second-all[j].second));
				mat[j][i] = mat[i][j];
			}
			
		}
		
		int start = 0;
		double re = INF; 
		int fp[10][1024];
		for (int i = 0; i < num; i++){
			int path = 1 << i;
			double tmp = tsp(i, path);
			if (re > tmp){
				re = tmp;
				for (int i = 0; i < 10; i++){
					for (int j = 0; j < 1024; j++){
						fp[i][j] = pt[i][j];
					}
				}
				start = i;
			}
			for (int i = 0; i < 10; i++){
				for (int j = 0; j < 1024; j++){
					dp[i][j] = -1;
				}
			}
			memset(pt,0,sizeof(pt));
		}

		printf("**********************************************************\n");
		printf("Network #%d\n",count);
		int bp = 1 << start;
		int next = fp[start][bp];
		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", all[start].first,all[start].second, all[next].first, all[next].second, mat[start][next]);
		for (int i = 1; i < num-1; i++){
			bp |= (1<<next);
			int ori = next;
			next = fp[next][bp];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", all[ori].first,all[ori].second, all[next].first, all[next].second, mat[ori][next]);
		}
		printf("Number of feet of cable required is %.2lf.\n", re);
		
	}	




	return 0;
}
