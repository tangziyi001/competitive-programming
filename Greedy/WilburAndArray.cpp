/*
 *	CodeForces 596B
 *	Created by Ziyi Tang
 *	Greedy
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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


int all[200010];
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int now;
		cin >> now;
		all[i] = now;
	}
	int tmp = 0;
	ll sum;
	REP(i,0,n){
		sum += abs(all[i]-tmp);
		tmp = all[i];
	}
	cout << sum << endl;

	return 0;
}
