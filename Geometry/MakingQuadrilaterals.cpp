/*
 *	UVA 12256
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 70
#define MOD 1000000007

ll all[MAXN];
int main(){
	int n;
	int t = 1;
	all[0] = all[1] = all[2] = 1LL;
	REP(i,3,MAXN){
		all[i] = all[i-1]+all[i-2]+all[i-3];
	}
	while(cin >> n && n != 0){
		printf("Case %d: %lld\n",t,all[n-1]);
		t++;
	}
	return 0;
}
