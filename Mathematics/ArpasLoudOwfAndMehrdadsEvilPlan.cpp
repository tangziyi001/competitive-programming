/*
 *	Codeforces 742C - Arpa's loud Owf and Mehrdad's evil plan
 *	Created by Ziyi Tang
 *	DFS and Math
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
#define MAXN 105
#define MOD 1000000007

vi all;
vi num;
int mark[MAXN];
int dfs(int idx, int ori){
	int nxt = all[idx];
	if(mark[nxt] != -1 && nxt == ori) return 0;
	else if(mark[nxt] != -1) return -INF;
	else {
		mark[nxt] = 1;
		return 1+dfs(nxt, ori);
	}
}
// GCD
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

// LCM
int lcm(int a, int b){
	return a * (b / gcd(a , b));
}
int main(){
	int n; cin >> n;
	FILL(mark,-1);
	REP(i,0,n){
		int tmp; cin >> tmp;
		all.push_back(tmp-1);
	}
	REP(i,0,n){
		if(mark[i] == -1){
			mark[i] = 1;
			int now = 1+dfs(i, i);
			if(now < 0){
				cout << -1 << endl;
				return 0;
			}
			//cout << "now" << now << endl;
			now = now%2 == 0 ? now/2 : now;
			num.push_back(now);
		}
	}
	int re = 1;
	REP(i,0,num.size()){
		re = lcm(re, num[i]);
	}
	cout << re << endl;
	return 0;
}