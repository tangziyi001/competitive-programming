/*
 *	UVA 11933
 *	Created by Ziyi Tang
 *	Bitwise Operation
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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
	int n;
	while(cin >> n && n!=0){
		vi allone;
		bitset<32> b(n);
		REP(i,0,32){
			if(b[i] == 1){
				allone.push_back(i);
				// cout << "push" << i << endl;
			}
		}
		int sz = allone.size();
		bitset<32> x;
		bitset<32> y;
		REP(i,0,sz){
			if(i%2 == 0){
				x.set(allone[i],1);
			}
			else{
				y.set(allone[i],1);
			}
		}
		cout << x.to_ulong() << " " << y.to_ulong() << endl;
		

	}

	return 0;
}
