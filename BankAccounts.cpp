/*
 *	Goldman Sachs CodeSprint 1
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
typedef vector<double> vd;
typedef vector<vd> vvd;
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ((x) > EPS)
#define MAXN 1000
#define MOD 1000000007

vi all;
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		int n,k,x,d; cin >> n >> k >> x >> d;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		double cost = 0.0;
		REP(i,0,n){
			cost += max((double)k, x*all[i]*1.0/100);
		}
		if(cost <= d){
			cout << "fee" << endl;
		} else {
			cout << "upfront" << endl;
		}
	}
	return 0;
}