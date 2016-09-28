/*
 *	
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	string line;
	cin >> line;
	int idx = 0;
	vector<string> all;
	vector<int> allI;
	REP(i,0,line.size()){
		if(line[i] == '+'){
			all.push_back(line.substr(idx,i-idx));
			idx = i+1;
		}
	}
	if(line.size() > idx)
		all.push_back(line.substr(idx));
	sort(all.begin(), all.end());
	REP(i,0,all.size()){
		if(i != 0) cout << "+";
		cout << all[i];
	}
	cout << endl;
	return 0;
}