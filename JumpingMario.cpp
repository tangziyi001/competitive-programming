/*
 *	UVA 11764
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vi all;
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		int n, tmp;
		cin >> n;
		int ca =  0, cb = 0;
		all.clear();
		REP(i,0,n){
			cin >> tmp;
			all.push_back(tmp);
		}
		REP(i,1,n){
			if(all[i] > all[i-1])
				ca++;
			if(all[i] < all[i-1])
				cb++;
		}
		printf("Case %d: %d %d\n", t, ca, cb);
	}
	return 0;
}