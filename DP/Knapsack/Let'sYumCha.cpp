/*
 *	UVA 11566
 *	Created by Ziyi Tang
 *	Knapsack with more three states, Accuracy of Long Double
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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int price[210];
int favor[210];
int dp[1150][210][230];
int knapsack(int p, int i, int tp, int tq, int q, int up, int tea){
	if (i >= tq){
		return 0;
	}
	if ( ceil((double)(p + price[i] + tea) * 1.1L) > tp){
		return knapsack(p, i+1, tp, tq, q, up, tea);
	}
	if (q >= up){
		return 0;
	}
	if (dp[p][i][q] != -1){
		return dp[p][i][q];
	}
	else{
		int tmp1 = favor[i] + knapsack(p + price[i], i+1, tp, tq, q+1, up, tea);
		int tmp2 = knapsack(p, i+1, tp, tq, q, up, tea);
		return dp[p][i][q] = max(tmp1, tmp2);
	}
}
int main(){
	int n, x, t, k;
	while (scanf("%d %d %d %d", &n,&x,&t,&k) && ( n != 0||x != 0||t != 0||k != 0 )){
		memset(price, 0, sizeof(price));
		memset(favor, 0, sizeof(favor));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 2*k; i+=2){
			int p;
			scanf("%d",&p);
			price[i] = p;
			price[i+1] = p;
			for (int j = 0; j < n+1; j++){
				int f;
				scanf("%d",&f);
				favor[i] += f;
			}
			//cout << favor[i] << endl;
			favor[i+1] = favor[i];
		}
		int total_price = (n+1)*x;
		int total_quantity = 2*(n+1);
		int total_tea = t*(n+1);
		//cout << total_price << " " << 2*k << " " << total_quantity << endl;
		int result = knapsack(0, 0, total_price, 2*k, 0, total_quantity, total_tea);
		//cout << result << endl;
		double mean = (double)result/(double)(n+1);
		printf("%0.2lf\n", mean);

	}




	return 0;
}
