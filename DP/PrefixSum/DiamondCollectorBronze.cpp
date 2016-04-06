/*
 *	USACO 2016 US Open Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	Prefix Sum
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
#define MAXN 10005

int sum[MAXN+1];
int all[MAXN];
int n,k;
int main(){
	freopen("diamond.in", "r", stdin);
  	freopen("diamond.out", "w", stdout);
  	cin >> n >> k;
  	FILL(sum,0);
  	FILL(all,0);
  	REP(i,0,n){
  		int tmp;
  		cin >> tmp;
  		all[tmp]++;
  	}
  	sum[0] = 0;
  	REP(i,0,MAXN){
  		sum[i+1] = all[i]+sum[i];
  	}
  	int maxp = 0;
  	REP(i,0,MAXN){
  		int right = min(MAXN, i+k+1);
  		int num = sum[right]-sum[i];
  		maxp = max(maxp, num);
  	}
  	cout << maxp << endl;

	return 0;
}