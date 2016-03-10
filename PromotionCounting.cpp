/*
 *	USACO 2016 January Contest, Bronze 1
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
#include <fstream>
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

vpi all;
int re[3];
int main(){
	ifstream infile("promote.in");
	REP(i,0,4){
		int a,b;
		infile >> a >> b;
		all.push_back(make_pair(a,b));
	}
	re[2] = all[3].second-all[3].first;
	re[1] = all[2].second-all[2].first+re[2];
	re[0] = all[1].second-all[1].first+re[1];
	infile.close();
	ofstream ofile("promote.out");
	REP(i,0,3)
		ofile << re[i] << endl;
	ofile.close();
	return 0;
}

