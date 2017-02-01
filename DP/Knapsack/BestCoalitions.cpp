/*
 *	UVA 11658
 *	Created by Ziyi Tang
 *	DP: Knapsack
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int n,idx;
vector<int> all;
int dp[105][10010];
int main(){
	while(cin >> n >> idx && n != 0 && idx != 0){
		all.clear();
		int val = 0;
		FILL(dp,0);
		all.push_back(-1);
		REP(i,1,n+1){
			int a,b,tmp;
			scanf("%d.%d", &a, &b);
			tmp = a*100+b;
			if(i == idx){
				val = tmp;
				continue;
			}
			all.push_back((int)tmp);
		}
		int sz = all.size();
		REP(i,0,105){
			dp[i][0] = 1;
		}
		REP(i,1,sz){
			REP(j,0,10005) {
				dp[i][j] = dp[i-1][j];
				if(j >= all[i]){
					if(dp[i-1][j-all[i]] == 1)
						dp[i][j] = 1;
				}
			}
		}
		double re = 0;
		// REP(i,0,10010) if(dp[sz-1][i] == 1) cout << i << endl;
		REP(i,0,10010){
			if(dp[sz-1][i] == 1 && i+val > 5000){
				//cout << val << " " << i+val << endl;
				re = 100.0*val/(i+val);
				printf("%.2f\n", re);
				break;
			}
		}
	}
	return 0;
}