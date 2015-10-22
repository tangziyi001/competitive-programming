/*
 *	UVA 216
 *	Created by Ziyi Tang
 *	Bitmask in TSP problem
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
vector<pair<int, int> > all;
int num;

double tsp(int pos, int path){
	if (path == (1 << num) - 1){
		return dp[pos][path] = mat[pos][0];
	}
	if (dp[pos][path] != -1){
		//cout << pos << " " << path << " binary "<< dp[pos][path] << endl;
		return dp[pos][path];
	}
	else{
		double minp = INF;
		for (int i = 0; i < num; i++){
			if ((path & (1 << i)) == 0){
				cout << path << "path" << endl;
				double tmp = mat[pos][i]+tsp(i, path | (1 << i));
				if (minp > tmp)
					minp = tmp;
			}
		}
		return dp[pos][path] = minp;
	}
}
int main(){
	
	while (scanf("%d", &num) && num != 0){
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
		int path = 1;
		double re = tsp(0, path);
		// for (int i = 0 ; i < num; i++){
		// 	for (int j = 0; j < num; j++){
		// 		cout << mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		printf("%lf\n", re);
	}	




	return 0;
}
