/*
 *	UVA 10777
 *	Coded by Ziyi Tang
 *	Expectation Recurrence Equation
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
#define MOD 1000000007


int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		int n;
		double left = 1.0;
		double right = 0.0;
		cin >> n;
		REP(i,0,n){
			int tt;
			double pro;
			cin >> tt >> pro;
			if(tt >= 0){
				right += pro*tt;
			}
			else{
				tt = -tt;
				left-=pro;
				right+=pro*tt;
			}
		}
		if(fabs(left) < 1e-9)
			printf("Case %d: God! Save me\n",t);
		else
			printf("Case %d: %.2lf\n", t, right/left+1e-9);
	}
	return 0;
}