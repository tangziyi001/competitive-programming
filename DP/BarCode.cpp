/*
 *	UVA 10721
 *	Created by Ziyi Tang
 *	How Do You Add
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

int n,k,m;
ll dp[55][55]; //k,n


int main(){
	while (cin >> n >> k >> m){
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n && i <= m; i++){
			dp[1][i] = 1;
		}
		for (int i = 2; i <= k; i++){
			for (int j = 1; j <= n; j++){
				for (int t = 1; t <= m; t++){
					if (j-t < 1) continue;
					dp[i][j] += dp[i-1][j-t];
				}
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}
