/*
 *	UVA 306
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Find lcm for the peroid of each position
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
#define MAXN 205
#define MOD 1000000007

vi keys;
int n,k;
// GCD
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
// LCM
int lcm(int a, int b){
	return a * (b / gcd(a , b));
}
int main(){
	while(cin >> n && n != 0){
		keys.clear();	
		REP(i,0,n){
			int tmp; cin >> tmp;
			keys.push_back(tmp);
		}
		int peroid = 1;
		REP(i,0,n){
			int tmp = keys[i];
			int count = 1;
			while(tmp-1 != i){
				count++;
				tmp = keys[tmp-1];
			}
			//cout << count << endl;
			if(count)
				peroid = lcm(peroid, count);
		}
		while(cin >> k && k != 0){
			k %= peroid;
			getchar();
			string line;
			getline(cin, line);
			int sz = line.size();
			char build[2][205];
			int idx = 0;
			REP(i,0,n){
				if(i < sz)
					build[idx][i] = line[i];
				else
					build[idx][i] = ' ';
			}
			while(k--){
				idx ^= 1;
				REP(i,0,n){
					build[idx][keys[i]-1] = build[idx^1][i];
				}
			}
			string re = "";
			REP(i,0,n){
				re+=build[idx][i];
			}
			cout << re << endl;
		}
		cout << endl;
	}
	return 0;
}