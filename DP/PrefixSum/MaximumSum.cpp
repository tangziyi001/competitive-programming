/*
 *	UVA 108
 *	Created by Ziyi Tang
 *	Prefix Sum
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

int sum[105][105];
int all[105][105];
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		REP(j,0,n){
			int tmp;
			cin >> tmp;
			all[i][j] = tmp;
		}
	}
	sum[1][1] = all[0][0];
	REP(i,1,n+1){
		REP(j,1,n+1){
			sum[i][j] = sum[i][j-1] + sum[i-1][j] + all[i-1][j-1] - sum[i-1][j-1];
		}
	}
	int maxp = -INF;
	REP(i,1,n+1){
		REP(j,1,n+1){
			REP(a,i,n+1){
				REP(b,j,n+1){
					maxp = max(maxp, sum[a][b]-sum[a][j-1]-sum[i-1][b]+sum[i-1][j-1]);
				}
			}
		}
	}
	cout << maxp << endl;
	return 0;
}
