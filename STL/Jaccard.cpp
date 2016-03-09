/*
 *	APS Midterm C.D
 *	Created by Ziyi Tang
 *	LIS with dp
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vi all;
int dp[100005];
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		FILL(dp,0);
		int n,k;
		cin >> n >> k;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		dp[0] = 1;
		int mmax = 0;
		REP(i,1,n){
			int maxp = 0;
			REP(j,0,i){
				if(all[i] >= k + all[j])
					maxp = max(maxp, dp[j]);
			}
			dp[i] = 1 + maxp;
			mmax = max(mmax, dp[i]);
		}
		// REP(i,0,n){
		// 	cout << dp[i] << endl;
		// }
		cout << mmax << endl;
	}
	return 0;
}

