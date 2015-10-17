/*
 *	UVA 10819
 *	Created by Ziyi Tang
 *	Knapsack with extra twist.
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
#define INF 1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
 
int dp[10250][110];
int price[110];
int favor[110];
int bud, fav;
int check(int m, int n){
	if(m > bud && bud < 1800){
		return -1000;
	}
	if(m > bud + 200){
		return -1000;
	}
	if(n == fav){
		if (m > bud && m <= 2000){
			return -1000;
		}
		return 0;
	}
	if (dp[m][n] != -1){
		return dp[m][n];
	}
	else{
		return dp[m][n] = max(favor[n] + check(m+price[n],n+1), check(m, n+1));
	}
}
int main(){
	while (scanf("%d %d", &bud, &fav) != EOF){
		memset(dp,-1,sizeof(dp));
		int tmpfav = fav;
		int tmp1, tmp2;
		for (int i = 0; i < tmpfav; i++){
			scanf("%d %d", &tmp1, &tmp2);
			price[i] = tmp1;
			favor[i] = tmp2;
		}
		int result = check(0, 0);
		printf("%d\n", result);
	}




	return 0;
}
