/*
 *	UVA 11085
 *	Created by Ziyi Tang
 *	Pre-Computation
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

vvi pre;
vi all;
vi now;

bool place(int pos, int idx){
	REP(i,0,pos){
		if(now[i] == idx || abs(now[i]-idx) == abs(i-pos))
			return false;
	}
	return true;
}
void rec(int pos){
	if(pos == 8){
		pre.push_back(now); 
		return;
	}
	REP(i,0,8) if(place(pos, i)){
		now[pos] = i;
		rec(pos+1);
	}
}

int main(){
	
	pre.clear();
	now.assign(8,0);
	rec(0);
	int sz = pre.size();
	// REP(i,0,sz){
	// 	REP(j,0,8){
	// 		cout << pre[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int first;
	int test = 0;
	while(cin >> first){
		test++;
		all.clear();
		all.push_back(first-1);
		REP(i,0,7){
			int tmp;
			cin >> tmp;
			all.push_back(tmp-1);
		}
		int minp = INF;
		REP(i,0,sz){
			int cont = 0;
			REP(j,0,8){
				if(all[j] != pre[i][j])
					cont++;
			}
			minp = min(minp,cont);
		}
		printf("Case %d: %d\n",test, minp);

	}
	return 0;
}
