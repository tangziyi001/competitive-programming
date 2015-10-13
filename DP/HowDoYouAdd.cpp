// UVA 10943
// n+k-1 choose k-1. Dynamic Programming. To put n balls into k boxes, recursively Put i in the first box, and remaining n-i into k-1 box.

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const ll mod = 1000000;
ll c;
ll k;
ll dp [105][105];

ll check(ll c, ll k){
	if (dp[c][k] != -1){
		return dp[c][k]%mod;
	}
	else{
		dp[c][k] = 0;
		for (int i = 0; i <= c; i++){
			dp[c][k] += check(c-i, k-1);
			
		}
		return dp[c][k]%mod;
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 105; i++){
		dp[i][1] = 1;
		dp[0][i] = 1;
	}
	while (cin >> c >> k && (c != 0 || k != 0)){	
		ll x = check (c,k);	
		cout << x << endl;
	}
}

