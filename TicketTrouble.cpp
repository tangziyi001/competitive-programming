/*
 *	Code Jam to I/O 2017 for Women A
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
#define MAXN 105
#define MOD 1000000007

int main(){
	int T;
	cin >> T;
	REP(t,1,T+1){
		vpi all;
		set<pi> ss;
		int mark[MAXN];
		FILL(mark,0);
		int f,s;
		cin >> f >> s;
		REP(i,0,f){
			int a,b;
			cin >> a >> b;
			all.push_back(make_pair(a,b));
		}
		int cont = 0;
		REP(i,0,f){
			if(ss.count(all[i]) != 0) continue;
			ss.insert(all[i]);
			mark[all[i].first]+=1;
			if(all[i].second != all[i].first)
				mark[all[i].second]+=1;
		}
		REP(i,0,MAXN){
			cont = max(cont,mark[i]);
		}
		printf("Case #%d: %d\n", t,cont);
	}
	return 0;
}