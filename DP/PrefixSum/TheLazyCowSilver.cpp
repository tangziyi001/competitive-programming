/*
 *	USACO 2014 March Contest, Silver 2
 *	Coded by Ziyi Tang
 *	Prefix Sum by rows
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
#define MAXN 500

int grid[MAXN][MAXN];
int sum[MAXN+1][MAXN+1];
int n,k;
bool check(int c){
	if(c >= 0 && c < n) return true;
	return false;
}
int main(){
	freopen("lazy.in", "r", stdin);
  	freopen("lazy.out", "w", stdout);
  	cin >> n >> k;
  	REP(i,0,n) REP(j,0,n){
  		int tmp;
  		cin >> tmp;
  		grid[i][j] = tmp;
  	}
  	
  	REP(i,0,n){
  		sum[i][0] = 0;
  	}
  	REP(i,0,n) REP(j,0,n){
  		sum[i][j+1] = sum[i][j] + grid[i][j];
  	}
  	int maxp = 0;
  	REP(i,0,n) REP(j,0,n){
  		int allsum = 0;
  		for(int r = -k; r <= k; r++) if(check(i+r)){
  			int rad = k-abs(r);
  			int left = max(0, j-rad);
  			int right = min(n-1, j+rad);
  			allsum += sum[i+r][right+1]-sum[i+r][left];
  		}
  		maxp = max(maxp, allsum);
  	}
  	cout << maxp << endl;
	return 0;
}