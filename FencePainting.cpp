/*
 *	USACO 2015 December Contest, Bronze 1
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

int all[105];
int a,b,c,d;
int main(){
	FILL(all,0);
	ifstream ifile("paint.in");
	ifile >> a >> b >> c >> d;
	ifile.close();
	REP(i,a,b){
		all[i] = 1;
	}
	REP(i,c,d){
		all[i] = 1;
	}
	int cont = 0;
	REP(i,0,101){
		if(all[i] == 1)
			cont++;
	}
	ofstream ofile("paint.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}