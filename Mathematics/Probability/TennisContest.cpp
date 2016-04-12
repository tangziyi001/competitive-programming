/*
 *	UVA 12457
 *	Coded by Ziyi Tang
 *	Binomial Distribution
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
typedef unsigned long long ll;
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
#define MAXN 50

ll comb[MAXN][MAXN]; // n choose k
void dp(){
	comb[0][0] = 1ULL;
	REP(i,1,MAXN) REP(j,0,i+1){
		comb[i][j] = comb[i-1][j];
		if(j >= 1)
			comb[i][j] += comb[i-1][j-1];
	}
}
int main(){
	REP(i,0,MAXN) REP(j,0,MAXN)
		comb[i][j] = 0ULL;
	dp();
	// REP(i,0,10){
	// 	REP(j,0,10){
	// 		cout << comb[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int test;
	cin >> test;
	while(test--){
		int n;
		double p;
		cin >> n >> p;
		int all = 2*n-1;
		double bwin = 0.0;
 		REP(i,0,n){
 			double now = comb[all][i]*pow(1-p,i)*pow(p,all-i);
 			//cout << now << endl;
 			bwin += now;
		}
		printf("%.2lf\n", bwin);
	}
	return 0;
}