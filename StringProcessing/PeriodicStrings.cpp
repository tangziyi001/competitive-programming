/*
 *	
 *	Coded by Ziyi Tang, CS480 S16 New York University
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	int test;
	cin >> test;
	REP(cas,1,test+1){
		string now;
		cin >> now;
		int sz = now.size();
		int re = -1;
		REP(k,1,sz+1){
			if(sz%k != 0) continue;
			string p = now.substr(0,k);
			//cout << p << endl;
			int flag = 1;
			for(int i = 0; i < sz-k+1; i+=k){
				string t = now.substr(i,k);
				//cout << "t " << t << endl;
				if(p != t){
					flag = 0;
					break;
				}
			}
			if(flag){
				re = k;
				break;
			}
		}
		if(cas != 1) cout << endl;
		cout << re << endl;
	}
	return 0;
}