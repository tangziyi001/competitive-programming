/*
 *	UVA 484
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

map<int,int> all;
vector<int> order;
int main(){
	string str;
	//getline(cin,str);
	int now;
	//stringstream ss(str);
	while(scanf("%d",&now) != EOF){
		if(all.find(now) == all.end()){
			order.push_back(now);
			all[now] = 1;
		}
		else all[now] += 1;
	}
	int sz = order.size();
	REP(i,0,sz){
		cout << order[i] << " " << all[order[i]] << endl;
	}
	return 0;
}
