// Codechef SEARRAYS
// Created by Ziyi Tang
// Basic DP

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#define MAXN 100050
#define MOD 1000000007
using namespace std;

long long dp[MAXN];
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < MAXN; i++){
			dp[i] = 0LL;
		}
		int n,k;
		cin >> n >> k;
		long long re = 0LL;
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			dp[i] = dp[i-1];
			if(i-k >= 0){
				dp[i] += 1+dp[i-k];
				dp[i] %= MOD;
			}
		}
		cout << (1+dp[n])%MOD << endl;
	}
	return 0;
}