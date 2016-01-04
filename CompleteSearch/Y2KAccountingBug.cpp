/*
 *	UVA 10576
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
int s,d;
int rec(int pos, int earn){
	if(pos >= 5){
		int five = 0;
		for(int i = pos-5; i < pos; i++){
			five += all[i];
		}
		if(five >= 0)
			return -INF;
	}
	if(pos == 12) return earn;
	int maxp = -INF;
	all.push_back(s);
	maxp = max(maxp, rec(pos+1, earn+s));
	all.pop_back();
	all.push_back(-d);
	maxp = max(maxp, rec(pos+1, earn-d));
	all.pop_back();
	return maxp;
}
int main(){
	while(cin >> s >> d){
		int re = rec(0,0);
		if(re >= 0)
			cout << re << endl;
		else
			cout << "Deficit" << endl;
	}
	return 0;
}
