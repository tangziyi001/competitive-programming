/*
 *	UVA 11935
 *	Created by Ziyi Tang
 *	Simulation
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

int main(){
	string line;
	double maxp = 0;
	double recent_cost = 0;
	int recent_idx = 0;
	int leak = 0;
	int cost = 0;
	while(getline(cin,line) && line != "0 Fuel consumption 0"){
		stringstream ss(line);
		int km;
		ss >> km; 
		string cas;
		ss >> cas;
		recent_cost +=  (km-recent_idx)*((double)cost/100+leak);
		maxp = max(maxp, recent_cost);
		//cout << "rc" << recent_cost << "Cost" << cost << "leak" << leak << endl;
		if(cas == "Fuel"){
			string tmp;
			ss >> tmp;
			ss >> cost;
		}
		else if(cas == "Goal"){
			printf("%.3lf\n",maxp);
			maxp = 0;
			recent_cost = 0;
			recent_idx = 0;
			leak = 0;
			cost = 0;
			continue;
		}
		else if(cas == "Leak"){
			leak+=1;
		}
		else if(cas == "Gas"){
			string tmp;
			ss >> tmp;
			recent_cost = 0;
		}
		else{
			leak = 0;
		}
		recent_idx = km;
	}
	return 0;
}

