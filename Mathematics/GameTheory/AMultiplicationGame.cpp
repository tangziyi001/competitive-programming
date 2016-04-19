/*
 *	UVA 847
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Stan always times 9 and Ollie always times 2
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
#define MOD 1000000007

int main(){
	int n;
	while(cin >> n){
		int now = 0;
		ll cur = 1LL;
		while(cur < n){
			if(!now){
				cur*=9;
			}
			else
				cur*=2;
			now ^= 1;
		}
		if(!now) cout << "Ollie wins." << endl;
		else
			cout << "Stan wins." << endl;

	}

	return 0;
}