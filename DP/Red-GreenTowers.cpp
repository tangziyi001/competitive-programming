/*
 *	CodeForces 478D
 *	Created by Ziyi Tang
 *	dp[i][j]: the number of different towers for level i with exact j red blocks.
 *	dp[i][j] = dp[i-1][j] + dp[i-1][j-i] (if j >= i)
 *	Note: Use 1D array.
 *  Sum up all possible towers with 0 to r-1 red blocks.
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
#define MAXN 200005
#define MOD 1000000007


int dp[MAXN];
int tmp[MAXN];
int r,g;
void copy(int* a, int* b){
	REP(i,0,r+1) b[i] = a[i];
}

// Binary Search for the Max Height
int findHeight(int num){
	int i = 1;
	int j = 1000;
	while(i <= j){
		int mid = (i+j)>>1;
		if(mid*(mid+1)/2 <= num)
			i = mid+1;
		else
			j = mid-1;
	}
	return j;
}

int main(){
	cin >> r >> g;
	int h = findHeight(r+g);
	//cout << h << "height" << endl;
	dp[0] = 1;
	REP(i,1,h+1){
		copy(dp, tmp);
		REP(j,0,r+1){
			dp[j] = tmp[j];
			if(j >= i)
				dp[j] += tmp[j-i];
			dp[j] %= MOD;
		}
	}
	int ans = 0;
	for(int i = 0; i <= r; i++) if(i+g >= h*(h+1)/2) {
		ans+=dp[i];
		ans%=MOD;
	}
	cout << ans << endl;

	return 0;
}

