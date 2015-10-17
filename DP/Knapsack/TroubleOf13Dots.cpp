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

int dp[10005][110];
vi price;
vi favor;
int bud, fav;
int check(int m, int n){
	if (m < 0 && bud < 1800){
		return -1000;
	}
	else if (m < -200){
		return -1000;
	}
	if (n == 0){
		if (m < 0 && bud-m <= 2000){
			return -1000;
		}
		else{
			return 0;
		}
	}
	if (dp[m][n] != -1){
		return dp[m][n];
	}
	else{
		return dp[m][n] = max(favor[n] + check(m-price[n], n-1), check(m, n-1));
	}
}
int main(){
	while (cin >> bud >> fav){
		memset(dp,-1,sizeof(dp));
		int tmpfav = fav;
		price.clear();
		favor.clear();
		int tmp1, tmp2;
		while (tmpfav--){
			cin >> tmp1 >> tmp2;
			price.push_back(tmp1);
			favor.push_back(tmp2);
		}
		int result = check(bud, fav-1);
		cout << result << endl;
	}




	return 0;
}
