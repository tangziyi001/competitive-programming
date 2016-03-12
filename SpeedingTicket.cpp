/*
 *	USACO 2015 December Contest, Bronze 2
 *	Created by Ziyi Tang
 *	
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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

int n,m;
int a[105];
int b[105];
int main(){
	ifstream ifile("speeding.in");
	ifile >> n >> m;
	int idx = 0;
	REP(i,0,n){
		int length, tmp;
		ifile >> length >> tmp;
		REP(j,0,length)
			a[idx++] = tmp;
	}
	idx = 0;
	REP(i,0,m){
		int length, tmp;
		ifile >> length >> tmp;
		REP(j,0,length)
			b[idx++] = tmp;
	}
	ifile.close();
	int maxp = 0;
	REP(i,0,101){
		maxp = max(maxp, b[i]-a[i]);
	}
	ofstream ofile("speeding.out");
	cout << maxp << endl;
	ofile << maxp << endl;
	ofile.close();
	return 0;
}