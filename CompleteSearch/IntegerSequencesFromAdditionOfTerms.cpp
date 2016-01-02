/*
 *	UVA 00927
 *	Created by Ziyi Tang
 *	Find the corresponding number with certain n
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
#define MAXN 1000010

vector<int> co;
int degree;
int d,k;

ll compute(int n){
	ll re = 0;
	REP(i,0,degree+1){
		re += (co[i] * (ll)pow(n,i));
	}
	return re;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		co.clear();
		cin >> degree;
		REP(i,0,degree+1){
			int tmp;
			cin >> tmp;
			co.push_back(tmp);
		}
		cin >> d >> k;
		int n = 1;
		while((d+n*d)*n/2 < k){
			n++;
			//cout << n << endl;
		}
		cout << compute(n) << endl;
	}
	return 0;
}
