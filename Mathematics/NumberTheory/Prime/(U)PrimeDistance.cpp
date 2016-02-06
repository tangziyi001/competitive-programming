/*
 *	UVA 10140
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
#define MAXN 100000

int all[MAXN];
int main(){
	FILL(all,0);
	for(ll i = 2; i < MAXN; i++){
		if(all[i] == 0){
			for(ll j = 2; j*i < MAXN; j++){
				all[j] = 1;
			}
		}
	}
	ll l,r;
	cout << "done" << endl;
	while(cin >> l >> r){
		ll max_left = -1;
		ll max_right = -1;
		ll min_left = -1;
		int min_dis = -1;
		for(int i = l; i <= r; i++){
			if(max_left == -1) max_left = i;
			else(max_right = i);
		}
		if(max_left == -1 || max_right == -1){
			cout << "no" << endl;
		}else{
			cout << all[max_left] << endl;
		}
	}
	return 0;
}
