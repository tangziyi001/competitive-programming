/*
 *	MathFunctions
 *	Created by Ziyi Tang
 *	
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

// Binet's Formula, approximate fib
ll binet(int n){
	double g = (1+sqrt(5))/2;
	return (ll)((pow(g,n)-(pow(-g,-n)))/sqrt(5));
}

// Combination DP
ll comb[MAXN][MAXN]; // n choose k
void dp(){
	comb[0][0] = 1LL;
	REP(i,1,MAXN) REP(j,0,i+1){
		comb[i][j] = comb[i-1][j];
		if(j >= 1)
			comb[i][j] += comb[i-1][j-1];
	}
}

// Power Computation
ll power(ll base, ll n){
	if(n == 0LL) return 1LL;
	//if(n == 1LL) return base;
	ll tmp = power(base,n/2);
	ll now = tmp*tmp;
	if(n&1){
		now = base*now;
	}
	return now;
}


int main(){
	REP(i,0,10)
	cout << power(2,i) << endl;
	return 0;
}

/*
 *	Compute Polynomial; Given coefficients ai and value x
 *	Naive approach: iteraye through every xi
 *	Faster way: b_n = a_n, b_n-1=a_n-1+b_n*x
 *
 *	Combination: C(n,k) = n!/((n-k)!k!)
 *	
 *
 *
 *
 *
 *
 *
 *
 *
 */
