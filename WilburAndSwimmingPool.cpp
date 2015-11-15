/*
 *	CodeForces 596A
 *	Created by Ziyi Tang
 *	
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdlib.h>
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



int main(){
	int num;
	cin >> num;
	vpi all;
	REP(i,0,num){
		int a,b;
		cin >> a >>b;
		all.push_back(make_pair(a,b));
	}
	int sz = all.size();
	if(all.size() == 1)
		cout << -1 << endl;
	else if(sz == 2){
		pi x = all[0];
		pi y = all[1];
		if(x.first == y.first || x.second == y.second){
			cout << -1 << endl;
		}
		else{
			int h = abs(x.first-y.first);
			int v = abs(x.second-y.second);x
			cout << h*v << endl;
		}
	}
	else{
		int good = 0;
		REP(i,0,sz-1){
			REP(j,i+1,sz){
				pi x = all[i];
				pi y = all[j];
				if(x.first != y.first && x.second != y.second){
					int h = abs(x.first-y.first);
					int v = abs(x.second-y.second);
					cout << h*v << endl;
					good = 1;
					break;
				}
			}
			if(good){
				break;
			}
		}

	}

	return 0;
}
