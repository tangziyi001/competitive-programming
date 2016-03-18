/*
 *	CodeForces 655B
 *	Coded by Ziyi Tang
 *	Greedy
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

int n,k;
ll sum = 0LL;
int main(){
	cin >> n >> k;
	k = min(k, (int)n/2);
	int tmp = n;
	REP(i,0,k){
		sum += 2*(tmp-2)+1;
		tmp-=2;
	}
	cout << sum << endl;
	return 0;
}

