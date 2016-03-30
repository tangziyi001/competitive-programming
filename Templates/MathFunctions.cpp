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
	if(a == 0 || b == 0) return 1;
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


int main(){
	for(int i = 0; i < 100; i++){
		cout << i << " " << binet(i) << endl;
	}
	return 0;
}

/*
 *	Compute Polynomial; Given coefficients ai and value x
 *	Naive approach: iteraye through every xi
 *	Faster way: b_n = a_n, b_n-1=a_n-1+b_n*x
 *
 *
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
