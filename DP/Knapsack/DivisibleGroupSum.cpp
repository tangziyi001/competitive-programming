/*
 *	UVA 10616
 *	Created by Ziyi Tang
 *	Subset Sum in Dynamic Programming
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

// all numbers, chosen numbers, mod
ll dp[205][15][25];
bool ck[205][15][25];
vector<ll> all;
ll d = 0;

ll maxnum(ll n, ll m, ll mod){
	if(m < 0){
		if (mod == 0){
			return 1;
		}
		return 0;
	}
	if(n < 0){
		return 0;
	}
	if (ck[n][m][mod] == true){
		return dp[n][m][mod];
	}
	else{
		ck[n][m][mod] = true;
		ll newmod = (all[n]%d+mod+d)%d;
		return dp[n][m][mod] = maxnum(n-1, m-1, newmod) + maxnum(n-1,m,mod);
	}
}

int main(){
	int n,q;
	int count = 0;
	while (cin >> n >> q && n != 0 && q != 0){
		count++;
		all.clear();
		for (int i = 0; i < n; i++){
			ll tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		printf("SET %d:\n",count);
		for (int i = 0; i < q; i++){
			memset(dp, 0, sizeof(dp));
			memset(ck,false, sizeof(ck));
			ll m, qu;
			cin >> qu >> m;
			d = qu;
			ll re = maxnum(n-1, m-1, 0);
			printf("QUERY %d: %lld\n",i+1,re);
		}
	}

	return 0;
}
