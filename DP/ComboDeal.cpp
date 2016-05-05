/*
 *	UVA 10898
 *	Coded by Ziyi Tang
 *	DP with STL map
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

map<vi, int> dp;
vector<pair<vi, int> > all; // Combo, price
int n;
int sz;
bool check(int k, vi now){
	REP(i,0,n){
		if(now[i] < all[k].first[i]){
			return false;
		}
	}
	return true;
}
void myprint(vi now){
	REP(i,0,now.size()){
		cout << now[i] << " ";
	}
	cout << endl;
}
int rec(vi now){
	//myprint(now);
	if(dp.find(now) != dp.end()){
		return dp[now];
	}
	int minp = INF;
	REP(k,0,sz) if(check(k, now)){
		vi nxt;
		REP(i,0,n){
			nxt.push_back(now[i]-all[k].first[i]);
		}
		minp = min(minp, rec(nxt)+all[k].second);
	}
	return dp[now] = minp;
}
int main(){
	while(cin >> n){
		dp.clear();
		dp[vi(n,0)]=0;
		all.clear();
		sz = 0;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			vi now;
			// Push individuals
			REP(j,0,n){
				if(j == i)
					now.push_back(1);
				else
					now.push_back(0);
			}
			all.push_back(make_pair(now,tmp));
			//myprint(now);
		}
		// Push combos
		int com;
		cin >> com;
		REP(i,0,com){
			vi now;
			REP(j,0,n){
				int tmp;
				cin >> tmp;
				now.push_back(tmp);
			}
			int pri;
			cin >> pri;
			all.push_back(make_pair(now, pri));
			//myprint(now);
		}
		sz = all.size();
		int q;
		cin >> q;
		REP(i,0,q){
			int tmp;
			vi now;
			REP(j,0,n){
				cin >> tmp;
				now.push_back(tmp);
			}
			int minp = rec(now);
			cout << minp << endl;
		}
	}

	return 0;
}