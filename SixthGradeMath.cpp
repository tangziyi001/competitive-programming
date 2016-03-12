/*
 *	ICPC NY 2008A
 *	Created by Ziyi Tang
 *	GCD & LCM
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

// GCD
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

// LCM
int lcm(int a, int b){
	return a * (b / gcd(a , b));
}

int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int a,b;
		cin >> a >> b;
		printf("%d %d %d\n", i+1, lcm(a,b), gcd(a,b));
	}
	return 0;
}
