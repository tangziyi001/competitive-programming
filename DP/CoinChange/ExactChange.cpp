/*
 *	UVA 11517
 *	Created by Ziyi Tang
 *	Coin change for Bottom-up DP
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

int value, num;
int money[105];
int dp[30050];

int main(){
	int test;
	scanf("%d", &test);
	while (test--){
		for (int i = 0; i < 30000; i++){
			dp[i] = INF;
		}
		scanf("%d", &value);
		scanf("%d", &num);
		for (int i = 0; i < num; i++){
			scanf("%d", &(money[i]));
		}
		dp[0] = 0;
		for (int i = 0; i < num; i++){
			for (int j = 30000-money[i]; j >= 0; j--){
				if (dp[j] < INF){
					//cout << dp[12] << endl;
					dp[j+money[i]] = min(dp[j+money[i]], 1+dp[j]);
				}
			}
		}
		int amount = value;
		int tmp = dp[amount];
		//cout << tmp << endl;
		while (tmp == INF && amount < 30000){
			amount++;
			tmp = dp[amount];
		}
		printf("%d %d\n", amount, tmp);	
	}	




	return 0;
}
