/*
 *	UVA 10487
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vi all;
int main(){
	int n;
	int t = 0;
	while(cin >> n && n != 0){
		t++;
		all.clear();
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		int sz = all.size();
		int q;
		cin >> q;
		printf("Case %d:\n",t);
		REP(i,0,q){
			int tmp;
			cin >> tmp;
			int close = INF;
			REP(i,0,sz-1) REP(j,i+1,sz){
				int now = all[i]+all[j];
				if(abs(now-tmp) < abs(close-tmp)){
					close = now;
				}
			}
			printf("Closest sum to %d is %d.\n", tmp, close);
		}
	}
	return 0;
}
