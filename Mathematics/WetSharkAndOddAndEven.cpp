/*
 *	CodeForces 341A
 *	Created by Ziyi Tang
 *	Sum all numbers. If the sum is even then return it. Else, substract the min odd.
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

vector<ll> all;
int main(){
	int n;
	cin >> n;
	ll sum = 0;
	REP(i,0,n){
		ll tmp;
		cin >> tmp;
		all.push_back(tmp);
		sum+=tmp;
	}
	int idx = 0;
	sort(all.begin(),all.end());
	if(sum%2==0) cout << sum << endl;
	else{
		while(all[idx]%2==0 && idx < n) idx++;
		cout << sum-all[idx] << endl;
	}

	return 0;
}
