/*
 *	CodeForces 341C
 *	Created by Ziyi Tang
 *	For each pair p1,p2, the probability of p1*p2%p == 0 equals 1-the probability
 * 	that both of them is not divisible by p (because either of them is divisible 
 *	by p, then the product is divisible by p). The number of number between
 *	l and r that is not divisible by p is r/p-(l-1)/p.
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

vpi all;
int main(){
	int n,p;
	cin >> n >> p;
	int l,r;
	double re = 0;
	REP(i,0,n){
		cin >> l >> r;
		all.push_back(make_pair(l,r));
	}
	REP(i,0,n){
		pi p1 = all[i];
		pi p2 = all[(i+1)%n];
		int l1 = p1.first;
		int l2 = p2.first;
		int r1 = p1.second;
		int r2 = p2.second;
		int a1 = r1/p-(l1-1)/p;
		int a2 = r2/p-(l2-1)/p;
		double per = ((double)(r1-l1+1-a1)/(r1-l1+1))*((double)(r2-l2+1-a2)/(r2-l2+1));
		re+=(1-per)*2000;
	}
	printf("%.6lf\n",re);
	return 0;
}
