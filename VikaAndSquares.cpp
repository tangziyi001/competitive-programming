/*
 *	CodeForces 337B
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
typedef unsigned long long ull;
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

vector<ull> all;
int main(){
	int n;
	cin >> n;
	ull start = 0LL;
	ull first = 0LL;
	ull idx = 0LL;
	ull minp = INFL;
	ull dis = -1;
	REP(i,0,n){
		ull tmp;
		cin >> tmp;
		all.push_back(tmp);
		if(tmp < minp){
			minp = tmp; 
			idx = i;
			start = i;
			first = i;
			dis = 0LL;
		}
		else if(tmp == minp){
			idx = i;
			dis = max(dis, idx-start-1);
			start = i;
		}
	}
	dis = max(dis, (first+n-start-1)%n);
	ull re = n*all[idx] + dis;
	
	cout << re << endl;
	return 0;
}
