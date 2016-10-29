/*
 *	UVA 941
 *	Created by Ziyi Tang
 *	Permutations
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
#define MAXN 25
#define MOD 1000000007

ll fac[MAXN];
int main(){
	fac[0] = 1;
	REP(i,1,21){
		fac[i] = i*fac[i-1];
	}
	int test;
	cin >> test;
	while(test--){
		ll n;
		string line;
		cin >> line; cin >> n;
		sort(line.begin(), line.end());
		string re = "";
		int sz = line.size();
		for(int i = sz; i >= 1; i--){
			int idx = n/fac[i-1];
			re += line[idx];
			line.erase(line.begin()+idx);
			n %= fac[i-1];
		}
		cout << re << endl;
	}
	return 0;
}