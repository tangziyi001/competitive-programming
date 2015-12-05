/*
 *	UVA 11222
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

vvi all;
vvi uni;
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		set<int> mtmp;
		vector<set<int> > allset;
		allset.assign(3,mtmp);
		all.clear();
		uni.clear();

		vi tt;
		all.assign(3,tt);
		uni.assign(3,tt);
		REP(i,0,3){
			int num;
			cin >> num;
			REP(j,0,num){
				int tmp;
				cin >> tmp;
				//cout << i << j << tmp << endl;
				all[i].push_back(tmp);
				allset[i].insert(tmp);
			}
		}

		REP(i,0,3){
			int sz = all[i].size();
			int now = 0;
			REP(j,0,sz){
				now = all[i][j];
				//cout << now << endl;
				if(i == 0){
					if(allset[1].find(now) == allset[1].end() && allset[2].find(now) == allset[2].end()){
						uni[0].push_back(now);
					}

				}
				if(i == 1){
					if(allset[0].find(now) == allset[0].end() && allset[2].find(now) == allset[2].end()){
						uni[1].push_back(now);
					}

				}
				if(i == 2){
					if(allset[0].find(now) == allset[0].end() && allset[1].find(now) == allset[1].end()){
						uni[2].push_back(now);
					}
				}
			}
		}
		printf("Case #%d:\n", t);
		int fs,ss,ts;
		fs = uni[0].size();
		ss = uni[1].size();
		ts = uni[2].size();
		int maxp = fs;
		maxp = max(maxp,ss);
		maxp = max(maxp,ts);
		REP(i,0,3){
			int sz = uni[i].size();
			if(sz == maxp){
				cout << i+1 << " " << maxp;
				sort(uni[i].begin(),uni[i].end());
				REP(j,0,sz){
					cout << " " << uni[i][j];
				}
				cout << endl;
			}
		}





	}
	return 0;
}
