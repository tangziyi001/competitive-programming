/*
 *	Codeforces 749D - Leaving Auction
 *	Created by Ziyi Tang
 *	Max Set. Binary Search
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
#define MAXN 1000
#define MOD 1000000007

vvi all;
set<int> ss; // max
set<int> tt; // temp max
map<int,int> mm; // max, idx
vi maxv; // idx, max
int main(){
	int n;
	cin >> n;
	all.assign(n,vi(0,0));
	maxv.assign(n,-1);
	REP(i,0,n){
		int a,val;
		cin >> a >> val;
		all[a-1].push_back(val);
		mm[val] = a-1;
		maxv[a-1] = val;
	}
	REP(i,0,n) if(maxv[i] != -1){
		ss.insert(maxv[i]);
	}
	int q;
	cin >> q;
	REP(i,0,q){
		int num = 0;
		cin >> num;
		REP(j,0,num){
			int now;
			cin >> now;
			now--;
			int maxp = maxv[now];
			if(maxp != -1){
				tt.insert(maxp);
				ss.erase(maxp);
			}
		}
		if(ss.size() == 0) {
			cout << 0 << " " << 0 << endl;
		} else {
			int maxval = *ss.rbegin();
			int maxidx = mm[maxval];
			//cout << maxidx+1 << ":" << maxval << endl;
			if(ss.size() > 1){
				int secondmax = *(next(ss.rbegin()));
				int secondmaxi = mm[secondmax];
				cout << maxidx+1 << " " << *upper_bound(all[maxidx].begin(), all[maxidx].end(), secondmax) << endl;
			} else {
				cout << maxidx+1 << " " << all[maxidx][0] << endl;
			}
		}
		while(!tt.empty()){
			ss.insert(*tt.begin());
			tt.erase(tt.begin());
		}
	}
	return 0;
}