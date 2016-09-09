/*
 *	Codeforces Educational Round 15 C
 *	Created by Ziyi Tang
 *	Binary Search and Two Pointer
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

vi ns;
vi ms;
int n,m;
bool check(ll r){
	int ni = 0;
	REP(i,0,m){
		while(ns[ni] >= ms[i]-r && ns[ni] <= ms[i]+r){
			ni++;
			if(ni == n) return true;
		}
	}
	return false;
}
int main(){
	cin >> n >> m;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		ns.push_back(tmp);
	}
	REP(i,0,m){
		int tmp;
		cin >> tmp;
		ms.push_back(tmp);
	}
	ll i = 0, j = 2000000000;
	while(i <= j){
		ll mid = (i+j)/2;
		if(check(mid))
			j = mid-1;
		else
			i = mid+1;
	}
	cout << i << endl;
	return 0;
}